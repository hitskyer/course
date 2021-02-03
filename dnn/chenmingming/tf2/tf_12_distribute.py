# 分布式训练
import tensorflow as tf
import tensorflow_datasets as tfds
import os, json

# 1 单机多卡 MirroredStrategy

# strategy = tf.distribute.MirroredStrategy()
# 指定设备
# strategy = tf.distribute.MirroredStrategy(devices=['/gpu:0'])
# ------------------------------------------------
num_epochs = 5
batch_size_per_replica = 64
learning_rate = 1e-4

# 定义策略
strategy = tf.distribute.MirroredStrategy()
print("设备数量：{}".format(strategy.num_replicas_in_sync))
batch_size = batch_size_per_replica * strategy.num_replicas_in_sync

# -----多机训练-----
num_workers = 2
os.environ['TF_CONFIG'] = json.dumps({
    'cluster': {
        'worker': ["localhost:20000", "localhost:20001"]
    },
    'task': {'type': 'worker', 'index': 0}
})
strategy = tf.distribute.MultiWorkerMirroredStrategy()
batch_size = batch_size_per_replica * num_workers
# -------------------

def resize(img, label):  # 处理图片
    img = tf.image.resize(img, [224, 224]) / 255.0
    return img, label


# 载入猫狗分类数据集
dataset = tfds.load("cats_vs_dogs", split=tfds.Split.TRAIN, as_supervised=True)
dataset = dataset.map(resize).shuffle(1024).batch(batch_size)

# 使用策略
with strategy.scope():
    model = tf.keras.applications.MobileNetV2(weights=None, classes=2)
    model.compile(
        optimizer=tf.keras.optimizers.Adam(learning_rate=learning_rate),
        loss=tf.keras.losses.SparseCategoricalCrossentropy(),
        metrics=[tf.keras.metrics.sparse_categorical_accuracy]
    )

model.fit(dataset, epochs=num_epochs)

# 2. 多机训练 MultiWorkerMirroredStrategy

# num_workers = 2
# os.environ['TF_CONFIG'] = json.dumps({
#     'cluster': {
#         'worker': ["localhost:20000", "localhost:20001"]
#     },
#     'task': {'type': 'worker', 'index': 0}
# })
# strategy = tf.distribute.experimental.MultiWorkerMirroredStrategy()
# batch_size = batch_size_per_replica * num_workers
