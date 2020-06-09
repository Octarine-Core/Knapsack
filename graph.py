#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np

f = open("/home/octa/Knapsack/out.txt")
sizes = [n for n in range(1, 36)]
times = []
for line in f:
    times.append(float(line))
fig, ax = plt.subplots()
ax.plot(sizes, times)
plt.show()
