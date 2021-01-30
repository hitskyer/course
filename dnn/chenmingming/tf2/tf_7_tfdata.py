import tensorflow as tf
import numpy as np

X = tf.constant([2013, 2014, 2015, 2016, 2017])
Y = tf.constant([12000, 14000, 15000, 16500, 17500])
dataset = tf.data.Dataset.from_tensor_slices((X, Y))
for x, y in dataset:
    print(x.numpy(), y.numpy())

import matplotlib.pyplot as plt

(train_data, train_label), (_, _) = tf.keras.datasets.mnist.load_data()
train_data = np.expand_dims(train_data.astype(np.float32) / 255., axis=-1)
mnistdata = tf.data.Dataset.from_tensor_slices((train_data, train_label))


def rotate90(img, label):
    img = tf.image.rot90(img)
    return img, label


mnistdata = mnistdata.map(map_func=rotate90, num_parallel_calls=2)

mnistdata = mnistdata.prefetch(buffer_size=tf.data.experimental.AUTOTUNE).shuffle(buffer_size=100).batch(5)

for img, label in mnistdata:  # img ,label 包含5个样本
    fig, axs = plt.subplots(1, 5)  # 1行5列
    for i in range(5):
        axs[i].set_title(label.numpy()[i])
        axs[i].imshow(img.numpy()[i, :, :, :])
    plt.show()
