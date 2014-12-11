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
# Author: David Zeuthen <davidz@redhat.com>
#  (2014) Jonatan Palsson <jonatan.palsson@pelagicore.com>

import sys
import optparse

from . import config
from . import utils
from . import dbustypes
from . import parser
from . import codegen

def find_arg(arg_list, arg_name):
    for a in arg_list:
        if a.name == arg_name:
            return a
    return None

def find_method(iface, method):
    for m in iface.methods:
        if m.name == method:
            return m
    return None

def find_signal(iface, signal):
    for m in iface.signals:
        if m.name == signal:
            return m
    return None

def find_prop(iface, prop):
    for m in iface.properties:
        if m.name == prop:
            return m
    return None

def codegen_main():
    arg_parser = optparse.OptionParser('%prog [options]')
    arg_parser.add_option('', '--xml-files', metavar='FILE', action='append',
                          help='D-Bus introspection XML file')
    arg_parser.add_option('', '--interface-prefix', metavar='PREFIX', default='',
                            help='String to strip from D-Bus interface names for code and docs')
    arg_parser.add_option('', '--cpp-namespace', metavar='NAMESPACE', default='',
                            help='The namespace to use for generated C++ code')
    arg_parser.add_option('', '--generate-cpp-code', metavar='OUTFILES',
                          help='Generate C++ code in OUTFILES.[cpp|h]')
    (opts, args) = arg_parser.parse_args();

    all_ifaces = []
    node_xmls = []
    for fname in args:
        f = open(fname, 'rb')
        xml_data = f.read()
        node_xmls.append(xml_data)
        f.close()
        parsed_ifaces = parser.parse_dbus_xml(xml_data)
        all_ifaces.extend(parsed_ifaces)

    interface_prefix_list = opts.interface_prefix.split(",")

    for i in all_ifaces:
        i.post_process(interface_prefix_list, opts.cpp_namespace)

    cpp_code = opts.generate_cpp_code

    if cpp_code:
        proxy_h = open(cpp_code + "_proxy" + '.h', 'w')
        proxy_cpp = open(cpp_code + "_proxy" + '.cpp', 'w')
        stub_h = open(cpp_code + "_stub" + '.h', 'w')
        stub_cpp = open(cpp_code + "_stub" + '.cpp', 'w')
        common_h = open(cpp_code + "_common" + '.h', 'w')
        common_cpp = open(cpp_code + "_common" + '.cpp', 'w')
        gen = codegen.CodeGenerator(all_ifaces,
                                    opts.cpp_namespace,
                                    interface_prefix_list,
                                    node_xmls,
                                    proxy_h, proxy_cpp,
                                    stub_cpp, stub_h,
                                    common_cpp, common_h);
        print proxy_h.name
        ret = gen.generate()
        proxy_h.close()
        proxy_cpp.close()
        stub_h.close()
        stub_cpp.close()

    sys.exit(0)

if __name__ == "__main__":
    codegen_main()
