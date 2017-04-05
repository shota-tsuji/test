# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

from mpl_toolkits.mplot3d import axes3d

size = 10
result = np.loadtxt("./result2.csv", delimiter=",")
loop = result.shape[0] / size
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
xlist = np.linspace(0, 5, size)
ylist = np.linspace(0, 5, size)
X, Y = np.meshgrid(xlist, ylist)
ims = []
for step in range(0, loop):
    #im = plt.plot(, result[step])
    #result_2d = np.empty((0, size), dtype=np.float16)
    result_2d = result[size * step]
    for i in range(1, size):
        #np.append(result, result[size * step +i], axis=0)
        result_2d = np.concatenate((result_2d, result[size * step +i]), axis=0)
    #result_2d = result_2d.reshape(result_2d, size)
    result_2d = result_2d.reshape(size, size)
#    im, = plt.plot(result[step], 'r')
    im = ax.plot_wireframe(X, Y, result_2d)
    ims.append([im])

ani = animation.ArtistAnimation(fig, ims)
plt.show()
ani.save('result_thermal.gif', writer='imagemagick', fps=4)
