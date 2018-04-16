#include "teststubmain.h"
#include "tools.h"
#include <iostream>


TestImpl::TestImpl() {
    m_PropReadByteStringArrayValue.push_back("Value1");
    m_PropReadByteStringArrayValue.push_back("Value2");
    m_PropReadObjectPathArrayValue.push_back("Value3");
    m_PropReadObjectPathArrayValue.push_back("Value4");
    m_PropReadStringArrayValue.push_back("Value5");
    m_PropReadStringArrayValue.push_back("Value6");
    m_PropReadByteStringValue = "Value7";
    m_PropReadSignatureValue = "Value8";
    m_PropReadObjectPathValue = "Value9";
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
    m_PropWriteObjectPathArratValue.push_back("Value13");
    m_PropWriteObjectPathArratValue.push_back("Value14");
    m_PropWriteObjectPathArratValue.push_back("Value15");
    m_PropWriteStringArrayValue.push_back("Value16");
    m_PropWriteByteStringValue = "Value17";
    m_PropWriteSignatureValue = "Value18";
    m_PropWriteObjectPathValue = "Value19";
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
    m_PropReadWriteSignatureValue = "Value26";
    m_PropReadWriteObjectPathValue = "Value27";
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

void TestImpl::TestVariant(Glib::VariantBase Param1, TestMessageHelper invocation)
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

void TestImpl::TestByteStringArray (
        std::vector<std::string>  Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestObjectPathArray (
        std::vector<std::string>  Param1,
        TestMessageHelper invocation) {

    std::vector<Glib::VariantBase> list;
    GVariantBuilder builder;
    g_variant_builder_init (&builder, G_VARIANT_TYPE("ao"));
    for (int i = 0; i < Param1.size(); i++) {
        g_variant_builder_add (&builder, "o", Param1[i].c_str());
    }
    Glib::VariantBase ret = Glib::wrap(g_variant_builder_end (&builder));

    invocation.ret(ret);
}

void TestImpl::TestStringArray (
        std::vector<std::string>  Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestByteString (
        std::string Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestSignature (
        std::string Param1,
        TestMessageHelper invocation) {
    invocation.ret(Glib::wrap(g_variant_new_signature(Param1.c_str())));
}

void TestImpl::TestObjectPath (
        std::string Param1,
        TestMessageHelper invocation) {
    invocation.ret(Glib::wrap(g_variant_new_object_path(Param1.c_str())));
}

void TestImpl::TestString (
        std::string Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestDouble (
        double Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt64 (
        guint64 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt64 (
        gint64 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt (
        guint32 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt (
        gint32 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestUInt16 (
        guint16 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestInt16 (
        gint16 Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestChar (
        guchar Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestBoolean (
        bool Param1,
        TestMessageHelper invocation) {
    invocation.ret(Param1);
}

void TestImpl::TestAll (
        std::vector<std::string>  in_Param1,
        std::vector<std::string>  in_Param2,
        std::vector<std::string>  in_Param3,
        std::string in_Param4,
        std::string in_Param5,
        std::string in_Param6,
        std::string in_Param7,
        double in_Param8,
        guint64 in_Param9,
        gint64 in_Param10,
        guint32 in_Param11,
        gint32 in_Param12,
        guint16 in_Param13,
        gint16 in_Param14,
        guchar in_Param15,
        bool in_Param16,
        TestMessageHelper invocation) {}

void TestImpl::TestTriggerInternalPropertyChange(gint32 newValue,
                                                 TestMessageHelper invocation) {
    TestPropInternalReadPropertyChange_set (newValue);
    TestPropInternalReadWritePropertyChange_set (newValue);
    invocation.ret();
}

std::vector<std::string>  TestImpl::TestPropReadByteStringArray_get() {return m_PropReadByteStringArrayValue;}
std::vector<std::string>  TestImpl::TestPropReadObjectPathArray_get() {return m_PropReadObjectPathArrayValue;}
std::vector<std::string>  TestImpl::TestPropReadStringArray_get() {return m_PropReadStringArrayValue;}
std::string TestImpl::TestPropReadByteString_get() {return m_PropReadByteStringValue;}
std::string TestImpl::TestPropReadSignature_get() {return m_PropReadSignatureValue;}
std::string TestImpl::TestPropReadObjectPath_get() {return m_PropReadObjectPathValue;}
std::string TestImpl::TestPropReadString_get() {return m_PropReadStringValue;}
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
std::vector<std::string>  TestImpl::TestPropWriteObjectPathArray_get() {return m_PropWriteObjectPathArratValue;}
std::vector<std::string>  TestImpl::TestPropWriteStringArray_get() {return m_PropWriteStringArrayValue;}
std::string TestImpl::TestPropWriteByteString_get() {return m_PropWriteByteStringValue;}
std::string TestImpl::TestPropWriteSignature_get() {return m_PropWriteSignatureValue;}
std::string TestImpl::TestPropWriteObjectPath_get() {return m_PropWriteObjectPathValue;}
std::string TestImpl::TestPropWriteString_get() {return m_PropWriteStringValue;}
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
std::vector<std::string>  TestImpl::TestPropReadWriteObjectPathArray_get() {return m_PropReadWriteObjectPathArrayValue;}
std::vector<std::string>  TestImpl::TestPropReadWriteStringArray_get() {return m_PropReadWriteStringArrayValue;}
std::string TestImpl::TestPropReadWriteByteString_get() {return m_PropReadWriteByteStringValue;}
std::string TestImpl::TestPropReadWriteSignature_get() {return m_PropReadWriteSignatureValue;}
std::string TestImpl::TestPropReadWriteObjectPath_get() {return m_PropReadWriteObjectPathValue;}
std::string TestImpl::TestPropReadWriteString_get() {return m_PropReadWriteStringValue;}
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
bool TestImpl::TestPropWriteByteStringArray_setHandler(std::vector<std::string>  value) {
    return false;
}
bool TestImpl::TestPropWriteObjectPathArray_setHandler(std::vector<std::string>  value) {
    return false;
}
bool TestImpl::TestPropWriteStringArray_setHandler(std::vector<std::string>  value) {
    return false;
}
bool TestImpl::TestPropWriteByteString_setHandler(std::string value) {
    return false;
}
bool TestImpl::TestPropWriteSignature_setHandler(std::string value) {
    return false;
}
bool TestImpl::TestPropWriteObjectPath_setHandler(std::string value) {
    return false;
}
bool TestImpl::TestPropWriteString_setHandler(std::string value) {
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

bool TestImpl::TestPropReadWriteByteStringArray_setHandler(std::vector<std::string>  value) {
    m_PropReadWriteByteStringArrayValue = value;
    TestSignalByteStringArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteObjectPathArray_setHandler(std::vector<std::string>  value) {
    m_PropReadWriteObjectPathArrayValue = value;
    TestSignalObjectPathArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteStringArray_setHandler(std::vector<std::string>  value) {
    m_PropReadWriteStringArrayValue = value;
    TestSignalStringArray_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteByteString_setHandler(std::string value) {
    m_PropReadWriteByteStringValue = value;
    TestSignalByteString_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteSignature_setHandler(std::string value) {
    m_PropReadWriteSignatureValue = value;
    TestSignalSignature_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteObjectPath_setHandler(std::string value) {
    m_PropReadWriteObjectPathValue = value;
    TestSignalObjectPath_signal.emit(value);
    return true;
}
bool TestImpl::TestPropReadWriteString_setHandler(std::string value) {
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
