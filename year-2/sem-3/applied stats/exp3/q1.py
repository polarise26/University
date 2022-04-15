# Problem:
# 1. Generate a random sample with mean 5, std. dev. 2.
# 2. Plot the distribution
# 3. Give the summary statistics

import numpy as np
import matplotlib.pyplot as plt

n = int(input("Enter the number of samples: "))
A = np.random.normal(5, 2, n)
mean = np.mean(A)
stddev = np.std(A)
var = np.var(A)

print("Sample list with {} elements:\n\n{}\n\nSummary:\nMean = {:.4f}\nStandard deviation = {:.4f}\nVariance = {:.4f}".format(
    n, A, mean, stddev, var))

plt.grid()
plt.xlabel("X")
plt.ylabel("Number of samples")
plt.hist(A, color='slateblue')
plt.show()
