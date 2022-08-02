#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "convert_from_python.hpp"
#include "numpy_python.hpp"


#include <string>
#include <stdexcept>


#include <iostream>
#include "gutil/metaprogramming.hpp" // defined in my_cpp_lib


namespace gutil{

inline PyObject * import_module(const std::string & name){
    PyObject * module = PyImport_ImportModule(name.c_str()); // new reference
    if (!module){
        throw std::runtime_error("could not load module");
    }
    return module;
}

inline PyObject * get_attr(PyObject * module, const std::string & name){
    PyObject * func = PyObject_GetAttrString(module,name.c_str()); // returns new reference
    if (!func){
        throw std::runtime_error("could not load attribute");
    }

    return func;
}


inline void AddPath(const std::string & path){
    PyObject *sys_path = PySys_GetObject("path"); // borrowed reference
    PyObject * py_path = Py_BuildValue("s",path.c_str() );
    int error= PyList_Append(sys_path, py_path);
    Py_DecRef(py_path);
    if (error == -1){
        throw std::runtime_error("could not append to list");
    }
}


template <typename... pyobjects>
PyObject * call_function(PyObject * func, pyobjects... pyobjects_objs){
    static_assert(gutil::all_same<PyObject *, pyobjects...>::value, "can only pass PyObject *");
    if (!PyFunction_Check(func)) throw std::runtime_error("have to pass a function");
    PyObject * res = PyObject_CallFunctionObjArgs(func,pyobjects_objs..., NULL);
    if (PyErr_Occurred()) throw std::runtime_error("error during function call");
    if (!res) throw std::runtime_error("function did not return anything");
    return res; // new reference
}





inline std::ostream & PrintObject(PyObject * obj, std::ostream & out = std::cout){
    PyObject* objectsRepresentation = PyObject_Repr(obj); // new reference
    const char * res = PyUnicode_AsUTF8(objectsRepresentation);
    Py_DecRef(objectsRepresentation);
    out << res;
    return  out;

}

inline std::ostream & PrintType(PyObject * obj, std::ostream & out = std::cout){
    PyObject * type = PyObject_Type(obj); // new references
    PrintObject(type, out);
    Py_DecRef(type);
    return out;
}


}