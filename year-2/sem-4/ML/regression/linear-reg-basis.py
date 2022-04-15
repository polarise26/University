import numpy as np
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression

X, y = make_regression(100, 5, shuffle=True, random_state=1, noise=5, bias=0.5)

X = np.exp(X)
x0 = np.ones((100, 1), float)
X = np.concatenate((x0, X), axis=1)

X_trans = np.transpose(X)
Xprod_inverse = np.linalg.inv(np.matmul(X_trans, X))
XY_mult = np.matmul(X_trans, y)

w = np.matmul(Xprod_inverse, XY_mult)


reg = LinearRegression().fit(X, y)
print("\nw = (X^TX)^-1 * X^T*t")
print("Weights\n")
print(w)
print("\nRegression coefficient: ")
print(reg.coef_)
print("\nRegression Intercept:")
print(reg.intercept_)
