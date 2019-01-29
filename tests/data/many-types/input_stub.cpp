static const char interfaceXml0[] = R"XML_DELIMITER(<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
                      "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
<node>
  <interface name="org.gdbus.codegen.glibmm.Test">
    <method name="TestStringVariantDict">
      <arg type="a{sv}" name="Param1" direction="in"></arg>
      <arg type="a{sv}" name="Param2" direction="out"></arg>
    </method>

    <method name="TestStringStringDict">
      <arg type="a{ss}" name="Param1" direction="in"></arg>
      <arg type="a{ss}" name="Param2" direction="out"></arg>
    </method>

    <method name="TestUintIntDict">
      <arg type="a{ui}" name="Param1" direction="in"></arg>
      <arg type="a{ui}" name="Param2" direction="out"></arg>
    </method>

    <method name="TestVariant">
       <arg type="v" name="Param1" direction="in"></arg>
       <arg type="v" name="Param2" direction="out"></arg>
    </method>

    <method name="TestByteStringArray">
        <arg type="aay" name="Param1" direction="in"></arg>
        <arg type="aay" name="Param2" direction="out"></arg>
    </method>

    <method name="TestObjectPathArray">
        <arg type="ao" name="Param1" direction="in"></arg>
        <arg type="ao" name="Param2" direction="out"></arg>
    </method>

    <method name="TestStringArray">
        <arg type="as" name="Param1" direction="in"></arg>
        <arg type="as" name="Param2" direction="out"></arg>
    </method>

    <method name="TestByteString">
        <arg type="ay" name="Param1" direction="in"></arg>
        <arg type="ay" name="Param2" direction="out"></arg>
    </method>

    <method name="TestStruct">
      <arg type="(ss)" name="Param1" direction="in"></arg>
      <arg type="(ss)" name="Param2" direction="out"></arg>
    </method>

    <method name="TestStructArray">
      <arg type="a(usi)" name="Param1" direction="in"></arg>
      <arg type="a(usi)" name="Param2" direction="out"></arg>
    </method>

    <method name="TestDictStructArray">
      <arg type="a(sa{sv})" name="Param1" direction="in"></arg>
      <arg type="a(sa{sv})" name="Param2" direction="out"></arg>
    </method>

    <method name="TestSignature">
        <arg type="g" name="Param1" direction="in"></arg>
        <arg type="g" name="Param2" direction="out"></arg>
    </method>

    <method name="TestObjectPath">
        <arg type="o" name="Param1" direction="in"></arg>
        <arg type="o" name="Param2" direction="out"></arg>
    </method>

    <method name="TestString">
        <arg type="s" name="Param1" direction="in"></arg>
        <arg type="s" name="Param2" direction="out"></arg>
    </method>

    <method name="TestDouble">
        <arg type="d" name="Param1" direction="in"></arg>
        <arg type="d" name="Param2" direction="out"></arg>
    </method>

    <method name="TestUInt64">
        <arg type="t" name="Param1" direction="in"></arg>
        <arg type="t" name="Param2" direction="out"></arg>
    </method>

    <method name="TestInt64">
        <arg type="x" name="Param1" direction="in"></arg>
        <arg type="x" name="Param2" direction="out"></arg>
    </method>

    <method name="TestUInt">
        <arg type="u" name="Param1" direction="in"></arg>
        <arg type="u" name="Param2" direction="out"></arg>
    </method>

    <method name="TestInt">
        <arg type="i" name="Param1" direction="in"></arg>
        <arg type="i" name="Param2" direction="out"></arg>
    </method>

    <method name="TestUInt16">
        <arg type="q" name="Param1" direction="in"></arg>
        <arg type="q" name="Param2" direction="out"></arg>
    </method>

    <method name="TestInt16">
        <arg type="n" name="Param1" direction="in"></arg>
        <arg type="n" name="Param2" direction="out"></arg>
    </method>

    <method name="TestChar">
        <arg type="y" name="Param1" direction="in"></arg>
        <arg type="y" name="Param2" direction="out"></arg>
    </method>

    <method name="TestBoolean">
        <arg type="b" name="Param1" direction="in"></arg>
        <arg type="b" name="Param2" direction="out"></arg>
    </method>

    <method name="TestAll">
        <arg type="aay" name="in_Param1"  direction="in"></arg>
        <arg type="ao"  name="in_Param2"  direction="in"></arg>
        <arg type="as"  name="in_Param3"  direction="in"></arg>
        <arg type="ay"  name="in_Param4"  direction="in"></arg>
        <arg type="g"   name="in_Param5"  direction="in"></arg>
        <arg type="o"   name="in_Param6"  direction="in"></arg>
        <arg type="s"   name="in_Param7"  direction="in"></arg>
        <arg type="d"   name="in_Param8"  direction="in"></arg>
        <arg type="t"   name="in_Param9"  direction="in"></arg>
        <arg type="x"   name="in_Param10" direction="in"></arg>
        <arg type="u"   name="in_Param11" direction="in"></arg>
        <arg type="i"   name="in_Param12" direction="in"></arg>
        <arg type="q"   name="in_Param13" direction="in"></arg>
        <arg type="n"   name="in_Param14" direction="in"></arg>
        <arg type="y"   name="in_Param15" direction="in"></arg>
        <arg type="b"   name="in_Param16" direction="in"></arg>

        <arg type="aay" name="out_Param1"  direction="out"></arg>
        <arg type="ao"  name="out_Param2"  direction="out"></arg>
        <arg type="as"  name="out_Param3"  direction="out"></arg>
        <arg type="ay"  name="out_Param4"  direction="out"></arg>
        <arg type="g"   name="out_Param5"  direction="out"></arg>
        <arg type="o"   name="out_Param6"  direction="out"></arg>
        <arg type="s"   name="out_Param7"  direction="out"></arg>
        <arg type="d"   name="out_Param8"  direction="out"></arg>
        <arg type="t"   name="out_Param9"  direction="out"></arg>
        <arg type="x"   name="out_Param10" direction="out"></arg>
        <arg type="u"   name="out_Param11" direction="out"></arg>
        <arg type="i"   name="out_Param12" direction="out"></arg>
        <arg type="q"   name="out_Param13" direction="out"></arg>
        <arg type="n"   name="out_Param14" direction="out"></arg>
        <arg type="y"   name="out_Param15" direction="out"></arg>
        <arg type="b"   name="out_Param16" direction="out"></arg>
    </method>

    <method name="TestTriggerInternalPropertyChange">
        <arg type="i" name="NewPropertyValue"></arg>
    </method>

    <!-- Signals -->

    <signal name="TestSignalByteStringArray">
        <arg type="aay" name="Param1"></arg>
    </signal>

    <signal name="TestSignalObjectPathArray">
        <arg type="ao" name="Param1"></arg>
    </signal>

    <signal name="TestSignalStringArray">
        <arg type="as" name="Param1"></arg>
    </signal>

    <signal name="TestSignalByteString">
        <arg type="ay" name="Param1"></arg>
    </signal>

    <signal name="TestSignalSignature">
        <arg type="g" name="Param1"></arg>
    </signal>

    <signal name="TestSignalObjectPath">
        <arg type="o" name="Param1"></arg>
    </signal>

    <signal name="TestSignalString">
        <arg type="s" name="Param1"></arg>
    </signal>

    <signal name="TestSignalDouble">
        <arg type="d" name="Param1"></arg>
    </signal>

    <signal name="TestSignalUInt64">
        <arg type="t" name="Param1"></arg>
    </signal>

    <signal name="TestSignalInt64">
        <arg type="x" name="Param1"></arg>
    </signal>

    <signal name="TestSignalUInt">
        <arg type="u" name="Param1"></arg>
    </signal>

    <signal name="TestSignalInt">
        <arg type="i" name="Param1"></arg>
    </signal>

    <signal name="TestSignalUInt16">
        <arg type="q" name="Param1"></arg>
    </signal>

    <signal name="TestSignalInt16">
        <arg type="n" name="Param1"></arg>
    </signal>

    <signal name="TestSignalChar">
        <arg type="y" name="Param1"></arg>
    </signal>

    <signal name="TestSignalBoolean">
        <arg type="b" name="Param1"></arg>
    </signal>

    <signal name="TestSignalAll">
        <arg type="aay" name="in_Param1"></arg>
        <arg type="ao"  name="in_Param2"></arg>
        <arg type="as"  name="in_Param3"></arg>
        <arg type="ay"  name="in_Param4"></arg>
        <arg type="g"   name="in_Param5"></arg>
        <arg type="o"   name="in_Param6"></arg>
        <arg type="s"   name="in_Param7"></arg>
        <arg type="d"   name="in_Param8"></arg>
        <arg type="t"   name="in_Param9"></arg>
        <arg type="x"   name="in_Param10"></arg>
        <arg type="u"   name="in_Param11"></arg>
        <arg type="i"   name="in_Param12"></arg>
        <arg type="q"   name="in_Param13"></arg>
        <arg type="n"   name="in_Param14"></arg>
        <arg type="y"   name="in_Param15"></arg>
        <arg type="b"   name="in_Param16"></arg>

        <arg type="aay" name="out_Param1"></arg>
        <arg type="ao"  name="out_Param2"></arg>
        <arg type="as"  name="out_Param3"></arg>
        <arg type="ay"  name="out_Param4"></arg>
        <arg type="g"   name="out_Param5"></arg>
        <arg type="o"   name="out_Param6"></arg>
        <arg type="s"   name="out_Param7"></arg>
        <arg type="d"   name="out_Param8"></arg>
        <arg type="t"   name="out_Param9"></arg>
        <arg type="x"   name="out_Param10"></arg>
        <arg type="u"   name="out_Param11"></arg>
        <arg type="i"   name="out_Param12"></arg>
        <arg type="q"   name="out_Param13"></arg>
        <arg type="n"   name="out_Param14"></arg>
        <arg type="y"   name="out_Param15"></arg>
        <arg type="b"   name="out_Param16"></arg>
    </signal>

    <!-- Properties -->

    <property name="TestPropReadByteStringArray"        type="aay" access="read" />
    <property name="TestPropReadObjectPathArray"        type="ao"  access="read" />
    <property name="TestPropReadStringArray"            type="as"  access="read" />
    <property name="TestPropReadByteString"             type="ay"  access="read" />
    <property name="TestPropReadSignature"              type="g"   access="read" />
    <property name="TestPropReadObjectPath"             type="o"   access="read" />
    <property name="TestPropReadString"                 type="s"   access="read" />
    <property name="TestPropReadDouble"                 type="d"   access="read" />
    <property name="TestPropReadUInt64"                 type="t"   access="read" />
    <property name="TestPropReadInt64"                  type="x"   access="read" />
    <property name="TestPropReadUInt"                   type="u"   access="read" />
    <property name="TestPropReadInt"                    type="i"   access="read" />
    <property name="TestPropReadUInt16"                 type="q"   access="read" />
    <property name="TestPropReadInt16"                  type="n"   access="read" />
    <property name="TestPropReadChar"                   type="y"   access="read" />
    <property name="TestPropReadBoolean"                type="b"   access="read" />
    <property name="TestPropInternalReadPropertyChange" type="i"   access="read" />

    <property name="TestPropWriteByteStringArray" type="aay" access="write" />
    <property name="TestPropWriteObjectPathArray" type="ao"  access="write" />
    <property name="TestPropWriteStringArray"     type="as"  access="write" />
    <property name="TestPropWriteByteString"      type="ay"  access="write" />
    <property name="TestPropWriteSignature"       type="g"   access="write" />
    <property name="TestPropWriteObjectPath"      type="o"   access="write" />
    <property name="TestPropWriteString"          type="s"   access="write" />
    <property name="TestPropWriteDouble"          type="d"   access="write" />
    <property name="TestPropWriteUInt64"          type="t"   access="write" />
    <property name="TestPropWriteInt64"           type="x"   access="write" />
    <property name="TestPropWriteUInt"            type="u"   access="write" />
    <property name="TestPropWriteInt"             type="i"   access="write" />
    <property name="TestPropWriteUInt16"          type="q"   access="write" />
    <property name="TestPropWriteInt16"           type="n"   access="write" />
    <property name="TestPropWriteChar"            type="y"   access="write" />
    <property name="TestPropWriteBoolean"         type="b"   access="write" />

    <property name="TestPropReadWriteByteStringArray"           type="aay" access="readwrite" />
    <property name="TestPropReadWriteObjectPathArray"           type="ao"  access="readwrite" />
    <property name="TestPropReadWriteStringArray"               type="as"  access="readwrite" />
    <property name="TestPropReadWriteByteString"                type="ay"  access="readwrite" />
    <property name="TestPropReadWriteSignature"                 type="g"   access="readwrite" />
    <property name="TestPropReadWriteObjectPath"                type="o"   access="readwrite" />
    <property name="TestPropReadWriteString"                    type="s"   access="readwrite" />
    <property name="TestPropReadWriteDouble"                    type="d"   access="readwrite" />
    <property name="TestPropReadWriteUInt64"                    type="t"   access="readwrite" />
    <property name="TestPropReadWriteInt64"                     type="x"   access="readwrite" />
    <property name="TestPropReadWriteUInt"                      type="u"   access="readwrite" />
    <property name="TestPropReadWriteInt"                       type="i"   access="readwrite" />
    <property name="TestPropReadWriteUInt16"                    type="q"   access="readwrite" />
    <property name="TestPropReadWriteInt16"                     type="n"   access="readwrite" />
    <property name="TestPropReadWriteChar"                      type="y"   access="readwrite" />
    <property name="TestPropReadWriteBoolean"                   type="b"   access="readwrite" />
    <property name="TestPropInternalReadWritePropertyChange"    type="i"   access="readwrite" />

  </interface>
