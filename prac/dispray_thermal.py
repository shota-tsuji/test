    # coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

result = np.loadtxt("./result2.csv", delimiter=",")
#print result[0]
loop = result.shape[0]
fig = plt.figure()
ims = []
for step in range(0, loop):
    #im = plt.plot(, result[step])
    im, = plt.plot(result[step], 'r')
    ims.append([im])

ani = animation.ArtistAnimation(fig, ims)
plt.show()
ani.save('result_thermal.gif', writer='imagemagick', fps=4)
