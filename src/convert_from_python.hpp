#pragma once
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdexcept>
#include <unordered_map>

namespace gutil{
    template <typename T>
    T convert_to_c(PyObject * obj);

    template<>
    inline long convert_to_c(PyObject * obj){
        if (!PyLong_Check(obj)) throw std::runtime_error("incorrect type (not long)");
        long res = PyLong_AsLong(obj);
        return res;
    }

    template <>
    inline double convert_to_c(PyObject * obj){
        if (!PyFloat_Check(obj)) throw std::runtime_error("incorrect type (not float)");
        double res = PyFloat_AsDouble (obj);
        if (PyErr_Occurred()) throw std::runtime_error("py error occured");
        return res;
    }
    template <>
    inline std::string convert_to_c(PyObject * obj){
        if (!PyUnicode_Check(obj)) throw std::runtime_error("incorrect type (not unicode)");
        const char * out = PyUnicode_AsUTF8(obj);
        if (!out) throw std::runtime_error ("null pointer");
        if (PyErr_Occurred()) throw std::runtime_error("py error occured");
        std::string s(out);
        return s;
    }

    template <>
    inline std::unordered_map<std::string, double> convert_to_c(PyObject * obj){
        // convert python dictionary to unordered_map
        if (!PyDict_Check(obj)) throw std::runtime_error("incorrect type (not dictionary)");
        std::unordered_map<std::string, double> res;
        PyObject *key, *value;
        Py_ssize_t pos = 0; 
        
        while (PyDict_Next(obj, &pos, &key, &value)) {
            std::string key_c = convert_to_c<std::string>(key);
            double value_c = convert_to_c<double>(value);
            res[key_c] = value_c;
        }
        return res;
    }





}