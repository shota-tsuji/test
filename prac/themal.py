# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Initial condition
T = np.array([0., 0., 0., 100.])
x_ax = range(len(T))
delta_x = 1
delta_t = 0.1
# k is coefficent 
k = 1.
# the number of loop
loop = 100
# S is source of thermal
S = np.zeros(T.shape)

fig = plt.figure()
ims = []
for cnt in range(0, loop):
    for i in range(1, len(T) -1):
        T[i] = T[i] + k * delta_t / ( delta_x **2 ) * (T[i+1] -2*T[i] + T[i-1]) + S[i] * delta_t

    # first position T[0] and T[last] are not changed because of baundary condition.
    im = plt.plot(x_ax, T, 'r')
    ims.append(im)

# ims list includes the plot-images!!!
# And you put the plot-images into ArtistAnimation
ani = animation.ArtistAnimation(fig, ims)
# animate = []


#ims = plt.plot(range(0, len(T)), T)
# plt.title('Thermal expansion')

# def animate(nframe):
#    ims = plt.plot(range(0, len(T)), T)
#    plt.title('Thermal expansion')
#    animate.append(ims)


#anim = animation.FuncAnimation(fig, animate, frames=30)
# anim.save('thermal_1d.gif', writer='imagemagick', fps=4)

plt.show()
ani.save('thermal_1d.gif', writer='imagemagick', fps=4);

