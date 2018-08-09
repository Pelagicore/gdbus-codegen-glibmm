
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

    bool TestPropReadByteStringArray_set(std::vector<std::string> value);
    bool TestPropReadObjectPathArray_set(std::vector<std::string> value);
    bool TestPropReadStringArray_set(std::vector<std::string> value);
    bool TestPropReadByteString_set(std::string value);
    bool TestPropReadSignature_set(std::string value);
    bool TestPropReadObjectPath_set(std::string value);
    bool TestPropReadString_set(std::string value);
    bool TestPropReadDouble_set(double value);
    bool TestPropReadUInt64_set(guint64 value);
    bool TestPropReadInt64_set(gint64 value);
    bool TestPropReadUInt_set(guint32 value);
    bool TestPropReadInt_set(gint32 value);
    bool TestPropReadUInt16_set(guint16 value);
    bool TestPropReadInt16_set(gint16 value);
    bool TestPropReadChar_set(guchar value);
    bool TestPropReadBoolean_set(bool value);
    bool TestPropInternalReadPropertyChange_set(gint32 value);
    bool TestPropWriteByteStringArray_set(std::vector<std::string> value);
    bool TestPropWriteObjectPathArray_set(std::vector<std::string> value);
    bool TestPropWriteStringArray_set(std::vector<std::string> value);
    bool TestPropWriteByteString_set(std::string value);
    bool TestPropWriteSignature_set(std::string value);
    bool TestPropWriteObjectPath_set(std::string value);
    bool TestPropWriteString_set(std::string value);
    bool TestPropWriteDouble_set(double value);
    bool TestPropWriteUInt64_set(guint64 value);
    bool TestPropWriteInt64_set(gint64 value);
    bool TestPropWriteUInt_set(guint32 value);
    bool TestPropWriteInt_set(gint32 value);
    bool TestPropWriteUInt16_set(guint16 value);
    bool TestPropWriteInt16_set(gint16 value);
    bool TestPropWriteChar_set(guchar value);
    bool TestPropWriteBoolean_set(bool value);
    bool TestPropReadWriteByteStringArray_set(std::vector<std::string> value);
    bool TestPropReadWriteObjectPathArray_set(std::vector<std::string> value);
    bool TestPropReadWriteStringArray_set(std::vector<std::string> value);
    bool TestPropReadWriteByteString_set(std::string value);
    bool TestPropReadWriteSignature_set(std::string value);
    bool TestPropReadWriteObjectPath_set(std::string value);
    bool TestPropReadWriteString_set(std::string value);
    bool TestPropReadWriteDouble_set(double value);
    bool TestPropReadWriteUInt64_set(guint64 value);
    bool TestPropReadWriteInt64_set(gint64 value);
    bool TestPropReadWriteUInt_set(guint32 value);
    bool TestPropReadWriteInt_set(gint32 value);
    bool TestPropReadWriteUInt16_set(guint16 value);
    bool TestPropReadWriteInt16_set(gint16 value);
    bool TestPropReadWriteChar_set(guchar value);
    bool TestPropReadWriteBoolean_set(bool value);
    bool TestPropInternalReadWritePropertyChange_set(gint32 value);
protected:
virtual void TestStringVariantDict (
    std::map<Glib::ustring,Glib::VariantBase> Param1,
    TestMessageHelper msg) = 0;
virtual void TestStringStringDict (
    std::map<Glib::ustring,Glib::ustring> Param1,
    TestMessageHelper msg) = 0;
virtual void TestUintIntDict (
    std::map<guint32,gint32> Param1,
    TestMessageHelper msg) = 0;
virtual void TestVariant (
    Glib::VariantBase Param1,
    TestMessageHelper msg) = 0;
virtual void TestByteStringArray (
    std::vector<std::string> Param1,
    TestMessageHelper msg) = 0;
virtual void TestObjectPathArray (
    std::vector<std::string> Param1,
    TestMessageHelper msg) = 0;
virtual void TestStringArray (
    std::vector<std::string> Param1,
    TestMessageHelper msg) = 0;
virtual void TestByteString (
    std::string Param1,
    TestMessageHelper msg) = 0;
virtual void TestStruct (
    std::tuple<Glib::ustring,Glib::ustring> Param1,
    TestMessageHelper msg) = 0;
virtual void TestStructArray (
    std::vector<std::tuple<guint32,Glib::ustring,gint32>> Param1,
    TestMessageHelper msg) = 0;
virtual void TestDictStructArray (
    std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> Param1,
    TestMessageHelper msg) = 0;
virtual void TestSignature (
    std::string Param1,
    TestMessageHelper msg) = 0;
virtual void TestObjectPath (
    std::string Param1,
    TestMessageHelper msg) = 0;
