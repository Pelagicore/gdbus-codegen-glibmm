#include "many-types_proxy.h"
#include "another-service_proxy.h"
#include "tools.h"
#include <iostream>
#include <iomanip>

Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> proxy;

void printStatus (std::string message, bool isOK) {
    if (isOK) {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[32m[  OK  ]\033[0m" << std::endl;
    } else {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[31m[ FAIL ]\033[0m" << std::endl;
    }
}

bool maps_are_equal(const std::map<Glib::ustring,Glib::VariantBase> &a,
                    const std::map<Glib::ustring,Glib::VariantBase> &b) {
    bool equal = (a.size() == b.size());
    for (const auto p: b) {
        if (!p.second.equal(a.at(p.first))) {
            equal = false;
            break;
        }
    }
    return equal;
}

void on_test_string_variant_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                          const std::map<Glib::ustring,Glib::VariantBase> expectedMap) {
    std::map<Glib::ustring,Glib::VariantBase> res;
    proxy->TestStringVariantDict_finish(res, result);

    /* The following comparison will be possible only with glibmm 2.58, due to
     *   https://bugzilla.gnome.org/show_bug.cgi?id=789330
     * Until that, we separately compare keys and values.
     */
    // printStatus("StringVariantDict", res == expectedMap);

    printStatus("StringVariantDict", maps_are_equal(res, expectedMap));
}

void on_test_string_string_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const std::map<Glib::ustring,Glib::ustring> expectedMap) {
    std::map<Glib::ustring,Glib::ustring> res;
    proxy->TestStringStringDict_finish(res, result);

    printStatus("StringStringDict", res == expectedMap);
}

void on_test_uint_int_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const std::map<guint32,gint32> expectedMap) {
    std::map<guint32,gint32> res;
    proxy->TestUintIntDict_finish(res, result);

    printStatus("UintIntDict", res == expectedMap);
}

void on_test_variant_finished(const Glib::RefPtr<Gio::AsyncResult> result, Glib::Variant<Glib::ustring> expectedBase) {
    Glib::VariantBase base;
    proxy->TestVariant_finish(base, result);

    Glib::ustring value;
    try {
        Glib::Variant<Glib::ustring> res = Glib::VariantBase::cast_dynamic< Glib::Variant<Glib::ustring> >(base);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cout << e.what() << std::endl;
    }

    printStatus("Variant", value == expectedBase.get());
}

void on_test_variant2_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                               std::string expectedString,
                               Glib::Variant<Glib::ustring> expectedVariant)
{
    Glib::ustring string;
    Glib::VariantBase base;
    proxy->TestVariant2_finish(string, base, result);

    Glib::ustring value;
    try {
        Glib::Variant<Glib::ustring> res =
            Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(base);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cerr << e.what() << std::endl;
    }

    printStatus("Variant2", string == expectedString && value == expectedVariant.get());
}

void on_test_byte_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    proxy->TestByteStringArray_finish(res, result);
    printStatus ("Byte string array", res == expected);
}

void on_test_object_path_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                        std::vector<Glib::DBusObjectPathString> expected) {
    std::vector<Glib::DBusObjectPathString> res;
    proxy->TestObjectPathArray_finish(res, result);
    printStatus ("Object path array", res == expected);
}

void on_test_string_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                   std::vector<Glib::ustring> expected) {
    std::vector<Glib::ustring> res;
    proxy->TestStringArray_finish(res, result);
    printStatus ("String array", res == expected);
}

void on_test_struct_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                              std::tuple<Glib::ustring,Glib::ustring> expected) {
    std::tuple<Glib::ustring,Glib::ustring> res;
    proxy->TestStruct_finish(res, result);
    printStatus ("Struct", res == expected);
}

void on_test_struct_array_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                    std::vector<std::tuple<guint32,Glib::ustring,gint32>> expected) {
    std::vector<std::tuple<guint32,Glib::ustring,gint32>> res;
    proxy->TestStructArray_finish(res, result);
    printStatus ("Struct array", res == expected);
}

