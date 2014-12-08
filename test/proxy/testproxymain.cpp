#include "many-types_proxy.h"
#include "tools.h"
#include <iostream>
#include <iomanip>

Glib::RefPtr<org::gdbus::codegen::glibmm::Test> proxy;

void printStatus (std::string message, bool isOK) {
    if (isOK) {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[32m[  OK  ]\033[0m" << std::endl;
    } else {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[31m[ FAIL ]\033[0m" << std::endl;
    }
}

void on_test_byte_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    proxy->TestByteStringArray_finish(res, result);
    printStatus ("Byte string array", res == expected);
}

void on_test_object_path_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    proxy->TestObjectPathArray_finish(res, result);
    printStatus ("Object path array", res == expected);
}

void on_test_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    proxy->TestStringArray_finish(res, result);
    printStatus ("String array", res == expected);
}

void on_test_byte_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestByteString_finish(res, result);
    printStatus ("Byte string", res == expected);
}

void on_test_signature_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestSignature_finish(res, result);
    printStatus ("Signature", res == expected);
}

void on_test_object_path_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestObjectPath_finish(res, result);
    printStatus ("Object path", res == expected);
}

void on_test_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestString_finish(res, result);
    printStatus ("String", res == expected);
}

void on_test_double_finished (const Glib::RefPtr<Gio::AsyncResult> result, double expected) {
    double res;
    proxy->TestDouble_finish(res, result);
    printStatus ("Double", res == expected);
}

void on_test_uint64_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint64 expected) {
    guint64 res;
    proxy->TestUInt64_finish(res, result);
    printStatus ("UInt64", res == expected);
}

void on_test_int64_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint64 expected) {
    gint64 res;
    proxy->TestInt64_finish(res, result);
    printStatus ("Int64", res == expected);
}

void on_test_uint_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint expected) {
    guint res;
    proxy->TestUInt_finish(res, result);
    printStatus ("UInt", res == expected);
}

void on_test_int_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint expected) {
    gint res;
    proxy->TestInt_finish(res, result);
    printStatus ("Int", res == expected);
}

void on_test_uint16_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint16 expected) {
    guint16 res;
    proxy->TestUInt16_finish(res, result);
    printStatus ("UInt16", res == expected);
}

void on_test_int16_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint16 expected) {
    gint16 res;
    proxy->TestInt16_finish(res, result);
    printStatus ("Int16", res == expected);
}

void on_test_uchar_finished (const Glib::RefPtr<Gio::AsyncResult> result, guchar expected) {
    guchar res;
    proxy->TestChar_finish(res, result);
    printStatus ("Char", res == expected);
}

void on_test_boolean_finished (const Glib::RefPtr<Gio::AsyncResult> result, bool expected) {
    bool res;
    proxy->TestBoolean_finish(res, result);
    printStatus ("Boolean", res == expected);
}

void on_test_all_finished (const Glib::RefPtr<Gio::AsyncResult> result) {
    std::vector<std::string> resByteStringArray;
    std::vector<std::string> resObjectPathArray;
    std::vector<std::string> resStringArray;
    std::string resBytestring;
    std::string resSignature;
    std::string resObjectPath;
    std::string resString;
    double resDouble;
    guint64 resUint64;
    gint64 resInt64;
    guint resUint;
    gint resInt;
    guint16 resUint16;
    gint16 resInt16;
    guchar resUchar;
    bool resBoolean;

    proxy->TestAll_finish(
            resByteStringArray,
            resObjectPathArray,
            resStringArray,
            resBytestring,
            resSignature,
            resObjectPath,
            resString,
            resDouble,
            resUint64,
            resInt64,
            resUint,
            resInt,
            resUint16,
            resInt16,
            resUchar,
            resBoolean,
            result);
//    printStatus ("Boolean", res == expected);
}

void on_test_prop_read_write_string(const Glib::RefPtr<Gio::AsyncResult> result, const std::string &expected) {
    proxy->TestPropReadWriteString_set_finish(result);
    std::string actual = proxy->TestPropReadWriteString_get();
    printStatus("Property (write/read): TestPropReadWriteString", actual == expected);
}

