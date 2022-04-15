# Problem:
# 1. Create a dataset of a single variable comprising of only numerical values.
# 2. Create a normal distribution for it.
# 3. Convert it to Z distribution.
# 4. Plot both of the distributions.

import numpy as np
import matplotlib.pyplot as plt
from numpy.random.mtrand import normal


def zscore(x, mean, std):
    return((x-mean)/std)


n = int(input("Enter the number of samples: "))

normalData = np.random.normal(5, 2, n)
mean = np.mean(normalData)
stddev = np.std(normalData)
var = np.var(normalData)

zData = [zscore(i, mean, stddev) for i in normalData]

plt.title("Normal distribution with mean: 5 & std. dev.: 2")
plt.xlabel('x')
plt.ylabel('Normal Distribution')
plt.grid()
plt.hist(normalData, color='slateblue')
plt.show()

plt.title("Z - Distribution for above graph")
plt.xlabel('x')
plt.ylabel('Standard Normal / Z - Distribution')
plt.grid()
plt.hist(zData, color='aquamarine')
plt.show()