void on_test_dict_struct_array_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                         std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> expected) {
    std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> res;
    proxy->TestDictStructArray_finish(res, result);

    /* The following comparison will be possible only with glibmm 2.58, due to
     *   https://bugzilla.gnome.org/show_bug.cgi?id=789330
     * Until that, we separately compare keys and values.
     */
    //printStatus ("Dict Struct array a(sa{sv})", res == expected);

    bool ok = (res.size() == expected.size());
    if (ok) {
        for (int i = 0; i < res.size(); i++) {
            const auto v = res[i];
            const auto v_expected = expected[i];
            if (std::get<0>(v) != std::get<0>(v_expected)) {
                ok = false;
                break;
            }
            if (!maps_are_equal(std::get<1>(v), std::get<1>(v_expected))) {
                ok = false;
                break;
            }
        }
    }
    printStatus ("Dict Struct array a(sa{sv})", ok);
}

void on_test_byte_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    proxy->TestByteString_finish(res, result);
    printStatus ("Byte string", res == expected);
}

void on_test_signature_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                Glib::DBusSignatureString expected) {
    Glib::DBusSignatureString res;
    proxy->TestSignature_finish(res, result);
    printStatus ("Signature", res == expected);
}

void on_test_object_path_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                  Glib::DBusObjectPathString expected) {
    Glib::DBusObjectPathString res;
    proxy->TestObjectPath_finish(res, result);
    printStatus ("Object path", res == expected);
}

void on_test_string_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                             Glib::ustring expected) {
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

void on_test_all_finished (const Glib::RefPtr<Gio::AsyncResult> result) {
    std::vector<std::string> resByteStringArray;
    std::vector<Glib::DBusObjectPathString> resObjectPathArray;
    std::vector<Glib::ustring> resStringArray;
    std::string resBytestring;
    Glib::DBusSignatureString resSignature;
    Glib::DBusObjectPathString resObjectPath;
    Glib::ustring resString;
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

void on_test_trigger_internal_property_change_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                                        const int expected) {
    proxy->TestTriggerInternalPropertyChange_finish(result);

    printStatus ("Internal property (read)", proxy->TestPropInternalReadPropertyChange_get() == expected);
    printStatus ("Internal property (write/read)", proxy->TestPropInternalReadWritePropertyChange_get() == expected);
}

void on_test_error_finished(const Glib::RefPtr<Gio::AsyncResult> result)
{
    bool gotOurError = false;
    bool gotOurErrorCode = false;
    bool gotOurErrorMessage = false;
    namespace ogcg = org::gdbus::codegen::glibmm;

    try {
        proxy->TestError_finish(result);
    } catch (const ogcg::Error &e) {
        gotOurError = true;
        gotOurErrorCode = (e.code() == ogcg::Error::InvalidParams);
        gotOurErrorMessage = (e.what() == "Testing error message");
    }

    printStatus("Method errors (domain)", gotOurError);
    printStatus("Method errors (code)", gotOurErrorCode);
    printStatus("Method errors (message)", gotOurErrorMessage);
}

void on_test_prop_read_write_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const std::string &expected) {
    proxy->TestPropReadWriteString_set_finish(result);
    std::string actual = proxy->TestPropReadWriteString_get();
    printStatus("Property (write/read): TestPropReadWriteString", actual == expected);
}

void on_test_prop_read_write_byte_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                               const std::vector<std::string> &expected) {
    proxy->TestPropReadWriteByteStringArray_set_finish(result);
    std::vector<std::string> actual = proxy->TestPropReadWriteByteStringArray_get();
    printStatus("Property (write/read): TestPropReadWriteByteStringArray", actual == expected);
}

void on_test_prop_read_write_object_path_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                               const std::vector<Glib::DBusObjectPathString> &expected) {
    proxy->TestPropReadWriteObjectPathArray_set_finish(result);
    std::vector<Glib::DBusObjectPathString> actual = proxy->TestPropReadWriteObjectPathArray_get();
    printStatus("Property (write/read): TestPropReadWriteObjectPathArray", actual == expected);
}

void on_test_prop_read_write_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                          const std::vector<Glib::ustring> &expected) {
    proxy->TestPropReadWriteStringArray_set_finish(result);
    std::vector<Glib::ustring> actual = proxy->TestPropReadWriteStringArray_get();
    printStatus("Property (write/read): TestPropReadWriteStringArray", actual == expected);
}