void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result) {
    /* Input data */
    std::vector<std::string> inputStrVec;
    inputStrVec.push_back(__FUNCTION__);

    std::vector<std::string> inputObjPathVec;
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");

    std::string bytestring = "Hello world!";
    std::string signatureValue = "b";
    std::string objectPath = "/foo";
    std::string stringValue = "String";
    double doubleValue = 1337;
    guint64 uint64Value = 1338;
    gint64 int64Value = -1339;
    guint uintValue = 1340;
    gint intValue = -1341;
    guint16 uint16Value = 1342;
    gint16 int16Value = 1343;
    guchar ucharValue = 'A';
    bool booleanValue = true;

    /* Proxy */ 
    proxy = org::gdbus::codegen::glibmm::Test::createForBusFinish(result);

    /* Byte string array */
    proxy->TestByteStringArray(inputStrVec, sigc::bind(sigc::ptr_fun(&on_test_byte_string_array_finished), inputStrVec));

//    /* Object path array */
//    proxy->TestObjectPathArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_object_path_array_finished), inputObjPathVec));

    /* String array */
    proxy->TestStringArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_string_array_finished), inputObjPathVec));

    /* Byte string */
    proxy->TestByteString(bytestring, sigc::bind(sigc::ptr_fun(&on_test_byte_string_finished), bytestring));

    /* Signature */
    proxy->TestSignature(signatureValue, sigc::bind(sigc::ptr_fun(&on_test_signature_finished), signatureValue));

    /* Object path */
    proxy->TestObjectPath(objectPath, sigc::bind(sigc::ptr_fun(&on_test_object_path_finished), objectPath));

    /* String */
    proxy->TestString(stringValue, sigc::bind(sigc::ptr_fun(&on_test_string_finished), stringValue));

    /* Double */
    proxy->TestDouble(doubleValue, sigc::bind(sigc::ptr_fun(&on_test_double_finished), doubleValue));

    /* UInt64 */
    proxy->TestUInt64(uint64Value, sigc::bind(sigc::ptr_fun(&on_test_uint64_finished), uint64Value));

    /* Int64 */
    proxy->TestInt64(int64Value, sigc::bind(sigc::ptr_fun(&on_test_int64_finished), int64Value));

    /* UInt */
    proxy->TestUInt(uintValue, sigc::bind(sigc::ptr_fun(&on_test_uint_finished), uintValue));

    /* Int */
    proxy->TestInt(intValue, sigc::bind(sigc::ptr_fun(&on_test_int_finished), intValue));

    /* UInt16 */
    proxy->TestUInt16(uint16Value, sigc::bind(sigc::ptr_fun(&on_test_uint16_finished), uint16Value));

    /* Int16 */
    proxy->TestInt16(int16Value, sigc::bind(sigc::ptr_fun(&on_test_int16_finished), int16Value));

    /* Char */
    proxy->TestChar(ucharValue, sigc::bind(sigc::ptr_fun(&on_test_uchar_finished), ucharValue));

    /* Boolean */
    proxy->TestBoolean(booleanValue, sigc::bind(sigc::ptr_fun(&on_test_boolean_finished), booleanValue));

