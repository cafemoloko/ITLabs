import numpy as np
from sklearn.utils import shuffle


x = np.loadtxt('wine_i')  # input data
y = np.loadtxt('wine_o')  # output data
t = 0.1                   # learning rate
e = 98                    # number of iterations


def perceptron_train(x, y, t, e):

    delta_arr = []
    w = np.zeros(len(x[0]))         # weights
    n = 0                           # counter
    while n < e:
        xs = np.array(x)
        ys = np.array(y)
        xs, xy = shuffle(xs, ys)    # shuffling training samples
        for i in range(0, len(xs)):
            f = np.dot(xs[i], w)
            delta = ys - f           # delta
            delta_arr.append(delta)
            for d in range(0, len(delta_arr)):
                if d != 0:
                    for j in range(0, len(w)):
                        w[j] = w[j] + t * (ys[i] - d) * xs[i][j]  # updating the weights
        n += 1

    return w


print("Number of iterations: %s" % e)
print("Weights:")
print(perceptron_train(x, y, t, e))

