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
    static void createForBus(Gio::DBus::BusType busType,
                             Gio::DBus::ProxyFlags proxyFlags,
                             const std::string &name,
                             const std::string &objectPath,
                             const Gio::SlotAsyncReady &slot);

    static Glib::RefPtr<Test> createForBusFinish (Glib::RefPtr<Gio::AsyncResult> result);

    void TestCall(
        gint32 Param1,
        std::map<Glib::ustring,Glib::VariantBase> Param2,
        const Gio::SlotAsyncReady &slot);

    void TestCall_finish (
        std::string &Param3,
        std::map<Glib::ustring,Glib::VariantBase> &Param4,
        const Glib::RefPtr<Gio::AsyncResult> &res);

    std::vector<std::string> TestPropReadStringArray_get();

    sigc::signal<void, std::vector<std::string> > TestSignalObjectPathArray_signal;

    void reference() {}
    void unreference() {}

    void handle_signal(const Glib::ustring &sender_name,
                       const Glib::ustring &signal_name,
                       const Glib::VariantContainerBase &parameters);

private:
    Test(Glib::RefPtr<Gio::DBus::Proxy> proxy): Glib::ObjectBase() {
        this->m_proxy = proxy;
        this->m_proxy->signal_signal().connect(sigc::mem_fun(this, &Test::handle_signal));
    }
    Glib::RefPtr<Gio::DBus::Proxy> m_proxy;
};

}// glibmm
}// codegen
}// gdbus
}// org

