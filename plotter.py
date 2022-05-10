#!/usr/bin/env python3

import re
import matplotlib

matplotlib.use ("Agg")

import matplotlib.pyplot as plt

x = []
y = []

fdata = open ("plot_data.txt", "r")
lines = fdata.readlines()
fdata.close()
print ("status: file read")

regex = re.compile (r"\d+:\ \[\d+,\ (\d+)\]:\ (\d+)")
print ("status: regex compiled")

print ("status: generating data set")
for line in lines:
    match = regex.search (line)
    x.append (match.group (1))
    y.append (match.group (2))
print ("status: data set generated")

print ("status: plotting in progress")
plt.plot (x, y)
plt.savefig ("plot.png")
# plt.show()
print ("status: plot complete")
