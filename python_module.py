import numpy as np


def f(x):
    '''
    very simple function
    '''
    return 2*x

def array_func(x):
    return float(x.shape[0])

def array_func2(x):
    return float(np.sum(x))

def array_func_multi_argument(x,y):
    return float(np.sum(x*y))


def ret_dict():
    return {"a": float(2), "b": float(3)}