#include "py_util.hpp"


int main(){
    PyObject * obj =  Py_BuildValue("s", "asdhj12");
    std::string obj_str = gutil::convert_to_c<std::string>(obj);

    std::cout << obj_str << std::endl;

    return 0;
}