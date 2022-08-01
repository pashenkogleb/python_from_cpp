#include "py_util.hpp"

int main(){
    Py_Initialize();
    import_array();


    gutil::AddPath("/home/gpashchenko/projects/python_from_cpp");

    PyObject * module = gutil::import_module("python_module");
    PyObject * func = gutil::get_attr(module, "ret_dict");

    PyObject * dict_res = gutil::call_function(func);

    auto c_res = gutil::convert_to_c<std::unordered_map<std::string, double>>(dict_res);
    for (auto it = c_res.begin(); it!=c_res.end(); ++it){
        std::cout << it->first << ": " << it->second <<", ";
    }
    std::cout << std::endl;




    return 0;
}