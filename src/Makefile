CXXFLAGS=-I/usr/include/python3.8 -I/home/gpashchenko/projects/my_cpp_lib -Wall -std=c++11 -O3
CC=g++
LDLIBS = -lpython3.8

BUILDDIR = ../build
OUTDIR = ../out
deps = py_util.hpp
TARGETS = array_func simple_func numpy_vs_cpp multiple_arguments #ADD TARGETS TO THIS LINE

_TARGETS = $(patsubst %, $(OUTDIR)/%.out, $(TARGETS))

# run: $(_RUN_TARGET)
# 	$(_RUN_TARGET)

$(TARGETS): $(_TARGETS)  #can call make array_func
	../out/$@.out
	

compile: $(_TARGETS)



$(OUTDIR)/%.out: $(BUILDDIR)/%.o
	$(CC) -o $@ $< $(LDLIBS)

$(BUILDDIR)/%.o : %.cpp $(deps)
	$(CC) -c $(CXXFLAGS) -o $@ $< 




clean:
	rm -f *.o