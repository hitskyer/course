import tensorflow as tf
# import tensorflow_datasets as tfds

num_epoch = 2
batch_size = 128
learning_rate = 1e-3

version = tf.__version__
gpu_ok = tf.test.is_gpu_available()
print("tf version:", version, "\nuse GPU", gpu_ok)