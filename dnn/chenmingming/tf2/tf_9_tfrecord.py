import random
import os
import tensorflow as tf

train_data_dir = "./dogs-vs-cats/train/"
test_data_dir = "./dogs-vs-cats/test/"

# 训练文件路径
file_dir = [train_data_dir + filename for filename in os.listdir(train_data_dir)]
labels = [0 if filename[0] == 'c' else 1
          for filename in os.listdir(train_data_dir)]

# 打包并打乱
f_l = list(zip(file_dir, labels))
random.shuffle(f_l)
file_dir, labels = zip(*f_l)

# 切分训练集，验证集
valid_ratio = 0.1
idx = int((1 - valid_ratio) * len(file_dir))
train_files, valid_files = file_dir[:idx], file_dir[idx:]
train_labels, valid_labels = labels[:idx], labels[idx:]

# tfrecord 格式数据存储路径
train_tfrecord_file = "./dogs-vs-cats/train.tfrecords"
valid_tfrecord_file = "./dogs-vs-cats/valid.tfrecords"

# 存储过程
# 预先定义一个写入器
with tf.io.TFRecordWriter(path=train_tfrecord_file) as writer:
    # 遍历原始数据
    for filename, label in zip(train_files, train_labels):
        img = open(filename, 'rb').read()  # 读取图片，img 是 Byte 类型的字符串
        # 建立 feature 的 字典 k : v
        feature = {
            'image': tf.train.Feature(bytes_list=tf.train.BytesList(value=[img])),
            'label': tf.train.Feature(int64_list=tf.train.Int64List(value=[label]))
        }
        # feature 包裹成 example
        example = tf.train.Example(features=tf.train.Features(feature=feature))
        # example 序列化为字符串，写入
        writer.write(example.SerializeToString())

# 读取过程
# 读取 tfrecord 数据，得到 tf.data.Dataset 对象
raw_train_dataset = tf.data.TFRecordDataset(train_tfrecord_file)
# 特征的格式、数据类型
feature_description = {
    'image': tf.io.FixedLenFeature(shape=[], dtype=tf.string),
    'label': tf.io.FixedLenFeature([], tf.int64),
}


def _parse_example(example_string): # 解码每个example
    # tf.io.parse_single_example 反序列化
    feature_dict = tf.io.parse_single_example(example_string, feature_description)
    # 图像解码
    feature_dict['image'] = tf.io.decode_jpeg(feature_dict['image'])
    # 返回数据 X, y
    return feature_dict['image'], feature_dict['label']

# 处理数据集
train_dataset = raw_train_dataset.map(_parse_example)

import matplotlib.pyplot as plt
for img, label in train_dataset:
    plt.title('cat' if label==0 else 'dog')
    plt.imshow(img.numpy())
    plt.show()