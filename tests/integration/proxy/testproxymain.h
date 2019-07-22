#include "many-types_proxy.h"

#include <cstdlib>

class TestProxyImpl {
public:
    TestProxyImpl();

    void fail();
    int exit_status() const { return m_exit_status; }

    sigc::signal<void> &done() { return m_done; }

private:
    void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result);

private:
    Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> m_proxy;
    sigc::signal<void> m_done;
    int m_exit_status = EXIT_SUCCESS;
};