</node>
)XML_DELIMITER";

#include "OUTPUT_DIR/input_stub.h"

org::gdbus::codegen::glibmm::Test::Test():
    connectionId(0),
    registeredId(0),
    m_interfaceName("org.gdbus.codegen.glibmm.Test")
{
    TestSignalByteStringArray_signal.connect(sigc::mem_fun(this, &Test::TestSignalByteStringArray_emitter));
    TestSignalObjectPathArray_signal.connect(sigc::mem_fun(this, &Test::TestSignalObjectPathArray_emitter));
    TestSignalStringArray_signal.connect(sigc::mem_fun(this, &Test::TestSignalStringArray_emitter));
    TestSignalByteString_signal.connect(sigc::mem_fun(this, &Test::TestSignalByteString_emitter));
    TestSignalSignature_signal.connect(sigc::mem_fun(this, &Test::TestSignalSignature_emitter));
    TestSignalObjectPath_signal.connect(sigc::mem_fun(this, &Test::TestSignalObjectPath_emitter));
    TestSignalString_signal.connect(sigc::mem_fun(this, &Test::TestSignalString_emitter));
    TestSignalDouble_signal.connect(sigc::mem_fun(this, &Test::TestSignalDouble_emitter));
    TestSignalUInt64_signal.connect(sigc::mem_fun(this, &Test::TestSignalUInt64_emitter));
    TestSignalInt64_signal.connect(sigc::mem_fun(this, &Test::TestSignalInt64_emitter));
    TestSignalUInt_signal.connect(sigc::mem_fun(this, &Test::TestSignalUInt_emitter));
    TestSignalInt_signal.connect(sigc::mem_fun(this, &Test::TestSignalInt_emitter));
    TestSignalUInt16_signal.connect(sigc::mem_fun(this, &Test::TestSignalUInt16_emitter));
    TestSignalInt16_signal.connect(sigc::mem_fun(this, &Test::TestSignalInt16_emitter));
    TestSignalChar_signal.connect(sigc::mem_fun(this, &Test::TestSignalChar_emitter));
    TestSignalBoolean_signal.connect(sigc::mem_fun(this, &Test::TestSignalBoolean_emitter));
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
    } catch(const Glib::Error &ex) {
        g_warning("Registration of object failed");
    }
    return id;
}

