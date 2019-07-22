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

    /* signal handlers */
    void record_signal();
    void on_test_signal_byte_string_array_cb(const std::vector<std::string> s);
    void on_test_signal_object_path_array_cb(const std::vector<Glib::DBusObjectPathString> s);
    void on_test_signal_string_array_cb(const std::vector<Glib::ustring> s);
    void on_test_signal_byte_string_cb(const std::string s);
    void on_test_signal_signature_cb(const Glib::DBusSignatureString s);
    void on_test_signal_object_path_cb(const Glib::DBusObjectPathString s);
    void on_test_signal_string_cb(const std::string s);
    void on_test_signal_double_cb(const double s);
    void on_test_signal_uint64_cb(const guint64 s);
    void on_test_signal_int64_cb(const gint64 s);
    void on_test_signal_uint_cb(const guint s);
    void on_test_signal_int_cb(const gint s);
    void on_test_signal_uint16_cb(const guint16 s);
    void on_test_signal_int16_cb(const gint16 s);
    void on_test_signal_char_cb(const guchar s);
    void on_test_signal_boolean_cb(const bool s);

private:
    Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> m_proxy;
    sigc::signal<void> m_done;
    int m_exit_status = EXIT_SUCCESS;
    unsigned int m_pending_signals = 0;
};
