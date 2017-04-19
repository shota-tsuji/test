# coding: utf-8
#import matplotlib.pylab as plt
import matplotlib.pyplot as plt
import numpy as np
import numpy.linalg as lin
import sys

def f(x, y):
    return -2.0 * x**2 + 3 * x -2 * y * x

def g(x, y):
    return -1.0 * y**2 + 2 * y - x * y

def makeJac(x, y):
    def f_x(x, y):
        return -4.0 * x +3 -2 * y
    def f_y(x, y):
        return -2.0 * x
    def g_x(x, y):
        return -1.0 * y
    def g_y(x, y):
        return -2.0 * y + 2 - x
    return np.array([[f_x(x, y), f_y(x, y)], 
                     [g_x(x, y), g_y(x, y)]])


#def plotEigVec(V, fixed_point, x_vec):
#    # 固有ベクトルは列ベクトルなので転置して扱う
#    y_whole = []
#    #for v in lin.inv(V):
#        x_vec = xrange(5)
#        y_vec = []
#        y = fixed_point[1]
#        if v[0] != 0:
#            for x in x_vec:
#                y_next = y + v[1] / v[0]
#                y_vec.append(y_next)
#                y = y_next
#        else:
#            for x in x_vec:
#                y_vec.append(v[1] * x)
#        plt.plot(x_vec, y_vec)
#        y_whole.extend(y_vec)
#        print 'plot'
#    #plt.axis('equal')
#    #plt.xlim(min())
#    print max(y_whole)
#    plt.ylim[min(y_whole), max(y_whole)]
#    plt.grid()
#    plt.show()

def plotEigVec():
    for fixed_point in fixed:
        # 固有値・固有ベクトルを求める
        # Aはヤコビ行列
        A = makeJac(fixed_point[0], fixed_point[1])
        D, V = lin.eig(A)
        print D
        print V
        #plotEigVec(V, fixed_point, x_ax)
        # 固有ベクトルに沿った直線をplot
        for v in V.T:
            if v[0] == 0:
                x_plt = np.zeros(7)
                y_plt = [fixed_point[1] + y for y in range(7)]
            elif v[1] == 0:
                y_plt = np.zeros(7)
                x_plt = [fixed_point[0] + x for x in range(7)]
            else:
                x_plt = np.arange(0.0, 4.0, 1.0, dtype=np.float32)
                y_plt = fixed_point[1] + v[1] / v[0] * x_plt
                print 'else'
                print fixed_point
                print x_plt
                print y_plt
                print 'else break'
            plt.plot(x_plt, y_plt, color='k')
            plt.scatter(fixed_point[0], fixed_point[1], c='blue', s=40, marker='o')



def plotStateXY(x, y):
    x_ax = [x]
    y_ax = [y]
    print 'Initial condition: ' + str([x, y])
    for step in range(0, loop):
        #print [x, y]
        x_next = x + f(x, y) * dx
        y_next = y + g(x, y) * dy
        x_ax.append(x_next)
        y_ax.append(y_next)
        x, y = x_next, y_next
    
    
    plt.plot(range(loop+1), x_ax, color='b')
    plt.title('X state for eqation(1)')
    plt.xlabel('Time-step')
    plt.ylabel('Number of individuals X')
    plt.grid()
    plt.show()
    
    plt.plot(range(loop+1), y_ax, color='r')
    plt.title('Y state for eqation(1)')
    plt.xlabel('Time-step')
    plt.ylabel('Number of individuals Y')
    plt.grid()
    plt.show()
    
    plt.plot(x_ax, y_ax, color='g')
    plotEigVec()
    plt.title('phase plane for eqation(1)')
    plt.xlabel('number of individuals x')
    plt.ylabel('number of individuals y')
    plt.grid()
    #ax = plt.gca()
    plt.axis('equal')
    #fig = plt.figure()
    #ax = fig.add_subplot(111, aspect='equal')
    #ax.plot()
    plt.show()
dx = 0.01
dy = 0.01
loop = 400

#x, y = 3, 5
fixed = ([0.0,0.0], [0.0, 2.0], [3.0/2, 0.0])
if __name__ == '__main__':
    initialPoints = ([0.1, 0.1], [0.3, 4.0], [3.0, 3.0], [4.5, 2.1])
    for point in initialPoints:
        plotStateXY(point[0], point[1])

