#include "py_util.hpp"


int main(){
    Py_Initialize();
    import_array();

        

    #ifdef USE_NUMPY

    #else

    #endif

    return 0;
}