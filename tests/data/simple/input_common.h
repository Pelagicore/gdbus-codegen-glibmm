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

    void ret(std::string p0, std::map<Glib::ustring,Glib::VariantBase> p1) {
        std::vector<Glib::VariantBase> vlist;
        Glib::Variant<Glib::ustring> var0 =
            Glib::Variant<Glib::ustring>::create(p0);
        vlist.push_back(var0);
        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> var1 =
            Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>>::create(p1);
        vlist.push_back(var1);

        m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
    }

private:
    Glib::RefPtr<Gio::DBus::MethodInvocation> m_message;
};

