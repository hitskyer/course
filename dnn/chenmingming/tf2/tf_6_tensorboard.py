import tensorflow as tf
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


# 自定义多层感知机模型
class MLPmodel(tf.keras.Model):
    def __init__(self):
        super().__init__()
        # 除第一维以外的维度展平
        self.flatten = tf.keras.layers.Flatten()
        self.dense1 = tf.keras.layers.Dense(units=100, activation='relu')
        self.dense2 = tf.keras.layers.Dense(units=10)

    def call(self, input):
        x = self.flatten(input)
        x = self.dense1(x)
        x = self.dense2(x)
        output = tf.nn.softmax(x)
        return output


# %%

num_epochs = 5
batch_size = 50
learning_rate = 1e-4
log_dir = './log'
mymodel = MLPmodel()

# %%
data_loader = MNistLoader()
optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)
num_batches = int(data_loader.num_train_data // batch_size * num_epochs)
# 实例化记录器
summary_writer = tf.summary.create_file_writer(logdir=log_dir)
# 开启 trace，（可选），记录训练时的大量信息（图的结构，耗时等）
tf.summary.trace_on(profiler=True)

for idx in range(num_batches):
    X, y = data_loader.get_batch(batch_size)
    with tf.GradientTape() as tape:
        y_pred = mymodel(X)
        loss = tf.keras.losses.sparse_categorical_crossentropy(y_true=y, y_pred=y_pred)
        loss = tf.reduce_mean(loss)
        print("batch {}, loss {}".format(idx, loss.numpy()))
        # 记录器记录loss
        with summary_writer.as_default():
            tf.summary.scalar(name='loss', data=loss, step=idx)

    grads = tape.gradient(loss, mymodel.variables)
    optimizer.apply_gradients(grads_and_vars=zip(grads, mymodel.variables))

with summary_writer.as_default():
    tf.summary.trace_export(name='model_trace', step=0,
                            profiler_outdir=log_dir)
