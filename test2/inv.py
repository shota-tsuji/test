import numpy as np
import numpy.linalg as lin

A = np.array([[4, 5], [1, 3]])
print A
#for v in lin.inv(A):
#    print v
for v in A.T:
    print v


x_plt = np.arange(0.0, 4.0, 1.0, dtype=np.float32)
y_plt = 0 -2 / 3 * x_plt
print x_plt
print y_plt
