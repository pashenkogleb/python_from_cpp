#include "py_util.hpp"
#include "gutil/time_profiler.hpp"
#include "gutil/random.hpp"

int main(){
    Py_Initialize();
    import_array();

    gutil::AddPath("/home/gpashchenko/projects/python_from_cpp");

    PyObject * module = gutil::import_module("python_module");
    PyObject * func = gutil::get_attr(module, "array_func2");

    int size = 10000000;
    std::vector<double> vec = gutil::NormalVec(size);

    gutil::TimeProfile profiler;



    profiler.Start("c++");

    double sum =0;
    for (double x: vec){
        sum+=x;
    }
    std::cout << sum << std::endl;

    profiler.Start("python");
    PyObject * np_array = gutil::np_array(vec.data(), vec.size());
    PyObject * res = gutil::call_function(func, np_array);
    gutil::PrintObject(res) << std::endl;


    profiler.End();
    profiler.Result();


    return 0;
}