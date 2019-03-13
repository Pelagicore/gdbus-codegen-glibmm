#pragma once
#include <iostream>
#include <vector>
#include "glibmm.h"
#include "giomm.h"

namespace org {
namespace gdbus {
namespace codegen {
namespace glibmm {

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

    static Glib::VariantContainerBase TestStringVariantDict_pack(
        const std::map<Glib::ustring,Glib::VariantBase> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>> params =
            Glib::Variant<std::map<Glib::ustring,Glib::VariantBase>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestStringStringDict_pack(
        const std::map<Glib::ustring,Glib::ustring> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::map<Glib::ustring,Glib::ustring>> params =
            Glib::Variant<std::map<Glib::ustring,Glib::ustring>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestUintIntDict_pack(
        const std::map<guint32,gint32> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::map<guint32,gint32>> params =
            Glib::Variant<std::map<guint32,gint32>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestVariant_pack(
        const Glib::VariantBase & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<Glib::VariantBase> params =
            Glib::Variant<Glib::VariantBase>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestVariant2_pack(
        const Glib::ustring & arg_Param1,
        const Glib::VariantBase & arg_Param2) {
        Glib::VariantContainerBase base;
        std::vector<Glib::VariantBase> params;

        Glib::Variant<Glib::ustring> Param1_param =
            Glib::Variant<Glib::ustring>::create(arg_Param1);
        params.push_back(Param1_param);

        Glib::Variant<Glib::VariantBase> Param2_param =
            Glib::Variant<Glib::VariantBase>::create(arg_Param2);
        params.push_back(Param2_param);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestByteStringArray_pack(
        const std::vector<std::string> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::vector<std::string>> params =
            Glib::Variant<std::vector<std::string>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestObjectPathArray_pack(
        const std::vector<Glib::DBusObjectPathString> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::vector<Glib::DBusObjectPathString>> params =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestStringArray_pack(
        const std::vector<Glib::ustring> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::vector<Glib::ustring>> params =
            Glib::Variant<std::vector<Glib::ustring>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestByteString_pack(
        const std::string & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::string> params =
            Glib::Variant<std::string>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestStruct_pack(
        const std::tuple<Glib::ustring,Glib::ustring> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>> params =
            Glib::Variant<std::tuple<Glib::ustring,Glib::ustring>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestStructArray_pack(
        const std::vector<std::tuple<guint32,Glib::ustring,gint32>> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>> params =
            Glib::Variant<std::vector<std::tuple<guint32,Glib::ustring,gint32>>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestDictStructArray_pack(
        const std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>> & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>> params =
            Glib::Variant<std::vector<std::tuple<Glib::ustring,std::map<Glib::ustring,Glib::VariantBase>>>>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestSignature_pack(
        const Glib::DBusSignatureString & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::VariantStringBase params;
        Glib::VariantStringBase::create_signature(params, arg_Param1.c_str());
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestObjectPath_pack(
        const Glib::DBusObjectPathString & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::VariantStringBase params;
        Glib::VariantStringBase::create_object_path(params, arg_Param1.c_str());
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestString_pack(
        const Glib::ustring & arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<Glib::ustring> params =
            Glib::Variant<Glib::ustring>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestDouble_pack(
        double arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<double> params =
            Glib::Variant<double>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestUInt64_pack(
        guint64 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<guint64> params =
            Glib::Variant<guint64>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestInt64_pack(
        gint64 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<gint64> params =
            Glib::Variant<gint64>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestUInt_pack(
        guint32 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<guint32> params =
            Glib::Variant<guint32>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestInt_pack(
        gint32 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<gint32> params =
            Glib::Variant<gint32>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestUInt16_pack(
        guint16 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<guint16> params =
            Glib::Variant<guint16>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestInt16_pack(
        gint16 arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<gint16> params =
            Glib::Variant<gint16>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestChar_pack(
        guchar arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<guchar> params =
            Glib::Variant<guchar>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestBoolean_pack(
        bool arg_Param1) {
        Glib::VariantContainerBase base;
        Glib::Variant<bool> params =
            Glib::Variant<bool>::create(arg_Param1);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestAll_pack(
        const std::vector<std::string> & arg_in_Param1,
        const std::vector<Glib::DBusObjectPathString> & arg_in_Param2,
        const std::vector<Glib::ustring> & arg_in_Param3,
        const std::string & arg_in_Param4,
        const Glib::DBusSignatureString & arg_in_Param5,
        const Glib::DBusObjectPathString & arg_in_Param6,
        const Glib::ustring & arg_in_Param7,
        double arg_in_Param8,
        guint64 arg_in_Param9,
        gint64 arg_in_Param10,
        guint32 arg_in_Param11,
        gint32 arg_in_Param12,
        guint16 arg_in_Param13,
        gint16 arg_in_Param14,
        guchar arg_in_Param15,
        bool arg_in_Param16) {
        Glib::VariantContainerBase base;
        std::vector<Glib::VariantBase> params;

        Glib::Variant<std::vector<std::string>> in_Param1_param =
            Glib::Variant<std::vector<std::string>>::create(arg_in_Param1);
        params.push_back(in_Param1_param);

        Glib::Variant<std::vector<Glib::DBusObjectPathString>> in_Param2_param =
            Glib::Variant<std::vector<Glib::DBusObjectPathString>>::create(arg_in_Param2);
        params.push_back(in_Param2_param);

        Glib::Variant<std::vector<Glib::ustring>> in_Param3_param =
            Glib::Variant<std::vector<Glib::ustring>>::create(arg_in_Param3);
        params.push_back(in_Param3_param);

        Glib::Variant<std::string> in_Param4_param =
            Glib::Variant<std::string>::create(arg_in_Param4);
        params.push_back(in_Param4_param);

        Glib::VariantStringBase in_Param5_param;
        Glib::VariantStringBase::create_signature(in_Param5_param, arg_in_Param5.c_str());
        params.push_back(in_Param5_param);

        Glib::VariantStringBase in_Param6_param;
        Glib::VariantStringBase::create_object_path(in_Param6_param, arg_in_Param6.c_str());
        params.push_back(in_Param6_param);

        Glib::Variant<Glib::ustring> in_Param7_param =
            Glib::Variant<Glib::ustring>::create(arg_in_Param7);
        params.push_back(in_Param7_param);

        Glib::Variant<double> in_Param8_param =
            Glib::Variant<double>::create(arg_in_Param8);
        params.push_back(in_Param8_param);

        Glib::Variant<guint64> in_Param9_param =
            Glib::Variant<guint64>::create(arg_in_Param9);
        params.push_back(in_Param9_param);

        Glib::Variant<gint64> in_Param10_param =
            Glib::Variant<gint64>::create(arg_in_Param10);
        params.push_back(in_Param10_param);

        Glib::Variant<guint32> in_Param11_param =
            Glib::Variant<guint32>::create(arg_in_Param11);
        params.push_back(in_Param11_param);

        Glib::Variant<gint32> in_Param12_param =
            Glib::Variant<gint32>::create(arg_in_Param12);
        params.push_back(in_Param12_param);

        Glib::Variant<guint16> in_Param13_param =
            Glib::Variant<guint16>::create(arg_in_Param13);
        params.push_back(in_Param13_param);

        Glib::Variant<gint16> in_Param14_param =
            Glib::Variant<gint16>::create(arg_in_Param14);
        params.push_back(in_Param14_param);

        Glib::Variant<guchar> in_Param15_param =
            Glib::Variant<guchar>::create(arg_in_Param15);
        params.push_back(in_Param15_param);

        Glib::Variant<bool> in_Param16_param =
            Glib::Variant<bool>::create(arg_in_Param16);
        params.push_back(in_Param16_param);
        return Glib::VariantContainerBase::create_tuple(params);
    }

    static Glib::VariantContainerBase TestTriggerInternalPropertyChange_pack(
        gint32 arg_NewPropertyValue) {
        Glib::VariantContainerBase base;
        Glib::Variant<gint32> params =
            Glib::Variant<gint32>::create(arg_NewPropertyValue);
        return Glib::VariantContainerBase::create_tuple(params);
    }
};

} // glibmm
} // codegen
} // gdbus
} // org


