# ---------cat vs dog-------------
# https://michael.blog.csdn.net/
import tensorflow as tf
import pandas as pd
import numpy as np
import random
import os

num_epochs = 1
batch_size = 32
learning_rate = 1e-4
train_data_dir = "./dogs-vs-cats/train/"
test_data_dir = "./dogs-vs-cats/test/"


def _decode_and_resize(filename, label=None):
    img_string = tf.io.read_file(filename)
    img_decoded = tf.image.decode_jpeg(img_string)
    img_resized = tf.image.resize(img_decoded, [256, 256]) / 255.
    if label == None:
        return img_resized
    return img_resized, label


def processData(train_filenames, train_labels):
    train_dataset = tf.data.Dataset.from_tensor_slices((train_filenames, train_labels))
    train_dataset = train_dataset.map(map_func=_decode_and_resize)
    # train_dataset = train_dataset.shuffle(buffer_size=25000) # 非常耗内存，不使用
    train_dataset = train_dataset.batch(batch_size)
    train_dataset = train_dataset.prefetch(buffer_size=tf.data.experimental.AUTOTUNE)
    return train_dataset


if __name__ == "__main__":
    file_dir = [train_data_dir + filename for filename in os.listdir(train_data_dir)]
    labels = [0 if filename[0] == 'c' else 1
              for filename in os.listdir(train_data_dir)]
    f_l = list(zip(file_dir, labels))
    random.shuffle(f_l)
    file_dir, labels = zip(*f_l)
    valid_ratio = 0.1
    idx = int((1 - valid_ratio) * len(file_dir))
    train_files, valid_files = file_dir[:idx], file_dir[idx:]
    train_labels, valid_labels = labels[:idx], labels[idx:]
    train_filenames, valid_filenames = tf.constant(train_files), tf.constant(valid_files)
    train_labels, valid_labels = tf.constant(train_labels), tf.constant(valid_labels)

    train_dataset = processData(train_filenames, train_labels)
    valid_dataset = processData(valid_filenames, valid_labels)

    # basemodel = tf.keras.applications.MobileNetV2(input_shape=(256,256,3), include_top=False, classes=2)
    # model = tf.keras.Sequential([
    #     # basemodel,
    #     tf.keras.layers.Conv2D(32, 3, activation='relu', input_shape=(256, 256, 3)),
    #     # tf.keras.layers.MaxPooling2D(),
    #     # tf.keras.layers.Dropout(0.2),
    #     # tf.keras.layers.Conv2D(64, 5, activation='relu'),
    #     # tf.keras.layers.MaxPooling2D(),
    #     # tf.keras.layers.Dropout(0.2),
    #     # tf.keras.layers.Conv2D(128, 5, activation='relu'),
    #     # tf.keras.layers.MaxPooling2D(),
    #     # tf.keras.layers.Dropout(0.2),
    #     tf.keras.layers.Flatten(),
    #     tf.keras.layers.Dense(64, activation='relu'),
    #     tf.keras.layers.Dense(2, activation='softmax')
    #     # tf.keras.layers.Dense(2, activation='sigmoid')
    # ])

    # model.compile(
    #     optimizer=tf.keras.optimizers.Adam(learning_rate=learning_rate),
    #     loss=tf.keras.losses.sparse_categorical_crossentropy,
    #     metrics=[tf.keras.metrics.sparse_categorical_accuracy]
    # )

    # model.fit(train_dataset, epochs=num_epochs, validation_data=valid_dataset)

    # 模型导出
    # model.save('catdog.h5')
    # tf.saved_model.save(model, './saved')

    # 模型载入
    # model = tf.keras.models.load_model('catdog.h5')
    model = tf.saved_model.load('./saved')

    test_filenames = tf.constant([test_data_dir + filename for filename in os.listdir(test_data_dir)])
    test_data = tf.data.Dataset.from_tensor_slices(test_filenames)
    test_data = test_data.map(map_func=_decode_and_resize)
    test_data = test_data.batch(batch_size)

    # print(model.metrics_names)
    ans = model(test_data)
    prob = ans[:, 1] # dog 的概率
    id = list(range(1, 12501))
    output = pd.DataFrame({'id': id, 'label': prob})
    output.to_csv("submission.csv", index=False)
