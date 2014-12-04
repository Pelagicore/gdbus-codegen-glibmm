#include "teststubmain.h"
#include "tools.h"

void TestImpl::TestByteStringArray (
        std::vector<std::string>  Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Param1, invocation);
}

void TestImpl::TestObjectPathArray (
        std::vector<std::string>  Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (CodegenTools::stdStringVecToGlibStringVec(Param1), invocation);
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
    CodegenTools::retSingle (Glib::ustring(Param1), invocation);
}

void TestImpl::TestObjectPath (
        std::string Param1,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
    CodegenTools::retSingle (Glib::ustring(Param1), invocation);
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
std::vector<Glib::ustring>  TestImpl::TestPropReadObjectPathArray_get() {return m_PropReadObjectPathArrayValue;}
std::vector<Glib::ustring>  TestImpl::TestPropReadStringArray_get() {return m_PropReadStringArrayValue;}
std::string TestImpl::TestPropReadByteString_get() {return m_PropReadByteStringValue;}
Glib::ustring TestImpl::TestPropReadSignature_get() {return m_PropReadSignatureValue;}
Glib::ustring TestImpl::TestPropReadObjectPath_get() {return m_PropReadObjectPathValue;}
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
std::vector<Glib::ustring>  TestImpl::TestPropWriteObjectPathArray_get() {return m_PropWriteObjectPathArratValue;}
std::vector<Glib::ustring>  TestImpl::TestPropWriteStringArray_get() {return m_PropWriteStringArrayValue;}
std::string TestImpl::TestPropWriteByteString_get() {return m_PropWriteByteStringValue;}
Glib::ustring TestImpl::TestPropWriteSignature_get() {return m_PropWriteSignatureValue;}
Glib::ustring TestImpl::TestPropWriteObjectPath_get() {return m_PropWriteObjectPathValue;}
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
std::vector<Glib::ustring>  TestImpl::TestPropReadWriteObjectPathArray_get() {return m_PropReadWriteObjectPathArrayValue;}
std::vector<Glib::ustring>  TestImpl::TestPropReadWriteStringArray_get() {return m_PropReadWriteStringArrayValue;}
std::string TestImpl::TestPropReadWriteByteString_get() {return m_PropReadWriteByteStringValue;}
Glib::ustring TestImpl::TestPropReadWriteSignature_get() {return m_PropReadWriteSignatureValue;}
Glib::ustring TestImpl::TestPropReadWriteObjectPath_get() {return m_PropReadWriteObjectPathValue;}
Glib::ustring TestImpl::TestPropReadWriteString_get() {return m_PropReadWriteStringValue;}
double TestImpl::TestPropReadWriteDouble_get() {return m_PropReadWriteDoubleValue;}
guint64 TestImpl::TestPropReadWriteUInt64_get() {return m_PropReadWriteUInt64Value;}
gint64 TestImpl::TestPropReadWriteInt64_get() {return m_PropReadWriteInt64Value;}
guint32 TestImpl::TestPropReadWriteUInt_get() {return m_PropReadWriteUIntValue;}
gint32 TestImpl::TestPropReadWriteInt_get() {return m_PropReadWriteIntValue;}
guint16 TestImpl::TestPropReadWriteUInt16_get() {return m_PropReadUInt16Value;}
gint16 TestImpl::TestPropReadWriteInt16_get() {return m_PropReadWriteInt16Value;}
guchar TestImpl::TestPropReadWriteChar_get() {return m_PropReadWriteCharValue;}
bool TestImpl::TestPropReadWriteBoolean_get() {return m_PropReadWriteWriteBooleanValue;}

int main() {
    Glib::init();
    Gio::init();

    TestImpl impl;
    impl.connect(Gio::DBus::BUS_TYPE_SESSION,
                     "org.gdbus.codegen.glibmm.Test");

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
