#include "many-types_stub.h"

class TestImpl : public org::gdbus::codegen::glibmm::Test {
public:
    TestImpl();

    void TestVariant (
            Glib::VariantBase Param1,
            TestMessageHelper invocation);
    void TestStringVariantDict(
            std::map<Glib::ustring,Glib::VariantBase> Param1,
            TestMessageHelper invocation) override;
    void TestStringStringDict(
            std::map<Glib::ustring,Glib::ustring> Param1,
            TestMessageHelper invocation) override;
    void TestUintIntDict(
            std::map<guint32,gint32> Param1,
            TestMessageHelper invocation) override;
    void TestByteStringArray (
            std::vector<std::string>  Param1,
            TestMessageHelper invocation);
    void TestObjectPathArray (
            std::vector<std::string>  Param1,
            TestMessageHelper invocation);
    void TestStringArray (
            std::vector<std::string>  Param1,
            TestMessageHelper invocation);
    void TestStruct(
            std::tuple<Glib::ustring,Glib::ustring> Param1,
            TestMessageHelper invocation);
    void TestStructArray (
            std::vector<std::tuple<guint32,Glib::ustring,gint32>> Param1,
            TestMessageHelper invocation);
    void TestDictStructArray (
            std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> Param1,
            TestMessageHelper invocation);
    void TestByteString (
            std::string Param1,
            TestMessageHelper invocation);
    void TestSignature (
            std::string Param1,
            TestMessageHelper invocation);
    void TestObjectPath (
            std::string Param1,
            TestMessageHelper invocation);
    void TestString (
            std::string Param1,
            TestMessageHelper invocation);
    void TestDouble (
            double Param1,
            TestMessageHelper invocation);
    void TestUInt64 (
            guint64 Param1,
            TestMessageHelper invocation);
    void TestInt64 (
            gint64 Param1,
            TestMessageHelper invocation);
    void TestUInt (
            guint32 Param1,
            TestMessageHelper invocation);
    void TestInt (
            gint32 Param1,
            TestMessageHelper invocation);
    void TestUInt16 (
            guint16 Param1,
            TestMessageHelper invocation);
    void TestInt16 (
            gint16 Param1,
            TestMessageHelper invocation);
    void TestChar (
            guchar Param1,
            TestMessageHelper invocation);
    void TestBoolean (
            bool Param1,
            TestMessageHelper invocation);
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
            TestMessageHelper invocation);
    void TestTriggerInternalPropertyChange(gint32 newValue,
                                           TestMessageHelper invocation);


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
    gint32 TestPropInternalReadPropertyChange_get();
    gint32 TestPropInternalReadWritePropertyChange_get();


bool TestPropWriteByteStringArray_setHandler(std::vector<std::string>  value);
bool TestPropWriteObjectPathArray_setHandler(std::vector<std::string>  value);
bool TestPropWriteStringArray_setHandler(std::vector<std::string>  value);
bool TestPropWriteByteString_setHandler(std::string value);
bool TestPropWriteSignature_setHandler(std::string value);
bool TestPropWriteObjectPath_setHandler(std::string value);
bool TestPropWriteString_setHandler(std::string value);
bool TestPropWriteDouble_setHandler(double value);
bool TestPropWriteUInt64_setHandler(guint64 value);
bool TestPropWriteInt64_setHandler(gint64 value);
bool TestPropWriteUInt_setHandler(guint32 value);
bool TestPropWriteInt_setHandler(gint32 value);
bool TestPropWriteUInt16_setHandler(guint16 value);
bool TestPropWriteInt16_setHandler(gint16 value);
bool TestPropWriteChar_setHandler(guchar value);
bool TestPropWriteBoolean_setHandler(bool value);
bool TestPropReadWriteByteStringArray_setHandler(std::vector<std::string>  value);
bool TestPropReadWriteObjectPathArray_setHandler(std::vector<std::string>  value);
bool TestPropReadWriteStringArray_setHandler(std::vector<std::string>  value);
bool TestPropReadWriteByteString_setHandler(std::string value);
bool TestPropReadWriteSignature_setHandler(std::string value);
bool TestPropReadWriteObjectPath_setHandler(std::string value);
bool TestPropReadWriteString_setHandler(std::string value);
bool TestPropReadWriteDouble_setHandler(double value);
bool TestPropReadWriteUInt64_setHandler(guint64 value);
bool TestPropReadWriteInt64_setHandler(gint64 value);
bool TestPropReadWriteUInt_setHandler(guint32 value);
bool TestPropReadWriteInt_setHandler(gint32 value);
bool TestPropReadWriteUInt16_setHandler(guint16 value);
bool TestPropReadWriteInt16_setHandler(gint16 value);
bool TestPropReadWriteChar_setHandler(guchar value);
bool TestPropReadWriteBoolean_setHandler(bool value);
bool TestPropReadByteStringArray_setHandler(std::vector<std::string>  value) {return true;}
bool TestPropReadObjectPath_setHandler(std::string value) {return true;}
bool TestPropReadByteString_setHandler(std::string) {return true;}
bool TestPropReadSignature_setHandler(std::string) {return true;}
bool TestPropReadString_setHandler(std::string) {return true;}
bool TestPropReadObjectPathArray_setHandler(std::vector<std::string>  value) {return true;}
bool TestPropReadStringArray_setHandler(std::vector<std::string>  value) {return true;}
bool TestPropReadDouble_setHandler(double value) {return true;}
bool TestPropReadUInt64_setHandler(guint64 value) {return true;}
bool TestPropReadInt64_setHandler(gint64 value) {return true;}
bool TestPropReadUInt_setHandler(guint32 value) {return true;}
bool TestPropReadInt_setHandler(gint32 value) {return true;}
bool TestPropReadUInt16_setHandler(guint16 value) {return true;}
bool TestPropReadChar_setHandler(guchar value) {return true;}
bool TestPropReadInt16_setHandler(gint16 value) {return true;}
bool TestPropReadBoolean_setHandler(bool value) {return true;}
bool TestPropInternalReadPropertyChange_setHandler(gint32 value);
bool TestPropInternalReadWritePropertyChange_setHandler(gint32 value);

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
bool m_PropReadWriteBooleanValue;
gint32 m_TestPropInternalReadPropertyChangeValue;
gint32 m_TestPropInternalReadWritePropertyChangeValue;
};
