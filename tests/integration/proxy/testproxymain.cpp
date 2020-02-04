#include "testproxymain.h"

#include "another-service_proxy.h"
#include "tools.h"
#include <iostream>
#include <iomanip>

void TestProxyImpl::printStatus(const std::string &message, bool isOK)
{
    if (isOK) {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[32m[  OK  ]\033[0m" << std::endl;
    } else {
        std::cout << std::setw(60) << std::left << message << std::right << "\033[31m[ FAIL ]\033[0m" << std::endl;
        fail();
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

TestProxyImpl::TestProxyImpl()
{
    org::gdbus::codegen::glibmm::TestProxy::createForBus(
        Gio::DBus::BUS_TYPE_SESSION,
        Gio::DBus::PROXY_FLAGS_NONE,
        "org.gdbus.codegen.glibmm.Test",
        "/org/gdbus/codegen/glibmm/Test",
        sigc::mem_fun(this, &TestProxyImpl::proxy_created));
}

void TestProxyImpl::fail()
{
    m_exit_status = EXIT_FAILURE;
    m_done.emit();
}

void TestProxyImpl::record_call()
{
    m_pending_calls--;
    check_done();
}

void TestProxyImpl::on_test_string_variant_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                          const std::map<Glib::ustring,Glib::VariantBase> expectedMap) {
    std::map<Glib::ustring,Glib::VariantBase> res;
    m_proxy->TestStringVariantDict_finish(res, result);

    /* The following comparison will be possible only with glibmm 2.58, due to
     *   https://bugzilla.gnome.org/show_bug.cgi?id=789330
     * Until that, we separately compare keys and values.
     */
    // printStatus("StringVariantDict", res == expectedMap);

    printStatus("StringVariantDict", maps_are_equal(res, expectedMap));
    record_call();
}

void TestProxyImpl::on_test_string_string_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const std::map<Glib::ustring,Glib::ustring> expectedMap) {
    std::map<Glib::ustring,Glib::ustring> res;
    m_proxy->TestStringStringDict_finish(res, result);

    printStatus("StringStringDict", res == expectedMap);
    record_call();
}

void TestProxyImpl::on_test_uint_int_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const std::map<guint32,gint32> expectedMap) {
    std::map<guint32,gint32> res;
    m_proxy->TestUintIntDict_finish(res, result);

    printStatus("UintIntDict", res == expectedMap);
    record_call();
}

void TestProxyImpl::on_test_variant_finished(const Glib::RefPtr<Gio::AsyncResult> result, Glib::Variant<Glib::ustring> expectedBase) {
    Glib::VariantBase base;
    m_proxy->TestVariant_finish(base, result);

    Glib::ustring value;
    try {
        Glib::Variant<Glib::ustring> res = Glib::VariantBase::cast_dynamic< Glib::Variant<Glib::ustring> >(base);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cout << e.what() << std::endl;
    }

    printStatus("Variant", value == expectedBase.get());
    record_call();
}

void TestProxyImpl::on_test_variant2_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                               std::string expectedString,
                               Glib::Variant<Glib::ustring> expectedVariant)
{
    Glib::ustring string;
    Glib::VariantBase base;
    m_proxy->TestVariant2_finish(string, base, result);

    Glib::ustring value;
    try {
        Glib::Variant<Glib::ustring> res =
            Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(base);
        value = res.get();
    } catch (std::bad_cast e) {
        std::cerr << e.what() << std::endl;
    }

    printStatus("Variant2", string == expectedString && value == expectedVariant.get());
    record_call();
}

void TestProxyImpl::on_test_byte_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
    std::vector<std::string> res;
    m_proxy->TestByteStringArray_finish(res, result);
    printStatus ("Byte string array", res == expected);
    record_call();
}

void TestProxyImpl::on_test_object_path_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                        std::vector<Glib::DBusObjectPathString> expected) {
    std::vector<Glib::DBusObjectPathString> res;
    m_proxy->TestObjectPathArray_finish(res, result);
    printStatus ("Object path array", res == expected);
    record_call();
}

