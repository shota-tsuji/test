#import matplotlib.pylab as plt
import matplotlib.pyplot as plt
import numpy as np

dx = 0.01
dy = 0.01
loop = 20

def f(x, y):
    return - x**2 + 3 * x - y * x

def g(x, y):
    return - y**2 + 2 * y - x * y


x, y = 2.0, 1.0
x_ax = [x]
y_ax = [y]

for step in range(0, loop):
    print [x, y]
    x_next = x + f(x, y) * dx
    y_next = y + g(x, y) * dy
    x_ax.append(x_next)
    y_ax.append(y_next)
    x, y = x_next, y_next

plt.plot(x_ax, y_ax)
plt.title('Phase plane for eqation(1)')
plt.grid()
#ax = plt.gca()
plt.axis('equal')
#fig = plt.figure()
#ax = fig.add_subplot(111, aspect='equal')
#ax.plot()
plt.show()
