#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdexcept>
#include <iostream>

#include "py_util.hpp"

int main(){
    Py_Initialize();
    gutil::AddPath("/home/gpashchenko/projects/python_from_cpp");

    
    PyObject * module = gutil::import_module("python_module");
    PyObject * func = gutil::get_attr(module, "f");

    PyObject * python_res = PyObject_CallFunction(func, "d", 2.6); 

    double res =  PyFloat_AsDouble(python_res);

    std::cout << res << std::endl;

    return 0;
}