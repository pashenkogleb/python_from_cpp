#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdexcept>
#include <iostream>

#include "py_util.hpp"

int main(){
    Py_Initialize();
    

    PyObject * module = gutil::import_module("mytest");
    PyObject * func = gutil::func_from_module(module, "f");

    PyObject * python_res = PyObject_CallFunction(func, "d", 2.6); 

    double res =  PyFloat_AsDouble(python_res);

    std::cout << res << std::endl;

    return 0;
}