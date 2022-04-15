from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np

# %%

# Calculating W using the formula - [W = inverse(X'X) X' t]


def calculateWVectorX(X, t):
    XTranspose = np.transpose(X)

    tempTerm1 = np.linalg.inv(np.matmul(XTranspose, X))

    tempTerm2 = np.matmul(tempTerm1, XTranspose)

    W = np.matmul(tempTerm2, t)

    print("\nPrinting the W vector:")
    print(W)
    print("Shape:", np.shape(W))

    return W

# %%


# Generate data for classification
numberSamples = 100
testSize = 0.3
X, t = make_classification(
    numberSamples, 5, n_classes=2, shuffle=True, random_state=26)

# %%

# Describe the shape of X and t
print("\nDescribing X and t")
print(np.shape(X))
print(np.shape(t))

# Opening the variable explorer, we can clearly see that value in t is either 0 or 1

# %%

X_0 = np.repeat(1, numberSamples).reshape(1, 100)
X = np.append(np.transpose(X_0), X, axis=1)
X_train, X_test, y_train, y_test = train_test_split(
    X, t, test_size=testSize, random_state=21)

W = calculateWVectorX(X_train, y_train)

# Calculating y = X_test * W

y = np.matmul(X_test, W)

print("\nPrinting y = X_test * W:")
print(y)
print("Shape:", np.shape(y))

# %%

# Through y, if any values is < 0.5, make them 0 and if >= 0.5, make 1

resultY = []

for elt in y:
    if elt < 0.5:
        resultY.append(0)
    else:
        resultY.append(1)

print("\nResult of one hot key encoding:")
print(resultY)

# %%

# Comparing resultY with y_test
count = 0

for i in range(30):
    if resultY[i] == y_test[i]:
        count += 1

accuracy = (count / (testSize * numberSamples)) * 100

print(f'\nAccuracy: {accuracy:.3f}%')