void org::gdbus::codegen::glibmm::Test::connect(
    Gio::DBus::BusType busType,
    std::string name)
{
    connectionId = Gio::DBus::own_name(
        busType, name,
        sigc::mem_fun(this, &Test::on_bus_acquired),
        sigc::mem_fun(this, &Test::on_name_acquired),
        sigc::mem_fun(this, &Test::on_name_lost));
}

void org::gdbus::codegen::glibmm::Test::on_method_call(
    const Glib::RefPtr<Gio::DBus::Connection> &/* connection */,
    const Glib::ustring &/* sender */,
    const Glib::ustring &/* object_path */,
    const Glib::ustring &/* interface_name */,
    const Glib::ustring &method_name,
    const Glib::VariantContainerBase &parameters,
    const Glib::RefPtr<Gio::DBus::MethodInvocation> &invocation)
{
    if (method_name.compare("TestStringVariantDict") == 0) {
        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<Glib::ustring,Glib::VariantBase> p_Param1 = base_Param1.get();

        TestStringVariantDict(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestStringStringDict") == 0) {
        Glib::Variant<std::map<Glib::ustring,Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<Glib::ustring,Glib::ustring> p_Param1 = base_Param1.get();

        TestStringStringDict(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestUintIntDict") == 0) {
        Glib::Variant<std::map<guint32,gint32>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<guint32,gint32> p_Param1 = base_Param1.get();

        TestUintIntDict(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestVariant") == 0) {
        Glib::VariantContainerBase containerBase = parameters;
        GVariant *output0;
        g_variant_get_child(containerBase.gobj(), 0, "v", &output0);
        Glib::VariantBase p_Param1 =
            Glib::VariantBase(output0);

        TestVariant(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestByteStringArray") == 0) {
        Glib::Variant<std::vector<std::string>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::string> p_Param1 = base_Param1.get();

        TestByteStringArray(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestObjectPathArray") == 0) {
        Glib::Variant<std::vector<std::string>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::string> p_Param1 = base_Param1.get();

        TestObjectPathArray(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestStringArray") == 0) {
        Glib::Variant<std::vector<Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<Glib::ustring> p_Param1 = base_Param1.get();

        TestStringArray(
            TestTypeWrap::glibStringVecToStdStringVec(p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestByteString") == 0) {
        Glib::Variant<std::string> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::string p_Param1 = base_Param1.get();

        TestByteString(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestStruct") == 0) {
        Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::tuple<Glib::ustring,Glib::ustring> p_Param1 = base_Param1.get();

        TestStruct(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestStructArray") == 0) {
        Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::tuple<guint32,Glib::ustring,gint32>> p_Param1 = base_Param1.get();

        TestStructArray(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestDictStructArray") == 0) {
        Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> p_Param1 = base_Param1.get();

        TestDictStructArray(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestSignature") == 0) {
        Glib::Variant<Glib::ustring> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::ustring p_Param1 = base_Param1.get();

        TestSignature(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestObjectPath") == 0) {
        Glib::Variant<Glib::ustring> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::ustring p_Param1 = base_Param1.get();

        TestObjectPath(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestString") == 0) {
        Glib::Variant<Glib::ustring> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::ustring p_Param1 = base_Param1.get();

        TestString(
            Glib::ustring(p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestDouble") == 0) {
        Glib::Variant<double> base_Param1;
        parameters.get_child(base_Param1, 0);
        double p_Param1 = base_Param1.get();

        TestDouble(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestUInt64") == 0) {
        Glib::Variant<guint64> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint64 p_Param1 = base_Param1.get();

        TestUInt64(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestInt64") == 0) {
        Glib::Variant<gint64> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint64 p_Param1 = base_Param1.get();

        TestInt64(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestUInt") == 0) {
        Glib::Variant<guint32> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint32 p_Param1 = base_Param1.get();

        TestUInt(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestInt") == 0) {
        Glib::Variant<gint32> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint32 p_Param1 = base_Param1.get();

        TestInt(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestUInt16") == 0) {
        Glib::Variant<guint16> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint16 p_Param1 = base_Param1.get();

        TestUInt16(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestInt16") == 0) {
        Glib::Variant<gint16> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint16 p_Param1 = base_Param1.get();

        TestInt16(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestChar") == 0) {
        Glib::Variant<guchar> base_Param1;
        parameters.get_child(base_Param1, 0);
        guchar p_Param1 = base_Param1.get();

        TestChar(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestBoolean") == 0) {
        Glib::Variant<bool> base_Param1;
        parameters.get_child(base_Param1, 0);
        bool p_Param1 = base_Param1.get();

        TestBoolean(
            (p_Param1),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestAll") == 0) {
        Glib::Variant<std::vector<std::string>> base_in_Param1;
        parameters.get_child(base_in_Param1, 0);
        std::vector<std::string> p_in_Param1 = base_in_Param1.get();

        Glib::Variant<std::vector<std::string>> base_in_Param2;
        parameters.get_child(base_in_Param2, 1);
        std::vector<std::string> p_in_Param2 = base_in_Param2.get();

        Glib::Variant<std::vector<Glib::ustring>> base_in_Param3;
        parameters.get_child(base_in_Param3, 2);
        std::vector<Glib::ustring> p_in_Param3 = base_in_Param3.get();

        Glib::Variant<std::string> base_in_Param4;
        parameters.get_child(base_in_Param4, 3);
        std::string p_in_Param4 = base_in_Param4.get();

        Glib::Variant<Glib::ustring> base_in_Param5;
        parameters.get_child(base_in_Param5, 4);
        Glib::ustring p_in_Param5 = base_in_Param5.get();

        Glib::Variant<Glib::ustring> base_in_Param6;
        parameters.get_child(base_in_Param6, 5);
        Glib::ustring p_in_Param6 = base_in_Param6.get();

        Glib::Variant<Glib::ustring> base_in_Param7;
        parameters.get_child(base_in_Param7, 6);
        Glib::ustring p_in_Param7 = base_in_Param7.get();

        Glib::Variant<double> base_in_Param8;
        parameters.get_child(base_in_Param8, 7);
        double p_in_Param8 = base_in_Param8.get();

        Glib::Variant<guint64> base_in_Param9;
        parameters.get_child(base_in_Param9, 8);
        guint64 p_in_Param9 = base_in_Param9.get();

        Glib::Variant<gint64> base_in_Param10;
        parameters.get_child(base_in_Param10, 9);
        gint64 p_in_Param10 = base_in_Param10.get();

        Glib::Variant<guint32> base_in_Param11;
        parameters.get_child(base_in_Param11, 10);
        guint32 p_in_Param11 = base_in_Param11.get();

        Glib::Variant<gint32> base_in_Param12;
        parameters.get_child(base_in_Param12, 11);
        gint32 p_in_Param12 = base_in_Param12.get();

        Glib::Variant<guint16> base_in_Param13;
        parameters.get_child(base_in_Param13, 12);
        guint16 p_in_Param13 = base_in_Param13.get();

        Glib::Variant<gint16> base_in_Param14;
        parameters.get_child(base_in_Param14, 13);
        gint16 p_in_Param14 = base_in_Param14.get();

        Glib::Variant<guchar> base_in_Param15;
        parameters.get_child(base_in_Param15, 14);
        guchar p_in_Param15 = base_in_Param15.get();

        Glib::Variant<bool> base_in_Param16;
        parameters.get_child(base_in_Param16, 15);
        bool p_in_Param16 = base_in_Param16.get();

        TestAll(
            (p_in_Param1),
            (p_in_Param2),
            TestTypeWrap::glibStringVecToStdStringVec(p_in_Param3),
            (p_in_Param4),
            (p_in_Param5),
            (p_in_Param6),
            Glib::ustring(p_in_Param7),
            (p_in_Param8),
            (p_in_Param9),
            (p_in_Param10),
            (p_in_Param11),
            (p_in_Param12),
            (p_in_Param13),
            (p_in_Param14),
            (p_in_Param15),
            (p_in_Param16),
            TestMessageHelper(invocation));
    }

    if (method_name.compare("TestTriggerInternalPropertyChange") == 0) {
        Glib::Variant<gint32> base_NewPropertyValue;
        parameters.get_child(base_NewPropertyValue, 0);
        gint32 p_NewPropertyValue = base_NewPropertyValue.get();

        TestTriggerInternalPropertyChange(
            (p_NewPropertyValue),
            TestMessageHelper(invocation));
    }

}

void org::gdbus::codegen::glibmm::Test::on_interface_get_property(
    Glib::VariantBase &property,
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &sender,
    const Glib::ustring &object_path,
    const Glib::ustring &interface_name,
    const Glib::ustring &property_name)
{
    if (property_name.compare("TestPropReadByteStringArray") == 0) {
        property = Glib::Variant<std::vector<std::string>>::create((TestPropReadByteStringArray_get()));
    }

    if (property_name.compare("TestPropReadObjectPathArray") == 0) {
        property = Glib::Variant<std::vector<std::string>>::create((TestPropReadObjectPathArray_get()));
    }

    if (property_name.compare("TestPropReadStringArray") == 0) {
        property = Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadStringArray_get()));
    }

    if (property_name.compare("TestPropReadByteString") == 0) {
        property = Glib::Variant<std::string>::create((TestPropReadByteString_get()));
    }

    if (property_name.compare("TestPropReadSignature") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadSignature_get()));
    }

    if (property_name.compare("TestPropReadObjectPath") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadObjectPath_get()));
    }

    if (property_name.compare("TestPropReadString") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadString_get()));
    }

    if (property_name.compare("TestPropReadDouble") == 0) {
        property = Glib::Variant<double>::create((TestPropReadDouble_get()));
    }

    if (property_name.compare("TestPropReadUInt64") == 0) {
        property = Glib::Variant<guint64>::create((TestPropReadUInt64_get()));
    }

    if (property_name.compare("TestPropReadInt64") == 0) {
        property = Glib::Variant<gint64>::create((TestPropReadInt64_get()));
    }

    if (property_name.compare("TestPropReadUInt") == 0) {
        property = Glib::Variant<guint32>::create((TestPropReadUInt_get()));
    }

    if (property_name.compare("TestPropReadInt") == 0) {
        property = Glib::Variant<gint32>::create((TestPropReadInt_get()));
    }

    if (property_name.compare("TestPropReadUInt16") == 0) {
        property = Glib::Variant<guint16>::create((TestPropReadUInt16_get()));
    }

    if (property_name.compare("TestPropReadInt16") == 0) {
        property = Glib::Variant<gint16>::create((TestPropReadInt16_get()));
    }

    if (property_name.compare("TestPropReadChar") == 0) {
        property = Glib::Variant<guchar>::create((TestPropReadChar_get()));
    }

    if (property_name.compare("TestPropReadBoolean") == 0) {
        property = Glib::Variant<bool>::create((TestPropReadBoolean_get()));
    }

    if (property_name.compare("TestPropInternalReadPropertyChange") == 0) {
        property = Glib::Variant<gint32>::create((TestPropInternalReadPropertyChange_get()));
    }

    if (property_name.compare("TestPropReadWriteByteStringArray") == 0) {
        property = Glib::Variant<std::vector<std::string>>::create((TestPropReadWriteByteStringArray_get()));
    }

    if (property_name.compare("TestPropReadWriteObjectPathArray") == 0) {
        property = Glib::Variant<std::vector<std::string>>::create((TestPropReadWriteObjectPathArray_get()));
    }

    if (property_name.compare("TestPropReadWriteStringArray") == 0) {
        property = Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadWriteStringArray_get()));
    }

    if (property_name.compare("TestPropReadWriteByteString") == 0) {
        property = Glib::Variant<std::string>::create((TestPropReadWriteByteString_get()));
    }

    if (property_name.compare("TestPropReadWriteSignature") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadWriteSignature_get()));
    }

    if (property_name.compare("TestPropReadWriteObjectPath") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadWriteObjectPath_get()));
    }

    if (property_name.compare("TestPropReadWriteString") == 0) {
        property = Glib::Variant<Glib::ustring>::create((TestPropReadWriteString_get()));
    }

    if (property_name.compare("TestPropReadWriteDouble") == 0) {
        property = Glib::Variant<double>::create((TestPropReadWriteDouble_get()));
    }

    if (property_name.compare("TestPropReadWriteUInt64") == 0) {
        property = Glib::Variant<guint64>::create((TestPropReadWriteUInt64_get()));
    }

    if (property_name.compare("TestPropReadWriteInt64") == 0) {
        property = Glib::Variant<gint64>::create((TestPropReadWriteInt64_get()));
    }

    if (property_name.compare("TestPropReadWriteUInt") == 0) {
        property = Glib::Variant<guint32>::create((TestPropReadWriteUInt_get()));
    }

    if (property_name.compare("TestPropReadWriteInt") == 0) {
        property = Glib::Variant<gint32>::create((TestPropReadWriteInt_get()));
    }

    if (property_name.compare("TestPropReadWriteUInt16") == 0) {
        property = Glib::Variant<guint16>::create((TestPropReadWriteUInt16_get()));
    }

    if (property_name.compare("TestPropReadWriteInt16") == 0) {
        property = Glib::Variant<gint16>::create((TestPropReadWriteInt16_get()));
    }

    if (property_name.compare("TestPropReadWriteChar") == 0) {
        property = Glib::Variant<guchar>::create((TestPropReadWriteChar_get()));
    }

    if (property_name.compare("TestPropReadWriteBoolean") == 0) {
        property = Glib::Variant<bool>::create((TestPropReadWriteBoolean_get()));
    }

    if (property_name.compare("TestPropInternalReadWritePropertyChange") == 0) {
        property = Glib::Variant<gint32>::create((TestPropInternalReadWritePropertyChange_get()));
    }

}

bool org::gdbus::codegen::glibmm::Test::on_interface_set_property(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &sender,
    const Glib::ustring &object_path,
    const Glib::ustring &interface_name,
    const Glib::ustring &property_name,
    const Glib::VariantBase &value)
{
    if (property_name.compare("TestPropReadByteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropReadByteStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadByteStringArray");
        }
    }

    if (property_name.compare("TestPropReadObjectPathArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropReadObjectPathArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadObjectPathArray");
        }
    }

    if (property_name.compare("TestPropReadStringArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::ustring>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring>>>(value);
            std::vector<std::string> val =
                TestTypeWrap::glibStringVecToStdStringVec(castValue.get());
            TestPropReadStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadStringArray");
        }
    }

    if (property_name.compare("TestPropReadByteString") == 0) {
        try {
            Glib::Variant<std::string> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::string>>(value);
            std::string val =
                (castValue.get());
            TestPropReadByteString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadByteString");
        }
    }

    if (property_name.compare("TestPropReadSignature") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropReadSignature_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadSignature");
        }
    }

    if (property_name.compare("TestPropReadObjectPath") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropReadObjectPath_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadObjectPath");
        }
    }

    if (property_name.compare("TestPropReadString") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                Glib::ustring(castValue.get());
            TestPropReadString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadString");
        }
    }

    if (property_name.compare("TestPropReadDouble") == 0) {
        try {
            Glib::Variant<double> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<double>>(value);
            double val =
                (castValue.get());
            TestPropReadDouble_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadDouble");
        }
    }

    if (property_name.compare("TestPropReadUInt64") == 0) {
        try {
            Glib::Variant<guint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint64>>(value);
            guint64 val =
                (castValue.get());
            TestPropReadUInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadUInt64");
        }
    }

    if (property_name.compare("TestPropReadInt64") == 0) {
        try {
            Glib::Variant<gint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint64>>(value);
            gint64 val =
                (castValue.get());
            TestPropReadInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadInt64");
        }
    }

    if (property_name.compare("TestPropReadUInt") == 0) {
        try {
            Glib::Variant<guint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint32>>(value);
            guint32 val =
                (castValue.get());
            TestPropReadUInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadUInt");
        }
    }

    if (property_name.compare("TestPropReadInt") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (castValue.get());
            TestPropReadInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadInt");
        }
    }

    if (property_name.compare("TestPropReadUInt16") == 0) {
        try {
            Glib::Variant<guint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint16>>(value);
            guint16 val =
                (castValue.get());
            TestPropReadUInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadUInt16");
        }
    }

    if (property_name.compare("TestPropReadInt16") == 0) {
        try {
            Glib::Variant<gint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint16>>(value);
            gint16 val =
                (castValue.get());
            TestPropReadInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadInt16");
        }
    }

    if (property_name.compare("TestPropReadChar") == 0) {
        try {
            Glib::Variant<guchar> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guchar>>(value);
            guchar val =
                (castValue.get());
            TestPropReadChar_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadChar");
        }
    }

    if (property_name.compare("TestPropReadBoolean") == 0) {
        try {
            Glib::Variant<bool> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<bool>>(value);
            bool val =
                (castValue.get());
            TestPropReadBoolean_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadBoolean");
        }
    }

    if (property_name.compare("TestPropInternalReadPropertyChange") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (castValue.get());
            TestPropInternalReadPropertyChange_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropInternalReadPropertyChange");
        }
    }

    if (property_name.compare("TestPropWriteByteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropWriteByteStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteByteStringArray");
        }
    }

    if (property_name.compare("TestPropWriteObjectPathArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropWriteObjectPathArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteObjectPathArray");
        }
    }

    if (property_name.compare("TestPropWriteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::ustring>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring>>>(value);
            std::vector<std::string> val =
                TestTypeWrap::glibStringVecToStdStringVec(castValue.get());
            TestPropWriteStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteStringArray");
        }
    }

    if (property_name.compare("TestPropWriteByteString") == 0) {
        try {
            Glib::Variant<std::string> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::string>>(value);
            std::string val =
                (castValue.get());
            TestPropWriteByteString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteByteString");
        }
    }

    if (property_name.compare("TestPropWriteSignature") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropWriteSignature_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteSignature");
        }
    }

    if (property_name.compare("TestPropWriteObjectPath") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropWriteObjectPath_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteObjectPath");
        }
    }

    if (property_name.compare("TestPropWriteString") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                Glib::ustring(castValue.get());
            TestPropWriteString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteString");
        }
    }

    if (property_name.compare("TestPropWriteDouble") == 0) {
        try {
            Glib::Variant<double> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<double>>(value);
            double val =
                (castValue.get());
            TestPropWriteDouble_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteDouble");
        }
    }

    if (property_name.compare("TestPropWriteUInt64") == 0) {
        try {
            Glib::Variant<guint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint64>>(value);
            guint64 val =
                (castValue.get());
            TestPropWriteUInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteUInt64");
        }
    }

    if (property_name.compare("TestPropWriteInt64") == 0) {
        try {
            Glib::Variant<gint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint64>>(value);
            gint64 val =
                (castValue.get());
            TestPropWriteInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteInt64");
        }
    }

    if (property_name.compare("TestPropWriteUInt") == 0) {
        try {
            Glib::Variant<guint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint32>>(value);
            guint32 val =
                (castValue.get());
            TestPropWriteUInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteUInt");
        }
    }

    if (property_name.compare("TestPropWriteInt") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (castValue.get());
            TestPropWriteInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteInt");
        }
    }

    if (property_name.compare("TestPropWriteUInt16") == 0) {
        try {
            Glib::Variant<guint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint16>>(value);
            guint16 val =
                (castValue.get());
            TestPropWriteUInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteUInt16");
        }
    }

    if (property_name.compare("TestPropWriteInt16") == 0) {
        try {
            Glib::Variant<gint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint16>>(value);
            gint16 val =
                (castValue.get());
            TestPropWriteInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteInt16");
        }
    }

    if (property_name.compare("TestPropWriteChar") == 0) {
        try {
            Glib::Variant<guchar> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guchar>>(value);
            guchar val =
                (castValue.get());
            TestPropWriteChar_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteChar");
        }
    }

    if (property_name.compare("TestPropWriteBoolean") == 0) {
        try {
            Glib::Variant<bool> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<bool>>(value);
            bool val =
                (castValue.get());
            TestPropWriteBoolean_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropWriteBoolean");
        }
    }

    if (property_name.compare("TestPropReadWriteByteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropReadWriteByteStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteByteStringArray");
        }
    }

    if (property_name.compare("TestPropReadWriteObjectPathArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (castValue.get());
            TestPropReadWriteObjectPathArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteObjectPathArray");
        }
    }

    if (property_name.compare("TestPropReadWriteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::ustring>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring>>>(value);
            std::vector<std::string> val =
                TestTypeWrap::glibStringVecToStdStringVec(castValue.get());
            TestPropReadWriteStringArray_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteStringArray");
        }
    }

    if (property_name.compare("TestPropReadWriteByteString") == 0) {
        try {
            Glib::Variant<std::string> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::string>>(value);
            std::string val =
                (castValue.get());
            TestPropReadWriteByteString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteByteString");
        }
    }

    if (property_name.compare("TestPropReadWriteSignature") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropReadWriteSignature_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteSignature");
        }
    }

    if (property_name.compare("TestPropReadWriteObjectPath") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                (castValue.get());
            TestPropReadWriteObjectPath_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteObjectPath");
        }
    }

    if (property_name.compare("TestPropReadWriteString") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            std::string val =
                Glib::ustring(castValue.get());
            TestPropReadWriteString_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteString");
        }
    }

    if (property_name.compare("TestPropReadWriteDouble") == 0) {
        try {
            Glib::Variant<double> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<double>>(value);
            double val =
                (castValue.get());
            TestPropReadWriteDouble_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteDouble");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt64") == 0) {
        try {
            Glib::Variant<guint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint64>>(value);
            guint64 val =
                (castValue.get());
            TestPropReadWriteUInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt64");
        }
    }

    if (property_name.compare("TestPropReadWriteInt64") == 0) {
        try {
            Glib::Variant<gint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint64>>(value);
            gint64 val =
                (castValue.get());
            TestPropReadWriteInt64_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteInt64");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt") == 0) {
        try {
            Glib::Variant<guint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint32>>(value);
            guint32 val =
                (castValue.get());
            TestPropReadWriteUInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt");
        }
    }

    if (property_name.compare("TestPropReadWriteInt") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (castValue.get());
            TestPropReadWriteInt_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteInt");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt16") == 0) {
        try {
            Glib::Variant<guint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint16>>(value);
            guint16 val =
                (castValue.get());
            TestPropReadWriteUInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt16");
        }
    }

    if (property_name.compare("TestPropReadWriteInt16") == 0) {
        try {
            Glib::Variant<gint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint16>>(value);
            gint16 val =
                (castValue.get());
            TestPropReadWriteInt16_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteInt16");
        }
    }

    if (property_name.compare("TestPropReadWriteChar") == 0) {
        try {
            Glib::Variant<guchar> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guchar>>(value);
            guchar val =
                (castValue.get());
            TestPropReadWriteChar_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteChar");
        }
    }

    if (property_name.compare("TestPropReadWriteBoolean") == 0) {
        try {
            Glib::Variant<bool> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<bool>>(value);
            bool val =
                (castValue.get());
            TestPropReadWriteBoolean_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropReadWriteBoolean");
        }
    }

    if (property_name.compare("TestPropInternalReadWritePropertyChange") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (castValue.get());
            TestPropInternalReadWritePropertyChange_set(val);
        } catch (std::bad_cast e) {
            g_warning ("Bad cast when casting TestPropInternalReadWritePropertyChange");
        }
    }

    return true;
}

