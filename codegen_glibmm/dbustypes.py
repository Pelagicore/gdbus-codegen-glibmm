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

from . import utils

class TypeWrap:
    @staticmethod
    def cppSignatureForDbusSignature(sig):
        """
        The returned tuple has the following values, in order:
            - Type for "in"-parameter to generated function
            - Type for "out" parameter to generated function
            - Type for use with D-Bus function
            - function for casting D-Bus type to out-type
            - function for casting out-type to D-Bus type
        """
        if sig == 'b':
            return ('bool', 'bool', 'bool', "", "")
        elif sig == 'y':
            return ('guchar', 'guchar', 'guchar', "", "")
        elif sig == 'n':
            return ('gint16', 'gint16', 'gint16', "", "")
        elif sig == 'q':
            return ('guint16', 'guint16', 'guint16', "", "")
        elif sig == 'i':
            return ('gint32', 'gint32', 'gint32', "", "")
        elif sig == 'u':
            return ('guint32', 'guint32', 'guint32', "", "")
        elif sig == 'x':
            return ('gint64', 'gint64', 'gint64', "", "")
        elif sig == 't':
            return ('guint64', 'guint64', 'guint64', "", "")
        elif sig == 'd':
            return ('double', 'double', 'double', "", "")
        elif sig == 's':
            return ('std::string', 'std::string', 'Glib::ustring', "Glib::ustring", "")
        elif sig == 'o':
            return ('std::string', 'std::string', 'Glib::ustring', "", "")
        elif sig == 'g':
            return ('std::string', 'std::string', 'Glib::ustring', "", "")
        elif sig == 'ay':
            return ('std::string', 'std::string', 'std::string', "", "")
        elif sig == 'as':
            return ('std::vector<std::string> ', 'std::vector<std::string>', 'std::vector<Glib::ustring>', "TypeWrap::glibStringVecToStdStringVec", "TypeWrap::stdStringVecToGlibStringVec")
        elif sig == 'ao':
            return ('std::vector<std::string> ', 'std::vector<std::string>', 'std::vector<std::string>', "", "")
        elif sig == 'aay':
            return ('std::vector<std::string> ', 'std::vector<std::string>', 'std::vector<std::string>', "", "")
        elif sig == 'v':
            return ('Glib::VariantBase', 'Glib::VariantBase', '', '', '')
        else:
            return (None, None, None, None, None)

class Annotation:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.annotations = []

class Arg:
    def __init__(self, name, signature):
        self.name = name
        self.signature = signature
        self.annotations = []

    def post_process(self, arg_number):
        if self.name == None:
            self.name = 'unnamed_arg%d'%arg_number


        (self.cpptype_in, self.cpptype_out, self.cpptype_get, self.cpptype_get_cast, self.cpptype_to_dbus) = TypeWrap.cppSignatureForDbusSignature(self.signature)

        self.cpptype_send = lambda name, param, cpp_class_name: "Glib::Variant<"+self.cpptype_get+"> "+name+" = Glib::Variant<"+self.cpptype_get+">::create(arg_"+param+");"
        self.cppvalue_get = lambda varname, outvar, idx, cpp_class_name: "Glib::Variant<"+self.cpptype_in+"> "+varname+";\n    wrapped.get_child("+varname+","+idx+");\n    "+outvar+" = "+varname+".get();"

        if self.signature == 'as':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::Variant<std::vector<Glib::ustring> > "+name+" = Glib::Variant<std::vector<Glib::ustring> >::create(" + cpp_class_name + "TypeWrap::stdStringVecToGlibStringVec(arg_" + param + "));"
            self.cppvalue_get = lambda varname, outvar, idx, cpp_class_name: "Glib::VariantContainerBase "+varname+";\n" +\
                                 "    wrapped.get_child("+varname+", "+idx+");\n" +\
                                 "    " + cpp_class_name + "TypeWrap::unwrapList(".format(**locals())+outvar+", "+varname+");"
        elif self.signature == 'ao':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::Variant<std::vector<std::string> > "+name+" = Glib::Variant<std::vector< std::string > >::create_from_object_paths(arg_"+param+");"
            self.cppvalue_get = lambda varname, outvar, idx, cpp_class_name: "Glib::VariantContainerBase "+varname+";\n" +\
                                 "    wrapped.get_child("+varname+", "+idx+");\n" +\
                                 "    " + cpp_class_name + "TypeWrap::unwrapList(".format(**locals())+outvar+", "+varname+");"
        elif self.signature == 'aay':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::Variant<std::vector<std::string> > "+name+" = Glib::Variant<std::vector<std::string> >::create(arg_"+param+");"
            self.cppvalue_get = lambda varname, outvar, idx, cpp_class_name: "Glib::VariantContainerBase "+varname+";\n" +\
                                 "    wrapped.get_child("+varname+", "+idx+");\n" +\
                                 "    " + cpp_class_name + "TypeWrap::unwrapList("+outvar+", "+varname+");"
        elif self.signature == 'g':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::VariantStringBase "+name+";\n Glib::VariantStringBase::create_signature("+name+", arg_"+param+".c_str());"
        elif self.signature == 'o':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::VariantStringBase "+name+";\n Glib::VariantStringBase::create_object_path("+name+", arg_"+param+".c_str());"
        elif self.signature == 'v':
            self.cpptype_send = lambda name, param, cpp_class_name: "Glib::VariantBase params = arg_" + param + ";"
            self.cppvalue_get = lambda varname, outvar, idx, cpp_class_name: 'GVariant *output;\n' +\
                                '    g_variant_get_child(wrapped.gobj(), 0, "v", &output);\n\n' + "    " + outvar + ' = Glib::VariantBase(output);'

        if (self.cpptype_in, self.cpptype_out) == (None, None):
            print "Unknown signature: " + self.signature

            # default to GVariant
            self.cpptype_in  = 'Glib::VariantBase'
            self.cpptype_out  = 'Glib::VariantBase'
            self.cpptype_send = lambda name, param: "Glib::VariantBase "+name+" = arg_"+param+";"
            self.cppvalue_get = lambda varname, outvar, idx: "Glib::VariantBase "+varname+";\n  wrapped.get_child("+varname+","+idx+");\n  "+outvar+" = "+varname+";"

