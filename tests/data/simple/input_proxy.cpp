/*
 * Generated by gdbus-codegen-glibmm 2.42.0. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#include "OUTPUT_DIR/input_proxy.h"

#include <utility>

template<class T>
inline T specialGetter(Glib::Variant<T> variant)
{
    return variant.get();
}

template<>
inline std::string specialGetter(Glib::Variant<std::string> variant)
{
    // String is not guaranteed to be null-terminated, so don't use ::get()
    gsize n_elem;
    gsize elem_size = sizeof(char);
    char* data = (char*)g_variant_get_fixed_array(variant.gobj(), &n_elem, elem_size);

    return std::string(data, n_elem);
}

void org::gdbus::codegen::glibmm::TestProxy::TestCall(
    gint32 arg_Param1,
    const std::map<Glib::ustring,Glib::VariantBase> & arg_Param2,
    const Gio::SlotAsyncReady &callback,
    const Glib::RefPtr<Gio::Cancellable> &cancellable,
    int timeout_msec)
{
    Glib::VariantContainerBase base;
    base = TestTypeWrap::TestCall_pack(
        arg_Param1,
        arg_Param2);

    m_proxy->call("TestCall", callback, cancellable, base, timeout_msec);
}

void org::gdbus::codegen::glibmm::TestProxy::TestCall_finish(
    Glib::ustring &out_Param3,
    std::map<Glib::ustring,Glib::VariantBase> &out_Param4,
    const Glib::RefPtr<Gio::AsyncResult> &result)
{
    Glib::VariantContainerBase wrapped;
    wrapped = m_proxy->call_finish(result);

    Glib::Variant<Glib::ustring> out_Param3_v;
    wrapped.get_child(out_Param3_v, 0);
    out_Param3 = out_Param3_v.get();

    Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> out_Param4_v;
    wrapped.get_child(out_Param4_v, 1);
    out_Param4 = out_Param4_v.get();
}

std::tuple<Glib::ustring, std::map<Glib::ustring,Glib::VariantBase>>
org::gdbus::codegen::glibmm::TestProxy::TestCall_sync(
    gint32 arg_Param1,
    const std::map<Glib::ustring,Glib::VariantBase> & arg_Param2,
    const Glib::RefPtr<Gio::Cancellable> &cancellable,
    int timeout_msec)
{
    Glib::VariantContainerBase base;
    base = TestTypeWrap::TestCall_pack(
        arg_Param1,
        arg_Param2);

    Glib::VariantContainerBase wrapped;
    wrapped = m_proxy->call_sync("TestCall", cancellable, base, timeout_msec);

    Glib::ustring out_Param3;
    Glib::Variant<Glib::ustring> out_Param3_v;
    wrapped.get_child(out_Param3_v, 0);
    out_Param3 = out_Param3_v.get();

    std::map<Glib::ustring,Glib::VariantBase> out_Param4;
    Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> out_Param4_v;
    wrapped.get_child(out_Param4_v, 1);
    out_Param4 = out_Param4_v.get();

    return std::make_tuple(
        std::move(out_Param3),
        std::move(out_Param4)
    );
}

std::vector<Glib::ustring> org::gdbus::codegen::glibmm::TestProxy::TestPropReadStringArray_get(bool *ok)
{
    Glib::Variant<std::vector<Glib::ustring>> b;
    m_proxy->get_cached_property(b, "TestPropReadStringArray");
    if (b) {
        if (ok) {
            *ok = true;
        }
        return (specialGetter(b));
    } else {
        if (ok) {
            *ok = false;
        } else {
            g_warning("Unhandled error while getting property TestPropReadStringArray");
        }
        return std::vector<Glib::ustring>();
    }

}

void org::gdbus::codegen::glibmm::TestProxy::handle_signal(const Glib::ustring&/* sender_name */,
    const Glib::ustring& signal_name,
    const Glib::VariantContainerBase& parameters)
{
    static_cast<void>(signal_name); // maybe unused
    static_cast<void>(parameters); // maybe unused

    if (signal_name == "TestSignalObjectPathArray") {
        if (parameters.get_n_children() != 1) return;
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> base_Param1;
        parameters.get_child(base_Param1, 0);
        std::vector<Glib::DBusObjectPathString> p_Param1;
        p_Param1 = base_Param1.get();

        TestSignalObjectPathArray_signal.emit((p_Param1));
    }
}