void org::gdbus::codegen::glibmm::Test::TestSignalByteStringArray_emitter(std::vector<std::string> Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<std::string>>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalByteStringArray",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalObjectPathArray_emitter(std::vector<std::string> Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<std::string>>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalObjectPathArray",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalStringArray_emitter(std::vector<std::string> Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalStringArray",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalByteString_emitter(std::string Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::string>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalByteString",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalSignature_emitter(std::string Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::ustring>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalSignature",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalObjectPath_emitter(std::string Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::ustring>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalObjectPath",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalString_emitter(std::string Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::ustring>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalString",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalDouble_emitter(double Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<double>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalDouble",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalUInt64_emitter(guint64 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint64>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalUInt64",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalInt64_emitter(gint64 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint64>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalInt64",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalUInt_emitter(guint32 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint32>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalUInt",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalInt_emitter(gint32 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint32>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalInt",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalUInt16_emitter(guint16 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint16>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalUInt16",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalInt16_emitter(gint16 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint16>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalInt16",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalChar_emitter(guchar Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guchar>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalChar",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::TestSignalBoolean_emitter(bool Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<bool>::create((Param1)));;

    m_connection->emit_signal(
        m_objectPath,
        "org.gdbus.codegen.glibmm.Test",
        "TestSignalBoolean",
        Glib::ustring(),
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList));
}

void org::gdbus::codegen::glibmm::Test::on_bus_acquired(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &/* name */)
{
    registeredId = register_object(connection,
                                   "/org/gdbus/codegen/glibmm/Test");
    m_connection = connection;
}

void org::gdbus::codegen::glibmm::Test::on_name_acquired(
    const Glib::RefPtr<Gio::DBus::Connection> &/* connection */,
    const Glib::ustring &/* name */)
{
}

void org::gdbus::codegen::glibmm::Test::on_name_lost(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &/* name */)
{
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadByteStringArray_set(std::vector<std::string> value)
{
    if (TestPropReadByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadByteStringArray_get()));
        emitSignal("TestPropReadByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadObjectPathArray_set(std::vector<std::string> value)
{
    if (TestPropReadObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadObjectPathArray_get()));
        emitSignal("TestPropReadObjectPathArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadStringArray_set(std::vector<std::string> value)
{
    if (TestPropReadStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadStringArray_get()));
        emitSignal("TestPropReadStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadByteString_set(std::string value)
{
    if (TestPropReadByteString_setHandler(value)) {
        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>::create((TestPropReadByteString_get()));
        emitSignal("TestPropReadByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadSignature_set(std::string value)
{
    if (TestPropReadSignature_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadSignature_get()));
        emitSignal("TestPropReadSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadObjectPath_set(std::string value)
{
    if (TestPropReadObjectPath_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadObjectPath_get()));
        emitSignal("TestPropReadObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadString_set(std::string value)
{
    if (TestPropReadString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadString_get()));
        emitSignal("TestPropReadString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadDouble_set(double value)
{
    if (TestPropReadDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropReadDouble_get()));
        emitSignal("TestPropReadDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadUInt64_set(guint64 value)
{
    if (TestPropReadUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropReadUInt64_get()));
        emitSignal("TestPropReadUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadInt64_set(gint64 value)
{
    if (TestPropReadInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropReadInt64_get()));
        emitSignal("TestPropReadInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadUInt_set(guint32 value)
{
    if (TestPropReadUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropReadUInt_get()));
        emitSignal("TestPropReadUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadInt_set(gint32 value)
{
    if (TestPropReadInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropReadInt_get()));
        emitSignal("TestPropReadInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadUInt16_set(guint16 value)
{
    if (TestPropReadUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropReadUInt16_get()));
        emitSignal("TestPropReadUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadInt16_set(gint16 value)
{
    if (TestPropReadInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropReadInt16_get()));
        emitSignal("TestPropReadInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadChar_set(guchar value)
{
    if (TestPropReadChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropReadChar_get()));
        emitSignal("TestPropReadChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadBoolean_set(bool value)
{
    if (TestPropReadBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropReadBoolean_get()));
        emitSignal("TestPropReadBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropInternalReadPropertyChange_set(gint32 value)
{
    if (TestPropInternalReadPropertyChange_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropInternalReadPropertyChange_get()));
        emitSignal("TestPropInternalReadPropertyChange", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteByteStringArray_set(std::vector<std::string> value)
{
    if (TestPropWriteByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropWriteByteStringArray_get()));
        emitSignal("TestPropWriteByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteObjectPathArray_set(std::vector<std::string> value)
{
    if (TestPropWriteObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropWriteObjectPathArray_get()));
        emitSignal("TestPropWriteObjectPathArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteStringArray_set(std::vector<std::string> value)
{
    if (TestPropWriteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropWriteStringArray_get()));
        emitSignal("TestPropWriteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteByteString_set(std::string value)
{
    if (TestPropWriteByteString_setHandler(value)) {
        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>::create((TestPropWriteByteString_get()));
        emitSignal("TestPropWriteByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteSignature_set(std::string value)
{
    if (TestPropWriteSignature_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropWriteSignature_get()));
        emitSignal("TestPropWriteSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteObjectPath_set(std::string value)
{
    if (TestPropWriteObjectPath_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropWriteObjectPath_get()));
        emitSignal("TestPropWriteObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteString_set(std::string value)
{
    if (TestPropWriteString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropWriteString_get()));
        emitSignal("TestPropWriteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteDouble_set(double value)
{
    if (TestPropWriteDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropWriteDouble_get()));
        emitSignal("TestPropWriteDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteUInt64_set(guint64 value)
{
    if (TestPropWriteUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropWriteUInt64_get()));
        emitSignal("TestPropWriteUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteInt64_set(gint64 value)
{
    if (TestPropWriteInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropWriteInt64_get()));
        emitSignal("TestPropWriteInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteUInt_set(guint32 value)
{
    if (TestPropWriteUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropWriteUInt_get()));
        emitSignal("TestPropWriteUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteInt_set(gint32 value)
{
    if (TestPropWriteInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropWriteInt_get()));
        emitSignal("TestPropWriteInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteUInt16_set(guint16 value)
{
    if (TestPropWriteUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropWriteUInt16_get()));
        emitSignal("TestPropWriteUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteInt16_set(gint16 value)
{
    if (TestPropWriteInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropWriteInt16_get()));
        emitSignal("TestPropWriteInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteChar_set(guchar value)
{
    if (TestPropWriteChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropWriteChar_get()));
        emitSignal("TestPropWriteChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropWriteBoolean_set(bool value)
{
    if (TestPropWriteBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropWriteBoolean_get()));
        emitSignal("TestPropWriteBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteByteStringArray_set(std::vector<std::string> value)
{
    if (TestPropReadWriteByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadWriteByteStringArray_get()));
        emitSignal("TestPropReadWriteByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteObjectPathArray_set(std::vector<std::string> value)
{
    if (TestPropReadWriteObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadWriteObjectPathArray_get()));
        emitSignal("TestPropReadWriteObjectPathArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteStringArray_set(std::vector<std::string> value)
{
    if (TestPropReadWriteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create(TestTypeWrap::stdStringVecToGlibStringVec(TestPropReadWriteStringArray_get()));
        emitSignal("TestPropReadWriteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteByteString_set(std::string value)
{
    if (TestPropReadWriteByteString_setHandler(value)) {
        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>::create((TestPropReadWriteByteString_get()));
        emitSignal("TestPropReadWriteByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteSignature_set(std::string value)
{
    if (TestPropReadWriteSignature_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadWriteSignature_get()));
        emitSignal("TestPropReadWriteSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteObjectPath_set(std::string value)
{
    if (TestPropReadWriteObjectPath_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadWriteObjectPath_get()));
        emitSignal("TestPropReadWriteObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteString_set(std::string value)
{
    if (TestPropReadWriteString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadWriteString_get()));
        emitSignal("TestPropReadWriteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteDouble_set(double value)
{
    if (TestPropReadWriteDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropReadWriteDouble_get()));
        emitSignal("TestPropReadWriteDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteUInt64_set(guint64 value)
{
    if (TestPropReadWriteUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropReadWriteUInt64_get()));
        emitSignal("TestPropReadWriteUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteInt64_set(gint64 value)
{
    if (TestPropReadWriteInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropReadWriteInt64_get()));
        emitSignal("TestPropReadWriteInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteUInt_set(guint32 value)
{
    if (TestPropReadWriteUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropReadWriteUInt_get()));
        emitSignal("TestPropReadWriteUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteInt_set(gint32 value)
{
    if (TestPropReadWriteInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropReadWriteInt_get()));
        emitSignal("TestPropReadWriteInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteUInt16_set(guint16 value)
{
    if (TestPropReadWriteUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropReadWriteUInt16_get()));
        emitSignal("TestPropReadWriteUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteInt16_set(gint16 value)
{
    if (TestPropReadWriteInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropReadWriteInt16_get()));
        emitSignal("TestPropReadWriteInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteChar_set(guchar value)
{
    if (TestPropReadWriteChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropReadWriteChar_get()));
        emitSignal("TestPropReadWriteChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropReadWriteBoolean_set(bool value)
{
    if (TestPropReadWriteBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropReadWriteBoolean_get()));
        emitSignal("TestPropReadWriteBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::TestPropInternalReadWritePropertyChange_set(gint32 value)
{
    if (TestPropInternalReadWritePropertyChange_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropInternalReadWritePropertyChange_get()));
        emitSignal("TestPropInternalReadWritePropertyChange", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::Test::emitSignal(
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

    m_connection->emit_signal(
        m_objectPath,
        "org.freedesktop.DBus.Properties",
        "PropertiesChanged",
        Glib::ustring(),
        propertiesChangedVariant);

    return true;
}
