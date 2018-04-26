#pragma once
#include <string>
#include <glibmm.h>
#include <giomm.h>
#include "OUTPUT_DIR/input_common.h"

namespace org {
namespace gdbus {
namespace codegen {
namespace glibmm {

class Test {
public:
    Test();
    virtual ~Test();

    guint register_object(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                          const Glib::ustring &object_path);

    // deprecated:
    void connect(Gio::DBus::BusType, std::string);

    bool TestPropReadStringArray_set(std::vector<Glib::ustring> value);

protected:
    virtual void TestCall(
        gint32 Param1,
        std::map<Glib::ustring,Glib::VariantBase> Param2,
        TestMessageHelper msg) = 0;

    /* Handle the setting of a property
     * This method will be called as a result of a call to <PropName>_set
     * and should implement the actual setting of the property value.
     * Should return true on success and false otherwise.
     */
    virtual bool TestPropReadStringArray_setHandler(std::vector<Glib::ustring> value) = 0;
    virtual std::vector<Glib::ustring> TestPropReadStringArray_get() = 0;

    void TestSignalObjectPathArray_emitter(std::vector<Glib::DBusObjectPathString>);
    sigc::signal<void, std::vector<Glib::DBusObjectPathString>> TestSignalObjectPathArray_signal;

    void on_bus_acquired(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                         const Glib::ustring &name);

    void on_name_acquired(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                          const Glib::ustring &name);

    void on_name_lost(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name);

    void on_method_call(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                        const Glib::ustring &sender,
                        const Glib::ustring &object_path,
                        const Glib::ustring &interface_name,
                        const Glib::ustring &method_name,
                        const Glib::VariantContainerBase &parameters,
                        const Glib::RefPtr<Gio::DBus::MethodInvocation> &invocation);

    void on_interface_get_property(Glib::VariantBase& property,
                                   const Glib::RefPtr<Gio::DBus::Connection> &connection,
                                   const Glib::ustring &sender,
                                   const Glib::ustring &object_path,
                                   const Glib::ustring &interface_name,
                                   const Glib::ustring &property_name);

    bool on_interface_set_property(
        const Glib::RefPtr<Gio::DBus::Connection> &connection,
        const Glib::ustring &sender,
        const Glib::ustring &object_path,
        const Glib::ustring &interface_name,
        const Glib::ustring &property_name,
        const Glib::VariantBase &value);

private:
    bool emitSignal(const std::string &propName, Glib::VariantBase &value);

    guint connectionId, registeredId;
    Glib::RefPtr<Gio::DBus::NodeInfo> introspection_data;
    Glib::RefPtr<Gio::DBus::Connection> m_connection;
    std::string m_objectPath;
    std::string m_interfaceName;
};

} // glibmm
} // codegen
} // gdbus
} // org