virtual void TestString (
    std::string Param1,
    TestMessageHelper msg) = 0;
virtual void TestDouble (
    double Param1,
    TestMessageHelper msg) = 0;
virtual void TestUInt64 (
    guint64 Param1,
    TestMessageHelper msg) = 0;
virtual void TestInt64 (
    gint64 Param1,
    TestMessageHelper msg) = 0;
virtual void TestUInt (
    guint32 Param1,
    TestMessageHelper msg) = 0;
virtual void TestInt (
    gint32 Param1,
    TestMessageHelper msg) = 0;
virtual void TestUInt16 (
    guint16 Param1,
    TestMessageHelper msg) = 0;
virtual void TestInt16 (
    gint16 Param1,
    TestMessageHelper msg) = 0;
virtual void TestChar (
    guchar Param1,
    TestMessageHelper msg) = 0;
virtual void TestBoolean (
    bool Param1,
    TestMessageHelper msg) = 0;
virtual void TestAll (
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
    TestMessageHelper msg) = 0;
virtual void TestTriggerInternalPropertyChange (
    gint32 NewPropertyValue,
    TestMessageHelper msg) = 0;
virtual std::vector<std::string> TestPropReadByteStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadByteStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropReadObjectPathArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadObjectPathArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropReadStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::string TestPropReadByteString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadByteString_setHandler(std::string value) = 0;
virtual std::string TestPropReadSignature_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadSignature_setHandler(std::string value) = 0;
virtual std::string TestPropReadObjectPath_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadObjectPath_setHandler(std::string value) = 0;
virtual std::string TestPropReadString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadString_setHandler(std::string value) = 0;
virtual double TestPropReadDouble_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadDouble_setHandler(double value) = 0;
virtual guint64 TestPropReadUInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadUInt64_setHandler(guint64 value) = 0;
virtual gint64 TestPropReadInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadInt64_setHandler(gint64 value) = 0;
virtual guint32 TestPropReadUInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadUInt_setHandler(guint32 value) = 0;
virtual gint32 TestPropReadInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadInt_setHandler(gint32 value) = 0;
virtual guint16 TestPropReadUInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadUInt16_setHandler(guint16 value) = 0;
virtual gint16 TestPropReadInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadInt16_setHandler(gint16 value) = 0;
virtual guchar TestPropReadChar_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadChar_setHandler(guchar value) = 0;
virtual bool TestPropReadBoolean_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadBoolean_setHandler(bool value) = 0;
virtual gint32 TestPropInternalReadPropertyChange_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropInternalReadPropertyChange_setHandler(gint32 value) = 0;
virtual std::vector<std::string> TestPropWriteByteStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteByteStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropWriteObjectPathArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteObjectPathArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropWriteStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::string TestPropWriteByteString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteByteString_setHandler(std::string value) = 0;
virtual std::string TestPropWriteSignature_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteSignature_setHandler(std::string value) = 0;
virtual std::string TestPropWriteObjectPath_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteObjectPath_setHandler(std::string value) = 0;
virtual std::string TestPropWriteString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteString_setHandler(std::string value) = 0;
virtual double TestPropWriteDouble_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteDouble_setHandler(double value) = 0;
virtual guint64 TestPropWriteUInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteUInt64_setHandler(guint64 value) = 0;
virtual gint64 TestPropWriteInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteInt64_setHandler(gint64 value) = 0;
virtual guint32 TestPropWriteUInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteUInt_setHandler(guint32 value) = 0;
virtual gint32 TestPropWriteInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteInt_setHandler(gint32 value) = 0;
virtual guint16 TestPropWriteUInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteUInt16_setHandler(guint16 value) = 0;
virtual gint16 TestPropWriteInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteInt16_setHandler(gint16 value) = 0;
virtual guchar TestPropWriteChar_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteChar_setHandler(guchar value) = 0;
virtual bool TestPropWriteBoolean_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropWriteBoolean_setHandler(bool value) = 0;
virtual std::vector<std::string> TestPropReadWriteByteStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteByteStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropReadWriteObjectPathArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteObjectPathArray_setHandler(std::vector<std::string> value) = 0;
virtual std::vector<std::string> TestPropReadWriteStringArray_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteStringArray_setHandler(std::vector<std::string> value) = 0;
virtual std::string TestPropReadWriteByteString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteByteString_setHandler(std::string value) = 0;
virtual std::string TestPropReadWriteSignature_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteSignature_setHandler(std::string value) = 0;
virtual std::string TestPropReadWriteObjectPath_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteObjectPath_setHandler(std::string value) = 0;
virtual std::string TestPropReadWriteString_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteString_setHandler(std::string value) = 0;
virtual double TestPropReadWriteDouble_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteDouble_setHandler(double value) = 0;
virtual guint64 TestPropReadWriteUInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteUInt64_setHandler(guint64 value) = 0;
virtual gint64 TestPropReadWriteInt64_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteInt64_setHandler(gint64 value) = 0;
virtual guint32 TestPropReadWriteUInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteUInt_setHandler(guint32 value) = 0;
virtual gint32 TestPropReadWriteInt_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteInt_setHandler(gint32 value) = 0;
virtual guint16 TestPropReadWriteUInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteUInt16_setHandler(guint16 value) = 0;
virtual gint16 TestPropReadWriteInt16_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteInt16_setHandler(gint16 value) = 0;
virtual guchar TestPropReadWriteChar_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteChar_setHandler(guchar value) = 0;
virtual bool TestPropReadWriteBoolean_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropReadWriteBoolean_setHandler(bool value) = 0;
virtual gint32 TestPropInternalReadWritePropertyChange_get() = 0;

