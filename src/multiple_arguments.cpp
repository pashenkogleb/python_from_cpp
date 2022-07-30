#include "py_util.hpp"
#include <vector>

int main(){
    Py_Initialize();
    import_array();

    gutil::AddPath("/home/gpashchenko/projects/python_from_cpp");
    PyObject * module = gutil::import_module("python_module");
    PyObject * func = gutil::get_attr(module, "array_func_multi_argument");

    std::vector<float> x = {1,2,3};
    std::vector<float> y = {1,3,4};

    auto x_np = gutil::np_array(x.data(), x.size());
    auto y_np = gutil::np_array(y.data(), y.size());

    gutil::PrintObject(gutil::call_function(func, x_np, y_np)) << std::endl;

    return 0;
}