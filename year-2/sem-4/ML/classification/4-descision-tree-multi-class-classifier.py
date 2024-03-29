from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn import tree

# %%
numberSamples = 10
testSize = 0.3
testSampleSize = int(testSize * numberSamples)
trainSampleSize = int((1 - testSize) * numberSamples)
classes = 4

X, t = make_classification(numberSamples, 5, n_classes=classes,
                           random_state=40, n_informative=2, n_clusters_per_class=1)

X_0 = np.repeat(1, numberSamples).reshape(1, numberSamples)

X = np.append(np.transpose(X_0), X, axis=1)

# %%

X_train, X_test, y_train, y_test = train_test_split(
    X, t, test_size=testSize, random_state=0)

# %%

clf = tree.DecisionTreeClassifier()
clf = clf.fit(X_train, y_train)

# %%

predictedOutput = clf.predict(X_test)

print("True y:\n", y_test)
print("\nPredicted y:\n", predictedOutput)

count = 0

for i in range(len(y_test)):
    if y_test[i] == predictedOutput[i]:
        count += 1

accuracy = (count / (testSampleSize)) * 100

print(f'\nAccuracy: {accuracy:.3f}%')

# %%
tree.plot_tree(clf)
