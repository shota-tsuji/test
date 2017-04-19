# coding: utf-8
import numpy as np
from scipy import optimize

def fun(x):
    return [(3 - x[1]) * x[0] - x[0]**2, (2 - x[0]) * x[1] - x[1]**2]

def jac(x):
    return np.array([[-2 * x[0] + (3 - x[1]), -x[0]],
                    [-x[1], -2*x[1] + (2-x[0])]])

sol = optimize.root(fun, [0,1], method='broyden1')

print sol