class Method:
    def __init__(self, name):
        self.name = name
        self.in_args = []
        self.out_args = []
        self.annotations = []

    def post_process(self, interface_prefix, cns, cns_upper, cns_lower):
        name = self.name
        self.camel_name = name

        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')

        arg_count = 0
        for a in self.in_args:
            a.post_process(arg_count)
            arg_count += 1

        for a in self.out_args:
            a.post_process(arg_count)
            arg_count += 1

class Signal:
    def __init__(self, name):
        self.name = name
        self.args = []
        self.annotations = []

    def post_process(self, interface_prefix, cns, cns_upper, cns_lower, containing_iface):
        name = self.name
        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')
        self.iface_name = containing_iface.name

        arg_count = 0
        for a in self.args:
            a.post_process(arg_count)
            arg_count += 1

class Property:
    def __init__(self, name, signature, access):
        self.name = name
        self.signature = signature
        self.access = access
        self.annotations = []
        self.arg = Arg('value', self.signature)
        self.readable = False
        self.writable = False
        if self.access == 'readwrite':
            self.readable = True
            self.writable = True
        elif self.access == 'read':
            self.readable = True
        elif self.access == 'write':
            self.writable = True
        else:
            raise RuntimeError('Invalid access type %s'%self.access)

        (self.cpptype_in, self.cpptype_out, self.cpptype_get, self.cpptype_get_cast, self.cpptype_to_dbus) = TypeWrap.cppSignatureForDbusSignature(signature)

        if (self.cpptype_in, self.cpptype_out) == (None, None):
            print "Unknown signature: " + self.signature

            # default to GVariant
            self.cpptype_in  = 'const Glib::VariantBase &'
            self.cpptype_out  = 'Glib::VariantBase'

    def post_process(self, interface_prefix, cns, cns_upper, cns_lower):
        name = self.name
        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')
        # don't clash with the GType getter, e.g.: GType foo_bar_get_type (void); G_GNUC_CONST
        if self.name_lower == 'type':
            self.name_lower = 'type_'

        # recalculate arg
        self.arg.annotations = self.annotations
        self.arg.post_process(0)

class Interface:
    def __init__(self, name):
        self.name = name
        self.methods = []
        self.signals = []
        self.properties = []
        self.annotations = []

    def post_process(self, interface_prefix, c_namespace):
        if len(c_namespace) > 0:
            if utils.is_ugly_case(c_namespace):
                cns = c_namespace.replace('_', '')
                cns_upper = c_namespace.upper() + '_'
                cns_lower = c_namespace.lower() + '_'
            else:
                cns = c_namespace
                cns_upper = utils.camel_case_to_uscore(c_namespace).upper() + '_'
                cns_lower = utils.camel_case_to_uscore(c_namespace).lower() + '_'
        else:
            cns = ''
            cns_upper = ''
            cns_lower = ''

        name = self.name
        for prefix in interface_prefix:
            if name.startswith(prefix):
                name = name[len(prefix):]
        self.name_without_prefix = name
        name = utils.strip_dots(name)
        name_with_ns = utils.strip_dots(cns + '.' + name)
        self.camel_name = name_with_ns
        self.ns_upper = cns_upper
        self.name_lower = cns_lower + utils.camel_case_to_uscore(name)
        self.name_upper = utils.camel_case_to_uscore(name).upper()
        self.cpp_namespace_name = self.name_without_prefix.replace(".", "::")
        if cns != '':
            self.cpp_namespace_name = cns + "::" + self.cpp_namespace_name
        self.cpp_class_name = self.cpp_namespace_name.split("::")[-1]

        self.name_hyphen = self.name_upper.lower().replace('_', '-')

        for m in self.methods:
            m.post_process(interface_prefix, cns, cns_upper, cns_lower)

        for s in self.signals:
            s.post_process(interface_prefix, cns, cns_upper, cns_lower, self)

        for p in self.properties:
            p.post_process(interface_prefix, cns, cns_upper, cns_lower)
