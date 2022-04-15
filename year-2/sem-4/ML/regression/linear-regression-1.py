from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression
import numpy as np
import matplotlib.pyplot as plt


def printSummary(var, x):
    print("\nSummary Statistics for '{}'".format(var))
    print(f"Mean = {np.mean(x)}\nStandard Deviation = {np.std(x)}")


x, t = make_regression(100, 1, shuffle=True, bias=1, noise=0, random_state=5)

printSummary('x', x)
printSummary('t', t)

plt.scatter(x, t)
plt.show()

# %%
xMean = np.mean(x)
tMean = np.mean(t)

deltaX = [float(i - xMean) for i in x]
deltaXSquare = [float(pow(i, 2)) for i in x]
deltaT = [float(i - tMean) for i in t]

productDelta = []
for i in range(0, len(deltaT)):
    productDelta.append(deltaX[i] * deltaT[i])

m = sum(productDelta) / sum(deltaXSquare)
c = tMean - (m * xMean)

print(f'\n\nc = {c}\nm = {m}')

reg = LinearRegression().fit(x, t)
print(reg.score(x, t))
