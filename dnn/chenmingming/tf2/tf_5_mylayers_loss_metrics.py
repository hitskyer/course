import tensorflow as tf


class myLayer(tf.keras.layers.Layer):
    def __init__(self, units):
        super().__init__()
        self.units = units

    def build(self, input_shape):  # input_shape 是一个tensor
        # input_shape 是第一次运行 call() 时参数inputs的形状
        # 第一次使用该层的时候，调用build
        self.w = self.add_weight(name='w',
                                 shape=[input_shape[-1], self.units],
                                 initializer=tf.zeros_initializer())
        self.b = self.add_weight(name='b',
                                 shape=[self.units],
                                 initializer=tf.zeros_initializer())

    def call(self, inputs):
        y_pred = tf.matmul(inputs, self.w) + self.b
        return y_pred


class LinearModel(tf.keras.Model):
    def __init__(self):
        super().__init__()
        self.dense = myLayer(units=1)

    def call(self, inputs):
        output = self.dense(inputs)
        return output


import numpy as np

# 原始数据
X_raw = np.array([0.0, 1., 2., 3., 4.], dtype=np.float32)
y_raw = np.array([0.01, 2., 4., 5.98, 8.], dtype=np.float32)

X = np.expand_dims(X_raw, axis=-1)
y = np.expand_dims(y_raw, axis=-1)

# 转成张量
X = tf.constant(X)
y = tf.constant(y)


class myError(tf.keras.losses.Loss):
    def call(self, y_true, y_pred):
        return tf.reduce_mean(tf.square(y_true - y_pred))


class myMetric(tf.keras.metrics.Metric):
    def __init__(self):
        super().__init__()
        self.total = self.add_weight(name='total',
                                     dtype=tf.int32,
                                     initializer=tf.zeros_initializer())
        self.count = self.add_weight(name='count',
                                     dtype=tf.int32,
                                     initializer=tf.zeros_initializer())

    def update_state(self, y_true, y_pred, sample_weight=None):
        values = tf.cast(tf.abs(y_true - y_pred) < 0.1, tf.int32)
        self.total.assign_add(tf.shape(y_true)[0])
        self.count.assign_add(tf.reduce_sum(values))

    def result(self):
        return self.count / self.total


mymodel = LinearModel()
mymodel.compile(
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001),
    loss=myError(),
    metrics=[myMetric()]
)
path = "./checkp.ckpt"
mycheckpoint = tf.train.Checkpoint(mybestmodel=mymodel)  # 接受 **kwargs 键值对
manager = tf.train.CheckpointManager(mycheckpoint, directory="./",
                                     checkpoint_name="checkp.ckpt",
                                     max_to_keep=2)
for i in range(3):
    mymodel.fit(X, y, batch_size=6, epochs=81)
    manager.save()
print(mymodel.variables)

X_test = tf.constant([[5.1], [6.1]])
res = mymodel.predict(X_test)
print(res)

# %%
# path = "./checkp.ckpt"
# mycheckpoint = tf.train.Checkpoint(mybestmodel=mymodel) # 接受 **kwargs 键值对
# mycheckpoint.save(path)

restored_model = LinearModel()
mycheckpoint = tf.train.Checkpoint(mybestmodel=restored_model)
mycheckpoint.restore(tf.train.latest_checkpoint("./"))
X_test = tf.constant([[5.1], [6.1]])
res = restored_model.predict(X_test)
print(res)