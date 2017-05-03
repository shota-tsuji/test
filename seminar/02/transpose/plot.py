#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

name_title = "Mat-Mat Product(Transposed)"
name_pic = "a.jpeg"
result = np.loadtxt("./result_transpose.csv", delimiter=',')
vec_size = result[:, 0]
gflops = result[:, 1]


plt.plot(vec_size, gflops)

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim(xmin=vec_size[0], xmax=vec_size[-1])
plt.ylim(ymin=0, ymax=0.4)
plt.title(name_title)
plt.grid(True)
#plt.show()
plt.savefig(name_pic, bbox_inches='tight')
