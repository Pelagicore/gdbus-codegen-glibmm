#pragma once
#include <string>
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

    void TestCall(
        gint32 Param1,
        const std::map<Glib::ustring,Glib::VariantBase> & Param2,
        const Gio::SlotAsyncReady &slot,
        const Glib::RefPtr<Gio::Cancellable> &cancellable = {},
        int timeout_msec = -1);

    void TestCall_finish (
        Glib::ustring &Param3,
        std::map<Glib::ustring,Glib::VariantBase> &Param4,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<Glib::ustring> TestPropReadStringArray_get();
    sigc::signal<void> &TestPropReadStringArray_changed() {
        return m_TestPropReadStringArray_changed;
    }

    sigc::signal<void, std::vector<Glib::DBusObjectPathString> > TestSignalObjectPathArray_signal;

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

    sigc::signal<void> m_TestPropReadStringArray_changed;
};

}// glibmm
}// codegen
}// gdbus
}// org