void org::gdbus::codegen::glibmm::TestProxy::handle_properties_changed(
    const Gio::DBus::Proxy::MapChangedProperties &changed_properties,
    const std::vector<Glib::ustring> &/* invalidated_properties */)
{
    static_cast<void>(changed_properties); // maybe unused

    // Only check changed_properties since value will already be cached. Glib can be setup to get
    // values of invalidated properties in which case property will be in changed_properties when
    // value is actually received. See Gio::DBus::ProxyFlags::PROXY_FLAGS_GET_INVALIDATED_PROPERTIES .

    if (changed_properties.find("TestPropReadStringArray") != changed_properties.cend())
        m_TestPropReadStringArray_changed.emit();
}

org::gdbus::codegen::glibmm::TestProxy::TestProxy(const Glib::RefPtr<Gio::DBus::Proxy> &proxy) : m_proxy(proxy)
{
    m_proxy->signal_signal().connect(sigc::mem_fun(this, &TestProxy::handle_signal));
    m_proxy->signal_properties_changed().
        connect(sigc::mem_fun(this, &TestProxy::handle_properties_changed));
    org::gdbus::codegen::glibmm::Error::initialize();
}

void org::gdbus::codegen::glibmm::TestProxy::create(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    Gio::DBus::ProxyFlags proxyFlags,
    const std::string &name,
    const std::string &objectPath,
    const Gio::SlotAsyncReady &slot,
    const Glib::RefPtr<Gio::Cancellable> &cancellable)
{
    Gio::DBus::Proxy::create(connection,
        name,
        objectPath,
        "org.gdbus.codegen.glibmm.Test",
        slot,
        cancellable,
        Glib::RefPtr<Gio::DBus::InterfaceInfo>(),
        proxyFlags);
}

Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> org::gdbus::codegen::glibmm::TestProxy::createFinish(const Glib::RefPtr<Gio::AsyncResult> &result)
{
    Glib::RefPtr<Gio::DBus::Proxy> proxy =
        Gio::DBus::Proxy::create_finish(result);
    org::gdbus::codegen::glibmm::TestProxy *p =
        new org::gdbus::codegen::glibmm::TestProxy(proxy);
    return Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy>(p);
}

Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> org::gdbus::codegen::glibmm::TestProxy::create_sync(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    Gio::DBus::ProxyFlags proxyFlags,
    const std::string &name,
    const std::string &objectPath,
    const Glib::RefPtr<Gio::Cancellable> &cancellable)
{
    Glib::RefPtr<Gio::DBus::Proxy> proxy =
        Gio::DBus::Proxy::create_sync(connection,
            name,
            objectPath,
            "org.gdbus.codegen.glibmm.Test",
            cancellable,
            Glib::RefPtr<Gio::DBus::InterfaceInfo>(),
            proxyFlags);
    org::gdbus::codegen::glibmm::TestProxy *p =
        new org::gdbus::codegen::glibmm::TestProxy(proxy);
    return Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy>(p);
}

void org::gdbus::codegen::glibmm::TestProxy::createForBus(
    Gio::DBus::BusType busType,
    Gio::DBus::ProxyFlags proxyFlags,
    const std::string &name,
    const std::string &objectPath,
    const Gio::SlotAsyncReady &slot,
    const Glib::RefPtr<Gio::Cancellable> &cancellable)
{
    Gio::DBus::Proxy::create_for_bus(busType,
        name,
        objectPath,
        "org.gdbus.codegen.glibmm.Test",
        slot,
        cancellable,
        Glib::RefPtr<Gio::DBus::InterfaceInfo>(),
        proxyFlags);
}

Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> org::gdbus::codegen::glibmm::TestProxy::createForBusFinish(const Glib::RefPtr<Gio::AsyncResult> &result)
{
    Glib::RefPtr<Gio::DBus::Proxy> proxy =
        Gio::DBus::Proxy::create_for_bus_finish(result);
    org::gdbus::codegen::glibmm::TestProxy *p =
        new org::gdbus::codegen::glibmm::TestProxy(proxy);
    return Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy>(p);
}

Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy> org::gdbus::codegen::glibmm::TestProxy::createForBus_sync(
    Gio::DBus::BusType busType,
    Gio::DBus::ProxyFlags proxyFlags,
    const std::string &name,
    const std::string &objectPath,
    const Glib::RefPtr<Gio::Cancellable> &cancellable)
{
    Glib::RefPtr<Gio::DBus::Proxy> proxy =
        Gio::DBus::Proxy::create_for_bus_sync(busType,
            name,
            objectPath,
            "org.gdbus.codegen.glibmm.Test",
            cancellable,
            Glib::RefPtr<Gio::DBus::InterfaceInfo>(),
            proxyFlags);
    org::gdbus::codegen::glibmm::TestProxy *p =
        new org::gdbus::codegen::glibmm::TestProxy(proxy);
    return Glib::RefPtr<org::gdbus::codegen::glibmm::TestProxy>(p);
}
