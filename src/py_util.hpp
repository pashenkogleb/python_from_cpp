#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string>
#include <stdexcept>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include <iostream>
#include "gutil/metaprogramming.hpp" // defined in my_cpp_lib


namespace gutil{

PyObject * import_module(const std::string & name){
    PyObject * module = PyImport_ImportModule(name.c_str());
    if (!module){
        throw std::runtime_error("could not load module");
    }
    return module;
}

PyObject * get_attr(PyObject * module, const std::string & name){
    PyObject * func = PyObject_GetAttrString(module,name.c_str());
    if (!func){
        throw std::runtime_error("could not load attribute");
    }
    return func;
}


void AddPath(const std::string & path){
    PyObject *sys_path = PySys_GetObject("path");
    PyObject * py_path = Py_BuildValue("s",path.c_str() );
    PyList_Append(sys_path, py_path);
}


template <typename... pyobjects>
PyObject * call_function(PyObject * func, pyobjects... pyobjects_objs){
    static_assert(gutil::all_same<PyObject *, pyobjects...>::value, "can only pass PyObject *");
    return PyObject_CallFunctionObjArgs(func,pyobjects_objs..., NULL);
}








std::ostream & PrintObject(PyObject * obj, std::ostream & out = std::cout){
    PyObject* objectsRepresentation = PyObject_Repr(obj);
    const char * res = PyUnicode_AsUTF8(objectsRepresentation);
    out << res;
    return  out;

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

template <>
struct np_typenum<double>{
    static const int value = NPY_FLOAT64;
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