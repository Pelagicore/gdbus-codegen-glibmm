static const char interfaceXml0[] = R"XML_DELIMITER(<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
                      "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
<node>
  <interface name="org.gdbus.codegen.glibmm.Test">
    <!--
      Permission to perform the action has been denied. But let's not
      despair and continue writing this error description to make it span
      across several lines.
    -->
    <annotation name="org.gdbus.glibmm.Error" value="org.gdbus.codegen.glibmm.Test.Error.PermissionDenied" />

    <!-- Invalid parameters -->
    <annotation name="org.gdbus.glibmm.Error" value="org.gdbus.codegen.glibmm.Test.Error.InvalidParams" />

    <annotation name="org.gdbus.glibmm.Error" value="org.gdbus.codegen.glibmm.Test.Error.OutOfMemory" />

    <method name="TestCall">
      <arg type="i" name="Param1" direction="in"></arg>
      <arg type="a{sv}" name="Param2" direction="in"></arg>
      <arg type="s" name="Param3" direction="out"></arg>
      <arg type="a{sv}" name="Param4" direction="out"></arg>
    </method>

    <signal name="TestSignalObjectPathArray">
        <arg type="ao" name="Param1"></arg>
    </signal>

    <property name="TestPropReadStringArray" type="as" access="read" />
  </interface>
</node>
)XML_DELIMITER";

#include "OUTPUT_DIR/input_stub.h"

template<class T>
inline T specialGetter(Glib::Variant<T> variant)
{
    return variant.get();
}

template<>
inline std::string specialGetter(Glib::Variant<std::string> variant)
{
    // String is not guaranteed to be null-terminated, so don't use ::get()
    gsize n_elem;
    gsize elem_size = sizeof(char);
    char* data = (char*)g_variant_get_fixed_array(variant.gobj(), &n_elem, elem_size);

    return std::string(data, n_elem);
}

org::gdbus::codegen::glibmm::TestStub::TestStub():
    m_interfaceName("org.gdbus.codegen.glibmm.Test")
{
    TestSignalObjectPathArray_signal.connect(sigc::mem_fun(this, &TestStub::TestSignalObjectPathArray_emitter));
}

org::gdbus::codegen::glibmm::TestStub::~TestStub()
{
    unregister_object();
}

guint org::gdbus::codegen::glibmm::TestStub::register_object(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &object_path)
{
    if (!introspection_data) {
        try {
            introspection_data = Gio::DBus::NodeInfo::create_for_xml(interfaceXml0);
        } catch(const Glib::Error& ex) {
            g_warning("Unable to create introspection data for %s: %s", object_path.c_str(), ex.what().c_str());
            return 0;
        }
    }

    Gio::DBus::InterfaceVTable *interface_vtable =
        new Gio::DBus::InterfaceVTable(
            sigc::mem_fun(this, &TestStub::on_method_call),
            sigc::mem_fun(this, &TestStub::on_interface_get_property),
            sigc::mem_fun(this, &TestStub::on_interface_set_property));

    guint registration_id;
    try {
        registration_id = connection->register_object(object_path,
            introspection_data->lookup_interface("org.gdbus.codegen.glibmm.Test"),
            *interface_vtable);
    } catch(const Glib::Error &ex) {
        g_warning("Registration of object %s failed: %s", object_path.c_str(), ex.what().c_str());
        return 0;
    }

    m_registered_objects.emplace_back(RegisteredObject {
        registration_id,
        connection,
        object_path
    });

    return registration_id;
}

void org::gdbus::codegen::glibmm::TestStub::unregister_object()
{
    for (const RegisteredObject &obj: m_registered_objects) {
        obj.connection->unregister_object(obj.id);
    }
    m_registered_objects.clear();
}

