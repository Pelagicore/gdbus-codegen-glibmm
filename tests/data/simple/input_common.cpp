#include "OUTPUT_DIR/input_common.h"

#include <cstring>

namespace org {
namespace gdbus {
namespace codegen {
namespace glibmm {

static const GDBusErrorEntry error_entries[] = {
    { Error::InvalidParams, "org.gdbus.codegen.glibmm.Test.Error.InvalidParams" },
    { Error::OutOfMemory, "org.gdbus.codegen.glibmm.Test.Error.OutOfMemory" },
    { Error::PermissionDenied, "org.gdbus.codegen.glibmm.Test.Error.PermissionDenied" },
};

static void throw_func(GError *gerror)
{
    static const gchar prefix[] = "GDBus.Error:";
    Glib::ustring message;
    gint code = gerror->code;

    if (g_str_has_prefix(gerror->message, prefix)) {
        const char *colon = std::strstr(gerror->message + sizeof(prefix), ": ");
        message = colon ? (colon + 2) : gerror->message;
    } else {
        message = gerror->message;
    }
    g_error_free(gerror);

    throw Error(code, message);
}

static Glib::Quark register_domain_with_dbus()
{
    static const char domain[] = "org::gdbus::codegen::glibmm::ErrorQuark";
    Glib::QueryQuark quark(domain);
    if (quark.id() == 0) {
        static volatile gsize quark_volatile = 0;
        g_dbus_error_register_error_domain(domain,
                                           &quark_volatile,
                                           error_entries,
                                           G_N_ELEMENTS(error_entries));
        quark = Glib::QueryQuark(GQuark(quark_volatile));

        Glib::Error::register_domain(GQuark(quark_volatile), throw_func);
    }
    return static_cast<Glib::Quark>(quark);
}

Error::Error():
    Glib::Error()
{
}

Error::Error(int code, const Glib::ustring &message):
    Glib::Error(register_domain_with_dbus(), code, message)
{
}

void Error::initialize()
{
    register_domain_with_dbus();
}

GQuark Error::registered_domain()
{
    return register_domain_with_dbus().id();
}

}// glibmm
}// codegen
}// gdbus
}// org

