import tensorflow as tf
import numpy as np
gpus = tf.config.list_physical_devices('GPU')
tf.config.set_logical_device_configuration(
    gpus[0],
    [tf.config.LogicalDeviceConfiguration(memory_limit=4096),
     tf.config.LogicalDeviceConfiguration(memory_limit=4096)])
gpus = tf.config.list_logical_devices(device_type='GPU')
print(gpus)

@tf.function
def f(x):
    print("The function is running in Python")
    tf.print(x)


# a = tf.constant(1, dtype=tf.int32)
# f(a)
# b = tf.constant(2, dtype=tf.int32)
# f(b)
# b_ = np.array(2, dtype=np.int32)
# f(b_)
# c = tf.constant(0.1, dtype=tf.float32)
# f(c)
d = tf.constant(0.2, dtype=tf.float32)
# f(d)
print('--------------')
f(d)
f(1)
f(2)
f(1)
f(0.1)
f(0.2)
f(0.1)

print('----tf.TensorArray---')
arr = tf.TensorArray(dtype=tf.int64, size=1, dynamic_size=True)
arr = arr.write(index=1, value=512)
# arr.write(index=0, value=512) # 没有左值接受，会丢失
for i in range(arr.size()):
    print(arr.read(i))

# print('---device----')
# gpus = tf.config.list_physical_devices(device_type='GPU')
# cpus = tf.config.list_physical_devices(device_type='CPU')
# print(gpus, "\n", cpus)

# print("----make device invisible----")
# tf.config.set_visible_devices(devices=gpus[0:1], device_type="GPU")
# print(gpus, "\n", cpus)

# gpus = tf.config.list_physical_devices(device_type='GPU')
# for gpu in gpus:
#     tf.config.experimental.set_memory_growth(device=gpu, enable=True)