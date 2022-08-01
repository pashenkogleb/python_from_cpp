
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"


namespace gutil{

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
    PyObject * array = PyArray_SimpleNewFromData(1, &size, np_typenum<T>::value, data); // new reference (but this array does not own buffer)
    return array;
}

}