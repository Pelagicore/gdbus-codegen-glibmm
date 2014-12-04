#include "many-types_proxy.h"
#include "tools.h"

Glib::RefPtr<org::gdbus::codegen::glibmm::Test> proxy;

void on_test_byte_string_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<std::string> expected) {
      std::vector<std::string> res;
      proxy->TestByteStringArray_finish(res, result);
      g_assert (res == expected);
}

void on_test_object_path_array_finished (const Glib::RefPtr<Gio::AsyncResult> result, std::vector<Glib::ustring> expected) {
      std::vector<Glib::ustring> res;
      proxy->TestObjectPathArray_finish(res, result);
      g_assert (res == expected);
}

void proxy_created(const Glib::RefPtr<Gio::AsyncResult> result) {
    g_print ("Instance ready!\n");

    std::vector<std::string> inputStrVec;
    inputStrVec.push_back(__FUNCTION__);

    std::vector<std::string> inputObjPathVec;
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");
    inputObjPathVec.push_back("/org/gdbus/codegen/glibmm/Test");

    proxy = org::gdbus::codegen::glibmm::Test::createForBusFinish(result);
    proxy->TestByteStringArray(inputStrVec, sigc::bind(sigc::ptr_fun(&on_test_byte_string_array_finished), inputStrVec));
    proxy->TestObjectPathArray(inputObjPathVec, sigc::bind(sigc::ptr_fun(&on_test_object_path_array_finished), 
                                                    CodegenTools::stdStringVecToGlibStringVec(inputObjPathVec)));
}

int main() {
    Glib::init();
    Gio::init();

    org::gdbus::codegen::glibmm::Test::createForBus(Gio::DBus::BUS_TYPE_SESSION,
                                Gio::DBus::PROXY_FLAGS_NONE,
                                "org.gdbus.codegen.glibmm.Test",
                                "/org/gdbus/codegen/glibmm/Test",
                                sigc::ptr_fun(&proxy_created));

    Glib::RefPtr<Glib::MainLoop> ml = Glib::MainLoop::create();
    ml->run();
}
