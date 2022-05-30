import matplotlib.pyplot as plt
from sklearn.datasets import make_circles
import tensorflow as tf
from MLP import MLP


def CircleClassify():
    # generating data
    n_samples = 400
    noise = 0.02
    factor = 0.5
    #### use x_train (Feature vectors), y_train (Class ground truths) as training set
    x_train, y_train = make_circles(n_samples=n_samples, noise=noise, factor=factor)
    #### use x_test (Feature vectors) as test set
    #### you do not use y_test for this assignment.
    x_test, y_test = make_circles(n_samples=n_samples, noise=noise, factor=factor)

    #### visualizing training data distribution
    plt.scatter(x_train[:, 0], x_train[:, 1], c=y_train, marker='.')
    plt.title("Train data distribution")
    plt.show()

    ############ Write your codes here - begin


    ############ Write your codes here - end


if __name__ == '__main__':
    CircleClassify()
