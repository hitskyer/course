# ---------cat vs dog-------------
import tensorflow as tf
import os

num_epochs = 10
batch_size = 32
learning_rate = 1e-3
train_data_dir = "./dogs-vs-cats/train/"
test_data_dir = "./dogs-vs-cats/test/"


def _decode_and_resize(filename, label):
    img_string = tf.io.read_file(filename)
    img_decoded = tf.image.decode_jpeg(img_string)
    img_resized = tf.image.resize(img_decoded, [256, 256]) / 255.
    return img_resized, label


if __name__ == "__main__":
    train_filenames = tf.constant([train_data_dir + filename for filename in os.listdir(train_data_dir)])
    train_labels = tf.constant([0 if filename[0] == 'c' else 1
                                for filename in os.listdir(train_data_dir)])
    train_dataset = tf.data.Dataset.from_tensor_slices((train_filenames, train_labels))
    train_dataset = train_dataset.map(map_func=_decode_and_resize,
                                      num_parallel_calls=tf.data.experimental.AUTOTUNE)
    train_dataset = train_dataset.shuffle(buffer_size=20000)
    train_dataset = train_dataset.batch(batch_size)
    train_dataset = train_dataset.prefetch(buffer_size=tf.data.experimental.AUTOTUNE)

    model = tf.keras.Sequential([
        tf.keras.layers.Conv2D(32, 3, activation='relu', input_shape=(256, 256, 3)),
        tf.keras.layers.MaxPool2D(),
        tf.keras.layers.Conv2D(32, 5, activation='relu'),
        tf.keras.layers.MaxPool2D(),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(64, activation='relu'),
        tf.keras.layers.Dense(2, activation='sigmoid')
    ])

    model.compile(
        optimizer=tf.keras.optimizers.Adam(learning_rate=learning_rate),
        loss=tf.keras.losses.sparse_categorical_crossentropy,
        metrics=[tf.keras.metrics.sparse_categorical_accuracy]
    )

    model.fit(train_dataset, epochs=num_epochs)

    test_filenames = tf.constant([test_data_dir + filename for filename in os.listdir(test_data_dir)])
    test_data = tf.data.Dataset.from_tensor_slices(test_filenames)
    test_data = test_data.map(_decode_and_resize)
    test_data = test_data.batch(batch_size)

    print(model.metrics_names)
    ans = model.predict(test_data)
    print(ans)
