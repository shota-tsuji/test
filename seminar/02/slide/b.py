#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

name_title = "Block"
normal = np.loadtxt("./result.csv", delimiter=',')
block = np.loadtxt("./result_block.csv", delimiter=',')
vec_size = block[:, 0]
gflops_block = block[:, 1]
gflops_normal = normal[:, 1]

plt.plot(vec_size, gflops_block, label='block')
plt.plot(vec_size, gflops_normal, label='normal')

plt.rcParams["font.size"] = 18

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim(xmin=vec_size[0], xmax=vec_size[-1])
plt.ylim(ymin=0, ymax=0.35)
plt.title(name_title)
plt.grid(True)
#plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0)
plt.legend()
#plt.show()
name_file = 'b.jpeg'
plt.savefig(name_file, bbox_inches='tight')
