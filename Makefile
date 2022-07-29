CXXFLAGS=-I/usr/include/python3.8 -Wall -std=c++11
CC=g++
LDLIBS = -lpython3.8

TARGETS = simple_func 



array_func: array_func.o

simple_func: simple_func.o



run: array_func
	./array_func

clean:
	rm *.o