void on_test_prop_read_write_byte_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const std::string &expected) {
    proxy->TestPropReadWriteByteString_set_finish(result);
    std::string actual = proxy->TestPropReadWriteByteString_get();
    printStatus("Property (write/read): TestPropReadWriteByteString", actual == expected);
}

void on_test_prop_read_write_signature(const Glib::RefPtr<Gio::AsyncResult> result,
                                       const Glib::DBusSignatureString &expected) {
    proxy->TestPropReadWriteSignature_set_finish(result);
    Glib::DBusSignatureString actual = proxy->TestPropReadWriteSignature_get();
    printStatus("Property (write/read): TestPropReadWriteSignature", actual == expected);
}

void on_test_prop_read_write_double(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const double &expected) {
    proxy->TestPropReadWriteDouble_set_finish(result);
    double actual = proxy->TestPropReadWriteDouble_get();
    printStatus("Property (write/read): TestPropReadWriteDouble", actual == expected);
}

void on_test_prop_read_write_uint64(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const guint64 &expected) {
    proxy->TestPropReadWriteUInt64_set_finish(result);
    guint64 actual = proxy->TestPropReadWriteUInt64_get();
    printStatus("Property (write/read): TestPropReadWriteUInt64", actual == expected);
}

void on_test_prop_read_write_int64(const Glib::RefPtr<Gio::AsyncResult> result,
                                   const gint64 &expected) {
    proxy->TestPropReadWriteInt64_set_finish(result);
    gint64 actual = proxy->TestPropReadWriteInt64_get();
    printStatus("Property (write/read): TestPropReadWriteInt64", actual == expected);
}

void on_test_prop_read_write_uint(const Glib::RefPtr<Gio::AsyncResult> result,
                                  const guint &expected) {
    proxy->TestPropReadWriteUInt_set_finish(result);
    guint actual = proxy->TestPropReadWriteUInt_get();
    printStatus("Property (write/read): TestPropReadWriteUInt", actual == expected);
}

void on_test_prop_read_write_int(const Glib::RefPtr<Gio::AsyncResult> result,
                                 const gint &expected) {
    proxy->TestPropReadWriteInt_set_finish(result);
    int actual = proxy->TestPropReadWriteInt_get();
    printStatus("Property (write/read): TestPropReadWriteInt", actual == expected);
}

void on_test_prop_read_write_uint16(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const guint16 &expected) {
    proxy->TestPropReadWriteUInt16_set_finish(result);
    guint16 actual = proxy->TestPropReadWriteUInt16_get();
    printStatus("Property (write/read): TestPropReadWriteUInt16", actual == expected);
}

void on_test_prop_read_write_int16(const Glib::RefPtr<Gio::AsyncResult> result,
                                   const gint16 &expected) {
    proxy->TestPropReadWriteInt16_set_finish(result);
    gint16 actual = proxy->TestPropReadWriteInt16_get();
    printStatus("Property (write/read): TestPropReadWriteInt16", actual == expected);
}

void on_test_prop_read_write_char(const Glib::RefPtr<Gio::AsyncResult> result,
                                  const guchar &expected) {
    proxy->TestPropReadWriteChar_set_finish(result);
    guchar actual = proxy->TestPropReadWriteChar_get();
    printStatus("Property (write/read): TestPropReadWriteChar", actual == expected);
}

void on_test_prop_read_write_boolean(const Glib::RefPtr<Gio::AsyncResult> result,
                                     const guchar &expected) {
    proxy->TestPropReadWriteBoolean_set_finish(result);
    bool actual = proxy->TestPropReadWriteBoolean_get();
    printStatus("Property (write/read): TestPropReadWriteBoolean", actual == expected);
}

void on_test_signal_byte_string_array_cb(const std::vector<std::string> s) {
    printStatus("Signal TestSignalByteStringArray", true);
}

void on_test_signal_object_path_array_cb(const std::vector<Glib::DBusObjectPathString> s) {
    printStatus("Signal TestSignalObjectPathArray", true);
}

