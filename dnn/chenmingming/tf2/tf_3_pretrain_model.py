import tensorflow as tf
import tensorflow_datasets as tfds

num_epoch = 2
batch_size = 64
learning_rate = 1e-3

version = tf.__version__
gpu_ok = tf.test.is_gpu_available()
print("tf version:", version, "\nuse GPU", gpu_ok)

dataset = tfds.load("tf_flowers", split=tfds.Split.TRAIN, as_supervised=True)
dataset = dataset.map(lambda img, label: (tf.image.resize(img, (224, 224)) / 255.0, label)).shuffle(1024).batch(
    batch_size)

model = tf.keras.applications.MobileNetV2(include_top=True, weights=None, classes=5)
# weights 默认： "imagenet"
optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)
for e in range(num_epoch):
    for images, labels in dataset:
        with tf.GradientTape() as tape:
            pred = model(images, training=True)
            loss = tf.keras.losses.sparse_categorical_crossentropy(y_true=labels, y_pred=pred)
            loss = tf.reduce_mean(loss)
            print("loss: {}".format(loss.numpy()))
        grads = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(grads_and_vars=zip(grads, model.trainable_variables))
    print(pred)
