from sklearn.datasets import make_regression
import numpy as np
from sklearn.linear_model import LinearRegression

x, t = make_regression(100, 5, shuffle=True, bias=0.0, random_state=3)

x0 = np.ones((100, 1))
x = np.concatenate((x0, x), axis=1)
w = np.dot(np.dot(np.linalg.inv(np.dot(x.transpose(), x)), x.transpose()), t)

print("w:", w)

y = 0

for i in range(0, x.shape[1]):
    y = y + w[i]*x[i]

print("y:", y)

reg = LinearRegression().fit(x, t)

print("Regression Score: ", reg.score(x, t))
print("Regression coefficient: ", reg.coef_)
print("Regression intercept: ", reg.intercept_)
