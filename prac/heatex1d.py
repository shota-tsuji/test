# coding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import copy
import sys
import scipy.linalg as linalg
from scipy import optimize as opt
import scipy as sp

# 2次近似（銀）の学習 && 熱拡散率返す関数
def learning_kelvim_Ag():
    T_kelvin = np.array([150, 250, 300, 600, 800, 1000, 1200])
    expand_ratio = np.array([192, 176, 174, 161, 149, 137, 124])
    parameter0 = [0., 0., 0.]
    res = opt.leastsq(fit_func2, parameter0, args=(T_kelvin, expand_ratio))
    a, b, c = res[0][0], res[0][1], res[0][2]

    #x = range(150, 1200, 10)
    #plt.scatter(T_kelvin, expand_ratio)
    #k = []
    #for i in x:
    #    print i
    #    k.append( kelvin(i, res[0][0], res[0][1], res[0][2]))
    #    #plt.plot(i, kelvin(x, res[0], res[1], res[2]))
    #plt.plot(x, k)
    #plt.show()
    return a, b, c

def fit_func2(param, x, y):
    residual = y - (param[0]*x**2 + param[1]*x + param[2])
    return residual

def kelvin(T_i, a, b, c):
    return a * T_i**2 + b * T_i + c


#def fit_func(parameter, x, y):
#    a = parameter[0]
#    b = parameter[1]
#    c = [parameter[2]] * len(x) 
#    print c
#    #xx = [v**2 for v in x]
#    residual = y - (a * x * x + b * x + c)
#    print residual
#    return residual

# 安定性のあるdtを返す（引数：k, dx)
def stable_dt(k_max, dx):
    return dx**2 / (2.0 * k_max)

# 無次元化
def non_x(x):
    return x / L

def non_T(T):
    return (T - T0) / (Tw - T0)

def non_t(t):
    return t / tw

trans_non()



def make_matrixA():
    # make the A matrix of Ax = b.
    A = np.zeros((len(T), len(T))) # Matrix A is n**2
    near_points2 = []
    near_points2.append(-k * dt / (dx **2))
    near_points2.append(1 + 2 * k * dt / (dx **2))
    near_points2.append(-k * dt / (dx **2))
    A[0][0] = 1.0
    A[len(T)-1][len(T)-1] = 1.0
    for column in range(1, len(T) -1):
        A[column][column-1], A[column][column], A[column][column+1] = near_points2

    return A




# Initial condition
L = 50 + 2 #[mm]
tw = 10 #[s]
T0 = 273.15 #[K]
Tw = 373.15 #[K]
T = [c+T0 for c in np.zeros(L)]
T[-1] = T[-2] = Tw
T[0] = T[1]


x_ax = range(len(T))
dx = 1.0
#dt = 0.1
dt = stable_dt(Tw, dx)
print dt
sys.exit(0)
L_dt = [dt for i in range(len(T))] 
loop = 100
S = np.zeros(T.shape)
A = make_matrixA()



























# 関数用意


# Prepare LU-destructed matrix
LU = linalg.lu_factor(A)

fig = plt.figure()
ims = []

source_deltaT = [x * y for (x, y) in zip(S, L_dt)]

# Main Loop
for step in range(0, loop):
    inverse_A = np.linalg.inv(A)
    T_old = copy.deepcopy(T)
    for i in range(1, len(T)-1):
        t_puls_s = [x + y for (x, y) in zip(T_old, source_deltaT)]
        T = linalg.lu_solve(LU, t_puls_s)
    T[0] = T[1]
    T[-1] = T[-2]
    print T_old
    im = plt.plot(x_ax, T, 'r')
    ims.append(im)

   #print T


ani = animation.ArtistAnimation(fig, ims)
plt.title('Thermal expansion(Neumann Boundary)')
plt.show()
