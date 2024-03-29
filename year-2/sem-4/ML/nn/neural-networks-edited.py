import numpy as np
import math


def abs(x):
    return x if x > 0 else -x


def sigmoid(x):
    return 1/(1 + np.exp(-x))


def sigmoid_derivative(x):
    return x * (1 - x)


def checkError(predicted_output, epoch):
    # Capping the max epochs if it doesn't converge after 100 cycles
    if epoch >= 100:
        print("\nMax. number of epoch reached, returning false.")
        return False
    else:
        expected_output = [[0], [1], [1], [0]]
        for i, j in zip(expected_output, predicted_output):
            if abs(i[0] - j[0]) > 0.1:
                return True
        return False

# %%


# Input datasets
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
expected_output = np.array([[0], [1], [1], [0]])

epoch = 0

lr = 0.2

# %%

# Input number of all layers

# inputLayerNeurons = 2
# hiddenLayerNeurons = 2
# outputLayerNeurons = 1

inputLayerNeurons = int(input("Input Layers: "))
hiddenLayerNeurons = int(input("Hidden Layers: "))
outputLayerNeurons = int(input("Output Layers: "))

hidden_weights = []
for i in range(1, inputLayerNeurons + 1):
    hidden_weights_ind = []
    for j in range(inputLayerNeurons + 1, inputLayerNeurons + hiddenLayerNeurons + 1):
        hidden_weights_ind.append(float(input('w' + str(i) + str(j) + ": ")))
    hidden_weights.append(hidden_weights_ind)

output_weights = []
for i in range(inputLayerNeurons + 1, inputLayerNeurons + hiddenLayerNeurons + 1):
    output_weights_ind = []
    for j in range(inputLayerNeurons + hiddenLayerNeurons + 1, inputLayerNeurons + hiddenLayerNeurons + outputLayerNeurons + 1):
        output_weights_ind.append(float(input('w' + str(i) + str(j) + ": ")))
    output_weights.append(output_weights_ind)

hidden_bias = []
output_bias = []
for i in range(inputLayerNeurons + 1, inputLayerNeurons + hiddenLayerNeurons + outputLayerNeurons + 1):
    if i > inputLayerNeurons+hiddenLayerNeurons:
        output_bias.append(float(input("o" + str(i) + ": ")))
    else:
        hidden_bias.append(float(input("o" + str(i) + ": ")))

hidden_weights = np.asarray(hidden_weights)
hidden_bias = np.asarray([hidden_bias])
output_weights = np.asarray(output_weights)
output_bias = np.asarray([output_bias])

print("\n\nInitial hidden weights: ", end='')
print(*hidden_weights)
print("Initial hidden biases: ", end='')
print(*hidden_bias)
print("Initial output weights: ", end='')
print(*output_weights)
print("Initial output biases: ", end='')
print(*output_bias)


# %%

predicted_output = [[0], [0], [0], [0]]

iteration = 0

while checkError(predicted_output, epoch):
    print("\nIteration:", iteration)
    print("Epoch:", epoch)

    iteration += 1
    epoch += 1

    hidden_layer_activation = np.dot(inputs, hidden_weights)
    hidden_layer_activation += hidden_bias
    hidden_layer_output = sigmoid(hidden_layer_activation)

    output_layer_activation = np.dot(hidden_layer_output, output_weights)
    output_layer_activation += output_bias
    predicted_output = sigmoid(output_layer_activation)

    error = expected_output - predicted_output

    d_predicted_output = error * sigmoid_derivative(predicted_output)

    error_hidden_layer = d_predicted_output.dot(output_weights.T)

    d_hidden_layer = error_hidden_layer * \
        sigmoid_derivative(hidden_layer_output)

    output_weights += hidden_layer_output.T.dot(d_predicted_output) * lr
    output_bias += np.sum(d_predicted_output, axis=0, keepdims=True) * lr
    hidden_weights += inputs.T.dot(d_hidden_layer) * lr
    hidden_bias += np.sum(d_hidden_layer, axis=0, keepdims=True) * lr

# %%

print("\nFinal hidden weights: ", end='')
print(*hidden_weights)
print("Final hidden bias: ", end='')
print(*hidden_bias)
print("Final output weights: ", end='')
print(*output_weights)
print("Final output bias: ", end='')
print(*output_bias)

print("\nOutput from neural network: ", end='')
print(*predicted_output)
print("\nNo of epochs")
print(epoch)
