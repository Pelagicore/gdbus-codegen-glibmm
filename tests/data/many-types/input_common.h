#pragma once
#include <iostream>
#include <map>
#include <tuple>
#include "glibmm.h"
#include "giomm.h"

class TestTypeWrap {
public:
    template<typename T>
    static void unwrapList(std::vector<T> &list, const Glib::VariantContainerBase &wrapped) {
        for (uint i = 0; i < wrapped.get_n_children(); i++) {
            Glib::Variant<T> item;
            wrapped.get_child(item, i);
            list.push_back(item.get());
        }
    }

    static std::vector<Glib::ustring> stdStringVecToGlibStringVec(const std::vector<std::string> &strv) {
        std::vector<Glib::ustring> newStrv;
        for (uint i = 0; i < strv.size(); i++) {
            newStrv.push_back(strv[i]);
        }

        return newStrv;
    }

    static std::vector<std::string> glibStringVecToStdStringVec(const std::vector<Glib::ustring> &strv) {
        std::vector<std::string> newStrv;
        for (uint i = 0; i < strv.size(); i++) {
            newStrv.push_back(strv[i]);
        }

        return newStrv;
    }
};

class TestMessageHelper {
public:
    TestMessageHelper (const Glib::RefPtr<Gio::DBus::MethodInvocation> msg):
        m_message(msg) {}

    const Glib::RefPtr<Gio::DBus::MethodInvocation> getMessage() {
        return m_message;
    }

    void ret(Glib::Error error) {
        m_message->return_error(error);
    }

    void returnError(const Glib::ustring &domain, int code, const Glib::ustring &message) {
        m_message->return_error(domain, code, message);
    }

    void ret(const std::map<Glib::ustring,Glib::VariantBase> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> var0 =
            Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::map<Glib::ustring,Glib::ustring> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::map<Glib::ustring,Glib::ustring>> var0 =
            Glib::Variant<std::map<Glib::ustring,Glib::ustring>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::map<guint32,gint32> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::map<guint32,gint32>> var0 =
            Glib::Variant<std::map<guint32,gint32>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const Glib::VariantBase & p0) {
        std::vector<Glib::VariantBase> vlist;
        vlist.push_back(p0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<std::string> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<std::string>> var0 =
            Glib::Variant<std::vector<std::string>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<Glib::DBusObjectPathString> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> var0 =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<Glib::ustring> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<Glib::ustring>> var0 =
            Glib::Variant<std::vector<Glib::ustring>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::string & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::string> var0 =
            Glib::Variant<std::string>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::tuple<Glib::ustring,Glib::ustring> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>> var0 =
            Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<std::tuple<guint32,Glib::ustring,gint32>> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>> var0 =
            Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>> var0 =
            Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const Glib::DBusSignatureString & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::VariantStringBase var0;
        Glib::VariantStringBase::create_signature(var0, p0.c_str());
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const Glib::DBusObjectPathString & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::VariantStringBase var0;
        Glib::VariantStringBase::create_object_path(var0, p0.c_str());
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const Glib::ustring & p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<Glib::ustring> var0 =
            Glib::Variant<Glib::ustring>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(double p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<double> var0 =
            Glib::Variant<double>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(guint64 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<guint64> var0 =
            Glib::Variant<guint64>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(gint64 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<gint64> var0 =
            Glib::Variant<gint64>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(guint32 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<guint32> var0 =
            Glib::Variant<guint32>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(gint32 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<gint32> var0 =
            Glib::Variant<gint32>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(guint16 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<guint16> var0 =
            Glib::Variant<guint16>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(gint16 p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<gint16> var0 =
            Glib::Variant<gint16>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(guchar p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<guchar> var0 =
            Glib::Variant<guchar>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(bool p0) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<bool> var0 =
            Glib::Variant<bool>::create(p0);
        vlist.push_back(var0);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret(const std::vector<std::string> & p0, const std::vector<Glib::DBusObjectPathString> & p1, const std::vector<Glib::ustring> & p2, const std::string & p3, const Glib::DBusSignatureString & p4, const Glib::DBusObjectPathString & p5, const Glib::ustring & p6, double p7, guint64 p8, gint64 p9, guint32 p10, gint32 p11, guint16 p12, gint16 p13, guchar p14, bool p15) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<std::vector<std::string>> var0 =
            Glib::Variant<std::vector<std::string>>::create(p0);
        vlist.push_back(var0);
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> var1 =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create(p1);
        vlist.push_back(var1);
        Glib::Variant<std::vector<Glib::ustring>> var2 =
            Glib::Variant<std::vector<Glib::ustring>>::create(p2);
        vlist.push_back(var2);
        Glib::Variant<std::string> var3 =
            Glib::Variant<std::string>::create(p3);
        vlist.push_back(var3);
        Glib::VariantStringBase var4;
        Glib::VariantStringBase::create_signature(var4, p4.c_str());
        vlist.push_back(var4);
        Glib::VariantStringBase var5;
        Glib::VariantStringBase::create_object_path(var5, p5.c_str());
        vlist.push_back(var5);
        Glib::Variant<Glib::ustring> var6 =
            Glib::Variant<Glib::ustring>::create(p6);
        vlist.push_back(var6);
        Glib::Variant<double> var7 =
            Glib::Variant<double>::create(p7);
        vlist.push_back(var7);
        Glib::Variant<guint64> var8 =
            Glib::Variant<guint64>::create(p8);
        vlist.push_back(var8);
        Glib::Variant<gint64> var9 =
            Glib::Variant<gint64>::create(p9);
        vlist.push_back(var9);
        Glib::Variant<guint32> var10 =
            Glib::Variant<guint32>::create(p10);
        vlist.push_back(var10);
        Glib::Variant<gint32> var11 =
            Glib::Variant<gint32>::create(p11);
        vlist.push_back(var11);
        Glib::Variant<guint16> var12 =
            Glib::Variant<guint16>::create(p12);
        vlist.push_back(var12);
        Glib::Variant<gint16> var13 =
            Glib::Variant<gint16>::create(p13);
        vlist.push_back(var13);
        Glib::Variant<guchar> var14 =
            Glib::Variant<guchar>::create(p14);
        vlist.push_back(var14);
        Glib::Variant<bool> var15 =
            Glib::Variant<bool>::create(p15);
        vlist.push_back(var15);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

    void ret() {
        std::vector<Glib::VariantBase> vlist;

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

private:
    Glib::RefPtr<Gio::DBus::MethodInvocation> m_message;
};