//    /* All */
//    proxy->TestAll(inputStrVec,
//                   inputStrVec,
//                   inputStrVec,
//                   bytestring,
//                   signatureValue,
//                   objectPath,
//                   stringValue,
//                   doubleValue,
//                   uint64Value,
//                   int64Value,
//                   uintValue,
//                   intValue,
//                   uint16Value,
//                   int16Value,
//                   ucharValue,
//                   booleanValue,
//                   sigc::ptr_fun(&on_test_all_finished));
//

    std::vector<std::string> PropReadByteStringArrayValue;
    PropReadByteStringArrayValue.push_back("Value1");
    PropReadByteStringArrayValue.push_back("Value2");
    printStatus("Property (read): TestPropReadByteStringArray", proxy->TestPropReadByteStringArray_get() == PropReadByteStringArrayValue);

    std::vector<std::string> PropReadObjectPathArrayValue;
    PropReadObjectPathArrayValue.push_back("Value3");
    PropReadObjectPathArrayValue.push_back("Value4");
    printStatus("Property (read): TestPropReadObjectPathArrayValue", proxy->TestPropReadObjectPathArray_get() == PropReadObjectPathArrayValue);

    std::vector<std::string> PropReadStringArrayValue;
    PropReadStringArrayValue.push_back("Value5");
    PropReadStringArrayValue.push_back("Value6");
    printStatus("Property (read): TestPropReadStringArray", proxy->TestPropReadStringArray_get() == PropReadStringArrayValue);

    printStatus("Property (read): TestPropReadByteString", proxy->TestPropReadByteString_get() == "Value7");
    printStatus("Property (read): TestPropReadSignature", proxy->TestPropReadSignature_get() == "Value8");
    printStatus("Property (read): TestPropReadObjectPath", proxy->TestPropReadObjectPath_get() == "Value9");
    printStatus("Property (read): TestPropReadString", proxy->TestPropReadString_get() == "Value10");
    printStatus("Property (read): TestPropReadDouble", proxy->TestPropReadDouble_get() == 1337);
    printStatus("Property (read): TestPropReadUInt64", proxy->TestPropReadUInt64_get() == 1338);
    printStatus("Property (read): TestPropReadInt64", proxy->TestPropReadInt64_get() == 1339);
    printStatus("Property (read): TestPropReadUInt", proxy->TestPropReadUInt_get() == 1340);
    printStatus("Property (read): TestPropReadInt", proxy->TestPropReadInt_get() == 1341);
    printStatus("Property (read): TestPropReadUInt16", proxy->TestPropReadUInt16_get() == 1342);
    printStatus("Property (read): TestPropReadInt16", proxy->TestPropReadInt16_get() == 1343);
    printStatus("Property (read): TestPropReadChar", proxy->TestPropReadChar_get() == 'A');
    printStatus("Property (read): TestPropReadBoolean", proxy->TestPropReadBoolean_get() == true);

    std::vector<std::string> PropReadWriteByteStringArrayValue;
    PropReadWriteByteStringArrayValue.push_back("Value21");
    PropReadWriteByteStringArrayValue.push_back("Value22");
    printStatus("Property (read): TestPropReadWriteByteStringArray", proxy->TestPropReadWriteByteStringArray_get() == PropReadWriteByteStringArrayValue);

    std::vector<std::string> PropReadWriteObjectPathArrayValue;
    PropReadWriteObjectPathArrayValue.push_back("Value23");
    printStatus("Property (read): TestPropReadWriteObjectPathArray", proxy->TestPropReadWriteObjectPathArray_get() == PropReadWriteObjectPathArrayValue);

    std::vector<std::string> PropReadWriteStringArrayValue;
    PropReadWriteStringArrayValue.push_back("Value24");
    printStatus("Property (read): TestPropReadWriteStringArrayValue", proxy->TestPropReadWriteStringArray_get() == PropReadWriteStringArrayValue);

    printStatus("Property (read): TestPropReadWriteByteString", proxy->TestPropReadWriteByteString_get() == "Value25");
    printStatus("Property (read): TestPropReadWriteSignature", proxy->TestPropReadWriteSignature_get() == "Value26");
    printStatus("Property (read): TestPropReadWriteObjectPath", proxy->TestPropReadWriteObjectPath_get() == "Value27");
    printStatus("Property (read): TestPropReadWriteString", proxy->TestPropReadWriteString_get() == "Value28");
    printStatus("Property (read): TestPropReadWriteDouble", proxy->TestPropReadWriteDouble_get() == 1351);
    printStatus("Property (read): TestPropReadWriteUInt64", proxy->TestPropReadWriteUInt64_get() == 1352);
    printStatus("Property (read): TestPropReadWriteInt64", proxy->TestPropReadWriteInt64_get() == 1353);
    printStatus("Property (read): TestPropReadWriteUInt", proxy->TestPropReadWriteUInt_get() == 1354);
    printStatus("Property (read): TestPropReadWriteInt", proxy->TestPropReadWriteInt_get() == 1355);
    printStatus("Property (read): TestPropReadWriteUInt16", proxy->TestPropReadWriteUInt16_get() == 1356);
    printStatus("Property (read): TestPropReadWriteInt16", proxy->TestPropReadWriteInt16_get() == 1357);
    printStatus("Property (read): TestPropReadWriteChar", proxy->TestPropReadWriteChar_get() == 'C');
    printStatus("Property (read): TestPropReadWriteBoolean", proxy->TestPropReadWriteBoolean_get() == true);

    proxy->TestPropReadWriteString_set("Hello world", sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_string), "Hello world"));
}

int main() {
    Glib::init();
    Gio::init();

    org::gdbus::codegen::glibmm::Test::createForBus(Gio::DBus::BUS_TYPE_SESSION,
                                Gio::DBus::PROXY_FLAGS_NONE,
                                "org.gdbus.codegen.glibmm.Test",
                                "/org/gdbus/codegen/glibmm/Test",
                                sigc::ptr_fun(&proxy_created));

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
