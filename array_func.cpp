#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "py_util.hpp"
#include "numpy/arrayobject.h"


#include <stdexcept>
#include <iostream>
#include <vector>


int main(){
    Py_Initialize();
    import_array();
    PyObject * module = gutil::import_module("mytest");

    PyObject * array_func = gutil::get_attr(module, "array_func");
    PyObject * array_func2 = gutil::get_attr(module, "array_func2");

    std::vector<float> x=  {1,2,4};


    PyObject * arr = gutil::np_array(x.data(), x.size());


    gutil::PrintObject(gutil::call_function(array_func, arr));


    gutil::PrintObject(gutil::call_function(array_func2, arr));




    return 0;
}