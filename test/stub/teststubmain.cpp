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
    m_PropReadWriteObjectPathArrayValue.push_back("Value23");
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
    m_PropReadWriteWriteBooleanValue= true;
}

void TestImpl::TestByteStringArray (
        std::vector<std::string>  Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestObjectPathArray (
        std::vector<std::string>  Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {

    std::vector<Glib::VariantBase> list;
    GVariantBuilder builder;
    g_variant_builder_init (&builder, G_VARIANT_TYPE("ao"));
    for (int i = 0; i < Param1.size(); i++) {
        g_variant_builder_add (&builder, "o", Param1[i].c_str());
    }
    Glib::VariantBase ret = Glib::wrap(g_variant_builder_end (&builder));

    invocation->return_value(Glib::VariantContainerBase::create_tuple(ret));
}

void TestImpl::TestStringArray (
        std::vector<std::string>  Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (CodegenTools::stdStringVecToGlibStringVec(Param1), invocation);
}

void TestImpl::TestByteString (
        std::string Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestSignature (
        std::string Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingleRaw (Glib::wrap(g_variant_new_signature(Param1.c_str())), invocation);
}

void TestImpl::TestObjectPath (
        std::string Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingleRaw (Glib::wrap(g_variant_new_object_path(Param1.c_str())), invocation);
}

void TestImpl::TestString (
        std::string Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Glib::ustring(Param1), invocation);
}

void TestImpl::TestDouble (
        double Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestUInt64 (
        guint64 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestInt64 (
        gint64 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestUInt (
        guint32 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestInt (
        gint32 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestUInt16 (
        guint16 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestInt16 (
        gint16 Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestChar (
        guchar Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestBoolean (
        bool Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
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
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {}

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
bool TestImpl::TestPropReadWriteBoolean_get() {return m_PropReadWriteWriteBooleanValue;}

void TestImpl::TestPropWriteByteStringArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropWriteObjectPathArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropWriteStringArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropWriteByteString_set(std::string value) {}
void TestImpl::TestPropWriteSignature_set(std::string value) {}
void TestImpl::TestPropWriteObjectPath_set(std::string value) {}
void TestImpl::TestPropWriteString_set(std::string value) {}
void TestImpl::TestPropWriteDouble_set(double value) {}
void TestImpl::TestPropWriteUInt64_set(guint64 value) {}
void TestImpl::TestPropWriteInt64_set(gint64 value) {}
void TestImpl::TestPropWriteUInt_set(guint32 value) {}
void TestImpl::TestPropWriteInt_set(gint32 value) {}
void TestImpl::TestPropWriteUInt16_set(guint16 value) {}
void TestImpl::TestPropWriteInt16_set(gint16 value) {}
void TestImpl::TestPropWriteChar_set(guchar value) {}
void TestImpl::TestPropWriteBoolean_set(bool value) {}
void TestImpl::TestPropReadWriteByteStringArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropReadWriteObjectPathArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropReadWriteStringArray_set(std::vector<std::string>  value) {}
void TestImpl::TestPropReadWriteByteString_set(std::string value) {}
void TestImpl::TestPropReadWriteSignature_set(std::string value) {}
void TestImpl::TestPropReadWriteObjectPath_set(std::string value) {}

void TestImpl::TestPropReadWriteString_set(std::string value) {
    m_PropReadWriteStringValue = value;
}

void TestImpl::TestPropReadWriteDouble_set(double value) {}
void TestImpl::TestPropReadWriteUInt64_set(guint64 value) {}
void TestImpl::TestPropReadWriteInt64_set(gint64 value) {}
void TestImpl::TestPropReadWriteUInt_set(guint32 value) {}
void TestImpl::TestPropReadWriteInt_set(gint32 value) {}
void TestImpl::TestPropReadWriteUInt16_set(guint16 value) {}
void TestImpl::TestPropReadWriteInt16_set(gint16 value) {}
void TestImpl::TestPropReadWriteChar_set(guchar value) {}
void TestImpl::TestPropReadWriteBoolean_set(bool value) {}

int main() {
    Glib::init();
    Gio::init();

    TestImpl impl;
    impl.connect(Gio::DBus::BUS_TYPE_SESSION,
                     "org.gdbus.codegen.glibmm.Test");

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
