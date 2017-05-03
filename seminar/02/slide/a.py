#coding:utf-8
import numpy as np
import matplotlib.pyplot as plt

name_file = "Loop Exchange(i,j,k)"
ijk = np.loadtxt("./result_ijk.csv", delimiter=',')
ikj = np.loadtxt("./result_ikj.csv", delimiter=',')
kji = np.loadtxt("./result_kji.csv", delimiter=',')
kij = np.loadtxt("./result_kij.csv", delimiter=',')
jik = np.loadtxt("./result_jik.csv", delimiter=',')
jki = np.loadtxt("./result_jki.csv", delimiter=',')
vec_size = ijk[:, 0]
ijk_GFLOPS = ijk[:, 1]
ikj_GFLOPS = ikj[:, 1]
kji_GFLOPS = kji[:, 1]
kij_GFLOPS = kij[:, 1]
jik_GFLOPS = jik[:, 1]
jki_GFLOPS = jki[:, 1]

plt.plot(vec_size, ijk_GFLOPS, label='ijk')
plt.plot(vec_size, ikj_GFLOPS, label='ikj')
plt.plot(vec_size, kji_GFLOPS, label='kji')
plt.plot(vec_size, kij_GFLOPS, label='kij')
plt.plot(vec_size, jik_GFLOPS, label='jik')
plt.plot(vec_size, jki_GFLOPS, label='jki')

#plt.rcParams["font.size"] = 18

plt.xlabel("number of N")
plt.ylabel("GFLOPS")
plt.xlim(xmin=vec_size[0], xmax=vec_size[-1])
plt.ylim(ymin=0, ymax=0.4)
plt.title(name_file)
plt.grid(True)
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0)
#plt.show()
plt.savefig('b.jpeg', bbox_inches='tight')
