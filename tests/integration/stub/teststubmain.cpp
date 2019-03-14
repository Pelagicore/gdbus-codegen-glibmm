#include "teststubmain.h"
#include "tools.h"
#include <iostream>


TestImpl::TestImpl() {
    m_PropReadByteStringArrayValue.push_back("Value1");
    m_PropReadByteStringArrayValue.push_back("Value2");
    m_PropReadObjectPathArrayValue.push_back("/Value3");
    m_PropReadObjectPathArrayValue.push_back("/Value4");
    m_PropReadStringArrayValue.push_back("Value5");
    m_PropReadStringArrayValue.push_back("Value6");
    m_PropReadByteStringValue = "Value7";
    m_PropReadSignatureValue = "sa{sv}a(bi)";
    m_PropReadObjectPathValue = "/Value9";
    m_PropReadStringValue = "Value10";
    m_PropReadDoubleValue = 1337;
    m_PropReadUInt64Value = 1338;
    m_PropReadInt64Value = 1339;
    m_PropReadUIntValue = 1340;
    m_PropReadIntValue = 1341;
    m_PropReadUInt16Value = 1342;
    m_PropReadInt16Value = 1343;
    m_PropReadCharValue = 'A';
    m_PropReadBooleanValue = true;
    m_PropWriteByteStringArrayValue.push_back("Value11");
    m_PropWriteByteStringArrayValue.push_back("Value12");
    m_PropWriteObjectPathArratValue.push_back("/Value13");
    m_PropWriteObjectPathArratValue.push_back("/Value14");
    m_PropWriteObjectPathArratValue.push_back("/Value15");
    m_PropWriteStringArrayValue.push_back("Value16");
    m_PropWriteByteStringValue = "Value17";
    m_PropWriteSignatureValue = "Value18";
    m_PropWriteObjectPathValue = "/Value19";
    m_PropWriteStringValue = "Value20";
    m_PropWriteDoubleValue = 1344;
    m_PropWriteUInt64Value = 1345;
    m_PropWriteInt64Value = 1346;
    m_PropWriteUIntValue = 1347;
    m_PropWriteIntValue = 1348;
    m_PropWriteUInt16Value = 1349;
    m_PropWriteInt16Value = 1350;
    m_PropWriteCharValue = 'B';
    m_PropWriteBooleanValue = false;
    m_PropReadWriteByteStringArrayValue.push_back("Value21");
    m_PropReadWriteByteStringArrayValue.push_back("Value22");
    m_PropReadWriteObjectPathArrayValue.push_back("/object/path");
    m_PropReadWriteStringArrayValue.push_back("Value24");
    m_PropReadWriteByteStringValue = "Value25";
    m_PropReadWriteSignatureValue = "bada(ss)";
    m_PropReadWriteObjectPathValue = "/Value27";
    m_PropReadWriteStringValue = "Value28";
    m_PropReadWriteDoubleValue = 1351;
    m_PropReadWriteUInt64Value = 1352;
    m_PropReadWriteInt64Value = 1353;
    m_PropReadWriteUIntValue = 1354;
    m_PropReadWriteIntValue = 1355;
    m_PropReadWriteUInt16Value = 1356;
    m_PropReadWriteInt16Value = 1357;
    m_PropReadWriteCharValue = 'C';
    m_PropReadWriteBooleanValue= true;
}

void TestImpl::TestStringVariantDict(const std::map<Glib::ustring,Glib::VariantBase> &Param1,
                                     MethodInvocation &invocation)
{
    invocation.ret(Param1);
}

void TestImpl::TestStringStringDict(const std::map<Glib::ustring,Glib::ustring> &Param1,
                                    MethodInvocation &invocation)
{
    invocation.ret(Param1);
}

void TestImpl::TestUintIntDict(const std::map<guint32,gint32> &Param1,
                               MethodInvocation &invocation)
{
    invocation.ret(Param1);
}

void TestImpl::TestVariant(const Glib::VariantBase &Param1, MethodInvocation &invocation)
{
    std::string value;
    try {
        Glib::Variant<Glib::ustring> res = Glib::VariantBase::cast_dynamic< Glib::Variant<Glib::ustring> >(Param1);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cout << e.what() << std::endl;
    }

    Glib::Variant<Glib::Variant<Glib::ustring> > variantValue;
    variantValue = Glib::Variant<Glib::Variant<Glib::ustring> >::create(Glib::Variant<Glib::ustring>::create(value));

    invocation.ret(variantValue);
}