void TestProxyImpl::on_test_string_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                   std::vector<Glib::ustring> expected) {
    std::vector<Glib::ustring> res;
    m_proxy->TestStringArray_finish(res, result);
    printStatus ("String array", res == expected);
    record_call();
}

void TestProxyImpl::on_test_struct_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                              std::tuple<Glib::ustring,Glib::ustring> expected) {
    std::tuple<Glib::ustring,Glib::ustring> res;
    m_proxy->TestStruct_finish(res, result);
    printStatus ("Struct", res == expected);
    record_call();
}

void TestProxyImpl::on_test_struct_array_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                    std::vector<std::tuple<guint32,Glib::ustring,gint32>> expected) {
    std::vector<std::tuple<guint32,Glib::ustring,gint32>> res;
    m_proxy->TestStructArray_finish(res, result);
    printStatus ("Struct array", res == expected);
    record_call();
}

void TestProxyImpl::on_test_dict_struct_array_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                         std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> expected) {
    std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> res;
    m_proxy->TestDictStructArray_finish(res, result);

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
    record_call();
}

void TestProxyImpl::on_test_byte_string_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::string expected) {
    std::string res;
    m_proxy->TestByteString_finish(res, result);
    printStatus ("Byte string", res == expected);
    record_call();
}

void TestProxyImpl::on_test_signature_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                Glib::DBusSignatureString expected) {
    Glib::DBusSignatureString res;
    m_proxy->TestSignature_finish(res, result);
    printStatus ("Signature", res == expected);
    record_call();
}

void TestProxyImpl::on_test_object_path_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                  Glib::DBusObjectPathString expected) {
    Glib::DBusObjectPathString res;
    m_proxy->TestObjectPath_finish(res, result);
    printStatus ("Object path", res == expected);
    record_call();
}

void TestProxyImpl::on_test_string_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                             Glib::ustring expected) {
    Glib::ustring res;
    m_proxy->TestString_finish(res, result);
    printStatus ("String", res == expected);
    record_call();
}

void TestProxyImpl::on_test_double_finished (const Glib::RefPtr<Gio::AsyncResult> result, double expected) {
    double res;
    m_proxy->TestDouble_finish(res, result);
    printStatus ("Double", res == expected);
    record_call();
}

void TestProxyImpl::on_test_uint64_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint64 expected) {
    guint64 res;
    m_proxy->TestUInt64_finish(res, result);
    printStatus ("UInt64", res == expected);
    record_call();
}

void TestProxyImpl::on_test_int64_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint64 expected) {
    gint64 res;
    m_proxy->TestInt64_finish(res, result);
    printStatus ("Int64", res == expected);
    record_call();
}

void TestProxyImpl::on_test_uint_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint expected) {
    guint res;
    m_proxy->TestUInt_finish(res, result);
    printStatus ("UInt", res == expected);
    record_call();
}

void TestProxyImpl::on_test_int_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint expected) {
    gint res;
    m_proxy->TestInt_finish(res, result);
    printStatus ("Int", res == expected);
    record_call();
}

void TestProxyImpl::on_test_uint16_finished (const Glib::RefPtr<Gio::AsyncResult> result, guint16 expected) {
    guint16 res;
    m_proxy->TestUInt16_finish(res, result);
    printStatus ("UInt16", res == expected);
    record_call();
}

void TestProxyImpl::on_test_int16_finished (const Glib::RefPtr<Gio::AsyncResult> result, gint16 expected) {
    gint16 res;
    m_proxy->TestInt16_finish(res, result);
    printStatus ("Int16", res == expected);
    record_call();
}

void TestProxyImpl::on_test_uchar_finished (const Glib::RefPtr<Gio::AsyncResult> result, guchar expected) {
    guchar res;
    m_proxy->TestChar_finish(res, result);
    printStatus ("Char", res == expected);
    record_call();
}

void TestProxyImpl::on_test_boolean_finished (const Glib::RefPtr<Gio::AsyncResult> result, bool expected) {
    bool res;
    m_proxy->TestBoolean_finish(res, result);
    printStatus ("Boolean", res == expected);
    record_call();
}

