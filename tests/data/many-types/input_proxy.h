#pragma once
#include <string>
#include <glibmm.h>
#include <giomm.h>
#include "OUTPUT_DIR/input_common.h"

namespace org {
namespace gdbus {
namespace codegen {
namespace glibmm {

class Test : public Glib::ObjectBase {
public:
    static void createForBus (Gio::DBus::BusType busType,
                              Gio::DBus::ProxyFlags proxyFlags,
                              const std::string &name,
                              const std::string &objectPath,
                              const Gio::SlotAsyncReady &slot);

    static Glib::RefPtr<Test> createForBusFinish (Glib::RefPtr<Gio::AsyncResult> result);

    void TestStringVariantDict (
        std::map<Glib::ustring,Glib::VariantBase> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestStringVariantDict_finish (
        std::map<Glib::ustring,Glib::VariantBase>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestStringStringDict (
        std::map<Glib::ustring,Glib::ustring> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestStringStringDict_finish (
        std::map<Glib::ustring,Glib::ustring>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestUintIntDict (
        std::map<guint32,gint32> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestUintIntDict_finish (
        std::map<guint32,gint32>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    template <typename T>
    void TestVariant(
        T Param1,
        const Gio::SlotAsyncReady &callback)
    {
        Glib::VariantContainerBase base;
        Glib::Variant<Glib::Variant<T> > variantValue;
        variantValue = Glib::Variant<Glib::Variant<T> >::create(Glib::Variant<T>::create(Param1));
        Glib::VariantBase params = variantValue;
        base = Glib::VariantContainerBase::create_tuple(params);

    m_proxy->call(
        "TestVariant",
        callback,
        base);
}

    void TestVariant_finish (
        Glib::VariantBase& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestByteStringArray (
        std::vector<std::string> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestByteStringArray_finish (
        std::vector<std::string>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestObjectPathArray (
        std::vector<std::string> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestObjectPathArray_finish (
        std::vector<std::string>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestStringArray (
        std::vector<std::string> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestStringArray_finish (
        std::vector<std::string>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestByteString (
        std::string Param1,
        const Gio::SlotAsyncReady &slot);

    void TestByteString_finish (
        std::string& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestStruct (
        std::tuple<Glib::ustring,Glib::ustring> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestStruct_finish (
        std::tuple<Glib::ustring,Glib::ustring>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestStructArray (
        std::vector<std::tuple<guint32,Glib::ustring,gint32>> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestStructArray_finish (
        std::vector<std::tuple<guint32,Glib::ustring,gint32>>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestDictStructArray (
        std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> Param1,
        const Gio::SlotAsyncReady &slot);

    void TestDictStructArray_finish (
        std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestSignature (
        std::string Param1,
        const Gio::SlotAsyncReady &slot);

    void TestSignature_finish (
        std::string& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestObjectPath (
        std::string Param1,
        const Gio::SlotAsyncReady &slot);

    void TestObjectPath_finish (
        std::string& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestString (
        std::string Param1,
        const Gio::SlotAsyncReady &slot);

    void TestString_finish (
        std::string& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestDouble (
        double Param1,
        const Gio::SlotAsyncReady &slot);

    void TestDouble_finish (
        double& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestUInt64 (
        guint64 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestUInt64_finish (
        guint64& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestInt64 (
        gint64 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestInt64_finish (
        gint64& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestUInt (
        guint32 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestUInt_finish (
        guint32& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestInt (
        gint32 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestInt_finish (
        gint32& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestUInt16 (
        guint16 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestUInt16_finish (
        guint16& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestInt16 (
        gint16 Param1,
        const Gio::SlotAsyncReady &slot);

    void TestInt16_finish (
        gint16& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestChar (
        guchar Param1,
        const Gio::SlotAsyncReady &slot);

    void TestChar_finish (
        guchar& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestBoolean (
        bool Param1,
        const Gio::SlotAsyncReady &slot);

    void TestBoolean_finish (
        bool& Param2,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestAll (
        std::vector<std::string> in_Param1,
        std::vector<std::string> in_Param2,
        std::vector<std::string> in_Param3,
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
        const Gio::SlotAsyncReady &slot);

    void TestAll_finish (
        std::vector<std::string>& out_Param1,
        std::vector<std::string>& out_Param2,
        std::vector<std::string>& out_Param3,
        std::string& out_Param4,
        std::string& out_Param5,
        std::string& out_Param6,
        std::string& out_Param7,
        double& out_Param8,
        guint64& out_Param9,
        gint64& out_Param10,
        guint32& out_Param11,
        gint32& out_Param12,
        guint16& out_Param13,
        gint16& out_Param14,
        guchar& out_Param15,
        bool& out_Param16,
        const Glib::RefPtr<Gio::AsyncResult>& res);

    void TestTriggerInternalPropertyChange (
        gint32 NewPropertyValue,
        const Gio::SlotAsyncReady &slot);

    void TestTriggerInternalPropertyChange_finish (
        const Glib::RefPtr<Gio::AsyncResult>& res);

     std::vector<std::string> TestPropReadByteStringArray_get();
     std::vector<std::string> TestPropReadObjectPathArray_get();
     std::vector<std::string> TestPropReadStringArray_get();
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
     gint32 TestPropInternalReadPropertyChange_get();
     void TestPropWriteByteStringArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropWriteByteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteObjectPathArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropWriteObjectPathArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteStringArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropWriteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteByteString_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropWriteByteString_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteSignature_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropWriteSignature_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteObjectPath_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropWriteObjectPath_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteString_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropWriteString_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteDouble_set(double, const Gio::SlotAsyncReady &);
     void TestPropWriteDouble_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteUInt64_set(guint64, const Gio::SlotAsyncReady &);
     void TestPropWriteUInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteInt64_set(gint64, const Gio::SlotAsyncReady &);
     void TestPropWriteInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteUInt_set(guint32, const Gio::SlotAsyncReady &);
     void TestPropWriteUInt_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteInt_set(gint32, const Gio::SlotAsyncReady &);
     void TestPropWriteInt_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteUInt16_set(guint16, const Gio::SlotAsyncReady &);
     void TestPropWriteUInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteInt16_set(gint16, const Gio::SlotAsyncReady &);
     void TestPropWriteInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteChar_set(guchar, const Gio::SlotAsyncReady &);
     void TestPropWriteChar_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     void TestPropWriteBoolean_set(bool, const Gio::SlotAsyncReady &);
     void TestPropWriteBoolean_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::vector<std::string> TestPropReadWriteByteStringArray_get();
     void TestPropReadWriteByteStringArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropReadWriteByteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::vector<std::string> TestPropReadWriteObjectPathArray_get();
     void TestPropReadWriteObjectPathArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropReadWriteObjectPathArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::vector<std::string> TestPropReadWriteStringArray_get();
     void TestPropReadWriteStringArray_set(std::vector<std::string>, const Gio::SlotAsyncReady &);
     void TestPropReadWriteStringArray_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::string TestPropReadWriteByteString_get();
     void TestPropReadWriteByteString_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropReadWriteByteString_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::string TestPropReadWriteSignature_get();
     void TestPropReadWriteSignature_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropReadWriteSignature_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::string TestPropReadWriteObjectPath_get();
     void TestPropReadWriteObjectPath_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropReadWriteObjectPath_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     std::string TestPropReadWriteString_get();
     void TestPropReadWriteString_set(std::string, const Gio::SlotAsyncReady &);
     void TestPropReadWriteString_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     double TestPropReadWriteDouble_get();
     void TestPropReadWriteDouble_set(double, const Gio::SlotAsyncReady &);
     void TestPropReadWriteDouble_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     guint64 TestPropReadWriteUInt64_get();
     void TestPropReadWriteUInt64_set(guint64, const Gio::SlotAsyncReady &);
     void TestPropReadWriteUInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     gint64 TestPropReadWriteInt64_get();
     void TestPropReadWriteInt64_set(gint64, const Gio::SlotAsyncReady &);
     void TestPropReadWriteInt64_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     guint32 TestPropReadWriteUInt_get();
     void TestPropReadWriteUInt_set(guint32, const Gio::SlotAsyncReady &);
     void TestPropReadWriteUInt_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     gint32 TestPropReadWriteInt_get();
     void TestPropReadWriteInt_set(gint32, const Gio::SlotAsyncReady &);
     void TestPropReadWriteInt_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     guint16 TestPropReadWriteUInt16_get();
     void TestPropReadWriteUInt16_set(guint16, const Gio::SlotAsyncReady &);
     void TestPropReadWriteUInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     gint16 TestPropReadWriteInt16_get();
     void TestPropReadWriteInt16_set(gint16, const Gio::SlotAsyncReady &);
     void TestPropReadWriteInt16_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     guchar TestPropReadWriteChar_get();
     void TestPropReadWriteChar_set(guchar, const Gio::SlotAsyncReady &);
     void TestPropReadWriteChar_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     bool TestPropReadWriteBoolean_get();
     void TestPropReadWriteBoolean_set(bool, const Gio::SlotAsyncReady &);
     void TestPropReadWriteBoolean_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
     gint32 TestPropInternalReadWritePropertyChange_get();
     void TestPropInternalReadWritePropertyChange_set(gint32, const Gio::SlotAsyncReady &);
     void TestPropInternalReadWritePropertyChange_set_finish(const Glib::RefPtr<Gio::AsyncResult>&);
sigc::signal<void, std::vector<std::string> > TestSignalByteStringArray_signal;
sigc::signal<void, std::vector<std::string> > TestSignalObjectPathArray_signal;
sigc::signal<void, std::vector<std::string> > TestSignalStringArray_signal;
sigc::signal<void, std::string > TestSignalByteString_signal;
sigc::signal<void, std::string > TestSignalSignature_signal;
sigc::signal<void, std::string > TestSignalObjectPath_signal;
sigc::signal<void, std::string > TestSignalString_signal;
sigc::signal<void, double > TestSignalDouble_signal;
sigc::signal<void, guint64 > TestSignalUInt64_signal;
sigc::signal<void, gint64 > TestSignalInt64_signal;
sigc::signal<void, guint32 > TestSignalUInt_signal;
sigc::signal<void, gint32 > TestSignalInt_signal;
sigc::signal<void, guint16 > TestSignalUInt16_signal;
sigc::signal<void, gint16 > TestSignalInt16_signal;
sigc::signal<void, guchar > TestSignalChar_signal;
sigc::signal<void, bool > TestSignalBoolean_signal;

    void reference() {}
    void unreference() {}
    void handle_signal (const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters);

    private:
    Test (Glib::RefPtr<Gio::DBus::Proxy> proxy) : Glib::ObjectBase() {
        this->m_proxy = proxy;
        this->m_proxy->signal_signal().connect(sigc::mem_fun(this, &Test::handle_signal));
    }
    Glib::RefPtr<Gio::DBus::Proxy> m_proxy;
};
}// glibmm
}// codegen
}// gdbus
}// org