void on_test_signal_string_array_cb(const std::vector<Glib::ustring> s) {
    printStatus("Signal TestSignalStringArray", true);
}

void on_test_signal_byte_string_cb(const std::string s) {
    printStatus("Signal TestSignalByteString", true);
}

void on_test_signal_signature_cb(const Glib::DBusSignatureString s) {
    printStatus("Signal TestSignalSignature", true);
}

void on_test_signal_object_path_cb(const Glib::DBusObjectPathString s) {
    printStatus("Signal TestSignalObjectPath", true);
}

void on_test_signal_string_cb(const std::string s) {
    printStatus("Signal TestSignalString", true);
}

void on_test_signal_double_cb(const double s) {
    printStatus("Signal TestSignalDouble", true);
}

void on_test_signal_uint64_cb(const guint64 s) {
    printStatus("Signal TestSignalUInt64", true);
}

void on_test_signal_int64_cb(const gint64 s) {
    printStatus("Signal TestSignalInt64", true);
}

void on_test_signal_uint_cb(const guint s) {
    printStatus("Signal TestSignalUInt", true);
}

void on_test_signal_int_cb(const gint s) {
    printStatus("Signal TestSignalInt", true);
}

void on_test_signal_uint16_cb(const guint16 s) {
    printStatus("Signal TestSignalUInt16", true);
}

void on_test_signal_int16_cb(const gint16 s) {
    printStatus("Signal TestSignalInt16", true);
}

void on_test_signal_char_cb(const guchar s) {
    printStatus("Signal TestSignalChar", true);
}

void on_test_signal_boolean_cb(const bool s) {
    printStatus("Signal TestSignalBoolean", true);
}

