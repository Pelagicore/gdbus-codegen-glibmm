#include <glibmm.h>
#include <giomm.h>
#include <vector>
#include <string>

class CodegenTools {
public:
    template<typename T>
    static void retSingle (T retVal, const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) {
        invocation->return_value( Glib::VariantContainerBase::create_tuple(Glib::Variant<T>::create(retVal)));
    }

    template<typename T>
    static void unwrapList(std::vector<T> &list, const Glib::VariantContainerBase &wrapped) {
        for (int i = 0; i < wrapped.get_n_children (); i++) {
            Glib::Variant<T> item;
            wrapped.get_child(item, i);
            list.push_back(item.get());
        }
    }
    static std::vector<Glib::ustring> stdStringVecToGlibStringVec(const std::vector<std::string> &strv) {
        std::vector<Glib::ustring> newStrv;
        for (int i = 0; i < strv.size(); i++) {
            newStrv.push_back(strv[i]);
        }

        return newStrv;
    }
};
