#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

result = np.loadtxt("./result.csv", delimiter=',')
vec_size = result[:, 0]
gflops = result[:, 2]

plt.plot(vec_size, gflops)

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim(xmin=0, xmax=1100)
plt.ylim(ymin=0, ymax=0.4)
plt.title("Matrix Matrix Product")
plt.grid(True)
#plt.show()
plt.savefig('sem_MatMatProduct.jpeg', bbox_inches='tight')
