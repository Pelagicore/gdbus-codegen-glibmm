# -*- Mode: Python -*-

# GDBus - GLib D-Bus Library
#
# Copyright (C) 2008-2011 Red Hat, Inc.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General
# Public License along with this library; if not, see <http://www.gnu.org/licenses/>.
#
# Author: David Zeuthen   <davidz@redhat.com>
#  (2014) Jonatan Palsson <jonatan.palsson@pelagicore.com>

import sys, os

from jinja2 import Environment, FileSystemLoader

from textwrap import dedent

from . import config
from . import utils
from . import dbustypes

THIS_DIR = os.path.dirname(os.path.abspath(__file__))

# ----------------------------------------------------------------------------------------------------

SIGNAL_MAX_PARAM = 10

class CodeGenerator:
    def __init__(self, ifaces, namespace, interface_prefix, node_xmls, proxy_h, proxy_cpp, stub_cpp, stub_h, common_cpp, common_h):
        self.ifaces = ifaces
        self.proxy_h = proxy_h
        self.proxy_cpp = proxy_cpp
        self.stub_h = stub_h
        self.stub_cpp = stub_cpp
        self.common_h = common_h
        self.common_cpp = common_cpp
        self.node_xmls = node_xmls

    def emit (self, dest, text, newline = True):
        """ Emit code to the specified file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        dest.write (text)
        if newline:
            dest.write ("\n")

    def emit_h_p (self, text, newline = True):
        """ Emit code to proxy header file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.proxy_h, text, newline)

    def emit_cpp_p (self, text, newline = True):
        """ Emit code to proxy cpp file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.proxy_cpp, text, newline)

    def emit_h_s (self, text, newline = True):
        """ Emit code to stub header file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.stub_h, text, newline)

    def emit_cpp_s (self, text, newline = True):
        """ Emit code to stub cpp file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.stub_cpp, text, newline)

    def emit_h_common (self, text, newline = True):
        """ Emit code to common header file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.common_h, text, newline)

    def emit_cpp_common (self, text, newline = True):
        """ Emit code to common cpp file
            @param newline boolean indicating whether to append a newline to
                           generated code
        """
        self.emit(self.common_cpp, text, newline)

    def generate_proxy_header(self):
        """ Generate types and classes required by the proxy. This will
        generate a complete class declaration, which is implemented in the
        corresponding cpp file
        """
        h = self.j2_env.get_template('proxy.h.templ').render(
                interfaces=self.ifaces,
                common_h_name=self.common_h.name)
        self.emit_h_p(h)

    def generate_proxy_impl(self):
        """ Generate implementation code for the proxy objects.
        """
        h = self.j2_env.get_template('proxy.cpp.templ').render(
                interfaces=self.ifaces,
                program_version=config.VERSION,
                proxy_h_name=self.proxy_h.name)
        self.emit_cpp_p(h)

    def generate_stub_header(self):
        """ Generate types and classes for the stub. This will generate the
        complete class needed for implementing the stub. The code is placed in
        the header file for the stub.
        """
        h = self.j2_env.get_template('stub.h.templ').render(
                interfaces=self.ifaces,
                common_h_name=self.common_h.name)
        self.emit_h_s(h)

    def generate_stub_impl(self):
        """ Generate implementation code for the stub objects.
        """
        h = self.j2_env.get_template('stub.cpp.templ').render(
                interfaces=self.ifaces,
                node_xmls=self.node_xmls,
                program_version=config.VERSION,
                stub_h_name=self.stub_h.name)
        self.emit_cpp_s(h)

    def generate_common(self, interfaces):
        h = self.j2_env.get_template('common.h.templ').render(
                interfaces=interfaces)
        self.emit_h_common(h)

    def initialize_jinja(self):
        self.j2_env = Environment(loader=FileSystemLoader(THIS_DIR + "/templates/"),
                                  trim_blocks=True,
                                  lstrip_blocks=True)
        def is_templated(method):
            for a in method.in_args:
                if a.templated:
                    return True
            return False
        self.j2_env.tests['templated'] = is_templated

        def is_supported_by_sigc(signal):
            return len(signal.args) <= SIGNAL_MAX_PARAM
        self.j2_env.tests['supported_by_sigc'] = is_supported_by_sigc

        def to_utf8(value):
            return value.decode('utf-8')
        self.j2_env.filters['to_utf8'] = to_utf8

        def indent(value, levels):
            return value.replace('\n', '\n' + '    ' * levels)
        self.j2_env.filters['indent'] = indent

    def generate(self):
        # Jinja initialization
        self.initialize_jinja()

        # Proxy
        self.generate_proxy_header()
        self.generate_proxy_impl()

        # Stub
        self.generate_stub_header()
        self.generate_stub_impl()

        # Common
        self.generate_common(self.ifaces)
