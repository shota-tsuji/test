#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

result = np.loadtxt("./result_step.csv", delimiter=',')
vec_size = result[:, 0]
gflops = result[:, 1]

plt.plot(vec_size, gflops)

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim(xmin=vec_size[0], xmax=vec_size[-1])
plt.ylim(ymin=0.10, ymax=0.3)
plt.title("Matrix Matrix Product")
plt.grid(True)
#plt.show()
plt.savefig('c.jpeg', bbox_inches='tight')
