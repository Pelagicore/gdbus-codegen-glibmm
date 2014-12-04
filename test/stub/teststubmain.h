#include "many-types_stub.h"

class TestImpl : public org::gdbus::codegen::glibmm::Test {
    void TestByteStringArray (
            std::vector<std::string>  Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestObjectPathArray (
            std::vector<std::string>  Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestStringArray (
            std::vector<std::string>  Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestByteString (
            std::string Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestSignature (
            std::string Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestObjectPath (
            std::string Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestString (
            std::string Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestDouble (
            double Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestUInt64 (
            guint64 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestInt64 (
            gint64 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestUInt (
            guint32 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestInt (
            gint32 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestUInt16 (
            guint16 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestInt16 (
            gint16 Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestChar (
            guchar Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestBoolean (
            bool Param1,
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    void TestAll (
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
            const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);
    std::vector<std::string>  TestPropReadByteStringArray_get();
    std::vector<Glib::ustring>  TestPropReadObjectPathArray_get();
    std::vector<Glib::ustring>  TestPropReadStringArray_get();
    std::string TestPropReadByteString_get();
    Glib::ustring TestPropReadSignature_get();
    Glib::ustring TestPropReadObjectPath_get();
    Glib::ustring TestPropReadString_get();
    double TestPropReadDouble_get();
    guint64 TestPropReadUInt64_get();
    gint64 TestPropReadInt64_get();
    guint32 TestPropReadUInt_get();
    gint32 TestPropReadInt_get();
    guint16 TestPropReadUInt16_get();
    gint16 TestPropReadInt16_get();
    guchar TestPropReadChar_get();
    bool TestPropReadBoolean_get();
    std::vector<std::string>  TestPropWriteByteStringArray_get();
    std::vector<Glib::ustring>  TestPropWriteObjectPathArray_get();
    std::vector<Glib::ustring>  TestPropWriteStringArray_get();
    std::string TestPropWriteByteString_get();
    Glib::ustring TestPropWriteSignature_get();
    Glib::ustring TestPropWriteObjectPath_get();
    Glib::ustring TestPropWriteString_get();
    double TestPropWriteDouble_get();
    guint64 TestPropWriteUInt64_get();
    gint64 TestPropWriteInt64_get();
    guint32 TestPropWriteUInt_get();
    gint32 TestPropWriteInt_get();
    guint16 TestPropWriteUInt16_get();
    gint16 TestPropWriteInt16_get();
    guchar TestPropWriteChar_get();
    bool TestPropWriteBoolean_get();
    std::vector<std::string>  TestPropReadWriteByteStringArray_get();
    std::vector<Glib::ustring>  TestPropReadWriteObjectPathArray_get();
    std::vector<Glib::ustring>  TestPropReadWriteStringArray_get();
    std::string TestPropReadWriteByteString_get();
    Glib::ustring TestPropReadWriteSignature_get();
    Glib::ustring TestPropReadWriteObjectPath_get();
    Glib::ustring TestPropReadWriteString_get();
    double TestPropReadWriteDouble_get();
    guint64 TestPropReadWriteUInt64_get();
    gint64 TestPropReadWriteInt64_get();
    guint32 TestPropReadWriteUInt_get();
    gint32 TestPropReadWriteInt_get();
    guint16 TestPropReadWriteUInt16_get();
    gint16 TestPropReadWriteInt16_get();
    guchar TestPropReadWriteChar_get();
    bool TestPropReadWriteBoolean_get();

private:
std::vector<std::string> m_PropReadByteStringArrayValue;
std::vector<Glib::ustring> m_PropReadObjectPathArrayValue;
std::vector<Glib::ustring> m_PropReadStringArrayValue;
std::string m_PropReadByteStringValue;
Glib::ustring m_PropReadSignatureValue;
Glib::ustring m_PropReadObjectPathValue;
Glib::ustring m_PropReadStringValue;
double m_PropReadDoubleValue;
guint64 m_PropReadUInt64Value;
gint64 m_PropReadInt64Value;
guint32 m_PropReadUIntValue;
gint32 m_PropReadIntValue;
guint16 m_PropReadUInt16Value;
gint16 m_PropReadInt16Value;
guchar m_PropReadCharValue;
bool m_PropReadBooleanValue;
std::vector<std::string> m_PropWriteByteStringArrayValue;
std::vector<Glib::ustring> m_PropWriteObjectPathArratValue;
std::vector<Glib::ustring> m_PropWriteStringArrayValue;
std::string m_PropWriteByteStringValue;
Glib::ustring m_PropWriteSignatureValue;
Glib::ustring m_PropWriteObjectPathValue;
Glib::ustring m_PropWriteStringValue;
double m_PropWriteDoubleValue;
guint64 m_PropWriteUInt64Value;
gint64 m_PropWriteInt64Value;
guint32 m_PropWriteUIntValue;
gint32 m_PropWriteIntValue;
guint16 m_PropWriteUInt16Value;
gint16 m_PropWriteInt16Value;
guchar m_PropWriteCharValue;
bool m_PropWriteBooleanValue;
std::vector<std::string> m_PropReadWriteByteStringArrayValue;
std::vector<Glib::ustring> m_PropReadWriteObjectPathArrayValue;
std::vector<Glib::ustring> m_PropReadWriteStringArrayValue;
std::string m_PropReadWriteByteStringValue;
Glib::ustring m_PropReadWriteSignatureValue;
Glib::ustring m_PropReadWriteObjectPathValue;
Glib::ustring m_PropReadWriteStringValue;
double m_PropReadWriteDoubleValue;
guint64 m_PropReadWriteUInt64Value;
gint64 m_PropReadWriteInt64Value;
guint32 m_PropReadWriteUIntValue;
gint32 m_PropReadWriteIntValue;
guint16 m_PropReadWriteUInt16Value;
gint16 m_PropReadWriteInt16Value;
guchar m_PropReadWriteCharValue;
bool m_PropReadWriteWriteBooleanValue;
};
