#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

result = np.loadtxt("./result.csv", delimiter=',')
vec_size = result[:, 0]
gflops = result[:, 2]

plt.plot(vec_size, gflops)

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim()
plt.title("Matrix Matrix Product")
plt.grid(True)
#plt.show()
plt.savefig('sem_MatMatProduct.png', bbox_inches='tight')
