#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <glibmm.h>
#include <giomm.h>
#include "OUTPUT_DIR/input_common.h"

namespace org {
namespace gdbus {
namespace codegen {
namespace glibmm {

class Test : public Glib::ObjectBase {
public:
    static void createForBus(Gio::DBus::BusType busType,
                             Gio::DBus::ProxyFlags proxyFlags,
                             const std::string &name,
                             const std::string &objectPath,
                             const Gio::SlotAsyncReady &slot,
                             const Glib::RefPtr<Gio::Cancellable> &cancellable = {});

    static Glib::RefPtr<Test> createForBusFinish (Glib::RefPtr<Gio::AsyncResult> result);

    static Glib::RefPtr<Test> createForBus_sync(
        Gio::DBus::BusType busType,
        Gio::DBus::ProxyFlags proxyFlags,
        const std::string &name,
        const std::string &objectPath,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {});

    Glib::RefPtr<Gio::DBus::Proxy> dbusProxy() const { return m_proxy; }

    void TestStringVariantDict(
        const std::map<Glib::ustring,Glib::VariantBase> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStringVariantDict_finish (
        std::map<Glib::ustring,Glib::VariantBase> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::map<Glib::ustring,Glib::VariantBase>
    TestStringVariantDict_sync(
        const std::map<Glib::ustring,Glib::VariantBase> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStringStringDict(
        const std::map<Glib::ustring,Glib::ustring> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStringStringDict_finish (
        std::map<Glib::ustring,Glib::ustring> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::map<Glib::ustring,Glib::ustring>
    TestStringStringDict_sync(
        const std::map<Glib::ustring,Glib::ustring> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUintIntDict(
        const std::map<guint32,gint32> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUintIntDict_finish (
        std::map<guint32,gint32> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::map<guint32,gint32>
    TestUintIntDict_sync(
        const std::map<guint32,gint32> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestVariant(
        const Glib::VariantBase & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestVariant_finish (
        Glib::VariantBase &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    Glib::VariantBase
    TestVariant_sync(
        const Glib::VariantBase & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestVariant2(
        const Glib::ustring & Param1,
        const Glib::VariantBase & Param2,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestVariant2_finish (
        Glib::ustring &Param3,
        Glib::VariantBase &Param4,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::tuple<Glib::ustring, Glib::VariantBase>
    TestVariant2_sync(
        const Glib::ustring & Param1,        const Glib::VariantBase & Param2,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestByteStringArray(
        const std::vector<std::string> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestByteStringArray_finish (
        std::vector<std::string> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<std::string>
    TestByteStringArray_sync(
        const std::vector<std::string> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestObjectPathArray(
        const std::vector<Glib::DBusObjectPathString> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestObjectPathArray_finish (
        std::vector<Glib::DBusObjectPathString> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<Glib::DBusObjectPathString>
    TestObjectPathArray_sync(
        const std::vector<Glib::DBusObjectPathString> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStringArray(
        const std::vector<Glib::ustring> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStringArray_finish (
        std::vector<Glib::ustring> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<Glib::ustring>
    TestStringArray_sync(
        const std::vector<Glib::ustring> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestByteString(
        const std::string & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestByteString_finish (
        std::string &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::string
    TestByteString_sync(
        const std::string & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStruct(
        const std::tuple<Glib::ustring,Glib::ustring> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStruct_finish (
        std::tuple<Glib::ustring,Glib::ustring> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::tuple<Glib::ustring,Glib::ustring>
    TestStruct_sync(
        const std::tuple<Glib::ustring,Glib::ustring> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStructArray(
        const std::vector<std::tuple<guint32,Glib::ustring,gint32>> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestStructArray_finish (
        std::vector<std::tuple<guint32,Glib::ustring,gint32>> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<std::tuple<guint32,Glib::ustring,gint32>>
    TestStructArray_sync(
        const std::vector<std::tuple<guint32,Glib::ustring,gint32>> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestDictStructArray(
        const std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestDictStructArray_finish (
        std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>
    TestDictStructArray_sync(
        const std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestSignature(
        const Glib::DBusSignatureString & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestSignature_finish (
        Glib::DBusSignatureString &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    Glib::DBusSignatureString
    TestSignature_sync(
        const Glib::DBusSignatureString & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestObjectPath(
        const Glib::DBusObjectPathString & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestObjectPath_finish (
        Glib::DBusObjectPathString &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    Glib::DBusObjectPathString
    TestObjectPath_sync(
        const Glib::DBusObjectPathString & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestString(
        const Glib::ustring & Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestString_finish (
        Glib::ustring &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    Glib::ustring
    TestString_sync(
        const Glib::ustring & Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestDouble(
        double Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestDouble_finish (
        double &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    double
    TestDouble_sync(
        double Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt64(
        guint64 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt64_finish (
        guint64 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    guint64
    TestUInt64_sync(
        guint64 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt64(
        gint64 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt64_finish (
        gint64 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    gint64
    TestInt64_sync(
        gint64 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt(
        guint32 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt_finish (
        guint32 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    guint32
    TestUInt_sync(
        guint32 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt(
        gint32 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt_finish (
        gint32 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    gint32
    TestInt_sync(
        gint32 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt16(
        guint16 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestUInt16_finish (
        guint16 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    guint16
    TestUInt16_sync(
        guint16 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt16(
        gint16 Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestInt16_finish (
        gint16 &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    gint16
    TestInt16_sync(
        gint16 Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestChar(
        guchar Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestChar_finish (
        guchar &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    guchar
    TestChar_sync(
        guchar Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestBoolean(
        bool Param1,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestBoolean_finish (
        bool &Param2,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    bool
    TestBoolean_sync(
        bool Param1,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestAll(
        const std::vector<std::string> & in_Param1,
        const std::vector<Glib::DBusObjectPathString> & in_Param2,
        const std::vector<Glib::ustring> & in_Param3,
        const std::string & in_Param4,
        const Glib::DBusSignatureString & in_Param5,
        const Glib::DBusObjectPathString & in_Param6,
        const Glib::ustring & in_Param7,
        double in_Param8,
        guint64 in_Param9,
        gint64 in_Param10,
        guint32 in_Param11,
        gint32 in_Param12,
        guint16 in_Param13,
        gint16 in_Param14,
        guchar in_Param15,
        bool in_Param16,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestAll_finish (
        std::vector<std::string> &out_Param1,
        std::vector<Glib::DBusObjectPathString> &out_Param2,
        std::vector<Glib::ustring> &out_Param3,
        std::string &out_Param4,
        Glib::DBusSignatureString &out_Param5,
        Glib::DBusObjectPathString &out_Param6,
        Glib::ustring &out_Param7,
        double &out_Param8,
        guint64 &out_Param9,
        gint64 &out_Param10,
        guint32 &out_Param11,
        gint32 &out_Param12,
        guint16 &out_Param13,
        gint16 &out_Param14,
        guchar &out_Param15,
        bool &out_Param16,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::tuple<std::vector<std::string>, std::vector<Glib::DBusObjectPathString>, std::vector<Glib::ustring>, std::string, Glib::DBusSignatureString, Glib::DBusObjectPathString, Glib::ustring, double, guint64, gint64, guint32, gint32, guint16, gint16, guchar, bool>
    TestAll_sync(
        const std::vector<std::string> & in_Param1,        const std::vector<Glib::DBusObjectPathString> & in_Param2,        const std::vector<Glib::ustring> & in_Param3,        const std::string & in_Param4,        const Glib::DBusSignatureString & in_Param5,        const Glib::DBusObjectPathString & in_Param6,        const Glib::ustring & in_Param7,        double in_Param8,        guint64 in_Param9,        gint64 in_Param10,        guint32 in_Param11,        gint32 in_Param12,        guint16 in_Param13,        gint16 in_Param14,        guchar in_Param15,        bool in_Param16,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestTriggerInternalPropertyChange(
        gint32 NewPropertyValue,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestTriggerInternalPropertyChange_finish (
        const Glib::RefPtr<Gio::AsyncResult> &res);

    void
    TestTriggerInternalPropertyChange_sync(
        gint32 NewPropertyValue,const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    std::vector<std::string> TestPropReadByteStringArray_get();
    sigc::signal<void> &TestPropReadByteStringArray_changed() {
        return m_TestPropReadByteStringArray_changed;
    }

    std::vector<Glib::DBusObjectPathString> TestPropReadObjectPathArray_get();
    sigc::signal<void> &TestPropReadObjectPathArray_changed() {
        return m_TestPropReadObjectPathArray_changed;
    }

    std::vector<Glib::ustring> TestPropReadStringArray_get();
    sigc::signal<void> &TestPropReadStringArray_changed() {
        return m_TestPropReadStringArray_changed;
    }

    std::string TestPropReadByteString_get();
    sigc::signal<void> &TestPropReadByteString_changed() {
        return m_TestPropReadByteString_changed;
    }

    Glib::DBusSignatureString TestPropReadSignature_get();
    sigc::signal<void> &TestPropReadSignature_changed() {
        return m_TestPropReadSignature_changed;
    }

    Glib::DBusObjectPathString TestPropReadObjectPath_get();
    sigc::signal<void> &TestPropReadObjectPath_changed() {
        return m_TestPropReadObjectPath_changed;
    }

    Glib::ustring TestPropReadString_get();
    sigc::signal<void> &TestPropReadString_changed() {
        return m_TestPropReadString_changed;
    }

    double TestPropReadDouble_get();
    sigc::signal<void> &TestPropReadDouble_changed() {
        return m_TestPropReadDouble_changed;
    }

    guint64 TestPropReadUInt64_get();
    sigc::signal<void> &TestPropReadUInt64_changed() {
        return m_TestPropReadUInt64_changed;
    }

    gint64 TestPropReadInt64_get();
    sigc::signal<void> &TestPropReadInt64_changed() {
        return m_TestPropReadInt64_changed;
    }

    guint32 TestPropReadUInt_get();
    sigc::signal<void> &TestPropReadUInt_changed() {
        return m_TestPropReadUInt_changed;
    }

    gint32 TestPropReadInt_get();
    sigc::signal<void> &TestPropReadInt_changed() {
        return m_TestPropReadInt_changed;
    }

    guint16 TestPropReadUInt16_get();
    sigc::signal<void> &TestPropReadUInt16_changed() {
        return m_TestPropReadUInt16_changed;
    }

    gint16 TestPropReadInt16_get();
    sigc::signal<void> &TestPropReadInt16_changed() {
        return m_TestPropReadInt16_changed;
    }

    guchar TestPropReadChar_get();
    sigc::signal<void> &TestPropReadChar_changed() {
        return m_TestPropReadChar_changed;
    }

    bool TestPropReadBoolean_get();
    sigc::signal<void> &TestPropReadBoolean_changed() {
        return m_TestPropReadBoolean_changed;
    }

    gint32 TestPropInternalReadPropertyChange_get();
    sigc::signal<void> &TestPropInternalReadPropertyChange_changed() {
        return m_TestPropInternalReadPropertyChange_changed;
    }

    void TestPropWriteByteStringArray_set(const std::vector<std::string> &, const Gio::SlotAsyncReady &);
    void TestPropWriteByteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteByteStringArray_set_sync(const std::vector<std::string> &);
    sigc::signal<void> &TestPropWriteByteStringArray_changed() {
        return m_TestPropWriteByteStringArray_changed;
    }

    void TestPropWriteObjectPathArray_set(const std::vector<Glib::DBusObjectPathString> &, const Gio::SlotAsyncReady &);
    void TestPropWriteObjectPathArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteObjectPathArray_set_sync(const std::vector<Glib::DBusObjectPathString> &);
    sigc::signal<void> &TestPropWriteObjectPathArray_changed() {
        return m_TestPropWriteObjectPathArray_changed;
    }

    void TestPropWriteStringArray_set(const std::vector<Glib::ustring> &, const Gio::SlotAsyncReady &);
    void TestPropWriteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteStringArray_set_sync(const std::vector<Glib::ustring> &);
    sigc::signal<void> &TestPropWriteStringArray_changed() {
        return m_TestPropWriteStringArray_changed;
    }

    void TestPropWriteByteString_set(const std::string &, const Gio::SlotAsyncReady &);
    void TestPropWriteByteString_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteByteString_set_sync(const std::string &);
    sigc::signal<void> &TestPropWriteByteString_changed() {
        return m_TestPropWriteByteString_changed;
    }

    void TestPropWriteSignature_set(const Glib::DBusSignatureString &, const Gio::SlotAsyncReady &);
    void TestPropWriteSignature_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteSignature_set_sync(const Glib::DBusSignatureString &);
    sigc::signal<void> &TestPropWriteSignature_changed() {
        return m_TestPropWriteSignature_changed;
    }

    void TestPropWriteObjectPath_set(const Glib::DBusObjectPathString &, const Gio::SlotAsyncReady &);
    void TestPropWriteObjectPath_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteObjectPath_set_sync(const Glib::DBusObjectPathString &);
    sigc::signal<void> &TestPropWriteObjectPath_changed() {
        return m_TestPropWriteObjectPath_changed;
    }

    void TestPropWriteString_set(const Glib::ustring &, const Gio::SlotAsyncReady &);
    void TestPropWriteString_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteString_set_sync(const Glib::ustring &);
    sigc::signal<void> &TestPropWriteString_changed() {
        return m_TestPropWriteString_changed;
    }

    void TestPropWriteDouble_set(double, const Gio::SlotAsyncReady &);
    void TestPropWriteDouble_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteDouble_set_sync(double);
    sigc::signal<void> &TestPropWriteDouble_changed() {
        return m_TestPropWriteDouble_changed;
    }

    void TestPropWriteUInt64_set(guint64, const Gio::SlotAsyncReady &);
    void TestPropWriteUInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteUInt64_set_sync(guint64);
    sigc::signal<void> &TestPropWriteUInt64_changed() {
        return m_TestPropWriteUInt64_changed;
    }

    void TestPropWriteInt64_set(gint64, const Gio::SlotAsyncReady &);
    void TestPropWriteInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteInt64_set_sync(gint64);
    sigc::signal<void> &TestPropWriteInt64_changed() {
        return m_TestPropWriteInt64_changed;
    }

    void TestPropWriteUInt_set(guint32, const Gio::SlotAsyncReady &);
    void TestPropWriteUInt_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteUInt_set_sync(guint32);
    sigc::signal<void> &TestPropWriteUInt_changed() {
        return m_TestPropWriteUInt_changed;
    }

    void TestPropWriteInt_set(gint32, const Gio::SlotAsyncReady &);
    void TestPropWriteInt_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteInt_set_sync(gint32);
    sigc::signal<void> &TestPropWriteInt_changed() {
        return m_TestPropWriteInt_changed;
    }

    void TestPropWriteUInt16_set(guint16, const Gio::SlotAsyncReady &);
    void TestPropWriteUInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteUInt16_set_sync(guint16);
    sigc::signal<void> &TestPropWriteUInt16_changed() {
        return m_TestPropWriteUInt16_changed;
    }

    void TestPropWriteInt16_set(gint16, const Gio::SlotAsyncReady &);
    void TestPropWriteInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteInt16_set_sync(gint16);
    sigc::signal<void> &TestPropWriteInt16_changed() {
        return m_TestPropWriteInt16_changed;
    }

    void TestPropWriteChar_set(guchar, const Gio::SlotAsyncReady &);
    void TestPropWriteChar_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteChar_set_sync(guchar);
    sigc::signal<void> &TestPropWriteChar_changed() {
        return m_TestPropWriteChar_changed;
    }

    void TestPropWriteBoolean_set(bool, const Gio::SlotAsyncReady &);
    void TestPropWriteBoolean_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropWriteBoolean_set_sync(bool);
    sigc::signal<void> &TestPropWriteBoolean_changed() {
        return m_TestPropWriteBoolean_changed;
    }

    std::vector<std::string> TestPropReadWriteByteStringArray_get();
    void TestPropReadWriteByteStringArray_set(const std::vector<std::string> &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteByteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteByteStringArray_set_sync(const std::vector<std::string> &);
    sigc::signal<void> &TestPropReadWriteByteStringArray_changed() {
        return m_TestPropReadWriteByteStringArray_changed;
    }

    std::vector<Glib::DBusObjectPathString> TestPropReadWriteObjectPathArray_get();
    void TestPropReadWriteObjectPathArray_set(const std::vector<Glib::DBusObjectPathString> &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteObjectPathArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteObjectPathArray_set_sync(const std::vector<Glib::DBusObjectPathString> &);
    sigc::signal<void> &TestPropReadWriteObjectPathArray_changed() {
        return m_TestPropReadWriteObjectPathArray_changed;
    }

    std::vector<Glib::ustring> TestPropReadWriteStringArray_get();
    void TestPropReadWriteStringArray_set(const std::vector<Glib::ustring> &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteStringArray_set_sync(const std::vector<Glib::ustring> &);
    sigc::signal<void> &TestPropReadWriteStringArray_changed() {
        return m_TestPropReadWriteStringArray_changed;
    }

    std::string TestPropReadWriteByteString_get();
    void TestPropReadWriteByteString_set(const std::string &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteByteString_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteByteString_set_sync(const std::string &);
    sigc::signal<void> &TestPropReadWriteByteString_changed() {
        return m_TestPropReadWriteByteString_changed;
    }

    Glib::DBusSignatureString TestPropReadWriteSignature_get();
    void TestPropReadWriteSignature_set(const Glib::DBusSignatureString &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteSignature_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteSignature_set_sync(const Glib::DBusSignatureString &);
    sigc::signal<void> &TestPropReadWriteSignature_changed() {
        return m_TestPropReadWriteSignature_changed;
    }

    Glib::DBusObjectPathString TestPropReadWriteObjectPath_get();
    void TestPropReadWriteObjectPath_set(const Glib::DBusObjectPathString &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteObjectPath_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteObjectPath_set_sync(const Glib::DBusObjectPathString &);
    sigc::signal<void> &TestPropReadWriteObjectPath_changed() {
        return m_TestPropReadWriteObjectPath_changed;
    }

    Glib::ustring TestPropReadWriteString_get();
    void TestPropReadWriteString_set(const Glib::ustring &, const Gio::SlotAsyncReady &);
    void TestPropReadWriteString_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteString_set_sync(const Glib::ustring &);
    sigc::signal<void> &TestPropReadWriteString_changed() {
        return m_TestPropReadWriteString_changed;
    }

    double TestPropReadWriteDouble_get();
    void TestPropReadWriteDouble_set(double, const Gio::SlotAsyncReady &);
    void TestPropReadWriteDouble_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteDouble_set_sync(double);
    sigc::signal<void> &TestPropReadWriteDouble_changed() {
        return m_TestPropReadWriteDouble_changed;
    }

    guint64 TestPropReadWriteUInt64_get();
    void TestPropReadWriteUInt64_set(guint64, const Gio::SlotAsyncReady &);
    void TestPropReadWriteUInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteUInt64_set_sync(guint64);
    sigc::signal<void> &TestPropReadWriteUInt64_changed() {
        return m_TestPropReadWriteUInt64_changed;
    }

    gint64 TestPropReadWriteInt64_get();
    void TestPropReadWriteInt64_set(gint64, const Gio::SlotAsyncReady &);
    void TestPropReadWriteInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteInt64_set_sync(gint64);
    sigc::signal<void> &TestPropReadWriteInt64_changed() {
        return m_TestPropReadWriteInt64_changed;
    }

    guint32 TestPropReadWriteUInt_get();
    void TestPropReadWriteUInt_set(guint32, const Gio::SlotAsyncReady &);
    void TestPropReadWriteUInt_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteUInt_set_sync(guint32);
    sigc::signal<void> &TestPropReadWriteUInt_changed() {
        return m_TestPropReadWriteUInt_changed;
    }

    gint32 TestPropReadWriteInt_get();
    void TestPropReadWriteInt_set(gint32, const Gio::SlotAsyncReady &);
    void TestPropReadWriteInt_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteInt_set_sync(gint32);
    sigc::signal<void> &TestPropReadWriteInt_changed() {
        return m_TestPropReadWriteInt_changed;
    }

    guint16 TestPropReadWriteUInt16_get();
    void TestPropReadWriteUInt16_set(guint16, const Gio::SlotAsyncReady &);
    void TestPropReadWriteUInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteUInt16_set_sync(guint16);
    sigc::signal<void> &TestPropReadWriteUInt16_changed() {
        return m_TestPropReadWriteUInt16_changed;
    }

    gint16 TestPropReadWriteInt16_get();
    void TestPropReadWriteInt16_set(gint16, const Gio::SlotAsyncReady &);
    void TestPropReadWriteInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteInt16_set_sync(gint16);
    sigc::signal<void> &TestPropReadWriteInt16_changed() {
        return m_TestPropReadWriteInt16_changed;
    }

    guchar TestPropReadWriteChar_get();
    void TestPropReadWriteChar_set(guchar, const Gio::SlotAsyncReady &);
    void TestPropReadWriteChar_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteChar_set_sync(guchar);
    sigc::signal<void> &TestPropReadWriteChar_changed() {
        return m_TestPropReadWriteChar_changed;
    }

    bool TestPropReadWriteBoolean_get();
    void TestPropReadWriteBoolean_set(bool, const Gio::SlotAsyncReady &);
    void TestPropReadWriteBoolean_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropReadWriteBoolean_set_sync(bool);
    sigc::signal<void> &TestPropReadWriteBoolean_changed() {
        return m_TestPropReadWriteBoolean_changed;
    }

    gint32 TestPropInternalReadWritePropertyChange_get();
    void TestPropInternalReadWritePropertyChange_set(gint32, const Gio::SlotAsyncReady &);
    void TestPropInternalReadWritePropertyChange_set_finish(const Glib::RefPtr<Gio::AsyncResult> &);
    void TestPropInternalReadWritePropertyChange_set_sync(gint32);
    sigc::signal<void> &TestPropInternalReadWritePropertyChange_changed() {
        return m_TestPropInternalReadWritePropertyChange_changed;
    }

    sigc::signal<void, std::vector<std::string> > TestSignalByteStringArray_signal;
    sigc::signal<void, std::vector<Glib::DBusObjectPathString> > TestSignalObjectPathArray_signal;
    sigc::signal<void, std::vector<Glib::ustring> > TestSignalStringArray_signal;
    sigc::signal<void, std::string > TestSignalByteString_signal;
    sigc::signal<void, Glib::DBusSignatureString > TestSignalSignature_signal;
    sigc::signal<void, Glib::DBusObjectPathString > TestSignalObjectPath_signal;
    sigc::signal<void, Glib::ustring > TestSignalString_signal;
    sigc::signal<void, double > TestSignalDouble_signal;
    sigc::signal<void, guint64 > TestSignalUInt64_signal;
    sigc::signal<void, gint64 > TestSignalInt64_signal;
    sigc::signal<void, guint32 > TestSignalUInt_signal;
    sigc::signal<void, gint32 > TestSignalInt_signal;
    sigc::signal<void, guint16 > TestSignalUInt16_signal;
    sigc::signal<void, gint16 > TestSignalInt16_signal;
    sigc::signal<void, guchar > TestSignalChar_signal;
    sigc::signal<void, bool > TestSignalBoolean_signal;

    void reference() const override {}
    void unreference() const override {}

protected:
    Glib::RefPtr<Gio::DBus::Proxy> m_proxy;

private:
    Test(const Glib::RefPtr<Gio::DBus::Proxy> &proxy);

    void handle_signal(const Glib::ustring &sender_name,
                       const Glib::ustring &signal_name,
                       const Glib::VariantContainerBase &parameters);

    void handle_properties_changed(const Gio::DBus::Proxy::MapChangedProperties &changed_properties,
                                   const std::vector<Glib::ustring> &invalidated_properties);

    sigc::signal<void> m_TestPropReadByteStringArray_changed;
    sigc::signal<void> m_TestPropReadObjectPathArray_changed;
    sigc::signal<void> m_TestPropReadStringArray_changed;
    sigc::signal<void> m_TestPropReadByteString_changed;
    sigc::signal<void> m_TestPropReadSignature_changed;
    sigc::signal<void> m_TestPropReadObjectPath_changed;
    sigc::signal<void> m_TestPropReadString_changed;
    sigc::signal<void> m_TestPropReadDouble_changed;
    sigc::signal<void> m_TestPropReadUInt64_changed;
    sigc::signal<void> m_TestPropReadInt64_changed;
    sigc::signal<void> m_TestPropReadUInt_changed;
    sigc::signal<void> m_TestPropReadInt_changed;
    sigc::signal<void> m_TestPropReadUInt16_changed;
    sigc::signal<void> m_TestPropReadInt16_changed;
    sigc::signal<void> m_TestPropReadChar_changed;
    sigc::signal<void> m_TestPropReadBoolean_changed;
    sigc::signal<void> m_TestPropInternalReadPropertyChange_changed;
    sigc::signal<void> m_TestPropWriteByteStringArray_changed;
    sigc::signal<void> m_TestPropWriteObjectPathArray_changed;
    sigc::signal<void> m_TestPropWriteStringArray_changed;
    sigc::signal<void> m_TestPropWriteByteString_changed;
    sigc::signal<void> m_TestPropWriteSignature_changed;
    sigc::signal<void> m_TestPropWriteObjectPath_changed;
    sigc::signal<void> m_TestPropWriteString_changed;
    sigc::signal<void> m_TestPropWriteDouble_changed;
    sigc::signal<void> m_TestPropWriteUInt64_changed;
    sigc::signal<void> m_TestPropWriteInt64_changed;
    sigc::signal<void> m_TestPropWriteUInt_changed;
    sigc::signal<void> m_TestPropWriteInt_changed;
    sigc::signal<void> m_TestPropWriteUInt16_changed;
    sigc::signal<void> m_TestPropWriteInt16_changed;
    sigc::signal<void> m_TestPropWriteChar_changed;
    sigc::signal<void> m_TestPropWriteBoolean_changed;
    sigc::signal<void> m_TestPropReadWriteByteStringArray_changed;
    sigc::signal<void> m_TestPropReadWriteObjectPathArray_changed;
    sigc::signal<void> m_TestPropReadWriteStringArray_changed;
    sigc::signal<void> m_TestPropReadWriteByteString_changed;
    sigc::signal<void> m_TestPropReadWriteSignature_changed;
    sigc::signal<void> m_TestPropReadWriteObjectPath_changed;
    sigc::signal<void> m_TestPropReadWriteString_changed;
    sigc::signal<void> m_TestPropReadWriteDouble_changed;
    sigc::signal<void> m_TestPropReadWriteUInt64_changed;
    sigc::signal<void> m_TestPropReadWriteInt64_changed;
    sigc::signal<void> m_TestPropReadWriteUInt_changed;
    sigc::signal<void> m_TestPropReadWriteInt_changed;
    sigc::signal<void> m_TestPropReadWriteUInt16_changed;
    sigc::signal<void> m_TestPropReadWriteInt16_changed;
    sigc::signal<void> m_TestPropReadWriteChar_changed;
    sigc::signal<void> m_TestPropReadWriteBoolean_changed;
    sigc::signal<void> m_TestPropInternalReadWritePropertyChange_changed;
};

}// glibmm
}// codegen
}// gdbus
}// org

