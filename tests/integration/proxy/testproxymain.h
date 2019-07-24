#include "many-types_proxy.h"

#include <cstdlib>

class TestProxyImpl {
public:
    TestProxyImpl();

    void fail();
    int exit_status() const { return m_exit_status; }

    sigc::signal<void> &done() { return m_done; }

private:
    void printStatus(const std::string &message, bool isOk);
    void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result);
    void check_done();

    /* method callbacks */
    void record_call();
    void on_test_string_variant_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                              const std::map<Glib::ustring,Glib::VariantBase> expectedMap);
    void on_test_string_string_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                             const std::map<Glib::ustring,Glib::ustring> expectedMap);
    void on_test_uint_int_dict_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                        const std::map<guint32,gint32> expectedMap);
    void on_test_variant_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                  Glib::Variant<Glib::ustring> expectedBase);
    void on_test_variant2_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                   std::string expectedString,
                                   Glib::Variant<Glib::ustring> expectedVariant);
    void on_test_byte_string_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                            std::vector<std::string> expected);
    void on_test_object_path_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                            std::vector<Glib::DBusObjectPathString> expected);
    void on_test_string_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                       std::vector<Glib::ustring> expected);
    void on_test_struct_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                  std::tuple<Glib::ustring,Glib::ustring> expected);
    void on_test_struct_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                       std::vector<std::tuple<guint32,Glib::ustring,gint32>> expected);
    void on_test_dict_struct_array_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                            std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> expected);
    void on_test_byte_string_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                      std::string expected);
    void on_test_signature_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                    Glib::DBusSignatureString expected);
    void on_test_object_path_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                      Glib::DBusObjectPathString expected);
    void on_test_string_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                 Glib::ustring expected);
    void on_test_double_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                 double expected);
    void on_test_uint64_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                 guint64 expected);
    void on_test_int64_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                gint64 expected);
    void on_test_uint_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                               guint expected);
    void on_test_int_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                              gint expected);
    void on_test_uint16_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                 guint16 expected);
    void on_test_int16_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                gint16 expected);
    void on_test_uchar_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                guchar expected);
    void on_test_boolean_finished(const Glib::RefPtr<Gio::AsyncResult> result,
                                  bool expected);
    void on_test_all_finished(const Glib::RefPtr<Gio::AsyncResult> result);
    void on_test_trigger_internal_property_change_finished (const Glib::RefPtr<Gio::AsyncResult> result,
                                                            const int expected);
    void on_test_error_finished(const Glib::RefPtr<Gio::AsyncResult> result);
    void on_test_prop_read_write_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                        const std::string &expected);
    void on_test_prop_read_write_byte_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                                   const std::vector<std::string> &expected);
    void on_test_prop_read_write_object_path_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                                   const std::vector<Glib::DBusObjectPathString> &expected);
    void on_test_prop_read_write_string_array(const Glib::RefPtr<Gio::AsyncResult> result,
                                              const std::vector<Glib::ustring> &expected);
    void on_test_prop_read_write_byte_string(const Glib::RefPtr<Gio::AsyncResult> result,
                                             const std::string &expected);
    void on_test_prop_read_write_signature(const Glib::RefPtr<Gio::AsyncResult> result,
                                           const Glib::DBusSignatureString &expected);
    void on_test_prop_read_write_object_path(const Glib::RefPtr<Gio::AsyncResult> result,
                                             const Glib::DBusObjectPathString &expected);
    void on_test_prop_read_write_double(const Glib::RefPtr<Gio::AsyncResult> result,
                                        const double &expected);
    void on_test_prop_read_write_uint64(const Glib::RefPtr<Gio::AsyncResult> result,
                                        const guint64 &expected);
    void on_test_prop_read_write_int64(const Glib::RefPtr<Gio::AsyncResult> result,
                                       const gint64 &expected);
    void on_test_prop_read_write_uint(const Glib::RefPtr<Gio::AsyncResult> result,
                                      const guint &expected);
    void on_test_prop_read_write_int(const Glib::RefPtr<Gio::AsyncResult> result,
                                     const gint &expected);
    void on_test_prop_read_write_uint16(const Glib::RefPtr<Gio::AsyncResult> result,
                                        const guint16 &expected);
    void on_test_prop_read_write_int16(const Glib::RefPtr<Gio::AsyncResult> result,
                                       const gint16 &expected);
    void on_test_prop_read_write_char(const Glib::RefPtr<Gio::AsyncResult> result,
                                      const guchar &expected);
    void on_test_prop_read_write_boolean(const Glib::RefPtr<Gio::AsyncResult> result,
                                         const guchar &expected);

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

    void on_notification_received();
    void expect_notification(sigc::signal<void> &signal);

private:
    Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> m_proxy;
    sigc::signal<void> m_done;
    int m_exit_status = EXIT_SUCCESS;
    unsigned int m_pending_calls = 0;
    unsigned int m_pending_signals = 0;
    unsigned int m_pending_notifications = 0;
};
