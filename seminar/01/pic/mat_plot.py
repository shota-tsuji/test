import matplotlib.pyplot as plt
import numpy as np

n = 4
x = np.linspace(0, 1, n)
y = np.linspace(0, 1, n)

xv, yv = np.meshgrid(x, y, sparse=True)
print xv
print yv
