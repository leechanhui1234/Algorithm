import tensorflow as tf
from ImageClassifier import ImageClassifier
import matplotlib.pyplot as plt


def preprocessing_x(x_data):
    x_data = x_data / float(255.0)
    return x_data


def print_image(img_data):
    plt.figure()
    plt.imshow(img_data)
    plt.colorbar()
    plt.grid(False)
    plt.show()


def MNIST_Classify():
    mnist_train_data, mnist_test_data = tf.keras.datasets.mnist.load_data()
    class_names = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    #### use x_train (Images(Feature vectors)), y_train (Class ground truths) as training set
    x_train, y_train = mnist_train_data
    #### use x_test (Images(Feature vectors)), y_test (Class ground truths) as test set
    x_test, y_test = mnist_test_data
    ############ Write your codes here - begin


    ############ Write your codes here - end


if __name__ == '__main__':
    MNIST_Classify()

