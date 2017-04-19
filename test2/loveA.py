import numpy as np
import matplotlib.pyplot as plt
import sys

n = 5 
A = np.array([[3, 1],
              [0, 0]])
R, J = np.mgrid[-n:n, -n:n]
#R_dot, J_dot = np.dot()
R_dot = []
J_dot = []
for row in xrange(0, n):
    add_R = []
    add_J = []
    for column in xrange(0, n):
        #r_dot, j_dot = np.dot(A, [R[row][column], J[row][column]])
        r_dot, j_dot = np.dot(A, [R[row][column], J[row][column]])
        add_R.append(r_dot)
        add_J.append(j_dot)
    R_dot.append(add_R)
    J_dot.append(add_J)

print R_dot
print J_dot
plt.quiver(R, J, R_dot, J_dot, alpha=.5)

plt.show()
