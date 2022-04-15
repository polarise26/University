import matplotlib.pyplot as plt
import numpy as np


def coeffest(x, y):
    n = np.size(x)

    meanx = np.mean(x)
    meany = np.mean(y)
    ssxy = np.sum(x * y) - n * meanx * meany
    ssxx = np.sum(x * x) - n * meanx * meanx

    b[1] = ssxy / ssxx
    b[0] = meany - b[1] * meanx

    return (b[0], b[1])


def regressline(x, y, b):
    prv = b[0] + b[1]*x  # predicted response vector
    plt.scatter(x, y, prv, color="slateblue")
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()


x = np.array([0, 2, 4, 6, 8, 10, 12, 14, 16, 18])
y = np.array([0, 3, 6, 9, 12, 4, 8, 12, 16, 20])
b = np.arange(2)

print("This is Karan Taneja's code. SAP - 500084399")

b = coeffest(x, y)
regressline(x, y, b)