/* Handle the setting of a property
    * This method will be called as a result of a call to <PropName>_set
    * and should implement the actual setting of the property value.
    * Should return true on sucess and false otherwise.
    */
virtual bool TestPropInternalReadWritePropertyChange_setHandler(gint32 value) = 0;

void TestSignalByteStringArray_emitter(std::vector<std::string>);
sigc::signal<void, std::vector<std::string> > TestSignalByteStringArray_signal;

void TestSignalObjectPathArray_emitter(std::vector<std::string>);
sigc::signal<void, std::vector<std::string> > TestSignalObjectPathArray_signal;

void TestSignalStringArray_emitter(std::vector<std::string>);
sigc::signal<void, std::vector<std::string> > TestSignalStringArray_signal;

void TestSignalByteString_emitter(std::string);
sigc::signal<void, std::string > TestSignalByteString_signal;

void TestSignalSignature_emitter(std::string);
sigc::signal<void, std::string > TestSignalSignature_signal;

void TestSignalObjectPath_emitter(std::string);
sigc::signal<void, std::string > TestSignalObjectPath_signal;

void TestSignalString_emitter(std::string);
sigc::signal<void, std::string > TestSignalString_signal;

void TestSignalDouble_emitter(double);
sigc::signal<void, double > TestSignalDouble_signal;

void TestSignalUInt64_emitter(guint64);
sigc::signal<void, guint64 > TestSignalUInt64_signal;

void TestSignalInt64_emitter(gint64);
sigc::signal<void, gint64 > TestSignalInt64_signal;

void TestSignalUInt_emitter(guint32);
sigc::signal<void, guint32 > TestSignalUInt_signal;

void TestSignalInt_emitter(gint32);
sigc::signal<void, gint32 > TestSignalInt_signal;

void TestSignalUInt16_emitter(guint16);
sigc::signal<void, guint16 > TestSignalUInt16_signal;

void TestSignalInt16_emitter(gint16);
sigc::signal<void, gint16 > TestSignalInt16_signal;

void TestSignalChar_emitter(guchar);
sigc::signal<void, guchar > TestSignalChar_signal;

void TestSignalBoolean_emitter(bool);
sigc::signal<void, bool > TestSignalBoolean_signal;

void on_bus_acquired(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                     const Glib::ustring& /* name */);

void on_name_acquired(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                      const Glib::ustring& /* name */);

void on_name_lost(const Glib::RefPtr<Gio::DBus::Connection>& connection,
                  const Glib::ustring& /* name */);

void on_method_call(const Glib::RefPtr<Gio::DBus::Connection>& /* connection */,
                   const Glib::ustring& /* sender */,
                   const Glib::ustring& /* object_path */,
                   const Glib::ustring& /* interface_name */,
                   const Glib::ustring& method_name,
                   const Glib::VariantContainerBase& parameters,
                   const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation);

void on_interface_get_property(Glib::VariantBase& property,
                                       const Glib::RefPtr<Gio::DBus::Connection>& connection,
                                       const Glib::ustring& sender,
                                       const Glib::ustring& object_path,
                                       const Glib::ustring& interface_name,
                                       const Glib::ustring& property_name);

bool on_interface_set_property(
       const Glib::RefPtr<Gio::DBus::Connection>& connection,
       const Glib::ustring& sender,
       const Glib::ustring& object_path,
       const Glib::ustring& interface_name,
       const Glib::ustring& property_name,
       const Glib::VariantBase& value);

private:
bool emitSignal(const std::string& propName, Glib::VariantBase& value);

guint connectionId, registeredId;
Glib::RefPtr<Gio::DBus::NodeInfo> introspection_data;
Glib::RefPtr<Gio::DBus::Connection> m_connection;
std::string m_objectPath;
std::string m_interfaceName;
};
}// glibmm
}// codegen
}// gdbus
}// org
