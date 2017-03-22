# -*- coding: UTF-8 -*-
import numpy as np
import numpy.linalg as lin
import sys

def f( x1, x2 ):
    f1 = x1**3 + x2 -1
    f2 = x2**3 - x1 +1
    f_ = np.array( [[f1],
                    [f2]] )
    return f_

def Df( x1, x2 ):
    return np.array( [[3.0 * x1**2, 1.0],
                        [-1.0, 3 * x2**2 ]] ,dtype='float64')

x1 = 1.0
x2 = 1.0
n = 10
x = np.array( [x1, x2] ).reshape(2, 1) # 2d array
print x
#sys.exit(0)

for i in xrange(n):
    df_matrix = Df(x1, x2)
    #print df_matrix
    df_M_inv = lin.inv(df_matrix)
    #print df_M_inv
    #print -df_M_inv
    fx = f( x1, x2)
    print fx
    dx = - df_M_inv.dot( f(x1, x2) )
    #print dx
    x = x + dx
    x1 = x.tolist()[0][0]
    x2 = x.tolist()[1][0]
    #print x
    #print f( x[0], x[1] )
