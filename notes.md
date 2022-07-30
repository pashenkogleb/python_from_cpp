# Python C-API
Py_Initialize has to be called before start

## Calling functions
docs at: https://docs.python.org/3/c-api/call.html

To call functions have to either pass a tuple of arguments with PyObject_Call() or newer versions of python accept format string

To create tuple use PyTuple_Pack

## Python types
https://docs.python.org/3/reference/datamodel.html#types

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

## Efficiency
example numpy_vs_cpp shows that python is faster even with -O3 !!