void TestProxyImpl::on_test_all_finished (const Glib::RefPtr<Gio::AsyncResult> result) {
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

    m_proxy->TestAll_finish(
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

void TestProxyImpl::on_test_trigger_internal_property_change_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                                        const int expected) {
    m_proxy->TestTriggerInternalPropertyChange_finish(result);

    printStatus ("Internal property (read)", m_proxy->TestPropInternalReadPropertyChange_get() == expected);
    printStatus ("Internal property (write/read)", m_proxy->TestPropInternalReadWritePropertyChange_get() == expected);
    record_call();
}

void TestProxyImpl::on_test_error_finished(const Glib::RefPtr<Gio::AsyncResult> result)
{
    bool gotOurError = false;
    bool gotOurErrorCode = false;
    bool gotOurErrorMessage = false;
    namespace ogcg = org::gdbus::codegen::glibmm;

    try {
        m_proxy->TestError_finish(result);
    } catch (const ogcg::Error &e) {
        gotOurError = true;
        gotOurErrorCode = (e.code() == ogcg::Error::InvalidParams);
        gotOurErrorMessage = (e.what() == "Testing error message");
    }

    printStatus("Method errors (domain)", gotOurError);
    printStatus("Method errors (code)", gotOurErrorCode);
    printStatus("Method errors (message)", gotOurErrorMessage);
    record_call();
}

void TestProxyImpl::on_test_prop_read_write_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const std::string &expected) {
    m_proxy->TestPropReadWriteString_set_finish(result);
    std::string actual = m_proxy->TestPropReadWriteString_get();
    printStatus("Property (write/read): TestPropReadWriteString", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_byte_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                               const std::vector<std::string> &expected) {
    m_proxy->TestPropReadWriteByteStringArray_set_finish(result);
    std::vector<std::string> actual = m_proxy->TestPropReadWriteByteStringArray_get();
    printStatus("Property (write/read): TestPropReadWriteByteStringArray", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_object_path_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                               const std::vector<Glib::DBusObjectPathString> &expected) {
    m_proxy->TestPropReadWriteObjectPathArray_set_finish(result);
    std::vector<Glib::DBusObjectPathString> actual = m_proxy->TestPropReadWriteObjectPathArray_get();
    printStatus("Property (write/read): TestPropReadWriteObjectPathArray", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                          const std::vector<Glib::ustring> &expected) {
    m_proxy->TestPropReadWriteStringArray_set_finish(result);
    std::vector<Glib::ustring> actual = m_proxy->TestPropReadWriteStringArray_get();
    printStatus("Property (write/read): TestPropReadWriteStringArray", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_byte_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const std::string &expected) {
    m_proxy->TestPropReadWriteByteString_set_finish(result);
    std::string actual = m_proxy->TestPropReadWriteByteString_get();
    printStatus("Property (write/read): TestPropReadWriteByteString", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_signature(const Glib::RefPtr<Gio::AsyncResult> result,
                                       const Glib::DBusSignatureString &expected) {
    m_proxy->TestPropReadWriteSignature_set_finish(result);
    Glib::DBusSignatureString actual = m_proxy->TestPropReadWriteSignature_get();
    printStatus("Property (write/read): TestPropReadWriteSignature", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_object_path(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const Glib::DBusObjectPathString &expected) {
    m_proxy->TestPropReadWriteObjectPath_set_finish(result);
    Glib::DBusObjectPathString actual = m_proxy->TestPropReadWriteObjectPath_get();
    printStatus("Property (write/read): TestPropReadWriteObjectPath", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_double(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const double &expected) {
    m_proxy->TestPropReadWriteDouble_set_finish(result);
    double actual = m_proxy->TestPropReadWriteDouble_get();
    printStatus("Property (write/read): TestPropReadWriteDouble", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_uint64(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const guint64 &expected) {
    m_proxy->TestPropReadWriteUInt64_set_finish(result);
    guint64 actual = m_proxy->TestPropReadWriteUInt64_get();
    printStatus("Property (write/read): TestPropReadWriteUInt64", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_int64(const Glib::RefPtr<Gio::AsyncResult> result,
                                   const gint64 &expected) {
    m_proxy->TestPropReadWriteInt64_set_finish(result);
    gint64 actual = m_proxy->TestPropReadWriteInt64_get();
    printStatus("Property (write/read): TestPropReadWriteInt64", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_uint(const Glib::RefPtr<Gio::AsyncResult> result,
                                  const guint &expected) {
    m_proxy->TestPropReadWriteUInt_set_finish(result);
    guint actual = m_proxy->TestPropReadWriteUInt_get();
    printStatus("Property (write/read): TestPropReadWriteUInt", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_int(const Glib::RefPtr<Gio::AsyncResult> result,
                                 const gint &expected) {
    m_proxy->TestPropReadWriteInt_set_finish(result);
    int actual = m_proxy->TestPropReadWriteInt_get();
    printStatus("Property (write/read): TestPropReadWriteInt", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_uint16(const Glib::RefPtr<Gio::AsyncResult> result,
                                    const guint16 &expected) {
    m_proxy->TestPropReadWriteUInt16_set_finish(result);
    guint16 actual = m_proxy->TestPropReadWriteUInt16_get();
    printStatus("Property (write/read): TestPropReadWriteUInt16", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_int16(const Glib::RefPtr<Gio::AsyncResult> result,
                                   const gint16 &expected) {
    m_proxy->TestPropReadWriteInt16_set_finish(result);
    gint16 actual = m_proxy->TestPropReadWriteInt16_get();
    printStatus("Property (write/read): TestPropReadWriteInt16", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_char(const Glib::RefPtr<Gio::AsyncResult> result,
                                  const guchar &expected) {
    m_proxy->TestPropReadWriteChar_set_finish(result);
    guchar actual = m_proxy->TestPropReadWriteChar_get();
    printStatus("Property (write/read): TestPropReadWriteChar", actual == expected);
}

void TestProxyImpl::on_test_prop_read_write_boolean(const Glib::RefPtr<Gio::AsyncResult> result,
                                     const guchar &expected) {
    m_proxy->TestPropReadWriteBoolean_set_finish(result);
    bool actual = m_proxy->TestPropReadWriteBoolean_get();
    printStatus("Property (write/read): TestPropReadWriteBoolean", actual == expected);
}

void TestProxyImpl::on_test_signal_byte_string_array_cb(const std::vector<std::string> s) {
    printStatus("Signal TestSignalByteStringArray", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_object_path_array_cb(const std::vector<Glib::DBusObjectPathString> s) {
    printStatus("Signal TestSignalObjectPathArray", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_string_array_cb(const std::vector<Glib::ustring> s) {
    printStatus("Signal TestSignalStringArray", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_byte_string_cb(const std::string s) {
    printStatus("Signal TestSignalByteString", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_signature_cb(const Glib::DBusSignatureString s) {
    printStatus("Signal TestSignalSignature", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_object_path_cb(const Glib::DBusObjectPathString s) {
    printStatus("Signal TestSignalObjectPath", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_string_cb(const std::string s) {
    printStatus("Signal TestSignalString", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_double_cb(const double s) {
    printStatus("Signal TestSignalDouble", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_uint64_cb(const guint64 s) {
    printStatus("Signal TestSignalUInt64", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_int64_cb(const gint64 s) {
    printStatus("Signal TestSignalInt64", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_uint_cb(const guint s) {
    printStatus("Signal TestSignalUInt", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_int_cb(const gint s) {
    printStatus("Signal TestSignalInt", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_uint16_cb(const guint16 s) {
    printStatus("Signal TestSignalUInt16", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_int16_cb(const gint16 s) {
    printStatus("Signal TestSignalInt16", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_char_cb(const guchar s) {
    printStatus("Signal TestSignalChar", true);
    record_signal();
}

void TestProxyImpl::on_test_signal_boolean_cb(const bool s) {
    printStatus("Signal TestSignalBoolean", true);
    record_signal();
}

void TestProxyImpl::on_test_selective_signal_cb(const bool s) {
    printStatus("Signal TestSelectiveSignal", true);
    record_signal();
}

void TestProxyImpl::on_notification_received()
{
    m_pending_notifications--;
    check_done();
}

void TestProxyImpl::expect_notification(sigc::signal<void> &signal)
{
    m_pending_notifications++;
    signal.connect(sigc::mem_fun(this, &TestProxyImpl::on_notification_received));
}

void TestProxyImpl::check_done()
{
    if (m_pending_calls == 0 &&
        m_pending_notifications == 0 &&
        m_pending_signals == 0) {
        m_done.emit();
    }
}

void TestProxyImpl::proxy_created(const Glib::RefPtr<Gio::AsyncResult> result) {
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
    m_proxy = org::gdbus::codegen::glibmm::TestProxy::createForBusFinish(result);

    /* Dictionary string -> variant */
    m_proxy->TestStringVariantDict(variantMapValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_string_variant_dict_finished), variantMapValue));
    m_pending_calls++;

    /* Dictionary string -> string */
    m_proxy->TestStringStringDict(stringMapValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_string_string_dict_finished), stringMapValue));
    m_pending_calls++;

    /* Dictionary uint -> int */
    m_proxy->TestUintIntDict(intMapValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_uint_int_dict_finished), intMapValue));
    m_pending_calls++;

    /* Variant */
    m_proxy->TestVariant(variantValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_variant_finished), variantValue));
    m_pending_calls++;

    /* Variant2 */
    m_proxy->TestVariant2(stringValue, variantValue,
                        sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_variant2_finished), stringValue, variantValue));
    m_pending_calls++;

    /* Byte string array */
    m_proxy->TestByteStringArray(inputStrVec, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_byte_string_array_finished), inputStrVec));
    m_pending_calls++;

    /* Object path array */
    m_proxy->TestObjectPathArray(inputObjPathVec, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_object_path_array_finished), inputObjPathVec));
    m_pending_calls++;

    /* String array */
    m_proxy->TestStringArray(stringArray, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_string_array_finished), stringArray));
    m_pending_calls++;

    /* Struct */
    m_proxy->TestStruct(structure, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_struct_finished), structure));
    m_pending_calls++;

    /* Struct array */
    m_proxy->TestStructArray(structArray, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_struct_array_finished), structArray));
    m_pending_calls++;

    /* Dict Struct array */
    m_proxy->TestDictStructArray(dictStructArray, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_dict_struct_array_finished), dictStructArray));
    m_pending_calls++;

    /* Byte string */
    m_proxy->TestByteString(bytestring, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_byte_string_finished), bytestring));
    m_pending_calls++;

    /* Signature */
    m_proxy->TestSignature(signatureValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_signature_finished), signatureValue));
    m_pending_calls++;

    /* Object path */
    m_proxy->TestObjectPath(objectPath, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_object_path_finished), objectPath));
    m_pending_calls++;

    /* String */
    m_proxy->TestString(stringValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_string_finished), stringValue));
    m_pending_calls++;

    /* Double */
    m_proxy->TestDouble(doubleValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_double_finished), doubleValue));
    m_pending_calls++;

    /* UInt64 */
    m_proxy->TestUInt64(uint64Value, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_uint64_finished), uint64Value));
    m_pending_calls++;

    /* Int64 */
    m_proxy->TestInt64(int64Value, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_int64_finished), int64Value));
    m_pending_calls++;

    /* UInt */
    m_proxy->TestUInt(uintValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_uint_finished), uintValue));
    m_pending_calls++;

    /* Int */
    m_proxy->TestInt(intValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_int_finished), intValue));
    m_pending_calls++;

    /* UInt16 */
    m_proxy->TestUInt16(uint16Value, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_uint16_finished), uint16Value));
    m_pending_calls++;

    /* Int16 */
    m_proxy->TestInt16(int16Value, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_int16_finished), int16Value));
    m_pending_calls++;

    /* Char */
    m_proxy->TestChar(ucharValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_uchar_finished), ucharValue));
    m_pending_calls++;

    /* Boolean */
    m_proxy->TestBoolean(booleanValue, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_boolean_finished), booleanValue));
    m_pending_calls++;

//    /* All */
//    m_proxy->TestAll(inputStrVec,
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
//                   sigc::mem_fun(this, &TestProxyImpl::on_test_all_finished));
//

    /* Test setting internal properties using a function */
    m_proxy->TestTriggerInternalPropertyChange(42, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_trigger_internal_property_change_finished), 42));
    m_pending_calls++;

    /* Test method errors */
    org::gdbus::codegen::glibmm::Error::initialize();
    m_proxy->TestError(sigc::mem_fun(this, &TestProxyImpl::on_test_error_finished));
    m_pending_calls++;

    std::vector<std::string> PropReadByteStringArrayValue;
    PropReadByteStringArrayValue.push_back("Value1");
    PropReadByteStringArrayValue.push_back("Value2");
    printStatus("Property (read): TestPropReadByteStringArray", m_proxy->TestPropReadByteStringArray_get() == PropReadByteStringArrayValue);

    std::vector<Glib::DBusObjectPathString> PropReadObjectPathArrayValue;
    PropReadObjectPathArrayValue.push_back("/Value3");
    PropReadObjectPathArrayValue.push_back("/Value4");
    printStatus("Property (read): TestPropReadObjectPathArrayValue", m_proxy->TestPropReadObjectPathArray_get() == PropReadObjectPathArrayValue);

    std::vector<Glib::ustring> PropReadStringArrayValue;
    PropReadStringArrayValue.push_back("Value5");
    PropReadStringArrayValue.push_back("Value6");
    printStatus("Property (read): TestPropReadStringArray", m_proxy->TestPropReadStringArray_get() == PropReadStringArrayValue);

    //std::string res = m_proxy->TestPropReadByteString_get();
    //res.push_back('\0');
    //std::cout << res << std::endl;
    printStatus("Property (read): TestPropReadByteString", m_proxy->TestPropReadByteString_get() == std::string("Value7"));
    printStatus("Property (read): TestPropReadSignature", m_proxy->TestPropReadSignature_get() == "sa{sv}a(bi)");
    printStatus("Property (read): TestPropReadObjectPath", m_proxy->TestPropReadObjectPath_get() == "/Value9");
    printStatus("Property (read): TestPropReadString", m_proxy->TestPropReadString_get() == "Value10");
    printStatus("Property (read): TestPropReadDouble", m_proxy->TestPropReadDouble_get() == 1337);
    printStatus("Property (read): TestPropReadUInt64", m_proxy->TestPropReadUInt64_get() == 1338);
    printStatus("Property (read): TestPropReadInt64", m_proxy->TestPropReadInt64_get() == 1339);
    printStatus("Property (read): TestPropReadUInt", m_proxy->TestPropReadUInt_get() == 1340);
    printStatus("Property (read): TestPropReadInt", m_proxy->TestPropReadInt_get() == 1341);
    printStatus("Property (read): TestPropReadUInt16", m_proxy->TestPropReadUInt16_get() == 1342);
    printStatus("Property (read): TestPropReadInt16", m_proxy->TestPropReadInt16_get() == 1343);
    printStatus("Property (read): TestPropReadChar", m_proxy->TestPropReadChar_get() == 'A');
    printStatus("Property (read): TestPropReadBoolean", m_proxy->TestPropReadBoolean_get() == true);
    
    bool valueOk = false;
    m_proxy->TestPropReadBoolean_get(&valueOk);
    printStatus("Property (read): TestPropReadStatusBoolOk", valueOk == true);

    std::vector<std::string> PropReadWriteByteStringArrayValue;
    PropReadWriteByteStringArrayValue.push_back("Value21");
    PropReadWriteByteStringArrayValue.push_back("Value22");
    printStatus("Property (read): TestPropReadWriteByteStringArray", m_proxy->TestPropReadWriteByteStringArray_get() == PropReadWriteByteStringArrayValue);

    std::vector<Glib::DBusObjectPathString> PropReadWriteObjectPathArrayValue;
    PropReadWriteObjectPathArrayValue.push_back("/object/path");

    printStatus("Property (read): TestPropReadWriteObjectPathArray", m_proxy->TestPropReadWriteObjectPathArray_get() == PropReadWriteObjectPathArrayValue);

    std::vector<Glib::ustring> PropReadWriteStringArrayValue;
    PropReadWriteStringArrayValue.push_back("Value24");
    printStatus("Property (read): TestPropReadWriteStringArrayValue", m_proxy->TestPropReadWriteStringArray_get() == PropReadWriteStringArrayValue);

    printStatus("Property (read): TestPropReadWriteByteString", m_proxy->TestPropReadWriteByteString_get() == "Value25");
    printStatus("Property (read): TestPropReadWriteSignature", m_proxy->TestPropReadWriteSignature_get() == "bada(ss)");
    printStatus("Property (read): TestPropReadWriteObjectPath", m_proxy->TestPropReadWriteObjectPath_get() == "/Value27");
    printStatus("Property (read): TestPropReadWriteString", m_proxy->TestPropReadWriteString_get() == "Value28");
    printStatus("Property (read): TestPropReadWriteDouble", m_proxy->TestPropReadWriteDouble_get() == 1351);
    printStatus("Property (read): TestPropReadWriteUInt64", m_proxy->TestPropReadWriteUInt64_get() == 1352);
    printStatus("Property (read): TestPropReadWriteInt64", m_proxy->TestPropReadWriteInt64_get() == 1353);
    printStatus("Property (read): TestPropReadWriteUInt", m_proxy->TestPropReadWriteUInt_get() == 1354);
    printStatus("Property (read): TestPropReadWriteInt", m_proxy->TestPropReadWriteInt_get() == 1355);
    printStatus("Property (read): TestPropReadWriteUInt16", m_proxy->TestPropReadWriteUInt16_get() == 1356);
    printStatus("Property (read): TestPropReadWriteInt16", m_proxy->TestPropReadWriteInt16_get() == 1357);
    printStatus("Property (read): TestPropReadWriteChar", m_proxy->TestPropReadWriteChar_get() == 'C');
    printStatus("Property (read): TestPropReadWriteBoolean", m_proxy->TestPropReadWriteBoolean_get() == true);

    std::vector<std::string> PropReadWriteByteStringArrayValue2;
    PropReadWriteByteStringArrayValue2.push_back("Hello");
    PropReadWriteByteStringArrayValue2.push_back("World");
    m_proxy->TestPropReadWriteByteStringArray_set(
        PropReadWriteByteStringArrayValue2,
        sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_byte_string_array),
                   PropReadWriteByteStringArrayValue2));

    std::vector<Glib::DBusObjectPathString> PropReadWriteObjectPathArrayValue2;
    PropReadWriteObjectPathArrayValue2.push_back("/object/path");
    m_proxy->TestPropReadWriteObjectPathArray_set(
        PropReadWriteObjectPathArrayValue2,
        sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_object_path_array),
                   PropReadWriteObjectPathArrayValue2));

    std::vector<Glib::ustring> PropReadWriteStringArrayValue2;
    PropReadWriteStringArrayValue2.push_back("Stringarray");
    m_proxy->TestPropReadWriteStringArray_set(
        PropReadWriteStringArrayValue2,
        sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_string_array),
                   PropReadWriteStringArrayValue2));

    m_proxy->TestPropReadWriteByteString_set(
        "ByteString test",
        sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_byte_string),
                   "ByteString test"));

    m_proxy->TestPropReadWriteSignature_set("b", sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_signature), "b"));
    m_proxy->TestPropReadWriteObjectPath_set("/some/where", sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_object_path), "/some/where"));
    m_proxy->TestPropReadWriteString_set("Hello world", sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_string), "Hello world"));
    m_proxy->TestPropReadWriteDouble_set(7331, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_double), 7331));
    m_proxy->TestPropReadWriteUInt64_set(7332, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_uint64), 7332));
    m_proxy->TestPropReadWriteInt64_set(7333, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_int64), 7333));
    m_proxy->TestPropReadWriteUInt_set(7334, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_uint), 7334));
    m_proxy->TestPropReadWriteInt_set(7335, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_int), 7335));
    m_proxy->TestPropReadWriteUInt16_set(7336, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_uint16), 7336));
    m_proxy->TestPropReadWriteInt16_set(7337, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_int16), 7337));
    m_proxy->TestPropReadWriteChar_set('X', sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_char), 'X'));
    m_proxy->TestPropReadWriteBoolean_set(true, sigc::bind(sigc::mem_fun(this, &TestProxyImpl::on_test_prop_read_write_boolean), true));

    /* Test change notification, for the properties we just changed. */
    expect_notification(m_proxy->TestPropReadWriteByteStringArray_changed());
    expect_notification(m_proxy->TestPropReadWriteObjectPathArray_changed());
    expect_notification(m_proxy->TestPropReadWriteStringArray_changed());
    expect_notification(m_proxy->TestPropReadWriteByteString_changed());
    expect_notification(m_proxy->TestPropReadWriteSignature_changed());
    expect_notification(m_proxy->TestPropReadWriteObjectPath_changed());
    expect_notification(m_proxy->TestPropReadWriteString_changed());
    expect_notification(m_proxy->TestPropReadWriteDouble_changed());
    expect_notification(m_proxy->TestPropReadWriteUInt64_changed());
    expect_notification(m_proxy->TestPropReadWriteInt64_changed());
    expect_notification(m_proxy->TestPropReadWriteUInt_changed());
    expect_notification(m_proxy->TestPropReadWriteInt_changed());
    expect_notification(m_proxy->TestPropReadWriteUInt16_changed());
    expect_notification(m_proxy->TestPropReadWriteInt16_changed());
    expect_notification(m_proxy->TestPropReadWriteChar_changed());
    expect_notification(m_proxy->TestPropReadWriteBoolean_changed());

    /* Test signal emissions */
    m_proxy->TestSignalByteStringArray_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_byte_string_array_cb));
    m_pending_signals++;
    m_proxy->TestSignalObjectPathArray_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_object_path_array_cb));
    m_pending_signals++;
    m_proxy->TestSignalStringArray_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_string_array_cb));
    m_pending_signals++;
    m_proxy->TestSignalByteString_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_byte_string_cb));
    m_pending_signals++;
    m_proxy->TestSignalSignature_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_signature_cb));
    m_pending_signals++;
    m_proxy->TestSignalObjectPath_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_object_path_cb));
    m_pending_signals++;
    m_proxy->TestSignalString_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_string_cb));
    m_pending_signals++;
    m_proxy->TestSignalDouble_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_double_cb));
    m_pending_signals++;
    m_proxy->TestSignalUInt64_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_uint64_cb));
    m_pending_signals++;
    m_proxy->TestSignalInt64_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_int64_cb));
    m_pending_signals++;
    m_proxy->TestSignalUInt_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_uint_cb));
    m_pending_signals++;
    m_proxy->TestSignalInt_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_int_cb));
    m_pending_signals++;
    m_proxy->TestSignalUInt16_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_uint16_cb));
    m_pending_signals++;
    m_proxy->TestSignalInt16_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_int16_cb));
    m_pending_signals++;
    m_proxy->TestSignalChar_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_char_cb));
    m_pending_signals++;
    m_proxy->TestSignalBoolean_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_signal_boolean_cb));
    m_pending_signals++;

    /* Test Selective signal */
    m_proxy->TestSelectiveSignal_signal.connect(
        sigc::mem_fun(this, &TestProxyImpl::on_test_selective_signal_cb));
    m_pending_signals++;
    m_proxy->TestSelectiveSignalTrigger_sync(true);
}

void TestProxyImpl::record_signal()
{
    m_pending_signals--;
    check_done();
}

int main() {
    Glib::init();
    Gio::init();

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();

    TestProxyImpl proxyTest;
    proxyTest.done().connect([&]() { ml->quit(); });

    /* Define a test timeout to ensure that the test terminates */
    Glib::signal_timeout().connect_seconds_once([&]() {
        proxyTest.fail();
    }, 10);

    ml->run();

    return proxyTest.exit_status();
}
