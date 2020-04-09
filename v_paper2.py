import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import PercentFormatter

L = 12
S0 = 31
k = 10000

lev = np.loadtxt('lev_till_12_31.list')
hev = np.loadtxt('hev_till_12_31.list')
w = np.ones(k) / float(k)
print(np.mean(hev))
print(np.mean(lev))
plt.figure()
plt.cla()
plt.rcParams.update({'font.size': 10})
plt.hist(lev, bins=50, facecolor='blue', alpha=0.5, label=r'$\mathcal{A}_{lo}$', weights=w)
plt.hist(hev, bins=50, facecolor='red', alpha=0.5, label=r'$\mathcal{A}_{hi}$', weights=w)
# plt.plot([n, n], [0, 0.1], label='truth')

plt.xlabel('cardinality')
plt.ylabel('frequency')
plt.xlim([0,800000])
# plt.ylim([0,1000])
plt.title(r'$L = 12, S_0 = 31$')
plt.gca().yaxis.set_major_formatter(PercentFormatter(1))
plt.legend()
plt.grid(True)
plt.savefig("fig_till_12_31.pdf")