void TestImpl::TestVariant2(const Glib::ustring &Param1,
                            const Glib::VariantBase &Param2,
                            MethodInvocation &invocation)
{
    std::string value;
    try {
        Glib::Variant<Glib::ustring> res = Glib::VariantBase::cast_dynamic< Glib::Variant<Glib::ustring> >(Param2);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cout << e.what() << std::endl;
    }

    Glib::Variant<Glib::Variant<Glib::ustring> > variantValue;
    variantValue = Glib::Variant<Glib::Variant<Glib::ustring> >::create(Glib::Variant<Glib::ustring>::create(value));

    invocation.ret(Param1, variantValue);
}

void TestImpl::TestByteStringArray (
        const std::vector<std::string> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestObjectPathArray (
        const std::vector<Glib::DBusObjectPathString> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestStringArray (
        const std::vector<Glib::ustring> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestStruct(
        const std::tuple<Glib::ustring,Glib::ustring> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestStructArray (
        const std::vector<std::tuple<guint32,Glib::ustring,gint32>> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestDictStructArray (
        const std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestByteString (
        const std::string &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestSignature (
        const Glib::DBusSignatureString &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestObjectPath (
        const Glib::DBusObjectPathString &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestString (
        const Glib::ustring &Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestDouble (
        double Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt64 (
        guint64 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt64 (
        gint64 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt (
        guint32 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt (
        gint32 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt16 (
        guint16 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt16 (
        gint16 Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestChar (
        guchar Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestBoolean (
        bool Param1,
        MethodInvocation &invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestAll (
        const std::vector<std::string> &in_Param1,
        const std::vector<Glib::DBusObjectPathString> &in_Param2,
        const std::vector<Glib::ustring> &in_Param3,
        const std::string &in_Param4,
        const Glib::DBusSignatureString &in_Param5,
        const Glib::DBusObjectPathString &in_Param6,
        const Glib::ustring &in_Param7,
        double in_Param8,
        guint64 in_Param9,
        gint64 in_Param10,
        guint32 in_Param11,
        gint32 in_Param12,
        guint16 in_Param13,
        gint16 in_Param14,
        guchar in_Param15,
        bool in_Param16,
        MethodInvocation &invocation) {}

void TestImpl::TestTriggerInternalPropertyChange(gint32 newValue,
                                                 MethodInvocation &invocation) {
    TestPropInternalReadPropertyChange_set (newValue);
    TestPropInternalReadWritePropertyChange_set (newValue);
    invocation.ret();
}

void TestImpl::TestError(MethodInvocation &invocation) {
    using namespace org::gdbus::codegen::glibmm;
    invocation.ret(Error(Error::InvalidParams, "Testing error message"));
}

std::vector<std::string>  TestImpl::TestPropReadByteStringArray_get() {return m_PropReadByteStringArrayValue;}
std::vector<Glib::DBusObjectPathString>  TestImpl::TestPropReadObjectPathArray_get() {return m_PropReadObjectPathArrayValue;}
std::vector<Glib::ustring>  TestImpl::TestPropReadStringArray_get() {return m_PropReadStringArrayValue;}
std::string TestImpl::TestPropReadByteString_get() {return m_PropReadByteStringValue;}
Glib::DBusSignatureString TestImpl::TestPropReadSignature_get() {return m_PropReadSignatureValue;}
Glib::DBusObjectPathString TestImpl::TestPropReadObjectPath_get() {return m_PropReadObjectPathValue;}
Glib::ustring TestImpl::TestPropReadString_get() {return m_PropReadStringValue;}
double TestImpl::TestPropReadDouble_get() {return m_PropReadDoubleValue;}
guint64 TestImpl::TestPropReadUInt64_get() {return m_PropReadUInt64Value;}
gint64 TestImpl::TestPropReadInt64_get() {return m_PropReadInt64Value;}
guint32 TestImpl::TestPropReadUInt_get() {return m_PropReadUIntValue;}
gint32 TestImpl::TestPropReadInt_get() {return m_PropReadIntValue;}
guint16 TestImpl::TestPropReadUInt16_get() {return m_PropReadUInt16Value;}
gint16 TestImpl::TestPropReadInt16_get() {return m_PropReadInt16Value;}
guchar TestImpl::TestPropReadChar_get() {return m_PropReadCharValue;}
bool TestImpl::TestPropReadBoolean_get() {return m_PropReadBooleanValue;}
std::vector<std::string>  TestImpl::TestPropWriteByteStringArray_get() {return m_PropWriteByteStringArrayValue;}
std::vector<Glib::DBusObjectPathString>  TestImpl::TestPropWriteObjectPathArray_get() {return m_PropWriteObjectPathArratValue;}
std::vector<Glib::ustring>  TestImpl::TestPropWriteStringArray_get() {return m_PropWriteStringArrayValue;}
std::string TestImpl::TestPropWriteByteString_get() {return m_PropWriteByteStringValue;}
Glib::DBusSignatureString TestImpl::TestPropWriteSignature_get() {return m_PropWriteSignatureValue;}
Glib::DBusObjectPathString TestImpl::TestPropWriteObjectPath_get() {return m_PropWriteObjectPathValue;}
Glib::ustring TestImpl::TestPropWriteString_get() {return m_PropWriteStringValue;}
double TestImpl::TestPropWriteDouble_get() {return m_PropWriteDoubleValue;}
guint64 TestImpl::TestPropWriteUInt64_get() {return m_PropWriteUInt64Value;}
gint64 TestImpl::TestPropWriteInt64_get() {return m_PropWriteInt64Value;}
guint32 TestImpl::TestPropWriteUInt_get() {return m_PropWriteUIntValue;}
gint32 TestImpl::TestPropWriteInt_get() {return m_PropWriteIntValue;}
guint16 TestImpl::TestPropWriteUInt16_get() {return m_PropWriteUInt16Value;}
gint16 TestImpl::TestPropWriteInt16_get() {return m_PropWriteInt16Value;}
guchar TestImpl::TestPropWriteChar_get() {return m_PropWriteCharValue;}
bool TestImpl::TestPropWriteBoolean_get() {return m_PropWriteBooleanValue;}
std::vector<std::string>  TestImpl::TestPropReadWriteByteStringArray_get() {return m_PropReadWriteByteStringArrayValue;}
std::vector<Glib::DBusObjectPathString> TestImpl::TestPropReadWriteObjectPathArray_get() {return m_PropReadWriteObjectPathArrayValue;}
std::vector<Glib::ustring> TestImpl::TestPropReadWriteStringArray_get() {return m_PropReadWriteStringArrayValue;}
std::string TestImpl::TestPropReadWriteByteString_get() {return m_PropReadWriteByteStringValue;}
Glib::DBusSignatureString TestImpl::TestPropReadWriteSignature_get() {return m_PropReadWriteSignatureValue;}
Glib::DBusObjectPathString TestImpl::TestPropReadWriteObjectPath_get() {return m_PropReadWriteObjectPathValue;}
Glib::ustring TestImpl::TestPropReadWriteString_get() {return m_PropReadWriteStringValue;}
double TestImpl::TestPropReadWriteDouble_get() {return m_PropReadWriteDoubleValue;}
guint64 TestImpl::TestPropReadWriteUInt64_get() {return m_PropReadWriteUInt64Value;}
gint64 TestImpl::TestPropReadWriteInt64_get() {return m_PropReadWriteInt64Value;}
guint32 TestImpl::TestPropReadWriteUInt_get() {return m_PropReadWriteUIntValue;}
gint32 TestImpl::TestPropReadWriteInt_get() {return m_PropReadWriteIntValue;}
guint16 TestImpl::TestPropReadWriteUInt16_get() {return m_PropReadWriteUInt16Value;}
gint16 TestImpl::TestPropReadWriteInt16_get() {return m_PropReadWriteInt16Value;}
guchar TestImpl::TestPropReadWriteChar_get() {return m_PropReadWriteCharValue;}
bool TestImpl::TestPropReadWriteBoolean_get() {return m_PropReadWriteBooleanValue;}
gint32 TestImpl::TestPropInternalReadPropertyChange_get() {return m_TestPropInternalReadPropertyChangeValue;}
gint32 TestImpl::TestPropInternalReadWritePropertyChange_get() {return m_TestPropInternalReadWritePropertyChangeValue;}

/* These are not used, so we just return a dummy value here */
bool TestImpl::TestPropWriteByteStringArray_setHandler(const std::vector<std::string> &value) {
    return false;
}
bool TestImpl::TestPropWriteObjectPathArray_setHandler(const std::vector<Glib::DBusObjectPathString> &value) {
    return false;
}
bool TestImpl::TestPropWriteStringArray_setHandler(const std::vector<Glib::ustring> &value) {
    return false;
}
bool TestImpl::TestPropWriteByteString_setHandler(const std::string &value) {
    return false;
}
bool TestImpl::TestPropWriteSignature_setHandler(const Glib::DBusSignatureString &value) {
    return false;
}
bool TestImpl::TestPropWriteObjectPath_setHandler(const Glib::DBusObjectPathString &value) {
    return false;
}
bool TestImpl::TestPropWriteString_setHandler(const Glib::ustring &value) {
    return false;
}
bool TestImpl::TestPropWriteDouble_setHandler(double value) {
    return false;
}
bool TestImpl::TestPropWriteUInt64_setHandler(guint64 value) {
    return false;
}
bool TestImpl::TestPropWriteInt64_setHandler(gint64 value) {
    return false;
}
bool TestImpl::TestPropWriteUInt_setHandler(guint32 value) {
    return false;
}
bool TestImpl::TestPropWriteInt_setHandler(gint32 value) {
    return false;
}
bool TestImpl::TestPropWriteUInt16_setHandler(guint16 value) {
    return false;
}
bool TestImpl::TestPropWriteInt16_setHandler(gint16 value) {
    return false;
}
bool TestImpl::TestPropWriteChar_setHandler(guchar value) {
    return false;
}
bool TestImpl::TestPropWriteBoolean_setHandler(bool value) {
    return false;
}
/* End return dummy value warning */

bool TestImpl::TestPropReadWriteByteStringArray_setHandler(const std::vector<std::string> &value) {
    m_PropReadWriteByteStringArrayValue = value;
    TestSignalByteStringArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteObjectPathArray_setHandler(const std::vector<Glib::DBusObjectPathString> &value) {
    m_PropReadWriteObjectPathArrayValue = value;
    TestSignalObjectPathArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteStringArray_setHandler(const std::vector<Glib::ustring> &value) {
    m_PropReadWriteStringArrayValue = value;
    TestSignalStringArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteByteString_setHandler(const std::string &value) {
    m_PropReadWriteByteStringValue = value;
    TestSignalByteString_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteSignature_setHandler(const Glib::DBusSignatureString &value) {
    m_PropReadWriteSignatureValue = value;
    TestSignalSignature_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteObjectPath_setHandler(const Glib::DBusObjectPathString &value) {
    m_PropReadWriteObjectPathValue = value;
    TestSignalObjectPath_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteString_setHandler(const Glib::ustring &value) {
    m_PropReadWriteStringValue = value;
    TestSignalString_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteDouble_setHandler(double value) {
    m_PropReadWriteDoubleValue = value;
    TestSignalDouble_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteUInt64_setHandler(guint64 value) {
    m_PropReadWriteUInt64Value = value;
    TestSignalUInt64_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteInt64_setHandler(gint64 value) {
    m_PropReadWriteInt64Value = value;
    TestSignalInt64_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteUInt_setHandler(guint32 value) {
    m_PropReadWriteUIntValue = value;
    TestSignalUInt_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteInt_setHandler(gint32 value) {
    m_PropReadWriteIntValue = value;
    TestSignalInt_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteUInt16_setHandler(guint16 value) {
    m_PropReadWriteUInt16Value = value;
    TestSignalUInt16_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteInt16_setHandler(gint16 value) {
    m_PropReadWriteInt16Value = value;
    TestSignalInt16_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteChar_setHandler(guchar value) {
    m_PropReadWriteCharValue = value;
    TestSignalChar_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteBoolean_setHandler(bool value) {
    m_PropReadWriteBooleanValue = value;
    TestSignalBoolean_signal.emit(value);
    return true;
}

bool TestImpl::TestPropInternalReadPropertyChange_setHandler(gint32 value) {
    m_TestPropInternalReadPropertyChangeValue = value;
    return true;
}

bool TestImpl::TestPropInternalReadWritePropertyChange_setHandler(gint32 value) {
    m_TestPropInternalReadWritePropertyChangeValue = value;
    return true;
}

int main() {
    Glib::init();
    Gio::init();

    TestImpl impl;
    impl.connect(Gio::DBus::BUS_TYPE_SESSION,
                     "org.gdbus.codegen.glibmm.Test");

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
