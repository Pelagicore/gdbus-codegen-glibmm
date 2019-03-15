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

class Annotation:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.annotations = []


class Comment:
    def __init__(self, lines):
        self.lines = lines


class Error:
    def __init__(self, value):
        parts = value.rsplit('.', 1)
        self.name = parts[-1]
        self.prefix = parts[0] if len(parts) > 1 else ''
        self.doc_string = ''

    def __lt__(self, other):
        return self.prefix < other.prefix or (
                self.prefix == other.prefix and self.name < other.name)


class Type:
    def __init__(self, signature, cpptype = ''):
        self.signature = signature
        self.cpptype = cpptype

        # Used when:
        # - passing value from client to proxy methods
        # - passing value from client to proxy property setters
        # - in stub property setters, called after getting the value from
        #   D-Bus and before invoking the property handler
        # - as input parameter for the stub property handlers
        #self.cpptype_in

        # Used when:
        # - the client receives return parameters from the _finish() method;
        #   an extra '&' is added to the type
        # - getting a value of a property from the proxy
        # - emitting sigc::signals in the proxy
        # - returning value from a property getter in the stub virtual method
        # - emitting signals in the stub
        # - passing values to the property setter in the stub
        # - returning values from the stub methods via the helper
        #self.cpptype_out

        # Used when:
        # - declaring Variant templates in:
        #   * the proxy property getter
        #   * proxy property setter
        #   * proxy signal receiving code
        #   * stub method handler receiving code
        #   * stub property handler sending code
        #   * stub property handler receiving code
        #   * stub signal emission
        #   * stub helper method to return values from method invocations
        self.variant_type = cpptype

        # Used when converting from variant_type:
        # - to return value in proxy property getters
        # - when emitting signals in the proxy class
        # - in the stub method handlers, to pass params to the virtual
        #   implementation
        # - in stub property setters, to pass params to the virtual
        #   implementation
        self.cpptype_get_cast = ''

        # Used to cast cpptype_in to variant_type when creating variants
        self.cpptype_to_dbus = ''

    def __getattr__(self, name):
        if name == 'cpptype_in':
            return 'const ' + self.cpptype + ' &'
        elif name == 'cpptype_out':
            return self.cpptype

    def cppvalue_send(self, name, param, cpp_class_name):
        """ Used to create a Variant to be sent over D-Bus """
        t = self.variant_type
        return ("Glib::Variant<"+self.variant_type+"> "+name+
            " =\n    Glib::Variant<"+self.variant_type+">::create("+param+");")

    def cppvalue_get(self, outvar, idx, cpp_class_name):
        """ Used to extract a cpptype_out out of a Variant """
        varname = outvar + '_v'
        return ("Glib::Variant<"+self.variant_type+"> "+varname+
            ";\nwrapped.get_child("+varname+", "+idx+");\n"+
            outvar+" = "+varname+".get();")


class BasicType(Type):
    def __init__(self, signature, cpptype):
        Type.__init__(self, signature[0], cpptype)
        self.cpptype_in = cpptype


class StringType(Type):
    def __init__(self, signature):
        if signature.startswith('ay'):
            signature = 'ay'
            cpptype = 'std::string'
        else:
            signature = signature[0]
            if signature == 's':
                cpptype = 'Glib::ustring'
            elif signature == 'g':
                cpptype = 'Glib::DBusSignatureString'
            elif signature == 'o':
                cpptype = 'Glib::DBusObjectPathString'
        Type.__init__(self, signature, cpptype)

    def cppvalue_send(self, name, param, cpp_class_name):
        if self.signature == 's' or self.signature == 'ay':
            return Type.cppvalue_send(self, name, param, cpp_class_name)
        elif self.signature == 'g':
            method = 'create_signature'
        elif self.signature == 'o':
            method = 'create_object_path'
        return ("Glib::VariantStringBase " + name + ";\n" +
            "Glib::VariantStringBase::" + method + "(" + name +
            ", " + param + ".c_str());")


class VariantType(Type):
    def __init__(self):
        Type.__init__(self, 'v', 'Glib::VariantBase')

    def cppvalue_get(self, outvar, idx, cpp_class_name):
        return 'GVariant *output;\n' +\
                                'g_variant_get_child(wrapped.gobj(), ' + idx + ', "v", &output);\n' + outvar + ' = Glib::VariantBase(output);'


class ArrayType(Type):
    def __init__(self, signature):
        assert signature[0] == 'a'
        self.element = get_type(signature[1:])
        Type.__init__(self, signature[0] + self.element.signature)
        self.variant_type = 'std::vector<' + self.element.variant_type + '>'
        self.cpptype = self.variant_type

class StructType(Type):
    def __init__(self, signature):
        assert signature[0] == '('
        self.elements = []
        remaining_signature = signature[1:]
        signature = '('
        while remaining_signature[0] != ')':
            e = get_type(remaining_signature)
            self.elements.append(e)
            signature += e.signature
            remaining_signature = remaining_signature[len(e.signature):]
        signature += ')'
        Type.__init__(self, signature)
        type_string = ','.join([t.variant_type for t in self.elements])
        self.variant_type = 'std::tuple<' + type_string + '>'
        self.cpptype = self.variant_type


