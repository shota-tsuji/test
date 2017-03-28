# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D
import copy
import sys
import scipy.linalg as linalg

# Initial condition
T = np.array([0., 0., 0., 0., 0.,100.,
              0., 0., 0., 0., 0.,100.,
              0., 0., 0., 0., 0.,100.,
              0., 0., 0., 0., 0.,100.,
              0., 0., 0., 0., 0.,100.,
              0., 0., 0., 0., 0.,100.])
# dots on the one edge
edge_length = 6
x_ax = range(len(T) / edge_length)
#delta_x = 1
delta_t = 0.1
# k is coefficent 
k = 1.
# the number of loop
loop = 100
# S is source of thermal
#S = [0., 0., 0., 0.,
#     0., 0., 0., 0,
#     0., 0., 0., 0,
#     0., 0., 0., 0,
#     0., 0., 0., 0]
S = np.zeros_like(T)
# h = delta_x = delta_y
h = 1.

fig = plt.figure()
ax = Axes3D(fig)
ims = []
X, Y = np.meshgrid(x_ax, x_ax)


# compute coefficent previously
coef = 2 * k * delta_t / (h ** 2)

# Main Loop
for step in xrange(0, loop):
    T_old = copy.deepcopy(T)
    # Cut the lower edge and upper edge because of Boundary Constrain
    for i in xrange(edge_length, len(T)-edge_length):
        # Cut the left edge and right edge because of Boundary Constrain
        if((i % edge_length) != 0 and (i % edge_length) != (edge_length-1)):
            T[i] = T_old[i] + coef * (T_old[i+1] + T_old[i-1] + T_old[i+5] + T_old[i-5] -4*T_old[i]) + S[i] * delta_t
    #for i in xrange(0, len(T)-1):
    #    sys.stdout.write(str(T[i]) + ' ')
    #    if(i%5 == 4):
    #        print '\n'
    #    if(i == 24):
    #        print '\n'
    Tmesh = T.reshape((edge_length, edge_length))
    im = ax.plot_wireframe(X, Y, Tmesh)
    ims.append([im])



ani = animation.ArtistAnimation(fig, ims, repeat_delay=1000)
plt.show()
