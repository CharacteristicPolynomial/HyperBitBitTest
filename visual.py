import numpy as np
import matplotlib.pyplot as plt
import os

lev = {}
hev = {}

for fl in os.listdir('data'):
    ty = fl[0:3]
    n = int(fl[3:].split('.')[0])
    if (ty == 'lev'):
        lev[n] = np.loadtxt('data/'+fl)
    else:
        hev[n] = np.loadtxt('data/'+fl)

plt.figure()
for n in hev:
    plt.cla()
    plt.hist(lev[n], bins=50, facecolor='blue', alpha=0.5, label='low')
    plt.hist(hev[n], bins=50, facecolor='red', alpha=0.5, label='high')
    plt.plot([n, n], [0, 200])

    plt.xlabel('estimates')
    plt.ylabel('frequency')
    plt.xlim([0,800000])
    plt.ylim([0,200])
    plt.title('n = '+str(n))
    plt.legend()
    plt.grid(True)
    plt.savefig("figures/fig"+str(n)+".png")