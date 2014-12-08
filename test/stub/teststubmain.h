#include "many-types_stub.h"

class TestImpl : public org::gdbus::codegen::glibmm::Test {
public:
    TestImpl();

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
    std::vector<std::string>  TestPropReadObjectPathArray_get();
    std::vector<std::string>  TestPropReadStringArray_get();
    std::string TestPropReadByteString_get();
    std::string TestPropReadSignature_get();
    std::string TestPropReadObjectPath_get();
    std::string TestPropReadString_get();
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
    std::vector<std::string>  TestPropWriteObjectPathArray_get();
    std::vector<std::string>  TestPropWriteStringArray_get();
    std::string TestPropWriteByteString_get();
    std::string TestPropWriteSignature_get();
    std::string TestPropWriteObjectPath_get();
    std::string TestPropWriteString_get();
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
    std::vector<std::string>  TestPropReadWriteObjectPathArray_get();
    std::vector<std::string>  TestPropReadWriteStringArray_get();
    std::string TestPropReadWriteByteString_get();
    std::string TestPropReadWriteSignature_get();
    std::string TestPropReadWriteObjectPath_get();
    std::string TestPropReadWriteString_get();
    double TestPropReadWriteDouble_get();
    guint64 TestPropReadWriteUInt64_get();
    gint64 TestPropReadWriteInt64_get();
    guint32 TestPropReadWriteUInt_get();
    gint32 TestPropReadWriteInt_get();
    guint16 TestPropReadWriteUInt16_get();
    gint16 TestPropReadWriteInt16_get();
    guchar TestPropReadWriteChar_get();
    bool TestPropReadWriteBoolean_get();


void TestPropReadByteStringArray_set(std::vector<std::string>  value);
void TestPropReadObjectPathArray_set(std::vector<std::string>  value);
void TestPropReadStringArray_set(std::vector<std::string>  value);
void TestPropReadByteString_set(std::string value);
void TestPropReadSignature_set(std::string value);
void TestPropReadObjectPath_set(std::string value);
void TestPropReadString_set(std::string value);
void TestPropReadDouble_set(double value);
void TestPropReadUInt64_set(guint64 value);
void TestPropReadInt64_set(gint64 value);
void TestPropReadUInt_set(guint32 value);
void TestPropReadInt_set(gint32 value);
void TestPropReadUInt16_set(guint16 value);
void TestPropReadInt16_set(gint16 value);
void TestPropReadChar_set(guchar value);
void TestPropReadBoolean_set(bool value);
void TestPropWriteByteStringArray_set(std::vector<std::string>  value);
void TestPropWriteObjectPathArray_set(std::vector<std::string>  value);
void TestPropWriteStringArray_set(std::vector<std::string>  value);
void TestPropWriteByteString_set(std::string value);
void TestPropWriteSignature_set(std::string value);
void TestPropWriteObjectPath_set(std::string value);
void TestPropWriteString_set(std::string value);
void TestPropWriteDouble_set(double value);
void TestPropWriteUInt64_set(guint64 value);
void TestPropWriteInt64_set(gint64 value);
void TestPropWriteUInt_set(guint32 value);
void TestPropWriteInt_set(gint32 value);
void TestPropWriteUInt16_set(guint16 value);
void TestPropWriteInt16_set(gint16 value);
void TestPropWriteChar_set(guchar value);
void TestPropWriteBoolean_set(bool value);
void TestPropReadWriteByteStringArray_set(std::vector<std::string>  value);
void TestPropReadWriteObjectPathArray_set(std::vector<std::string>  value);
void TestPropReadWriteStringArray_set(std::vector<std::string>  value);
void TestPropReadWriteByteString_set(std::string value);
void TestPropReadWriteSignature_set(std::string value);
void TestPropReadWriteObjectPath_set(std::string value);
void TestPropReadWriteString_set(std::string value);
void TestPropReadWriteDouble_set(double value);
void TestPropReadWriteUInt64_set(guint64 value);
void TestPropReadWriteInt64_set(gint64 value);
void TestPropReadWriteUInt_set(guint32 value);
void TestPropReadWriteInt_set(gint32 value);
void TestPropReadWriteUInt16_set(guint16 value);
void TestPropReadWriteInt16_set(gint16 value);
void TestPropReadWriteChar_set(guchar value);
void TestPropReadWriteBoolean_set(bool value);


private:
std::vector<std::string> m_PropReadByteStringArrayValue;
std::vector<std::string> m_PropReadObjectPathArrayValue;
std::vector<std::string> m_PropReadStringArrayValue;
std::string m_PropReadByteStringValue;
std::string m_PropReadSignatureValue;
std::string m_PropReadObjectPathValue;
std::string m_PropReadStringValue;
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
std::vector<std::string> m_PropWriteObjectPathArratValue;
std::vector<std::string> m_PropWriteStringArrayValue;
std::string m_PropWriteByteStringValue;
std::string m_PropWriteSignatureValue;
std::string m_PropWriteObjectPathValue;
std::string m_PropWriteStringValue;
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
std::vector<std::string> m_PropReadWriteObjectPathArrayValue;
std::vector<std::string> m_PropReadWriteStringArrayValue;
std::string m_PropReadWriteByteStringValue;
std::string m_PropReadWriteSignatureValue;
std::string m_PropReadWriteObjectPathValue;
std::string m_PropReadWriteStringValue;
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
