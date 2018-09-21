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

import sys
import xml.parsers.expat

from . import dbustypes

class DBusXMLParser:
    STATE_TOP = 'top'
    STATE_NODE = 'node'
    STATE_INTERFACE = 'interface'
    STATE_METHOD = 'method'
    STATE_SIGNAL = 'signal'
    STATE_PROPERTY = 'property'
    STATE_ARG = 'arg'
    STATE_ANNOTATION = 'annotation'
    STATE_IGNORED = 'ignored'

    def __init__(self, xml_data):
        self._parser = xml.parsers.expat.ParserCreate()
        self._parser.CommentHandler = self.handle_comment
        self._parser.CharacterDataHandler = self.handle_char_data
        self._parser.StartElementHandler = self.handle_start_element
        self._parser.EndElementHandler = self.handle_end_element

        self.parsed_interfaces = []
        self._cur_object = None

        self.state = DBusXMLParser.STATE_TOP
        self.state_stack = []
        self._cur_object = None
        self._cur_object_stack = []

        self._last_comment = None

        self._parser.Parse(xml_data)

        # Sort the errors alphabetically
        for interface in self.parsed_interfaces:
            interface.errors.sort()


    def handle_comment(self, data):
        lines = data.split('\n')
        parsed_lines = []
        indent = -1
        for line in lines:
            if len(line) == 0: continue
            if indent < 0:
                orig_line = line
                line = line.lstrip()
                indent = len(orig_line) - len(line)
            else:
                line = line[indent:]
            parsed_lines.append(line.rstrip())
        # remove the last line, if empty
        if parsed_lines and len(parsed_lines[-1]) == 0:
            parsed_lines = parsed_lines[:-1]
        self._last_comment = dbustypes.Comment(parsed_lines)

    def handle_char_data(self, data):
        #print 'char_data=%s'%data
        pass

    def handle_start_element(self, name, attrs):
        old_state = self.state
        old_cur_object = self._cur_object
        if self.state == DBusXMLParser.STATE_IGNORED:
            self.state = DBusXMLParser.STATE_IGNORED
        elif self.state == DBusXMLParser.STATE_TOP:
            if name == DBusXMLParser.STATE_NODE:
                self.state = DBusXMLParser.STATE_NODE
            else:
                self.state = DBusXMLParser.STATE_IGNORED
        elif self.state == DBusXMLParser.STATE_NODE:
            if name == DBusXMLParser.STATE_INTERFACE:
                self.state = DBusXMLParser.STATE_INTERFACE
                iface = dbustypes.Interface(attrs['name'])
                self._cur_object = iface
                self.parsed_interfaces.append(iface)
            elif name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

            # assign docs, if any
            self._cur_object.doc_string = self._last_comment
            self._last_comment = None

        elif self.state == DBusXMLParser.STATE_INTERFACE:
            if name == DBusXMLParser.STATE_METHOD:
                self.state = DBusXMLParser.STATE_METHOD
                method = dbustypes.Method(attrs['name'])
                self._cur_object.methods.append(method)
                self._cur_object = method
            elif name == DBusXMLParser.STATE_SIGNAL:
                self.state = DBusXMLParser.STATE_SIGNAL
                signal = dbustypes.Signal(attrs['name'])
                self._cur_object.signals.append(signal)
                self._cur_object = signal
            elif name == DBusXMLParser.STATE_PROPERTY:
                self.state = DBusXMLParser.STATE_PROPERTY
                prop = dbustypes.Property(attrs['name'], attrs['type'], attrs['access'])
                self._cur_object.properties.append(prop)
                self._cur_object = prop
            elif name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                if attrs['name'] == 'org.gdbus.glibmm.Error':
                    error = dbustypes.Error(attrs['value'])
                    self._cur_object.errors.append(error)
                    self._cur_object = error
                else:
                    anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                    self._cur_object.annotations.append(anno)
                    self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

            # assign docs, if any
            self._cur_object.doc_string = self._last_comment
            self._last_comment = None

        elif self.state == DBusXMLParser.STATE_METHOD:
            if name == DBusXMLParser.STATE_ARG:
                self.state = DBusXMLParser.STATE_ARG
                arg_name = None
                if 'name' in attrs:
                    arg_name = attrs['name']
                arg = dbustypes.Arg(arg_name, attrs['type'])
                direction = attrs.get('direction', 'in')
                if direction == 'in':
                    self._cur_object.in_args.append(arg)
                elif direction == 'out':
                    self._cur_object.out_args.append(arg)
                else:
                    raise RuntimeError('Invalid direction "%s"'%(direction))
                self._cur_object = arg
            elif name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

        elif self.state == DBusXMLParser.STATE_SIGNAL:
            if name == DBusXMLParser.STATE_ARG:
                self.state = DBusXMLParser.STATE_ARG
                arg_name = None
                if 'name' in attrs:
                    arg_name = attrs['name']
                arg = dbustypes.Arg(arg_name, attrs['type'])
                self._cur_object.args.append(arg)
                self._cur_object = arg
            elif name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

        elif self.state == DBusXMLParser.STATE_PROPERTY:
            if name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

        elif self.state == DBusXMLParser.STATE_ARG:
            if name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

        elif self.state == DBusXMLParser.STATE_ANNOTATION:
            if name == DBusXMLParser.STATE_ANNOTATION:
                self.state = DBusXMLParser.STATE_ANNOTATION
                anno = dbustypes.Annotation(attrs['name'], attrs['value'])
                self._cur_object.annotations.append(anno)
                self._cur_object = anno
            else:
                self.state = DBusXMLParser.STATE_IGNORED

        else:
            raise RuntimeError('Unhandled state "%s" while entering element with name "%s"'%(self.state, name))

        self.state_stack.append(old_state)
        self._cur_object_stack.append(old_cur_object)

    def handle_end_element(self, name):
        self.state = self.state_stack.pop()
        self._cur_object = self._cur_object_stack.pop()

def parse_dbus_xml(xml_data):
    parser = DBusXMLParser(xml_data)
    return parser.parsed_interfaces
