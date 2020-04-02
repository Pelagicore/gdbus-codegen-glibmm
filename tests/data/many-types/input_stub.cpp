static const char interfaceXml0[] = R"XML_DELIMITER(<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN"
                      "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">
<node>
  <interface name="org.gdbus.codegen.glibmm.Test">
    <method name="TestStringVariantDict">
      <arg type="a{sv}" name="Param1" direction="in"></arg>
      <arg type="a{sv}" name="Param2" direction="out"></arg>
    </method>

    <!--
      TestStringStringDict:
        @Param1: the dictionary of strings
        @Param2: the output dictionary
      This method tests sending and receiving a dictionary of strings
    -->
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

    <method name="TestVariant2">
       <arg type="s" name="Param1" direction="in"></arg>
       <arg type="v" name="Param2" direction="in"></arg>
       <arg type="s" name="Param3" direction="out"></arg>
       <arg type="v" name="Param4" direction="out"></arg>
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

    <!--
         TestSignalByteStringArray: emitted to test arrays of byte arrays.

           @Param1: the array of arrays
    -->
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
    TestSignalByteStringArray_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalByteStringArray_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalByteStringArray_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalByteStringArray_emitter));
    TestSignalObjectPathArray_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalObjectPathArray_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalObjectPathArray_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalObjectPathArray_emitter));
    TestSignalStringArray_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalStringArray_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalStringArray_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalStringArray_emitter));
    TestSignalByteString_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalByteString_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalByteString_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalByteString_emitter));
    TestSignalSignature_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalSignature_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalSignature_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalSignature_emitter));
    TestSignalObjectPath_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalObjectPath_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalObjectPath_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalObjectPath_emitter));
    TestSignalString_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalString_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalString_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalString_emitter));
    TestSignalDouble_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalDouble_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalDouble_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalDouble_emitter));
    TestSignalUInt64_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalUInt64_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalUInt64_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalUInt64_emitter));
    TestSignalInt64_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalInt64_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalInt64_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalInt64_emitter));
    TestSignalUInt_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalUInt_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalUInt_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalUInt_emitter));
    TestSignalInt_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalInt_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalInt_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalInt_emitter));
    TestSignalUInt16_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalUInt16_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalUInt16_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalUInt16_emitter));
    TestSignalInt16_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalInt16_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalInt16_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalInt16_emitter));
    TestSignalChar_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalChar_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalChar_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalChar_emitter));
    TestSignalBoolean_signal.connect(sigc::bind<0>(sigc::mem_fun(this, &TestStub::TestSignalBoolean_emitter),
            std::vector<Glib::ustring>({""})) );
    TestSignalBoolean_selectiveSignal.connect(sigc::mem_fun(this, &TestStub::TestSignalBoolean_emitter));
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

    if (method_name.compare("TestStringVariantDict") == 0) {
        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<Glib::ustring,Glib::VariantBase> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestStringVariantDict(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestStringStringDict") == 0) {
        Glib::Variant<std::map<Glib::ustring,Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<Glib::ustring,Glib::ustring> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestStringStringDict(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestUintIntDict") == 0) {
        Glib::Variant<std::map<guint32,gint32>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::map<guint32,gint32> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestUintIntDict(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestVariant") == 0) {
        Glib::Variant<Glib::VariantBase> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::VariantBase p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestVariant(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestVariant2") == 0) {
        Glib::Variant<Glib::ustring> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::ustring p_Param1 = specialGetter(base_Param1);

        Glib::Variant<Glib::VariantBase> base_Param2;
        parameters.get_child(base_Param2, 1);
        Glib::VariantBase p_Param2 = specialGetter(base_Param2);

        MethodInvocation methodInvocation(invocation);
        TestVariant2(
            (p_Param1),
            (p_Param2),
            methodInvocation);
    }

    if (method_name.compare("TestByteStringArray") == 0) {
        Glib::Variant<std::vector<std::string>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::string> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestByteStringArray(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestObjectPathArray") == 0) {
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<Glib::DBusObjectPathString> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestObjectPathArray(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestStringArray") == 0) {
        Glib::Variant<std::vector<Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<Glib::ustring> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestStringArray(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestByteString") == 0) {
        Glib::Variant<std::string> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::string p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestByteString(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestStruct") == 0) {
        Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::tuple<Glib::ustring,Glib::ustring> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestStruct(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestStructArray") == 0) {
        Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::tuple<guint32,Glib::ustring,gint32>> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestStructArray(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestDictStructArray") == 0) {
        Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestDictStructArray(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestSignature") == 0) {
        Glib::Variant<Glib::DBusSignatureString> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::DBusSignatureString p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestSignature(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestObjectPath") == 0) {
        Glib::Variant<Glib::DBusObjectPathString> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::DBusObjectPathString p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestObjectPath(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestString") == 0) {
        Glib::Variant<Glib::ustring> base_Param1;
        parameters.get_child(base_Param1, 0);
        Glib::ustring p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestString(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestDouble") == 0) {
        Glib::Variant<double> base_Param1;
        parameters.get_child(base_Param1, 0);
        double p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestDouble(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestUInt64") == 0) {
        Glib::Variant<guint64> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint64 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestUInt64(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestInt64") == 0) {
        Glib::Variant<gint64> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint64 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestInt64(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestUInt") == 0) {
        Glib::Variant<guint32> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint32 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestUInt(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestInt") == 0) {
        Glib::Variant<gint32> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint32 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestInt(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestUInt16") == 0) {
        Glib::Variant<guint16> base_Param1;
        parameters.get_child(base_Param1, 0);
        guint16 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestUInt16(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestInt16") == 0) {
        Glib::Variant<gint16> base_Param1;
        parameters.get_child(base_Param1, 0);
        gint16 p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestInt16(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestChar") == 0) {
        Glib::Variant<guchar> base_Param1;
        parameters.get_child(base_Param1, 0);
        guchar p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestChar(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestBoolean") == 0) {
        Glib::Variant<bool> base_Param1;
        parameters.get_child(base_Param1, 0);
        bool p_Param1 = specialGetter(base_Param1);

        MethodInvocation methodInvocation(invocation);
        TestBoolean(
            (p_Param1),
            methodInvocation);
    }

    if (method_name.compare("TestAll") == 0) {
        Glib::Variant<std::vector<std::string>> base_in_Param1;
        parameters.get_child(base_in_Param1, 0);
        std::vector<std::string> p_in_Param1 = specialGetter(base_in_Param1);

        Glib::Variant<std::vector<Glib::DBusObjectPathString>> base_in_Param2;
        parameters.get_child(base_in_Param2, 1);
        std::vector<Glib::DBusObjectPathString> p_in_Param2 = specialGetter(base_in_Param2);

        Glib::Variant<std::vector<Glib::ustring>> base_in_Param3;
        parameters.get_child(base_in_Param3, 2);
        std::vector<Glib::ustring> p_in_Param3 = specialGetter(base_in_Param3);

        Glib::Variant<std::string> base_in_Param4;
        parameters.get_child(base_in_Param4, 3);
        std::string p_in_Param4 = specialGetter(base_in_Param4);

        Glib::Variant<Glib::DBusSignatureString> base_in_Param5;
        parameters.get_child(base_in_Param5, 4);
        Glib::DBusSignatureString p_in_Param5 = specialGetter(base_in_Param5);

        Glib::Variant<Glib::DBusObjectPathString> base_in_Param6;
        parameters.get_child(base_in_Param6, 5);
        Glib::DBusObjectPathString p_in_Param6 = specialGetter(base_in_Param6);

        Glib::Variant<Glib::ustring> base_in_Param7;
        parameters.get_child(base_in_Param7, 6);
        Glib::ustring p_in_Param7 = specialGetter(base_in_Param7);

        Glib::Variant<double> base_in_Param8;
        parameters.get_child(base_in_Param8, 7);
        double p_in_Param8 = specialGetter(base_in_Param8);

        Glib::Variant<guint64> base_in_Param9;
        parameters.get_child(base_in_Param9, 8);
        guint64 p_in_Param9 = specialGetter(base_in_Param9);

        Glib::Variant<gint64> base_in_Param10;
        parameters.get_child(base_in_Param10, 9);
        gint64 p_in_Param10 = specialGetter(base_in_Param10);

        Glib::Variant<guint32> base_in_Param11;
        parameters.get_child(base_in_Param11, 10);
        guint32 p_in_Param11 = specialGetter(base_in_Param11);

        Glib::Variant<gint32> base_in_Param12;
        parameters.get_child(base_in_Param12, 11);
        gint32 p_in_Param12 = specialGetter(base_in_Param12);

        Glib::Variant<guint16> base_in_Param13;
        parameters.get_child(base_in_Param13, 12);
        guint16 p_in_Param13 = specialGetter(base_in_Param13);

        Glib::Variant<gint16> base_in_Param14;
        parameters.get_child(base_in_Param14, 13);
        gint16 p_in_Param14 = specialGetter(base_in_Param14);

        Glib::Variant<guchar> base_in_Param15;
        parameters.get_child(base_in_Param15, 14);
        guchar p_in_Param15 = specialGetter(base_in_Param15);

        Glib::Variant<bool> base_in_Param16;
        parameters.get_child(base_in_Param16, 15);
        bool p_in_Param16 = specialGetter(base_in_Param16);

        MethodInvocation methodInvocation(invocation);
        TestAll(
            (p_in_Param1),
            (p_in_Param2),
            (p_in_Param3),
            (p_in_Param4),
            (p_in_Param5),
            (p_in_Param6),
            (p_in_Param7),
            (p_in_Param8),
            (p_in_Param9),
            (p_in_Param10),
            (p_in_Param11),
            (p_in_Param12),
            (p_in_Param13),
            (p_in_Param14),
            (p_in_Param15),
            (p_in_Param16),
            methodInvocation);
    }

    if (method_name.compare("TestTriggerInternalPropertyChange") == 0) {
        Glib::Variant<gint32> base_NewPropertyValue;
        parameters.get_child(base_NewPropertyValue, 0);
        gint32 p_NewPropertyValue = specialGetter(base_NewPropertyValue);

        MethodInvocation methodInvocation(invocation);
        TestTriggerInternalPropertyChange(
            (p_NewPropertyValue),
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

    if (property_name.compare("TestPropReadByteStringArray") == 0) {

        property = Glib::Variant<std::vector<std::string>>::create((TestPropReadByteStringArray_get()));
    }

    if (property_name.compare("TestPropReadObjectPathArray") == 0) {

        property = Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((TestPropReadObjectPathArray_get()));
    }

    if (property_name.compare("TestPropReadStringArray") == 0) {

        property = Glib::Variant<std::vector<Glib::ustring>>::create((TestPropReadStringArray_get()));
    }

    if (property_name.compare("TestPropReadByteString") == 0) {

        gsize len;
        char *data;

        std::string temp = TestPropReadByteString_get();
        len = temp.size();
        data = g_strndup (temp.c_str(), len);

        GVariant * newVar = g_variant_new_from_data (G_VARIANT_TYPE ("ay"), data, len, TRUE, g_free, data);

        property = Glib::Variant<std::string>(newVar);
    }

    if (property_name.compare("TestPropReadSignature") == 0) {

        property = Glib::Variant<Glib::DBusSignatureString>::create((TestPropReadSignature_get()));
    }

    if (property_name.compare("TestPropReadObjectPath") == 0) {

        property = Glib::Variant<Glib::DBusObjectPathString>::create((TestPropReadObjectPath_get()));
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

        property = Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((TestPropReadWriteObjectPathArray_get()));
    }

    if (property_name.compare("TestPropReadWriteStringArray") == 0) {

        property = Glib::Variant<std::vector<Glib::ustring>>::create((TestPropReadWriteStringArray_get()));
    }

    if (property_name.compare("TestPropReadWriteByteString") == 0) {

        gsize len;
        char *data;

        std::string temp = TestPropReadWriteByteString_get();
        len = temp.size();
        data = g_strndup (temp.c_str(), len);

        GVariant * newVar = g_variant_new_from_data (G_VARIANT_TYPE ("ay"), data, len, TRUE, g_free, data);

        property = Glib::Variant<std::string>(newVar);
    }

    if (property_name.compare("TestPropReadWriteSignature") == 0) {

        property = Glib::Variant<Glib::DBusSignatureString>::create((TestPropReadWriteSignature_get()));
    }

    if (property_name.compare("TestPropReadWriteObjectPath") == 0) {

        property = Glib::Variant<Glib::DBusObjectPathString>::create((TestPropReadWriteObjectPath_get()));
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

    if (property_name.compare("TestPropWriteByteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (specialGetter(castValue));
            TestPropWriteByteStringArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteByteStringArray");
        }
    }

    if (property_name.compare("TestPropWriteObjectPathArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::DBusObjectPathString>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::DBusObjectPathString>>>(value);
            std::vector<Glib::DBusObjectPathString> val =
                (specialGetter(castValue));
            TestPropWriteObjectPathArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteObjectPathArray");
        }
    }

    if (property_name.compare("TestPropWriteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::ustring>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring>>>(value);
            std::vector<Glib::ustring> val =
                (specialGetter(castValue));
            TestPropWriteStringArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteStringArray");
        }
    }

    if (property_name.compare("TestPropWriteByteString") == 0) {
        try {
            Glib::Variant<std::string> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::string>>(value);
            std::string val =
                (specialGetter(castValue));
            TestPropWriteByteString_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteByteString");
        }
    }

    if (property_name.compare("TestPropWriteSignature") == 0) {
        try {
            Glib::Variant<Glib::DBusSignatureString> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::DBusSignatureString>>(value);
            Glib::DBusSignatureString val =
                (specialGetter(castValue));
            TestPropWriteSignature_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteSignature");
        }
    }

    if (property_name.compare("TestPropWriteObjectPath") == 0) {
        try {
            Glib::Variant<Glib::DBusObjectPathString> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::DBusObjectPathString>>(value);
            Glib::DBusObjectPathString val =
                (specialGetter(castValue));
            TestPropWriteObjectPath_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteObjectPath");
        }
    }

    if (property_name.compare("TestPropWriteString") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            Glib::ustring val =
                (specialGetter(castValue));
            TestPropWriteString_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteString");
        }
    }

    if (property_name.compare("TestPropWriteDouble") == 0) {
        try {
            Glib::Variant<double> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<double>>(value);
            double val =
                (specialGetter(castValue));
            TestPropWriteDouble_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteDouble");
        }
    }

    if (property_name.compare("TestPropWriteUInt64") == 0) {
        try {
            Glib::Variant<guint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint64>>(value);
            guint64 val =
                (specialGetter(castValue));
            TestPropWriteUInt64_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteUInt64");
        }
    }

    if (property_name.compare("TestPropWriteInt64") == 0) {
        try {
            Glib::Variant<gint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint64>>(value);
            gint64 val =
                (specialGetter(castValue));
            TestPropWriteInt64_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteInt64");
        }
    }

    if (property_name.compare("TestPropWriteUInt") == 0) {
        try {
            Glib::Variant<guint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint32>>(value);
            guint32 val =
                (specialGetter(castValue));
            TestPropWriteUInt_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteUInt");
        }
    }

    if (property_name.compare("TestPropWriteInt") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (specialGetter(castValue));
            TestPropWriteInt_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteInt");
        }
    }

    if (property_name.compare("TestPropWriteUInt16") == 0) {
        try {
            Glib::Variant<guint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint16>>(value);
            guint16 val =
                (specialGetter(castValue));
            TestPropWriteUInt16_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteUInt16");
        }
    }

    if (property_name.compare("TestPropWriteInt16") == 0) {
        try {
            Glib::Variant<gint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint16>>(value);
            gint16 val =
                (specialGetter(castValue));
            TestPropWriteInt16_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteInt16");
        }
    }

    if (property_name.compare("TestPropWriteChar") == 0) {
        try {
            Glib::Variant<guchar> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guchar>>(value);
            guchar val =
                (specialGetter(castValue));
            TestPropWriteChar_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteChar");
        }
    }

    if (property_name.compare("TestPropWriteBoolean") == 0) {
        try {
            Glib::Variant<bool> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<bool>>(value);
            bool val =
                (specialGetter(castValue));
            TestPropWriteBoolean_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropWriteBoolean");
        }
    }

    if (property_name.compare("TestPropReadWriteByteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<std::string>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<std::string>>>(value);
            std::vector<std::string> val =
                (specialGetter(castValue));
            TestPropReadWriteByteStringArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteByteStringArray");
        }
    }

    if (property_name.compare("TestPropReadWriteObjectPathArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::DBusObjectPathString>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::DBusObjectPathString>>>(value);
            std::vector<Glib::DBusObjectPathString> val =
                (specialGetter(castValue));
            TestPropReadWriteObjectPathArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteObjectPathArray");
        }
    }

    if (property_name.compare("TestPropReadWriteStringArray") == 0) {
        try {
            Glib::Variant<std::vector<Glib::ustring>> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::vector<Glib::ustring>>>(value);
            std::vector<Glib::ustring> val =
                (specialGetter(castValue));
            TestPropReadWriteStringArray_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteStringArray");
        }
    }

    if (property_name.compare("TestPropReadWriteByteString") == 0) {
        try {
            Glib::Variant<std::string> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<std::string>>(value);
            std::string val =
                (specialGetter(castValue));
            TestPropReadWriteByteString_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteByteString");
        }
    }

    if (property_name.compare("TestPropReadWriteSignature") == 0) {
        try {
            Glib::Variant<Glib::DBusSignatureString> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::DBusSignatureString>>(value);
            Glib::DBusSignatureString val =
                (specialGetter(castValue));
            TestPropReadWriteSignature_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteSignature");
        }
    }

    if (property_name.compare("TestPropReadWriteObjectPath") == 0) {
        try {
            Glib::Variant<Glib::DBusObjectPathString> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::DBusObjectPathString>>(value);
            Glib::DBusObjectPathString val =
                (specialGetter(castValue));
            TestPropReadWriteObjectPath_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteObjectPath");
        }
    }

    if (property_name.compare("TestPropReadWriteString") == 0) {
        try {
            Glib::Variant<Glib::ustring> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(value);
            Glib::ustring val =
                (specialGetter(castValue));
            TestPropReadWriteString_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteString");
        }
    }

    if (property_name.compare("TestPropReadWriteDouble") == 0) {
        try {
            Glib::Variant<double> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<double>>(value);
            double val =
                (specialGetter(castValue));
            TestPropReadWriteDouble_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteDouble");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt64") == 0) {
        try {
            Glib::Variant<guint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint64>>(value);
            guint64 val =
                (specialGetter(castValue));
            TestPropReadWriteUInt64_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt64");
        }
    }

    if (property_name.compare("TestPropReadWriteInt64") == 0) {
        try {
            Glib::Variant<gint64> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint64>>(value);
            gint64 val =
                (specialGetter(castValue));
            TestPropReadWriteInt64_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteInt64");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt") == 0) {
        try {
            Glib::Variant<guint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint32>>(value);
            guint32 val =
                (specialGetter(castValue));
            TestPropReadWriteUInt_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt");
        }
    }

    if (property_name.compare("TestPropReadWriteInt") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (specialGetter(castValue));
            TestPropReadWriteInt_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteInt");
        }
    }

    if (property_name.compare("TestPropReadWriteUInt16") == 0) {
        try {
            Glib::Variant<guint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guint16>>(value);
            guint16 val =
                (specialGetter(castValue));
            TestPropReadWriteUInt16_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteUInt16");
        }
    }

    if (property_name.compare("TestPropReadWriteInt16") == 0) {
        try {
            Glib::Variant<gint16> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint16>>(value);
            gint16 val =
                (specialGetter(castValue));
            TestPropReadWriteInt16_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteInt16");
        }
    }

    if (property_name.compare("TestPropReadWriteChar") == 0) {
        try {
            Glib::Variant<guchar> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<guchar>>(value);
            guchar val =
                (specialGetter(castValue));
            TestPropReadWriteChar_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteChar");
        }
    }

    if (property_name.compare("TestPropReadWriteBoolean") == 0) {
        try {
            Glib::Variant<bool> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<bool>>(value);
            bool val =
                (specialGetter(castValue));
            TestPropReadWriteBoolean_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropReadWriteBoolean");
        }
    }

    if (property_name.compare("TestPropInternalReadWritePropertyChange") == 0) {
        try {
            Glib::Variant<gint32> castValue =
                Glib::VariantBase::cast_dynamic<Glib::Variant<gint32>>(value);
            gint32 val =
                (specialGetter(castValue));
            TestPropInternalReadWritePropertyChange_set(val);
        } catch (const std::bad_cast &) {
            g_warning ("Bad cast when casting TestPropInternalReadWritePropertyChange");
        }
    }

    return true;
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalByteStringArray_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const std::vector<std::string> & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<std::string>>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalByteStringArray",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalObjectPathArray_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const std::vector<Glib::DBusObjectPathString> & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalObjectPathArray",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalStringArray_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const std::vector<Glib::ustring> & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::vector<Glib::ustring>>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalStringArray",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalByteString_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const std::string & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<std::string>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalByteString",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalSignature_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const Glib::DBusSignatureString & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::DBusSignatureString>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalSignature",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalObjectPath_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const Glib::DBusObjectPathString & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::DBusObjectPathString>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalObjectPath",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalString_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,const Glib::ustring & Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<Glib::ustring>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalString",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalDouble_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,double Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<double>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalDouble",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalUInt64_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,guint64 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint64>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalUInt64",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalInt64_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,gint64 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint64>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalInt64",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalUInt_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,guint32 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint32>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalUInt",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalInt_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,gint32 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint32>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalInt",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalUInt16_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,guint16 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guint16>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalUInt16",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalInt16_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,gint16 Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<gint16>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalInt16",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalChar_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,guchar Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<guchar>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalChar",
                    bus_name,
                    params);
        }
    }
}

void org::gdbus::codegen::glibmm::TestStub::TestSignalBoolean_emitter(
    const std::vector<Glib::ustring> &destination_bus_names,bool Param1)
{
    std::vector<Glib::VariantBase> paramsList;

    paramsList.push_back(Glib::Variant<bool>::create((Param1)));;

    const Glib::VariantContainerBase params =
        Glib::Variant<std::vector<Glib::VariantBase>>::create_tuple(paramsList);
    for (const RegisteredObject &obj: m_registered_objects) {
        for (const auto &bus_name: destination_bus_names) {
            obj.connection->emit_signal(
                    obj.object_path,
                    "org.gdbus.codegen.glibmm.Test",
                    "TestSignalBoolean",
                    bus_name,
                    params);
        }
    }
}


bool org::gdbus::codegen::glibmm::TestStub::TestPropReadByteStringArray_set(const std::vector<std::string> & value)
{
    if (TestPropReadByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadByteStringArray_get()));

        emitSignal("TestPropReadByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadObjectPathArray_set(const std::vector<Glib::DBusObjectPathString> & value)
{
    if (TestPropReadObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> value_get =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((TestPropReadObjectPathArray_get()));

        emitSignal("TestPropReadObjectPathArray", value_get);
        return true;
    }

    return false;
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

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadByteString_set(const std::string & value)
{
    if (TestPropReadByteString_setHandler(value)) {
        gsize len;
        char *data;

        len = value.size();
        data = g_strndup (value.c_str(), len);

        GVariant * newVar = g_variant_new_from_data (G_VARIANT_TYPE ("ay"), data, len, TRUE, g_free, data);

        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>(newVar);

        emitSignal("TestPropReadByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadSignature_set(const Glib::DBusSignatureString & value)
{
    if (TestPropReadSignature_setHandler(value)) {
        Glib::Variant<Glib::DBusSignatureString> value_get =
            Glib::Variant<Glib::DBusSignatureString>::create((TestPropReadSignature_get()));

        emitSignal("TestPropReadSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadObjectPath_set(const Glib::DBusObjectPathString & value)
{
    if (TestPropReadObjectPath_setHandler(value)) {
        Glib::Variant<Glib::DBusObjectPathString> value_get =
            Glib::Variant<Glib::DBusObjectPathString>::create((TestPropReadObjectPath_get()));

        emitSignal("TestPropReadObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadString_set(const Glib::ustring & value)
{
    if (TestPropReadString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadString_get()));

        emitSignal("TestPropReadString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadDouble_set(double value)
{
    if (TestPropReadDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropReadDouble_get()));

        emitSignal("TestPropReadDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadUInt64_set(guint64 value)
{
    if (TestPropReadUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropReadUInt64_get()));

        emitSignal("TestPropReadUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadInt64_set(gint64 value)
{
    if (TestPropReadInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropReadInt64_get()));

        emitSignal("TestPropReadInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadUInt_set(guint32 value)
{
    if (TestPropReadUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropReadUInt_get()));

        emitSignal("TestPropReadUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadInt_set(gint32 value)
{
    if (TestPropReadInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropReadInt_get()));

        emitSignal("TestPropReadInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadUInt16_set(guint16 value)
{
    if (TestPropReadUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropReadUInt16_get()));

        emitSignal("TestPropReadUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadInt16_set(gint16 value)
{
    if (TestPropReadInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropReadInt16_get()));

        emitSignal("TestPropReadInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadChar_set(guchar value)
{
    if (TestPropReadChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropReadChar_get()));

        emitSignal("TestPropReadChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadBoolean_set(bool value)
{
    if (TestPropReadBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropReadBoolean_get()));

        emitSignal("TestPropReadBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropInternalReadPropertyChange_set(gint32 value)
{
    if (TestPropInternalReadPropertyChange_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropInternalReadPropertyChange_get()));

        emitSignal("TestPropInternalReadPropertyChange", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteByteStringArray_set(const std::vector<std::string> & value)
{
    if (TestPropWriteByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropWriteByteStringArray_get()));

        emitSignal("TestPropWriteByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteObjectPathArray_set(const std::vector<Glib::DBusObjectPathString> & value)
{
    if (TestPropWriteObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> value_get =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((TestPropWriteObjectPathArray_get()));

        emitSignal("TestPropWriteObjectPathArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteStringArray_set(const std::vector<Glib::ustring> & value)
{
    if (TestPropWriteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create((TestPropWriteStringArray_get()));

        emitSignal("TestPropWriteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteByteString_set(const std::string & value)
{
    if (TestPropWriteByteString_setHandler(value)) {
        gsize len;
        char *data;

        len = value.size();
        data = g_strndup (value.c_str(), len);

        GVariant * newVar = g_variant_new_from_data (G_VARIANT_TYPE ("ay"), data, len, TRUE, g_free, data);

        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>(newVar);

        emitSignal("TestPropWriteByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteSignature_set(const Glib::DBusSignatureString & value)
{
    if (TestPropWriteSignature_setHandler(value)) {
        Glib::Variant<Glib::DBusSignatureString> value_get =
            Glib::Variant<Glib::DBusSignatureString>::create((TestPropWriteSignature_get()));

        emitSignal("TestPropWriteSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteObjectPath_set(const Glib::DBusObjectPathString & value)
{
    if (TestPropWriteObjectPath_setHandler(value)) {
        Glib::Variant<Glib::DBusObjectPathString> value_get =
            Glib::Variant<Glib::DBusObjectPathString>::create((TestPropWriteObjectPath_get()));

        emitSignal("TestPropWriteObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteString_set(const Glib::ustring & value)
{
    if (TestPropWriteString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropWriteString_get()));

        emitSignal("TestPropWriteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteDouble_set(double value)
{
    if (TestPropWriteDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropWriteDouble_get()));

        emitSignal("TestPropWriteDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteUInt64_set(guint64 value)
{
    if (TestPropWriteUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropWriteUInt64_get()));

        emitSignal("TestPropWriteUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteInt64_set(gint64 value)
{
    if (TestPropWriteInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropWriteInt64_get()));

        emitSignal("TestPropWriteInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteUInt_set(guint32 value)
{
    if (TestPropWriteUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropWriteUInt_get()));

        emitSignal("TestPropWriteUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteInt_set(gint32 value)
{
    if (TestPropWriteInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropWriteInt_get()));

        emitSignal("TestPropWriteInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteUInt16_set(guint16 value)
{
    if (TestPropWriteUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropWriteUInt16_get()));

        emitSignal("TestPropWriteUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteInt16_set(gint16 value)
{
    if (TestPropWriteInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropWriteInt16_get()));

        emitSignal("TestPropWriteInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteChar_set(guchar value)
{
    if (TestPropWriteChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropWriteChar_get()));

        emitSignal("TestPropWriteChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropWriteBoolean_set(bool value)
{
    if (TestPropWriteBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropWriteBoolean_get()));

        emitSignal("TestPropWriteBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteByteStringArray_set(const std::vector<std::string> & value)
{
    if (TestPropReadWriteByteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<std::string>> value_get =
            Glib::Variant<std::vector<std::string>>::create((TestPropReadWriteByteStringArray_get()));

        emitSignal("TestPropReadWriteByteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteObjectPathArray_set(const std::vector<Glib::DBusObjectPathString> & value)
{
    if (TestPropReadWriteObjectPathArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> value_get =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create((TestPropReadWriteObjectPathArray_get()));

        emitSignal("TestPropReadWriteObjectPathArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteStringArray_set(const std::vector<Glib::ustring> & value)
{
    if (TestPropReadWriteStringArray_setHandler(value)) {
        Glib::Variant<std::vector<Glib::ustring>> value_get =
            Glib::Variant<std::vector<Glib::ustring>>::create((TestPropReadWriteStringArray_get()));

        emitSignal("TestPropReadWriteStringArray", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteByteString_set(const std::string & value)
{
    if (TestPropReadWriteByteString_setHandler(value)) {
        gsize len;
        char *data;

        len = value.size();
        data = g_strndup (value.c_str(), len);

        GVariant * newVar = g_variant_new_from_data (G_VARIANT_TYPE ("ay"), data, len, TRUE, g_free, data);

        Glib::Variant<std::string> value_get =
            Glib::Variant<std::string>(newVar);

        emitSignal("TestPropReadWriteByteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteSignature_set(const Glib::DBusSignatureString & value)
{
    if (TestPropReadWriteSignature_setHandler(value)) {
        Glib::Variant<Glib::DBusSignatureString> value_get =
            Glib::Variant<Glib::DBusSignatureString>::create((TestPropReadWriteSignature_get()));

        emitSignal("TestPropReadWriteSignature", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteObjectPath_set(const Glib::DBusObjectPathString & value)
{
    if (TestPropReadWriteObjectPath_setHandler(value)) {
        Glib::Variant<Glib::DBusObjectPathString> value_get =
            Glib::Variant<Glib::DBusObjectPathString>::create((TestPropReadWriteObjectPath_get()));

        emitSignal("TestPropReadWriteObjectPath", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteString_set(const Glib::ustring & value)
{
    if (TestPropReadWriteString_setHandler(value)) {
        Glib::Variant<Glib::ustring> value_get =
            Glib::Variant<Glib::ustring>::create((TestPropReadWriteString_get()));

        emitSignal("TestPropReadWriteString", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteDouble_set(double value)
{
    if (TestPropReadWriteDouble_setHandler(value)) {
        Glib::Variant<double> value_get =
            Glib::Variant<double>::create((TestPropReadWriteDouble_get()));

        emitSignal("TestPropReadWriteDouble", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteUInt64_set(guint64 value)
{
    if (TestPropReadWriteUInt64_setHandler(value)) {
        Glib::Variant<guint64> value_get =
            Glib::Variant<guint64>::create((TestPropReadWriteUInt64_get()));

        emitSignal("TestPropReadWriteUInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteInt64_set(gint64 value)
{
    if (TestPropReadWriteInt64_setHandler(value)) {
        Glib::Variant<gint64> value_get =
            Glib::Variant<gint64>::create((TestPropReadWriteInt64_get()));

        emitSignal("TestPropReadWriteInt64", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteUInt_set(guint32 value)
{
    if (TestPropReadWriteUInt_setHandler(value)) {
        Glib::Variant<guint32> value_get =
            Glib::Variant<guint32>::create((TestPropReadWriteUInt_get()));

        emitSignal("TestPropReadWriteUInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteInt_set(gint32 value)
{
    if (TestPropReadWriteInt_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropReadWriteInt_get()));

        emitSignal("TestPropReadWriteInt", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteUInt16_set(guint16 value)
{
    if (TestPropReadWriteUInt16_setHandler(value)) {
        Glib::Variant<guint16> value_get =
            Glib::Variant<guint16>::create((TestPropReadWriteUInt16_get()));

        emitSignal("TestPropReadWriteUInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteInt16_set(gint16 value)
{
    if (TestPropReadWriteInt16_setHandler(value)) {
        Glib::Variant<gint16> value_get =
            Glib::Variant<gint16>::create((TestPropReadWriteInt16_get()));

        emitSignal("TestPropReadWriteInt16", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteChar_set(guchar value)
{
    if (TestPropReadWriteChar_setHandler(value)) {
        Glib::Variant<guchar> value_get =
            Glib::Variant<guchar>::create((TestPropReadWriteChar_get()));

        emitSignal("TestPropReadWriteChar", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropReadWriteBoolean_set(bool value)
{
    if (TestPropReadWriteBoolean_setHandler(value)) {
        Glib::Variant<bool> value_get =
            Glib::Variant<bool>::create((TestPropReadWriteBoolean_get()));

        emitSignal("TestPropReadWriteBoolean", value_get);
        return true;
    }

    return false;
}

bool org::gdbus::codegen::glibmm::TestStub::TestPropInternalReadWritePropertyChange_set(gint32 value)
{
    if (TestPropInternalReadWritePropertyChange_setHandler(value)) {
        Glib::Variant<gint32> value_get =
            Glib::Variant<gint32>::create((TestPropInternalReadWritePropertyChange_get()));

        emitSignal("TestPropInternalReadWritePropertyChange", value_get);
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
