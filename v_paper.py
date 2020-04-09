import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import PercentFormatter

n = 400000
k = 10000

lev = np.loadtxt('lev400000.list')
hev = np.loadtxt('hev400000.list')
w = np.ones(k) / float(k)
print(np.sum(hev>1.2 * n)/k *100)
print(np.sum(lev<0.8 * n)/k *100)
# plt.figure()
# plt.cla()
# plt.rcParams.update({'font.size': 10})
# plt.hist(lev, bins=100, facecolor='blue', alpha=0.5, label=r'$\mathcal{A}_{lo}$', weights=w)
# plt.hist(hev, bins=100, facecolor='red', alpha=0.5, label=r'$\mathcal{A}_{hi}$', weights=w)
# plt.plot([n, n], [0, 0.1], label='truth')

# plt.xlabel('estimates')
# plt.ylabel('frequency')
# plt.xlim([0,800000])
# # plt.ylim([0,1000])
# plt.title(r'$\lambda = $'+str(n))
# plt.gca().yaxis.set_major_formatter(PercentFormatter(1))
# plt.legend()
# plt.grid(True)
# plt.savefig("fig"+str(n)+".pdf")