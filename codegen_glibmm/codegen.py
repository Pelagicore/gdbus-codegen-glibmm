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

import sys

from textwrap import dedent

from . import config
from . import utils
from . import dbustypes

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
        dest.write (text)
        if newline:
            dest.write ("\n")

    def emit_h_p (self, text, newline = True):
        self.emit(self.proxy_h, text, newline)

    def emit_cpp_p (self, text, newline = True):
        self.emit(self.proxy_cpp, text, newline)

    def emit_h_s (self, text, newline = True):
        self.emit(self.stub_h, text, newline)

    def emit_cpp_s (self, text, newline = True):
        self.emit(self.stub_cpp, text, newline)

    def emit_h_common (self, text, newline = True):
        self.emit(self.common_h, text, newline)

    def emit_cpp_common (self, text, newline = True):
        self.emit(self.common_cpp, text, newline)

    def generate_intro_proxy(self):
        self.emit_cpp_p(dedent('''/*
                     * Generated by gdbus-codegen-glibmm %s. DO NOT EDIT.
                     *
                     * The license of this code is the same as for the source it was derived from.
                     */
                     ''') %(config.VERSION))

        self.emit_cpp_p('#include "%s"' %(self.proxy_h.name))

    def declare_types_proxy(self):
        self.emit_h_p("#include <string>")
        self.emit_h_p("#include <glibmm.h>")
        self.emit_h_p("#include <giomm.h>")
        self.emit_h_p("#include \""+self.common_h.name+"\"")
        self.emit_h_p("")

        for i in self.ifaces:
            for ns in i.cpp_namespace_name.split("::")[:-1]:
                self.emit_h_p ("namespace %s {" % ns)
            self.emit_h_p(dedent('''
            class {i.cpp_class_name} : public Glib::ObjectBase {{
            public:
                static void createForBus (Gio::DBus::BusType busType,
                                          Gio::DBus::ProxyFlags proxyFlags,
                                          const std::string &name,
                                          const std::string &objectPath,
                                          const Gio::SlotAsyncReady &slot);

                static Glib::RefPtr<{i.cpp_class_name}> createForBusFinish (Glib::RefPtr<Gio::AsyncResult> result);''').format(**locals()))

            for m in i.methods:
                # Async call method
                self.emit_h_p("    void %s (" % m.name)
                for a in m.in_args:
                    self.emit_h_p("      %s %s," % (a.cpptype_in, a.name))
                self.emit_h_p("      const Gio::SlotAsyncReady &slot);\n")
                self.emit_h_p("")

                # _finish method
                self.emit_h_p("    void %s_finish (" % m.name)
                for a in m.out_args:
                    self.emit_h_p("      %s& %s," % (a.cpptype_out, a.name))
                self.emit_h_p("      const Glib::RefPtr<Gio::AsyncResult>& res);")

            for p in i.properties:
                if p.readable:
                    self.emit_h_p("     {p.cpptype_out} {p.name}_get();".format(**locals()))
                if p.writable:
                    self.emit_h_p("     void {p.name}_set({p.cpptype_in}, const Gio::SlotAsyncReady &);".format(**locals()))
                    self.emit_h_p("     void {p.name}_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);".format(**locals()))


            for s in i.signals:
                if (len(s.args) > SIGNAL_MAX_PARAM):
                    print "WARNING: signal %s has too many parameters, skipping" % s.name
                    continue
                params = []
                for a in s.args:
                    params.append(a.cpptype_out)
                params = ", ".join(params)
                self.emit_h_p(dedent('''sigc::signal<void, {params} > {s.name}_signal;''').format(**locals()))

            self.emit_h_p("")

            # Constructor
            self.emit_h_p(dedent('''
                void reference() {{}}
                void unreference() {{}}
                void handle_signal (const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters);

                private:
                {i.cpp_class_name} (Glib::RefPtr<Gio::DBus::Proxy> proxy) : Glib::ObjectBase() {{
                    this->m_proxy = proxy;
                    this->m_proxy->signal_signal().connect(sigc::mem_fun(this, &{i.cpp_class_name}::handle_signal));
                }}
                Glib::RefPtr<Gio::DBus::Proxy> m_proxy;
            }};''').format(**locals()))
            for ns in reversed(i.cpp_namespace_name.split("::")[:-1]):
                self.emit_h_p("}// %s" % ns)

    def generate_method_calls_proxy(self, i):
        for m in i.methods:
            # async begin
            self.emit_cpp_p('void %s::%s (' % (i.cpp_namespace_name, m.camel_name))
            for a in m.in_args:
                self.emit_cpp_p('    %s arg_%s,'%(a.cpptype_in, a.name))
            self.emit_cpp_p( '    const Gio::SlotAsyncReady &callback)'
                         '{')

            self.emit_cpp_p("  Glib::VariantContainerBase base;");

            if (len(m.in_args) > 1):
                self.emit_cpp_p("std::vector<Glib::VariantBase> params;")
                for a in m.in_args:
                    self.emit_cpp_p("  " + a.cpptype_send(a.name + "_param", a.name)+ "")
                    self.emit_cpp_p("  params.push_back (%s_param);" % a.name)
            elif (len (m.in_args) == 1):
                for a in m.in_args:
                    self.emit_cpp_p("  " + a.cpptype_send("params", a.name)+ "")

            if (len(m.in_args) > 0):
                self.emit_cpp_p("  base = Glib::VariantContainerBase::create_tuple (params);")

            self.emit_cpp_p('  m_proxy->call (')
            self.emit_cpp_p('    "%s",'%(m.name))

            self.emit_cpp_p('    callback,')
            self.emit_cpp_p('    base);')
            self.emit_cpp_p('}'
                         '')

            # Finish
            self.emit_cpp_p('void %s::%s_finish (' %(i.cpp_namespace_name, m.camel_name))
            for a in m.out_args:
                self.emit_cpp_p('     %s& out_%s,'%(a.cpptype_out, a.name))
            self.emit_cpp_p(dedent('''
            const Glib::RefPtr<Gio::AsyncResult>& result)
            {{
              Glib::VariantContainerBase wrapped;
              wrapped = m_proxy->call_finish(result);
            ''').format(**locals()))

            for x in range (0, len(m.out_args)):
                a = m.out_args[x]
                self.emit_cpp_p("  " + a.cppvalue_get (a.name + "_variant", "out_" + a.name, str(x)))
                self.emit_cpp_p("")
            self.emit_cpp_p("}")
            self.emit_cpp_p("")

    def generate_property_handlers_proxy(self, i):
            for p in i.properties:
                if p.readable:
                    self.emit_cpp_p(dedent('''
                    {p.cpptype_out} {i.cpp_namespace_name}::{p.name}_get() {{
                        std::vector<Glib::ustring> props = m_proxy->get_cached_property_names();
                        Glib::Variant<{p.cpptype_get} > b;
                        if (std::find(props.begin(), props.end(), "{p.name}") != props.end()) {{
                            m_proxy->get_cached_property(b, "{p.name}");
                        }} else {{
                            g_print ("Todo: lookup value\\n");
                        }}
                        return {p.cpptype_get_cast}(b.get());
                    }}''').format(**locals()))
                if p.writable:
                    self.emit_cpp_p(dedent('''

                    void {i.cpp_namespace_name}::{p.name}_set({p.cpptype_in} value, const Gio::SlotAsyncReady &cb) {{
                        std::vector<Glib::VariantBase> paramsVec;
                        paramsVec.push_back (Glib::Variant<Glib::ustring>::create("{i.name}"));
                        paramsVec.push_back (Glib::Variant<Glib::ustring>::create("{p.name}"));
                        paramsVec.push_back (Glib::Variant<Glib::VariantBase>::create(Glib::Variant<{p.cpptype_get} >::create({p.cpptype_to_dbus}(value))));
                        Glib::VariantContainerBase params = Glib::VariantContainerBase::create_tuple(paramsVec);
                        m_proxy->call("org.freedesktop.DBus.Properties.Set",
                                        cb,
                                        params
                                        );
                    }}

                    void {i.cpp_namespace_name}::{p.name}_set_finish(const Glib::RefPtr<Gio::AsyncResult>& res) {{
                    }}
                    ''').format(**locals()))

    def generate_signal_handler_proxy(self, i):
        self.emit_cpp_p(dedent('''
            void {i.cpp_namespace_name}::handle_signal (const Glib::ustring& sender_name,
                                                        const Glib::ustring& signal_name,
                                                        const Glib::VariantContainerBase& parameters) {{
        ''').format(**locals()))

        for s in i.signals:
            if (len(s.args) > SIGNAL_MAX_PARAM):
                print "WARNING: signal %s has too many parameters, skipping" % s.name
                continue

            self.emit_cpp_p(dedent('''
                if (signal_name == "{s.name}") {{''').format(**locals()))

            paramsList = []

            for ai in range(len(s.args)):
                a = s.args[ai]
                self.emit_cpp_p("        if (parameters.get_n_children() != "+str(len(s.args))+") { return; }")
                self.emit_cpp_p("        Glib::Variant<%s > base_%s;" % (a.cpptype_get, a.name))
                self.emit_cpp_p("        parameters.get_child(base_%s, %d);" % (a.name, ai))
                self.emit_cpp_p("        %s p_%s;" % (a.cpptype_get, a.name))
                self.emit_cpp_p("        p_%s = base_%s.get();" % (a.name, a.name))
                paramsList.append("%s(p_%s)" % (a.cpptype_get_cast, a.name))

            paramsList = ', '.join(paramsList)
            self.emit_cpp_p('''        {s.name}_signal.emit({paramsList});'''.format(**locals()))
            self.emit_cpp_p("}")

        self.emit_cpp_p(dedent('''
            }}
        ''').format(**locals()))

    def generate_proxy_creation(self, i):
        self.emit_cpp_p(dedent('''
        void {i.cpp_namespace_name}::createForBus (
            Gio::DBus::BusType busType,
            Gio::DBus::ProxyFlags proxyFlags,
            const std::string &name,
            const std::string &objectPath,
            const Gio::SlotAsyncReady &slot) {{
          Gio::DBus::Proxy::create_for_bus (busType,
              name,
              objectPath,
              "{i.name}",
              slot,
              Glib::RefPtr<Gio::DBus::InterfaceInfo>(),
              proxyFlags);
        }}

        Glib::RefPtr<{i.cpp_namespace_name}> {i.cpp_namespace_name}::createForBusFinish (Glib::RefPtr<Gio::AsyncResult> result) {{
            Glib::RefPtr<Gio::DBus::Proxy> proxy = Gio::DBus::Proxy::create_for_bus_finish (result);
            {i.cpp_namespace_name} *p = new {i.cpp_namespace_name} (proxy);
            return Glib::RefPtr<{i.cpp_namespace_name}> (p);
        }}''').format(**locals()))

    def generate_stub_introspection(self):
        for i in range(0, len(self.node_xmls)):
            node_xml = self.node_xmls[i]

            self.emit_h_s ("const char interfaceXml%d[] = { " % i, False)
            for char in node_xml:
                self.emit_h_s ("0x%s, " % char.encode("hex"), False)
            self.emit_h_s("0x00") # Null terminator
            self.emit_h_s ("};")

    def generate_stub_intro(self):
        self.emit_cpp_s ('#include "%s"' % self.stub_h.name)

    def declare_types_stub(self):
        self.emit_h_s(dedent('''
        #include <string>
        #include <glibmm.h>
        #include <giomm.h>
        #include "{self.common_h.name}"
        ''').format(**locals()))

        for i in self.ifaces:
            for ns in i.cpp_namespace_name.split("::")[:-1]:
                self.emit_h_s ("namespace %s {" % ns)

            self.emit_h_s("class %s {" % i.cpp_class_name)

            self.emit_h_s("public:")
            self.emit_h_s("%s ();" %i.cpp_class_name)
            self.emit_h_s("void connect (Gio::DBus::BusType, std::string);")
            for  p in i.properties:
                self.emit_h_s("bool {p.name}_set({p.cpptype_in} value);".format(**locals()))

            self.emit_h_s("protected:")
            for m in i.methods:
                # Async call method
                self.emit_h_s("virtual void %s (" % m.name)

                for a in m.in_args:
                    self.emit_h_s("    %s %s," % (a.cpptype_in, a.name))

                self.emit_h_s("    const MessageHelper msg) = 0;")

            for p in i.properties:
                self.emit_h_s("virtual {p.cpptype_out} {p.name}_get() = 0;".format(**locals()))
                self.emit_h_s(dedent('''
                    /* Handle the setting of a property
                        * This method will be called as a result of a call to <PropName>_set
                        * and should implement the actual setting of the property value.
                        * Should return true on sucess and false otherwise.
                        */'''))
                self.emit_h_s("virtual bool {p.name}_setHandler({p.cpptype_in} value) = 0;".format(**locals()))

            for s in i.signals:
                if (len(s.args) > SIGNAL_MAX_PARAM):
                    print "WARNING: signal %s has too many parameters, skipping" % s.name
                    continue
                args = []

                for a in s.args:
                    args.append(a.cpptype_out)

                argsStr = ", ".join(args)
                self.emit_h_s(dedent('''
                void {s.name}_emitter({argsStr});
                sigc::signal<void, {argsStr} > {s.name}_signal;''').format(**locals()))

            self.emit_h_s(dedent("""
            void on_bus_acquired(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                 const Glib::ustring& /* name */);

            void on_name_acquired(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                                  const Glib::ustring& /* name */);

            void on_name_lost(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                              const Glib::ustring& /* name */);

            void on_method_call(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                               const Glib::ustring& /* sender */,
                               const Glib::ustring& /* object_path */,
                               const Glib::ustring& /* interface_name */,
                               const Glib::ustring& method_name,
                               const Glib::VariantContainerBase& parameters,
                               const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);

            void on_interface_get_property(Glib::VariantBase& property,
                                                   const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                                   const Glib::ustring& sender,
                                                   const Glib::ustring& object_path,
                                                   const Glib::ustring& interface_name,
                                                   const Glib::ustring& property_name);

            bool on_interface_set_property(
                   const Glib::RefPtr<Gio::DBus::Connection>& connection,
                   const Glib::ustring& sender,
                   const Glib::ustring& object_path,
                   const Glib::ustring& interface_name,
                   const Glib::ustring& property_name,
                   const Glib::VariantBase& value);

            private:
            bool emitSignal(const std::string& propName, Glib::VariantBase& value);

            guint connectionId, registeredId;
            Glib::RefPtr<Gio::DBus::NodeInfo> introspection_data;
            Glib::RefPtr<Gio::DBus::Connection> m_connection;
            std::string m_objectPath;
            std::string m_interfaceName;
            };"""))

            for ns in reversed(i.cpp_namespace_name.split("::")[:-1]):
                self.emit_h_s("}// %s" % ns)

            self.emit_h_s("")

    def define_types_stub_creation(self, i):
        object_path = "/" + i.name.replace(".", "/")

        # Constructor
        self.emit_cpp_s(dedent('''
        {i.cpp_namespace_name}::{i.cpp_class_name} () : connectionId(0), registeredId(0), m_objectPath("{object_path}"), m_interfaceName("{i.name}") {{
        ''').format(**locals()))
        for s in i.signals:
            if (len(s.args) > SIGNAL_MAX_PARAM):
                print "WARNING: signal %s has too many parameters, skipping" % s.name
                continue
            self.emit_cpp_s("    {s.name}_signal.connect(sigc::mem_fun(this, &{i.cpp_class_name}::{s.name}_emitter));".format(**locals()))
        self.emit_cpp_s(dedent('''
        }}
        void {i.cpp_namespace_name}::connect (
            Gio::DBus::BusType busType,
            std::string name)
        {{
            try {{
                    introspection_data = Gio::DBus::NodeInfo::create_for_xml(interfaceXml0);
            }} catch(const Glib::Error& ex) {{
                    g_warning("Unable to create introspection data: ");
                    g_warning(std::string(ex.what()).c_str());
                    g_warning("\\n");
            }}
            connectionId = Gio::DBus::own_name(Gio::DBus::BUS_TYPE_SESSION,
                                               name,
                                               sigc::mem_fun(this, &{i.cpp_class_name}::on_bus_acquired),
                                               sigc::mem_fun(this, &{i.cpp_class_name}::on_name_acquired),
                                               sigc::mem_fun(this, &{i.cpp_class_name}::on_name_lost));
        }}''').format(**locals()))


    def define_types_method_handlers_stub(self, i):
        self.emit_cpp_s(dedent('''
        void {i.cpp_namespace_name}::on_method_call(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                           const Glib::ustring& /* sender */,
                           const Glib::ustring& /* object_path */,
                           const Glib::ustring& /* interface_name */,
                           const Glib::ustring& method_name,
                           const Glib::VariantContainerBase& parameters,
                           const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {{
        ''').format(**locals()))
        for m in i.methods:
            self.emit_cpp_s("    if (method_name.compare(\"%s\") == 0) {" % m.name)
            for ai in range(len(m.in_args)):
                a = m.in_args[ai]
                self.emit_cpp_s("        Glib::Variant<%s > base_%s;" % (a.cpptype_get, a.name))
                self.emit_cpp_s("        parameters.get_child(base_%s, %d);" % (a.name, ai))
                self.emit_cpp_s("        %s p_%s;" % (a.cpptype_get, a.name))
                self.emit_cpp_s("        p_%s = base_%s.get();" % (a.name, a.name))
                self.emit_cpp_s("")
            self.emit_cpp_s("        %s(" % m.name)
            for a in m.in_args:
                self.emit_cpp_s("    %s(p_%s)," % (a.cpptype_get_cast, a.name))
            self.emit_cpp_s("            MessageHelper(invocation));")
            self.emit_cpp_s("    }")
        self.emit_cpp_s("    }")

    def define_types_property_get_handlers_stub(self, i):
        object_path = "/" + i.name.replace(".", "/")

        self.emit_cpp_s(dedent('''
        void {i.cpp_namespace_name}::on_interface_get_property(Glib::VariantBase& property,
                                               const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                               const Glib::ustring& sender,
                                               const Glib::ustring& object_path,
                                               const Glib::ustring& interface_name,
                                               const Glib::ustring& property_name) {{
        ''').format(**locals()))

        for p in i.properties:
            if p.readable:
                self.emit_cpp_s(dedent('''
                    if (property_name.compare("{p.name}") == 0) {{
                        property = Glib::Variant<{p.cpptype_get} >::create({p.cpptype_to_dbus}({p.name}_get()));
                    }}
                ''').format(**locals()))

        self.emit_cpp_s("}")

    def define_types_property_set_handlers_stub(self, i):
        object_path = "/" + i.name.replace(".", "/")
        self.emit_cpp_s(dedent('''
        bool {i.cpp_namespace_name}::on_interface_set_property(
               const Glib::RefPtr<Gio::DBus::Connection>& connection,
               const Glib::ustring& sender,
               const Glib::ustring& object_path,
               const Glib::ustring& interface_name,
               const Glib::ustring& property_name,
               const Glib::VariantBase& value) {{
        ''').format(**locals()))

        for p in i.properties:
            self.emit_cpp_s(dedent('''
                if (property_name.compare("{p.name}") == 0) {{
                    try {{
                        Glib::Variant<{p.cpptype_get} > castValue = Glib::VariantBase::cast_dynamic<Glib::Variant<{p.cpptype_get} > >(value);
                        {p.cpptype_out} val;
                        val = {p.cpptype_get_cast}(castValue.get());''').format(**locals()))
            self.emit_cpp_s('''        {p.name}_set(val);'''.format(**locals()))
            self.emit_cpp_s(dedent('''
                    }} catch (std::bad_cast e) {{
                        g_warning ("Bad cast when casting {p.name}");
                    }}
                }}
            ''').format(**locals()))

        self.emit_cpp_s(dedent('''
            return true;
        }}
        ''').format(**locals()))

    def define_types_signal_emitters_stub(self, i):
        object_path = "/" + i.name.replace(".", "/")

        for s in i.signals:
            if (len(s.args) > SIGNAL_MAX_PARAM):
                print "WARNING: signal %s has too many parameters, skipping" % s.name
                continue
            args = []

            for a in s.args:
                args.append(a.cpptype_out + " " + a.name)

            argsStr = ", ".join(args)
            self.emit_cpp_s(dedent('''void {i.cpp_namespace_name}::{s.name}_emitter({argsStr}) {{
            std::vector<Glib::VariantBase> paramsList;''').format(**locals()))

            for a in s.args:
                self.emit_cpp_s(dedent('''
                paramsList.push_back(Glib::Variant<{a.cpptype_get} >::create({a.cpptype_to_dbus}({a.name})));;
                ''').format(**locals()))

            self.emit_cpp_s(dedent('''      m_connection->emit_signal(
                    "{object_path}",
                    "{s.iface_name}",
                    "{s.name}",
                    Glib::ustring(),
                    Glib::Variant<std::vector<Glib::VariantBase> >::create_tuple(paramsList));
            }}''').format(**locals()))

    def define_types_dbus_callbacks_stub(self, i):
        object_path = "/" + i.name.replace(".", "/")
        self.emit_cpp_s(dedent('''
        void {i.cpp_namespace_name}::on_bus_acquired(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                 const Glib::ustring& /* name */) {{
            Gio::DBus::InterfaceVTable *interface_vtable =
                  new Gio::DBus::InterfaceVTable(
                        sigc::mem_fun(this, &{i.cpp_class_name}::on_method_call),
                        sigc::mem_fun(this, &{i.cpp_class_name}::on_interface_get_property),
                        sigc::mem_fun(this, &{i.cpp_class_name}::on_interface_set_property));
            try {{
                registeredId = connection->register_object(m_objectPath,
                introspection_data->lookup_interface("{i.name}"),
                *interface_vtable);
                m_connection = connection;
            }}
            catch(const Glib::Error& ex) {{
                g_warning("Registration of object failed");
            }}

            return;
        }}
        void {i.cpp_namespace_name}::on_name_acquired(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                              const Glib::ustring& /* name */) {{}}

        void {i.cpp_namespace_name}::on_name_lost(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                          const Glib::ustring& /* name */) {{}}
        ''').format(**locals()))

    def define_types_property_setters_stub(self, i):
        for p in i.properties:
            self.emit_cpp_s(dedent('''
            bool {i.cpp_namespace_name}::{p.name}_set({p.cpptype_in} value) {{
                if ({p.name}_setHandler(value)) {{
                    Glib::Variant<{p.cpptype_get} > value_get = Glib::Variant<{p.cpptype_get} >::create({p.cpptype_to_dbus}({p.name}_get()));
                    emitSignal("{p.name}", value_get);
                    return true;
                }}

                return false;
            }}''').format(**locals()))

    def define_types_emit_stub(self, i):
            self.emit_cpp_s(dedent('''
            bool {i.cpp_namespace_name}::emitSignal(const std::string& propName, Glib::VariantBase& value) {{
                std::map<Glib::ustring, Glib::VariantBase> changedProps;
                std::vector<Glib::ustring> changedPropsNoValue;

                changedProps[propName] = value;

                Glib::Variant<std::map<Glib::ustring,  Glib::VariantBase> > changedPropsVar = Glib::Variant<std::map <Glib::ustring, Glib::VariantBase> >::create (changedProps);
                Glib::Variant<std::vector<Glib::ustring> > changedPropsNoValueVar = Glib::Variant<std::vector<Glib::ustring> >::create(changedPropsNoValue);
                std::vector<Glib::VariantBase> ps;
                ps.push_back(Glib::Variant<Glib::ustring>::create(m_interfaceName));
                ps.push_back(changedPropsVar);
                ps.push_back(changedPropsNoValueVar);
                Glib::VariantContainerBase propertiesChangedVariant = Glib::Variant<std::vector<Glib::VariantBase> >::create_tuple(ps);

                m_connection->emit_signal(
                    m_objectPath,
                    "org.freedesktop.DBus.Properties",
                    "PropertiesChanged",
                    Glib::ustring(),
                    propertiesChangedVariant);

                return true;
            }}''').format(**locals()))

    def create_common(self):
        self.emit_h_common(dedent("""
        #include <iostream>
        #include "glibmm.h"
        #include "giomm.h"
        class Common {
            public:
                template<typename T>
                static void unwrapList(std::vector<T> &list, const Glib::VariantContainerBase &wrapped) {
                    for (uint i = 0; i < wrapped.get_n_children (); i++) {
                        Glib::Variant<T> item;
                        wrapped.get_child(item, i);
                        list.push_back(item.get());
                    }
                }

                static std::vector<Glib::ustring> stdStringVecToGlibStringVec(const std::vector<std::string> &strv) {
                    std::vector<Glib::ustring> newStrv;
                    for (uint i = 0; i < strv.size(); i++) {
                        newStrv.push_back(strv[i]);
                    }

                    return newStrv;
                }

                static std::vector<std::string> glibStringVecToStdStringVec(const std::vector<Glib::ustring> &strv) {
                    std::vector<std::string> newStrv;
                    for (uint i = 0; i < strv.size(); i++) {
                        newStrv.push_back(strv[i]);
                    }

                    return newStrv;
                }
        };
        class MessageHelper {
        public:
            MessageHelper (const Glib::RefPtr<Gio::DBus::MethodInvocation> msg) :
                m_message(msg) {}

            const Glib::RefPtr<Gio::DBus::MethodInvocation> getMessage() {
                return m_message;
            }
        """))

        args = {}
        for i in self.ifaces:
            for m in i.methods:
                argstring = ""
                argvals = []
                for a in m.out_args:
                    argstring += a.cpptype_out
                    argvals.append(a)
                args[argstring] = argvals

        for a in args:
            a = args[a]
            templateVars = []
            params = []
            for i in range(len(a)):
                templateVars.append("typename T%d" % i)
                params.append(a[i].cpptype_out + " p%s" % i)
            if (len(templateVars) > 0):
                self.emit_h_common("template <"+','.join(templateVars)+">")
            self.emit_h_common("void ret (" + ', '.join(params) +")")
            self.emit_h_common("{")
            self.emit_h_common("    std::vector<Glib::VariantBase> vlist;")

            for i in range(len(a)):
                self.emit_h_common("    vlist.push_back(Glib::Variant<"+a[i].cpptype_get+" >::create("+a[i].cpptype_to_dbus+"(p{i})));".format(**locals()))

            self.emit_h_common(dedent("""
                m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
            }
            """))

        self.emit_h_common(dedent("""
        private:
            Glib::RefPtr<Gio::DBus::MethodInvocation> m_message;
        };
        """))


    def generate(self):
        # Proxy
        self.generate_intro_proxy()
        self.declare_types_proxy()
        for i in self.ifaces:
            self.generate_method_calls_proxy(i)
            self.generate_property_handlers_proxy(i)
            self.generate_signal_handler_proxy(i)
            self.generate_proxy_creation(i)

        # Stub
        self.generate_stub_introspection()
        self.generate_stub_intro()
        self.declare_types_stub()
        for i in self.ifaces:
            self.define_types_stub_creation(i)
            self.define_types_method_handlers_stub(i)
            self.define_types_property_get_handlers_stub(i)
            self.define_types_property_set_handlers_stub(i)
            self.define_types_signal_emitters_stub(i)
            self.define_types_dbus_callbacks_stub(i)
            self.define_types_property_setters_stub(i)
            self.define_types_emit_stub(i)

        # Common
        self.create_common()