void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result) {
    /* Input data */
    std::map<Glib::ustring, Glib::VariantBase> variantMapValue {
        { "string value", Glib::Variant<Glib::ustring>::create("Yes indeed") },
        { "int value", Glib::Variant<int>::create(14) },
    };
    std::map<Glib::ustring, Glib::ustring> stringMapValue {
        { "name", "John" },
        { "surname", "O' Johns" },
        { "city", "Somewhere" },
    };
    std::map<guint32, gint32> intMapValue {
        { 27, 624390 },
        { 12, -384 },
        { 0, 1 },
    };
    Glib::Variant<Glib::ustring> variantValue = Glib::Variant<Glib::ustring>::create("string-as-variant");

    std::vector<std::string> inputStrVec;
    inputStrVec.push_back(__FUNCTION__);

    std::vector<Glib::DBusObjectPathString> inputObjPathVec;
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");

    std::tuple<Glib::ustring,Glib::ustring> structure {
        "one Mississippi", "two Mississippis",
    };

    std::vector<std::tuple<guint32,Glib::ustring,gint32>> structArray {
        { 2, "hello world", -3 },
        { 1, "", 2 },
    };

    std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> dictStructArray {
        { "hello world", variantMapValue },
        { "other", {
                { "key1", Glib::Variant<int>::create(-5) },
            }
        },
    };

    std::vector<Glib::ustring> stringArray {
        "First string", "", "After the empty one",
    };

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
    proxy = org::gdbus::codegen::glibmm::TestProxy::createForBusFinish(result);

    /* Dictionary string -> variant */
    proxy->TestStringVariantDict(variantMapValue, sigc::bind(sigc::ptr_fun(&on_test_string_variant_dict_finished), variantMapValue));

    /* Dictionary string -> string */
    proxy->TestStringStringDict(stringMapValue, sigc::bind(sigc::ptr_fun(&on_test_string_string_dict_finished), stringMapValue));

    /* Dictionary uint -> int */
    proxy->TestUintIntDict(intMapValue, sigc::bind(sigc::ptr_fun(&on_test_uint_int_dict_finished), intMapValue));

    /* Variant */
    proxy->TestVariant(variantValue, sigc::bind(sigc::ptr_fun(&on_test_variant_finished), variantValue));

    /* Variant2 */
    proxy->TestVariant2(stringValue, variantValue,
                        sigc::bind(sigc::ptr_fun(&on_test_variant2_finished), stringValue, variantValue));

    /* Byte string array */
    proxy->TestByteStringArray(inputStrVec, sigc::bind(sigc::ptr_fun(&on_test_byte_string_array_finished), inputStrVec));

    /* Object path array */
    proxy->TestObjectPathArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_object_path_array_finished), inputObjPathVec));

    /* String array */
    proxy->TestStringArray(stringArray, sigc::bind(sigc::ptr_fun(&on_test_string_array_finished), stringArray));

    /* Struct */
    proxy->TestStruct(structure, sigc::bind(sigc::ptr_fun(&on_test_struct_finished), structure));

    /* Struct array */
    proxy->TestStructArray(structArray, sigc::bind(sigc::ptr_fun(&on_test_struct_array_finished), structArray));

    /* Dict Struct array */
    proxy->TestDictStructArray(dictStructArray, sigc::bind(sigc::ptr_fun(&on_test_dict_struct_array_finished), dictStructArray));

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

    /* Test setting internal properties using a function */
    proxy->TestTriggerInternalPropertyChange(42, sigc::bind(sigc::ptr_fun(&on_test_trigger_internal_property_change_finished), 42));

    /* Test method errors */
    org::gdbus::codegen::glibmm::Error::initialize();
    proxy->TestError(sigc::ptr_fun(&on_test_error_finished));

    std::vector<std::string> PropReadByteStringArrayValue;
    PropReadByteStringArrayValue.push_back("Value1");
    PropReadByteStringArrayValue.push_back("Value2");
    printStatus("Property (read): TestPropReadByteStringArray", proxy->TestPropReadByteStringArray_get() == PropReadByteStringArrayValue);

    std::vector<Glib::DBusObjectPathString> PropReadObjectPathArrayValue;
    PropReadObjectPathArrayValue.push_back("/Value3");
    PropReadObjectPathArrayValue.push_back("/Value4");
    printStatus("Property (read): TestPropReadObjectPathArrayValue", proxy->TestPropReadObjectPathArray_get() == PropReadObjectPathArrayValue);

    std::vector<Glib::ustring> PropReadStringArrayValue;
    PropReadStringArrayValue.push_back("Value5");
    PropReadStringArrayValue.push_back("Value6");
    printStatus("Property (read): TestPropReadStringArray", proxy->TestPropReadStringArray_get() == PropReadStringArrayValue);

    printStatus("Property (read): TestPropReadByteString", proxy->TestPropReadByteString_get() == "Value7");
    printStatus("Property (read): TestPropReadSignature", proxy->TestPropReadSignature_get() == "sa{sv}a(bi)");
    printStatus("Property (read): TestPropReadObjectPath", proxy->TestPropReadObjectPath_get() == "/Value9");
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

    std::vector<Glib::DBusObjectPathString> PropReadWriteObjectPathArrayValue;
    PropReadWriteObjectPathArrayValue.push_back("/object/path");

    printStatus("Property (read): TestPropReadWriteObjectPathArray", proxy->TestPropReadWriteObjectPathArray_get() == PropReadWriteObjectPathArrayValue);

    std::vector<Glib::ustring> PropReadWriteStringArrayValue;
    PropReadWriteStringArrayValue.push_back("Value24");
    printStatus("Property (read): TestPropReadWriteStringArrayValue", proxy->TestPropReadWriteStringArray_get() == PropReadWriteStringArrayValue);

    printStatus("Property (read): TestPropReadWriteByteString", proxy->TestPropReadWriteByteString_get() == "Value25");
    printStatus("Property (read): TestPropReadWriteSignature", proxy->TestPropReadWriteSignature_get() == "bada(ss)");
    printStatus("Property (read): TestPropReadWriteObjectPath", proxy->TestPropReadWriteObjectPath_get() == "/Value27");
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

    std::vector<std::string> PropReadWriteByteStringArrayValue2;
    PropReadWriteByteStringArrayValue2.push_back("Hello");
    PropReadWriteByteStringArrayValue2.push_back("World");
    proxy->TestPropReadWriteByteStringArray_set(
        PropReadWriteByteStringArrayValue2,
        sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_byte_string_array),
                   PropReadWriteByteStringArrayValue2));

    std::vector<Glib::DBusObjectPathString> PropReadWriteObjectPathArrayValue2;
    PropReadWriteObjectPathArrayValue2.push_back("/object/path");
    proxy->TestPropReadWriteObjectPathArray_set(
        PropReadWriteObjectPathArrayValue2,
        sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_object_path_array),
                   PropReadWriteObjectPathArrayValue2));

    std::vector<Glib::ustring> PropReadWriteStringArrayValue2;
    PropReadWriteStringArrayValue2.push_back("Stringarray");
    proxy->TestPropReadWriteStringArray_set(
        PropReadWriteStringArrayValue2,
        sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_string_array),
                   PropReadWriteStringArrayValue2));

    proxy->TestPropReadWriteByteString_set(
        "ByteString test",
        sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_byte_string),
                   "ByteString test"));

