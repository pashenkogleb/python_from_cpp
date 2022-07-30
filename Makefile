CXXFLAGS=-I/usr/include/python3.8 -I/home/gpashchenko/projects/my_cpp_lib -Wall -std=c++11 -O3
CC=g++
LDLIBS = -lpython3.8

TARGETS = simple_func 


run: numpy_vs_cpp
	./numpy_vs_cpp



clean:
	rm -f *.o