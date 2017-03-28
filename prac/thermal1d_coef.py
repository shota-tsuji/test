# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

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




fig = plt.figure(figsize=(10, 10))
ims = []
for step in range(0, loop):
    for i in range(1, len(T) -1):
        T[i] = T[i] + k * delta_t / ( delta_x **2 ) * (T[i+1] -2*T[i] + T[i-1]) + S[i] * delta_t
        im = plt.plot(range(0, len(T)), T)
        ims.append([im])


ani = animation.ArtistAnimation(fig, ims )
plt.show()
