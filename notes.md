# Python C-API
Py_Initialize has to be called before start

## Calling functions
docs at: https://docs.python.org/3/c-api/call.html

To call functions have to either pass a tuple of arguments with PyObject_Call() or newer versions of python accept format string

To create tuple use PyTuple_Pack

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
