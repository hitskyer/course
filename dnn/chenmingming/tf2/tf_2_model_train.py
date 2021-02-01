# %%

# tf.keras.Model  tf.keras.layers 构建模型
# tf.keras.losses 损失函数
# tf.keras.optimizer 优化器
# tf.keras.metrics 模型评估

import tensorflow as tf

X = tf.constant([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
y = tf.constant([[10.0], [20.0]])


class Linear(tf.keras.Model):
    def __init__(self):
        super().__init__()
        self.dense = tf.keras.layers.Dense(
            units=1,
            activation=None,
            kernel_initializer=tf.zeros_initializer(),
            bias_initializer=tf.zeros_initializer()
        )

    def call(self, input):
        output = self.dense(input)
        return output


model = Linear()
optimizer = tf.keras.optimizers.SGD(learning_rate=0.001)
print(model.variables)

for i in range(100):
    with tf.GradientTape() as tape:
        y_pred = model(X)
        loss = tf.reduce_mean(tf.square(y_pred - y))
    grads = tape.gradient(loss, model.variables)
    optimizer.apply_gradients(grads_and_vars=zip(grads, model.variables))

print(model.variables)

# %%
# 手写数字 tf 实现
import numpy as np


class MNistLoader():
    def __init__(self):
        data = tf.keras.datasets.mnist
        # 加载数据
        (self.train_data, self.train_label), (self.test_data, self.test_label) = data.load_data()
        # 扩展维度，灰度图1通道 [batch_size, 28, 28, chanels=1]
        self.train_data = np.expand_dims(self.train_data.astype(np.float32) / 255.0, axis=-1)
        self.test_data = np.expand_dims(self.test_data.astype(np.float32) / 255.0, axis=-1)
        self.train_label = self.train_label.astype(np.int32)
        self.test_label = self.test_label.astype(np.int32)
        # 样本个数
        self.num_train_data, self.num_test_data = self.train_data.shape[0], self.test_data.shape[0]

    def get_batch(self, batch_size):
        # 从训练集里随机取出 batch_size 个样本
        idx = np.random.randint(0, self.num_train_data, batch_size)
        return self.train_data[idx, :], self.train_label[idx]


# %%

# 自定义多层感知机模型
class MLPmodel(tf.keras.Model):
    def __init__(self):
        super().__init__()
        # 除第一维以外的维度展平
        self.flatten = tf.keras.layers.Flatten()
        self.dense1 = tf.keras.layers.Dense(units=100, activation='relu')
        self.dense2 = tf.keras.layers.Dense(units=10)

    @tf.function
    def call(self, input):
        x = self.flatten(input)
        x = self.dense1(x)
        x = self.dense2(x)
        output = tf.nn.softmax(x)
        return output


# %%

# CNN 模型
class myCNN(tf.keras.Model):
    def __init__(self):
        super().__init__()
        self.conv1 = tf.keras.layers.Conv2D(
            filters=32,
            kernel_size=[5, 5],
            padding='same',
            activation='relu'
        )
        self.pool1 = tf.keras.layers.MaxPool2D(pool_size=[2, 2], strides=2)
        self.conv2 = tf.keras.layers.Conv2D(
            filters=64,
            kernel_size=[5, 5],
            padding='same',
            activation='relu'
        )
        self.pool2 = tf.keras.layers.MaxPool2D(pool_size=[2, 2], strides=2)
        self.flatten = tf.keras.layers.Reshape(target_shape=(7 * 7 * 64,))
        self.dense1 = tf.keras.layers.Dense(units=1024, activation='relu')
        self.dense2 = tf.keras.layers.Dense(units=10)

    def call(self, inputs):  # [m, 28 , 28 , 1]
        # (n+2p-f)/s + 1，same 保持尺寸不变
        x = self.conv1(inputs)  # [m, 28 , 28 , 32]
        # 池化时 p 常为 0
        x = self.pool1(x)  # [m, 14 , 14 , 32]
        x = self.conv2(x)  # [m, 14 , 14 , 64]
        x = self.pool2(x)  # [m, 7 , 7 , 64]
        x = self.flatten(x)  # [m, 7*7*64]
        x = self.dense1(x)  # [m, 1024]
        x = self.dense2(x)  # [m, 10]
        outputs = tf.nn.softmax(x)  # [m, 10]
        return outputs


# %%

num_epochs = 5
batch_size = 50
learning_rate = 1e-4

mymodel = MLPmodel()
# mymodel = myCNN()
# mymodel = tf.keras.applications.MobileNetV2()

# mymodel = tf.keras.models.Sequential([
#     tf.keras.layers.Flatten(),
#     tf.keras.layers.Dense(100, activation='relu'),
#     tf.keras.layers.Dense(10),
#     tf.keras.layers.Softmax()
# ])

# inp = tf.keras.Input(shape=(28, 28, 1))
# x = tf.keras.layers.Flatten()(inp)
# x = tf.keras.layers.Dense(units=100, activation=tf.nn.relu)(x)
# x = tf.keras.layers.Dense(units=10)(x)
# out = tf.keras.layers.Softmax()(x)
# mymodel = tf.keras.Model(inputs=inp, outputs=out)

# %%
data_loader = MNistLoader()
# optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)
#
# num_batches = int(data_loader.num_train_data // batch_size * num_epochs)
# for idx in range(num_batches):
#     X, y = data_loader.get_batch(batch_size)
#     with tf.GradientTape() as tape:
#         y_pred = mymodel(X)
#         loss = tf.keras.losses.sparse_categorical_crossentropy(y_true=y, y_pred=y_pred)
#         loss = tf.reduce_mean(loss)
#         print("batch {}, loss {}".format(idx, loss.numpy()))
#     grads = tape.gradient(loss, mymodel.variables)
#     optimizer.apply_gradients(grads_and_vars=zip(grads, mymodel.variables))

mymodel.compile(
    optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate),
    loss=tf.keras.losses.sparse_categorical_crossentropy,
    metrics=[tf.keras.metrics.sparse_categorical_accuracy]
)
mymodel.fit(data_loader.train_data, data_loader.train_label,
            batch_size=batch_size,epochs=num_epochs)
# %%

# sparse_categorical_accuracy = tf.keras.metrics.SparseCategoricalAccuracy()
# num_batches = int(data_loader.num_test_data // batch_size)
# for idx in range(num_batches):
#     start, end = idx * batch_size, (idx + 1) * batch_size
#     y_pred = mymodel.predict(data_loader.test_data[start: end])
#     sparse_categorical_accuracy.update_state(y_true=data_loader.test_label[start:end],
#                                              y_pred=y_pred)
# print("test 准确率：{}".format(sparse_categorical_accuracy.result()))

# 导出模型
tf.saved_model.save(mymodel, "./my_model_path")
# 载入模型
mymodel = tf.saved_model.load('./my_model_path')

# res = mymodel.evaluate(data_loader.test_data, data_loader.test_label)
# print(res) # [loss, acc]
res = mymodel.call(data_loader.test_data)
print(res)
# %%
