# Python C-API
Py_Initialize has to be called before start

## Calling functions
docs at: https://docs.python.org/3/c-api/call.html

To call functions have to either pass a tuple of arguments with PyObject_Call() or newer versions of python accept format string

To create tuple use PyTuple_Pack

## Python types
https://docs.python.org/3/reference/datamodel.html#types

https://docs.python.org/3/c-api/concrete.html - Concrete objects Layer


String are unicode type **read more**

Usually have functions:
type here can be:

- Numeric
    - Long (long python integer that can be arbitrarily long, all integers are of this type)
    - Float
    - Bool
- Container
    - Dict


```
int Py{type}_Check(PyObject *) - check that object is of given type

PyObject * Py{type}_FromDouble(double x) - convert from c double to python object of that type

double Py{type}_AsDouble(PyObject *) - convert from python object to double


```

### Creating python objects from c++ objects:

https://docs.python.org/3/c-api/arg.html#building-values

I think I can just Py_BuildValue to convert c objects to python objects

```
Py_BuildValue("i", 3); 
```



**Have to Py_DECREF(obj) after I am done with these** 



**Have to be very careful with types**. For example: 
```
PyObject_CallFunction(func, "d", 2); # WRONG 
PyObject_CallFunction(func, "d", 2.0); # CORRECT
```


## Numpy 
```
#include "numpy/arrayobject.h"

import_array(); // has to be called from the start
```
## Creating arrays
```
 PyObject* PyArray_SimpleNewFromData(int number_dimensions, npy_intp const* dims, int typenum, void* data) 
```

I think that PyArray_SimpleNewFromData does not own data by default

### Typenums
- NPY_INT64
- NPY_FLOAT64


## Memory leaks
References can be 
- New reference (you own it, have to decrf)
- Borrow reference (you can use it but you do not own it, no need to decrf)



PyList_SetItem - steals reference so no need to decrement afterwards
PyList_Append - does not steal a reference so have to decrement

## Efficiency
example numpy_vs_cpp shows that python is faster even with -O3 !!

