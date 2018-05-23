static const char interfaceXml0[] = R"XML_DELIMITER(<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
                      "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
<node>
  <interface name="org.gdbus.codegen.glibmm.Test">
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

org::gdbus::codegen::glibmm::Test::Test () : connectionId(0), registeredId(0), m_interfaceName("org.gdbus.codegen.glibmm.Test") {

    TestSignalObjectPathArray_signal.connect(sigc::mem_fun(this, &Test::TestSignalObjectPathArray_emitter));

}

org::gdbus::codegen::glibmm::Test::~Test()
{
}

guint org::gdbus::codegen::glibmm::Test::register_object(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &object_path)
{
    if (!m_objectPath.empty() && m_objectPath != object_path) {
        g_warning("Cannot register the same object twice!");

        return 0;
    }
    try {
            introspection_data = Gio::DBus::NodeInfo::create_for_xml(interfaceXml0);
    } catch(const Glib::Error& ex) {
            g_warning("Unable to create introspection data: ");
            g_warning("%s\n", ex.what().c_str());
    }
    Gio::DBus::InterfaceVTable *interface_vtable =
        new Gio::DBus::InterfaceVTable(
            sigc::mem_fun(this, &Test::on_method_call),
            sigc::mem_fun(this, &Test::on_interface_get_property),
            sigc::mem_fun(this, &Test::on_interface_set_property));
    guint id = 0;
    try {
        id = connection->register_object(object_path,
            introspection_data->lookup_interface("org.gdbus.codegen.glibmm.Test"),
            *interface_vtable);
        m_connection = connection;
        m_objectPath = object_path;
    }
    catch(const Glib::Error &ex) {
        g_warning("Registration of object failed");
    }
    return id;
}

void org::gdbus::codegen::glibmm::Test::connect (
    Gio::DBus::BusType busType,
    std::string name)
{
    connectionId = Gio::DBus::own_name(busType,
                                       name,
                                       sigc::mem_fun(this, &Test::on_bus_acquired),
                                       sigc::mem_fun(this, &Test::on_name_acquired),
                                       sigc::mem_fun(this, &Test::on_name_lost));
}

void org::gdbus::codegen::glibmm::Test::on_method_call(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                   const Glib::ustring& /* sender */,
                   const Glib::ustring& /* object_path */,
                   const Glib::ustring& /* interface_name */,
                   const Glib::ustring& method_name,
                   const Glib::VariantContainerBase& parameters,
                   const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation)
{

    if (method_name.compare("TestCall") == 0) {
        Glib::Variant<gint32 > base_Param1;
        parameters.get_child(base_Param1, 0);
        gint32 p_Param1;
        p_Param1 = base_Param1.get();

        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase> > base_Param2;
        parameters.get_child(base_Param2, 1);
        std::map<Glib::ustring,Glib::VariantBase> p_Param2;
        p_Param2 = base_Param2.get();

        TestCall(
            (p_Param1),
            (p_Param2),
            TestMessageHelper(invocation));
    }
    }

void org::gdbus::codegen::glibmm::Test::on_interface_get_property(Glib::VariantBase& property,
                                       const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                       const Glib::ustring& sender,
                                       const Glib::ustring& object_path,
                                       const Glib::ustring& interface_name,
                                       const Glib::ustring& property_name) {


if (property_name.compare("TestPropReadStringArray") == 0) {
    property = Glib::Variant<std::vector<Glib::ustring> >::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadStringArray_get()));
}

}

bool org::gdbus::codegen::glibmm::Test::on_interface_set_property(
       const Glib::RefPtr<Gio::DBus::Connection>& connection,
       const Glib::ustring& sender,
       const Glib::ustring& object_path,
       const Glib::ustring& interface_name,
       const Glib::ustring& property_name,
       const Glib::VariantBase& value) {


if (property_name.compare("TestPropReadStringArray") == 0) {
    try {
        Glib::Variant<std::vector<Glib::ustring> > castValue = Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring> > >(value);
        std::vector<std::string> val;

val = TestTypeWrap::glibStringVecToStdStringVec(castValue.get());
        TestPropReadStringArray_set(val);

    } catch (std::bad_cast e) {
        g_warning ("Bad cast when casting TestPropReadStringArray");
    }
}


    return true;
}

void org::gdbus::codegen::glibmm::Test::TestSignalObjectPathArray_emitter(std::vector<std::string> Param1) {
            std::vector<Glib::VariantBase> paramsList;

paramsList.push_back(Glib::Variant<std::vector<std::string> >::create((Param1)));;

m_connection->emit_signal(
              "/org/gdbus/codegen/glibmm/Test",
              "org.gdbus.codegen.glibmm.Test",
              "TestSignalObjectPathArray",
              Glib::ustring(),
              Glib::Variant<std::vector<Glib::VariantBase> >::create_tuple(paramsList));
      }

void org::gdbus::codegen::glibmm::Test::on_bus_acquired(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                         const Glib::ustring& /* name */) {
    registeredId = register_object(connection,
                                   "/org/gdbus/codegen/glibmm/Test");
    m_connection = connection;

    return;
}
void org::gdbus::codegen::glibmm::Test::on_name_acquired(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                      const Glib::ustring& /* name */) {}

void org::gdbus::codegen::glibmm::Test::on_name_lost(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                  const Glib::ustring& /* name */) {}


bool org::gdbus::codegen::glibmm::Test::TestPropReadStringArray_set(std::vector<std::string> value) {
    if (TestPropReadStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring> > value_get = Glib::Variant<std::vector<Glib::ustring> >::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadStringArray_get()));
        emitSignal("TestPropReadStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::emitSignal(const std::string& propName, Glib::VariantBase& value) {
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
}
