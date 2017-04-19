import matplotlib.pylab as plt
import numpy as np

A = np.array([[3, 1], [1, 1]])
la, v = np.linalg.eig(A)
delta_x = 0.01
delta_y = 0.01
loop = 20

def f(x, y):
    return A[0][0] * x + A[0][1] * y

def g(x, y):
    return A[1][0] * x + A[1][1] * y

def vec_eig(eig_v):
    return 

x, y = 3, 4
x_ax = [x]
y_ax = [y]
for step in range(0, loop):
    #next_f = A[0][0] * delta_x + f(x_now, y_now)
    #next_g = A[1][1] * delta_y + g(x_now, y_now)
    #x_now = next_f * delta_x
    #y_now = next_g * delta_y
    x_next = x + f(x, y) * delta_x
    y_next = y + g(x, y) * delta_y
    print [x, y]
    x_ax.append(x_next)
    y_ax.append(y_next)
    x, y = x_next, y_next


plt.scatter(x_ax, y_ax)

x_ax2 = range(-5, 5)
y_ax2 = []
#for x_value in x_ax2:
#    y_ax2.append()
ax = plt.gca()
#ax.spines['right'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data', 0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data', 0))
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.title('Phase plane')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.show()
