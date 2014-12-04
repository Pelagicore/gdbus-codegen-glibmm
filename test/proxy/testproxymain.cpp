#include "many-types_proxy.h"
#include "tools.h"
#include <iostream>
#include <iomanip>

Glib::RefPtr<org::gdbus::codegen::glibmm::Test> proxy;

void printStatus (std::string message, bool isOK) {
    if (isOK) {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[32m[  OK  ]\033[0m" << std::endl;;
    } else {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[31m[ FAIL ]\033[0m" << std::endl;;
    }
}

void on_test_byte_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    proxy->TestByteStringArray_finish(res, result);
    printStatus ("Byte string array", res == expected);
}

void on_test_object_path_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<Glib::ustring> expected) {
    std::vector<Glib::ustring> res;
    proxy->TestObjectPathArray_finish(res, result);
    printStatus ("Object path array", res == expected);
}

void on_test_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<Glib::ustring> expected) {
    std::vector<Glib::ustring> res;
    proxy->TestStringArray_finish(res, result);
    printStatus ("String array", res == expected);
}

void on_test_byte_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestByteString_finish(res, result);
    printStatus ("Byte string", res == expected);
}

void on_test_signature_finished (const Glib::RefPtr<Gio::AsyncResult> result, Glib::ustring expected) {
    Glib::ustring res;
    proxy->TestSignature_finish(res, result);
    printStatus ("Signature", res == expected);
}

void on_test_object_path_finished (const Glib::RefPtr<Gio::AsyncResult> result, Glib::ustring expected) {
    Glib::ustring res;
    proxy->TestObjectPath_finish(res, result);
    printStatus ("Object path", res == expected);
}

void on_test_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    Glib::ustring res;
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

void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result) {
    /* Input data */
    std::vector<std::string> inputStrVec;
    inputStrVec.push_back(__FUNCTION__);

    std::vector<std::string> inputObjPathVec;
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");

    std::string bytestring = "Hello world!";
    Glib::ustring signature = "Signature";
    Glib::ustring objectPath = "/foo";
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

    /* Object path array */
    proxy->TestObjectPathArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_object_path_array_finished),
                                                    CodegenTools::stdStringVecToGlibStringVec(inputObjPathVec)));
    /* String array */
    proxy->TestStringArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_string_array_finished),
                                                    CodegenTools::stdStringVecToGlibStringVec(inputObjPathVec)));

    /* Byte string */
    proxy->TestByteString(bytestring, sigc::bind(sigc::ptr_fun(&on_test_byte_string_finished), bytestring));

    /* Signature */
    proxy->TestSignature(signature, sigc::bind(sigc::ptr_fun(&on_test_signature_finished), signature));

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