void org::gdbus::codegen::glibmm::TestStub::on_method_call(
    const Glib::RefPtr<Gio::DBus::Connection> &/* connection */,
    const Glib::ustring &/* sender */,
    const Glib::ustring &/* object_path */,
    const Glib::ustring &/* interface_name */,
    const Glib::ustring &method_name,
    const Glib::VariantContainerBase &parameters,
    const Glib::RefPtr<Gio::DBus::MethodInvocation> &invocation)
{
    static_cast<void>(method_name); // maybe unused
    static_cast<void>(parameters); // maybe unused
    static_cast<void>(invocation); // maybe unused

    if (method_name.compare("TestCall") == 0) {
        Glib::Variant<gint32> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint32 p_Param1 = specialGetter(base_Param1);

        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> base_Param2;
        parameters.get_child(base_Param2, 1);
        std::map<Glib::ustring,Glib::VariantBase> p_Param2 = specialGetter(base_Param2);

        MethodInvocation methodInvocation(invocation);
        TestCall(
            (p_Param1),
            (p_Param2),
            methodInvocation);
    }

}

void org::gdbus::codegen::glibmm::TestStub::on_interface_get_property(
    Glib::VariantBase &property,
    const Glib::RefPtr<Gio::DBus::Connection> &/* connection */,
    const Glib::ustring &/* sender */,
    const Glib::ustring &/* object_path */,
    const Glib::ustring &/* interface_name */,
    const Glib::ustring &property_name)
{
    static_cast<void>(property); // maybe unused
    static_cast<void>(property_name); // maybe unused

    if (property_name.compare("TestPropReadStringArray") == 0) {

        property = Glib::Variant<std::vector<Glib::ustring>>::create((TestPropReadStringArray_get()));
    }

}

bool org::gdbus::codegen::glibmm::TestStub::on_interface_set_property(
    const Glib::RefPtr<Gio::DBus::Connection> &/* connection */,
    const Glib::ustring &/* sender */,
    const Glib::ustring &/* object_path */,
    const Glib::ustring &/* interface_name */,
    const Glib::ustring &property_name,
    const Glib::VariantBase &value)
{
    static_cast<void>(property_name); // maybe unused
    static_cast<void>(value); // maybe unused

    return true;
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalObjectPathArray_emitter(std::vector<Glib::DBusObjectPathString> Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        obj.connection->emit_signal(
            obj.object_path,
            "org.gdbus.codegen.glibmm.Test",
            "TestSignalObjectPathArray",
            Glib::ustring(),
            params);
    }
}


bool org::gdbus::codegen::glibmm::TestStub::TestPropReadStringArray_set(const std::vector<Glib::ustring> & value)
{
    if (TestPropReadStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create((TestPropReadStringArray_get()));

        emitSignal("TestPropReadStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::emitSignal(
    const std::string &propName,
    Glib::VariantBase &value)
{
    std::map<Glib::ustring, Glib::VariantBase> changedProps;
    std::vector<Glib::ustring> changedPropsNoValue;

    changedProps[propName] = value;

    Glib::Variant<std::map<Glib::ustring, Glib::VariantBase>> changedPropsVar =
        Glib::Variant<std::map<Glib::ustring, Glib::VariantBase>>::create(changedProps);
    Glib::Variant<std::vector<Glib::ustring>> changedPropsNoValueVar =
        Glib::Variant<std::vector<Glib::ustring>>::create(changedPropsNoValue);
    std::vector<Glib::VariantBase> ps;
    ps.push_back(Glib::Variant<Glib::ustring>::create(m_interfaceName));
    ps.push_back(changedPropsVar);
    ps.push_back(changedPropsNoValueVar);
    Glib::VariantContainerBase propertiesChangedVariant =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(ps);

    for (const RegisteredObject &obj: m_registered_objects) {
        obj.connection->emit_signal(
            obj.object_path,
            "org.freedesktop.DBus.Properties",
            "PropertiesChanged",
            Glib::ustring(),
            propertiesChangedVariant);
    }

    return true;
}