class DictType(Type):
    def __init__(self, signature):
        assert signature.startswith('a{')
        remaining_signature = signature[2:]
        self.key = get_type(remaining_signature)
        assert (isinstance(self.key, BasicType) or isinstance(self.key, StringType))
        remaining_signature = remaining_signature[len(self.key.signature):]
        self.value = get_type(remaining_signature)
        assert self.value is not None
        remaining_signature = remaining_signature[len(self.value.signature):]
        assert remaining_signature[0] == '}'
        signature = 'a{' + self.key.signature + self.value.signature + '}'
        Type.__init__(self, signature)
        self.variant_type = 'std::map<%s,%s>' % (self.key.variant_type,
                self.value.variant_type)
        self.cpptype = self.variant_type


def get_type(signature):
    basic_types = {
        'b': 'bool',
        'y': 'guchar',
        'n': 'gint16',
        'q': 'guint16',
        'i': 'gint32',
        'u': 'guint32',
        'x': 'gint64',
        't': 'guint64',
        'd': 'double',
    }
    t = None
    if signature[0] in basic_types:
        t = BasicType(signature, basic_types[signature[0]])
    elif signature[0] in ('s', 'o', 'g'):
        t = StringType(signature)
    elif signature[0] == 'v':
        t = VariantType()
    elif signature[0] == '(':
        t = StructType(signature)
    elif signature[0] == 'a':
        if signature[1] == '{':
            t = DictType(signature)
        elif signature[1] == 'y':
            t = StringType(signature)
        else:
            t = ArrayType(signature)
    return t


class Arg:
    def __init__(self, name, signature):
        self.name = name
        self.type = get_type(signature)
        assert self.type is not None
        self.annotations = []

    def __getattr__(self, name):
        value = getattr(self.type, name)
        if name in ('cpptype_get_cast', 'cpptype_to_dbus'):
            if value.startswith('TypeWrap'):
                value = self.class_name + value
        return value

    def post_process(self, class_name, arg_number):
        self.class_name = class_name
        if self.name == None:
            self.name = 'unnamed_arg%d'%arg_number


class Method:
    def __init__(self, name):
        self.name = name
        self.in_args = []
        self.out_args = []
        self.annotations = []

    def post_process(self, class_name, cns, cns_upper, cns_lower):
        name = self.name
        self.camel_name = name

        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')

        arg_count = 0
        for a in self.in_args:
            a.post_process(class_name, arg_count)
            arg_count += 1

        for a in self.out_args:
            a.post_process(class_name, arg_count)
            arg_count += 1

class Signal:
    def __init__(self, name):
        self.name = name
        self.args = []
        self.annotations = []

    def post_process(self, class_name, cns, cns_upper, cns_lower, containing_iface):
        name = self.name
        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')
        self.iface_name = containing_iface.name

        arg_count = 0
        for a in self.args:
            a.post_process(class_name, arg_count)
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

    def __getattr__(self, name):
        return getattr(self.arg, name)

    def post_process(self, class_name, cns, cns_upper, cns_lower):
        name = self.name
        self.name_lower = utils.camel_case_to_uscore(name).lower().replace('-', '_')
        self.name_hyphen = self.name_lower.replace('_', '-')
        # don't clash with the GType getter, e.g.: GType foo_bar_get_type (void); G_GNUC_CONST
        if self.name_lower == 'type':
            self.name_lower = 'type_'

        # recalculate arg
        self.arg.annotations = self.annotations
        self.arg.post_process(class_name, 0)

class Interface:
    def __init__(self, name):
        self.name = name
        self.methods = []
        self.signals = []
        self.properties = []
        self.annotations = []
        self.errors = []

    def unique_return_types(self):
        # Helper to create a unique list of return types
        class CompWrap(object):
            def __init__(self, signature, args):
                self.signature, self.args = signature, args
            def __eq__(self, other):
                return self.signature == other.signature
            def __hash__(self):
                return hash(self.signature)

        args = {}
        for m in self.methods:
            method_signature = ''.join([arg.cpptype_out for arg in m.out_args])
            args[method_signature] = m.out_args

        return args.values()

    def post_process(self, interface_prefix, c_namespace, errors_namespace):
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
        namespace_and_class_name = self.name_without_prefix.replace(".", "::")
        (self.cpp_namespace_name, self.cpp_class_name) = namespace_and_class_name.rsplit('::', 1)
        if cns != '':
            self.cpp_namespace_name = cns + "::" + self.cpp_namespace_name

        self.cpp_class_name_proxy = self.cpp_class_name + 'Proxy'
        self.cpp_class_name_stub = self.cpp_class_name + 'Stub'

        self.name_hyphen = self.name_upper.lower().replace('_', '-')

        for m in self.methods:
            m.post_process(self.cpp_class_name, cns, cns_upper, cns_lower)

        for s in self.signals:
            s.post_process(self.cpp_class_name, cns, cns_upper, cns_lower, self)

        for p in self.properties:
            p.post_process(self.cpp_class_name, cns, cns_upper, cns_lower)

        self.errors_namespace = errors_namespace or self.cpp_namespace_name
