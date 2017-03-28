# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import copy
import sys

# Initial condition
T = np.array([0., 0., 0., 100.])
length_T = len(T)
L = length_T # [mm] # L is whole length of the material
delta_x = 1.0
delta_t = 1
T_0 = 0.0   # T_0 is a initial temperature and T_w is finit one.
T_w = 100.0
t_w = 30  # t_w means the whole time.
k = 1    # k is coefficent 
#S = np.zeros(T.shape)  # S is source of thermal





# Caluculate non-dimensionalized values at each position of T[i].
X_Non = [x / L for x in range(0, length_T)]

# Simulate until the whole time elapsed.
T_Non_new = np.zeros_like(T)
T_Non_new[0] = (T[0] - T_0) / (T_w - T_0)
T_Non_new[-1] = (T[-1] - T_0) / (T_w - T_0)

for t_now in range(0, t_w, delta_t):
    t_Non = t_now / t_w
    # Non-dimensionalize value about each temperature T[i].
    T_Non = [(T_i - T_0) / (T_w - T_0) for T_i in T]
    for x_now in range(1, length_T-1):
        T_Non_new[x_now] = T_Non[x_now] + k*delta_t / (delta_x ** 2) * (T_Non[x_now+1] -2*T_Non[x_now] + T_Non[x_now-1])

    # Invert toransform & Print the real values.

    #for x_now in range(1, length_T-1):
    #    #print T_Non_new[x_now] * (T_w - T_0) + T_0
    #    T_p = T_Non_new[x_now] * (T_w - T_0) + T_0
    #    sys.stdout.write(str(T_p) + '  ')
    #print '\n'


    T = [T_i_Non * (T_w - T_0) + T_0 for T_i_Non in T_Non_new]
    print T_Non_new
    #for x_now in range(1, length_T-1):
    #    #print T_Non_new[x_now] * (T_w - T_0) + T_0
    #    T_p = T_Non_new[x_now] * (T_w - T_0) + T_0
    #    sys.stdout.write(str(T_p) + '  ')
    #print '\n'






#fig = plt.figure()
#ims = []
#for step in range(0, loop):
#    T_old = copy.deepcopy(T)
#    for i in range(1, len(T) -1):
#        T[i] = T_old[i] + k * delta_t / ( delta_x **2 ) * (T_old[i+1] -2*T_old[i] + T_old[i-1]) + S[i] * delta_t
#        im = plt.plot(, T)
#        ims.append([im])
#
#
#ani = animation.ArtistAnimation(fig, ims )
#plt.show()
