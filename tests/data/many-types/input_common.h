
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
            for (uint i = 0; i < wrapped.get_n_children (); i++) {
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
    TestMessageHelper (const Glib::RefPtr<Gio::DBus::MethodInvocation> msg) :
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

void ret(std::map<Glib::ustring,Glib::VariantBase> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::map<Glib::ustring,Glib::VariantBase> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::map<Glib::ustring,Glib::ustring> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::map<Glib::ustring,Glib::ustring> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::map<guint32,gint32> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::map<guint32,gint32> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(Glib::VariantBase p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(p0);

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::vector<std::string> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::vector<Glib::ustring> >::create(TestTypeWrap::stdStringVecToGlibStringVec(p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::string p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<Glib::ustring >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::tuple<Glib::ustring,Glib::ustring> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::tuple<Glib::ustring,Glib::ustring> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::vector<std::tuple<guint32,Glib::ustring,gint32>> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(double p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<double >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(guint64 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<guint64 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(gint64 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<gint64 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(guint32 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<guint32 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(gint32 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<gint32 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(guint16 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<guint16 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(gint16 p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<gint16 >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(guchar p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<guchar >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(bool p0)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<bool >::create((p0)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret(std::vector<std::string> p0, std::vector<std::string> p1, std::vector<std::string> p2, std::string p3, std::string p4, std::string p5, std::string p6, double p7, guint64 p8, gint64 p9, guint32 p10, gint32 p11, guint16 p12, gint16 p13, guchar p14, bool p15)
{
    std::vector<Glib::VariantBase> vlist;
    vlist.push_back(Glib::Variant<std::vector<std::string> >::create((p0)));
    vlist.push_back(Glib::Variant<std::vector<std::string> >::create((p1)));
    vlist.push_back(Glib::Variant<std::vector<Glib::ustring> >::create(TestTypeWrap::stdStringVecToGlibStringVec(p2)));
    vlist.push_back(Glib::Variant<std::string >::create((p3)));
    vlist.push_back(Glib::Variant<Glib::ustring >::create((p4)));
    vlist.push_back(Glib::Variant<Glib::ustring >::create((p5)));
    vlist.push_back(Glib::Variant<Glib::ustring >::create((p6)));
    vlist.push_back(Glib::Variant<double >::create((p7)));
    vlist.push_back(Glib::Variant<guint64 >::create((p8)));
    vlist.push_back(Glib::Variant<gint64 >::create((p9)));
    vlist.push_back(Glib::Variant<guint32 >::create((p10)));
    vlist.push_back(Glib::Variant<gint32 >::create((p11)));
    vlist.push_back(Glib::Variant<guint16 >::create((p12)));
    vlist.push_back(Glib::Variant<gint16 >::create((p13)));
    vlist.push_back(Glib::Variant<guchar >::create((p14)));
    vlist.push_back(Glib::Variant<bool >::create((p15)));

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}

void ret()
{
    std::vector<Glib::VariantBase> vlist;

    m_message->return_value(Glib::Variant<Glib::VariantBase>::create_tuple(vlist));
}


private:
    Glib::RefPtr<Gio::DBus::MethodInvocation> m_message;
};

