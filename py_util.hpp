#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string>
#include <stdexcept>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include <iostream>


namespace gutil{

PyObject * import_module(const std::string & name){
    PyObject * module = PyImport_ImportModule(name.c_str());
    if (!module){
        throw std::runtime_error("could not load module");
    }
    return module;
}

PyObject * func_from_module(PyObject * module, const std::string & name){
    PyObject * func = PyObject_GetAttrString(module,name.c_str());
    if (!func){
        throw std::runtime_error("could not load function");
    }
    return func;
}

PyObject * call_function(PyObject * func, PyObject * arg){
    /*
    call with one arg
    */
    return PyObject_CallFunctionObjArgs(func,arg, NULL);
}

void PrintObject(PyObject * obj){
    PyObject* objectsRepresentation = PyObject_Repr(obj);
    const char * res = PyUnicode_AsUTF8(objectsRepresentation);
    std::cout << res << std::endl;
}



template <typename T>
struct np_typenum;

template <>
struct np_typenum<float>{
    static const int value =  NPY_FLOAT32;
};

template <>
struct np_typenum<int>{
    static const int value = NPY_INT32;
};


template <typename T>
PyObject * np_array(T * data, npy_intp size){
    /*
    creates 1D numpy array
    */
    PyObject * array = PyArray_SimpleNewFromData(1, &size, np_typenum<T>::value, data);
    return array;
}

}