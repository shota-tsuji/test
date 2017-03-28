# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import copy

# Initial condition
T = np.array([0., 0., 0., 100.])
delta_x = 1
delta_t = 0.3
# k is coefficent 
k = 1.
# the number of loop
loop = 500
# S is source of thermal
S = np.zeros(T.shape)



#for cnt in range(0, loop):
#    for i in range(1, len(T) -1):
#        T[i] = T[i] + k * delta_t / ( delta_x **2 ) * (T[i+1] -2*T[i] + T[i-1]) + S[i] * delta_t
#
    # first position T[0] and T[last] are not changed because of baundary condition.


fig = plt.figure()
ims = []
for step in range(0, loop):
	T_old = copy.deepcopy(T)
    for i in range(1, len(T) -1):
		T[i] = T_old[i] + k * delta_t / ( delta_x **2 ) * (T_old[i+1] -2*T_old[i] + T_old[i-1]) + S[i] * delta_t
        im = plt.plot(, T)
        ims.append([im])


ani = animation.ArtistAnimation(fig, ims )
plt.show()
# anim.save('thermal_1d.gif', writer='imagemagick', fps=4)
