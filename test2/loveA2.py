import numpy as np
import matplotlib.pyplot as plt
import sys

n = 5
a, b, c, d = 3, 1, 1, 1
A = np.matrix(((3, 1), (1, 1)))
J_dm, R = np.mgrid[-n:n, -n:n]
J = []
print len(J_dm)
for i in xrange(len(J_dm)-1, 0-1, -1):
	J.append(J_dm[i])
#print R
#print J
#R_dot, J_dot = np.dot()
R_dot = []
J_dot = []
for row in xrange(0, n):
    add_R = []
    add_J = []
    for column in xrange(0, n):
		#add = np.dot(A, [R[row][column], J[row][column]])
                #print add[0]
                r_dot = a * R[row][column] + b * J[row][column]
                j_dot = c * R[row][column] + d * J[row][column]
		add_R.append(r_dot)
		add_J.append(j_dot)
    R_dot.append(add_R)
    J_dot.append(add_J)



print R_dot
print J_dot
plt.quiver(R_dot, J_dot )

plt.show()
