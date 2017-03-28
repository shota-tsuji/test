# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D
import copy
import sys


# Initial condition
T = np.array([0., 0., 0., 100.])
x_ax = range(len(T))
delta_x = 1
delta_t = 0.1 
L_delta_t = [delta_t for i in range(len(T))] 
# k is coefficent 
k = 1.
# the number of loop
loop = 100
# S is source of thermal
#S = np.zeros(T.shape)
S = [0., 0., 0., 0.]
near_points2 = []
near_points2.append(-k * delta_t / (delta_x **2))
near_points2.append(1 + 2 * k * delta_t / (delta_x **2))
near_points2.append(-k * delta_t / (delta_x **2))
# make the A matrix of Ax = b.
A = np.zeros((len(T), len(T))) # Matrix A is n**2
#row1 = np.zeros(T.shape)
#row1[0] = 1.0
#A.append(row1)
# Boundary Constrain
A[0][0] = 1.0
A[len(T)-1][len(T)-1] = 1.0
for column in range(1, len(T) -1):
    A[column][column-1], A[column][column], A[column][column+1] = near_points2


fig = plt.figure()
ims = []
for step in range(0, loop):
    inverse_A = np.linalg.inv(A)
    T_old = copy.deepcopy(T)
    for i in range(1, len(T)-1):
        source_deltaT = [x * y for (x, y) in zip(S, L_delta_t)]
        T[i] = np.inner(inverse_A[i], [x + y for (x, y) in zip(T_old, source_deltaT)])
        im = plt.plot(x_ax, T, 'r')
        ims.append(im)

   #print T
#sys.exit()
#for cnt in range(0, loop):
#    for i in range(1, len(T) -1):
#        T[i] = T[i] + k * delta_t / ( delta_x **2 ) * (T[i+1] -2*T[i] + T[i-1]) + S[i] * delta_t
#
    # first position T[0] and T[last] are not changed because of baundary condition.


# ims list includes the plot-images!!!
# And you put the plot-images into ArtistAnimation
ani = animation.ArtistAnimation(fig, ims)


plt.title('Thermal expansion')

# def animate(nframe):
#    ims = plt.plot(range(0, len(T)), T)
#    plt.title('Thermal expansion')
#    animate.append(ims)


#anim = animation.FuncAnimation(fig, animate, frames=30)
# anim.save('thermal_1d.gif', writer='imagemagick', fps=4)

plt.show()
#ani.save('thermal_1d.gif', writer='imagemagick', fps=4);