//    proxy->TestPropReadWriteSignature_set("b", sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_signature), "b"));
    proxy->TestPropReadWriteString_set("Hello world", sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_string), "Hello world"));
    proxy->TestPropReadWriteDouble_set(7331, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_double), 7331));
    proxy->TestPropReadWriteUInt64_set(7332, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_uint64), 7332));
    proxy->TestPropReadWriteInt64_set(7333, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_int64), 7333));
    proxy->TestPropReadWriteUInt_set(7334, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_uint), 7334));
    proxy->TestPropReadWriteInt_set(7335, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_int), 7335));
    proxy->TestPropReadWriteUInt16_set(7336, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_uint16), 7336));
    proxy->TestPropReadWriteInt16_set(7337, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_int16), 7337));
    proxy->TestPropReadWriteChar_set('X', sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_char), 'X'));
    proxy->TestPropReadWriteBoolean_set(true, sigc::bind(sigc::ptr_fun(&on_test_prop_read_write_boolean), true));

    proxy->TestSignalByteStringArray_signal.connect(sigc::ptr_fun(&on_test_signal_byte_string_array_cb));
    proxy->TestSignalObjectPathArray_signal.connect(sigc::ptr_fun(&on_test_signal_object_path_array_cb));
    proxy->TestSignalStringArray_signal.connect(sigc::ptr_fun(&on_test_signal_string_array_cb));
    proxy->TestSignalByteString_signal.connect(sigc::ptr_fun(&on_test_signal_byte_string_cb));
    proxy->TestSignalSignature_signal.connect(sigc::ptr_fun(&on_test_signal_signature_cb));
    proxy->TestSignalObjectPath_signal.connect(sigc::ptr_fun(&on_test_signal_object_path_cb));
    proxy->TestSignalString_signal.connect(sigc::ptr_fun(&on_test_signal_string_cb));
    proxy->TestSignalDouble_signal.connect(sigc::ptr_fun(&on_test_signal_double_cb));
    proxy->TestSignalUInt64_signal.connect(sigc::ptr_fun(&on_test_signal_uint64_cb));
    proxy->TestSignalInt64_signal.connect(sigc::ptr_fun(&on_test_signal_int64_cb));
    proxy->TestSignalUInt_signal.connect(sigc::ptr_fun(&on_test_signal_uint_cb));
    proxy->TestSignalInt_signal.connect(sigc::ptr_fun(&on_test_signal_int_cb));
    proxy->TestSignalUInt16_signal.connect(sigc::ptr_fun(&on_test_signal_uint16_cb));
    proxy->TestSignalInt16_signal.connect(sigc::ptr_fun(&on_test_signal_int16_cb));
    proxy->TestSignalChar_signal.connect(sigc::ptr_fun(&on_test_signal_char_cb));
    proxy->TestSignalBoolean_signal.connect(sigc::ptr_fun(&on_test_signal_boolean_cb));
}

int main() {
    Glib::init();
    Gio::init();

    org::gdbus::codegen::glibmm::TestProxy::createForBus(Gio::DBus::BUS_TYPE_SESSION,
                                Gio::DBus::PROXY_FLAGS_NONE,
                                "org.gdbus.codegen.glibmm.Test",
                                "/org/gdbus/codegen/glibmm/Test",
                                sigc::ptr_fun(&proxy_created));

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
