import tensorflow_hub as hub
import matplotlib.pyplot as plt
from PIL import Image
import numpy as np
import tensorflow as tf


# 归一化，resize
def load_image_local(img_path, img_size=(256, 256)):
    # png 4 通道转jpg 3通道
    if 'png' in img_path:
        img = Image.open(img_path)
        img = img.convert('RGB')
        img.save("temp.jpg")
        img = plt.imread("temp.jpg").astype(np.float32)[np.newaxis, :, :, :]
    else:
        # 添加一个 batch_size 轴
        img = plt.imread(img_path).astype(np.float32)[np.newaxis, :, :, :]
    if img.max() > 1.0:
        img = img / 255.
    img = tf.image.resize(img, img_size, preserve_aspect_ratio=True)
    return img


# 绘制图片
def show_image(img, title, save=False, fig_dpi=300):
    plt.imshow(img, aspect='equal')
    plt.axis('off')
    plt.show()
    if save:
        plt.imsave(title + '.jpg', img.numpy())


# 图片路径
content_image_path = "pic1.png"
style_image_path = "pic2.jpg"

# 处理图片
content_image = load_image_local(content_image_path)
style_image = load_image_local(style_image_path)

# 展示图片
show_image(content_image[0], "Content Image")
show_image(style_image[0], "Style Image")

# 加载模型
hub_url = 'https://hub.tensorflow.google.cn/google/magenta/arbitrary-image-stylization-v1-256/2'
hub_model = hub.load(hub_url)

# 调用模型
# outputs = hub_model(tf.constant(content_image), tf.constant(style_image))
# stylized_image = outputs[0]  # 取出第一个样本预测值 [ :, :, 3]
#
# # 展示预测图片
# show_image(stylized_image[0], "Stylized Image", True)

# --------------------------------

num_classes = 10
model = tf.keras.Sequential([
    hub.KerasLayer("https://hub.tensorflow.google.cn/google/imagenet/inception_v3/feature_vector/4",
                   trainable=False),  # 可以设为True，微调
    tf.keras.layers.Dense(num_classes, activation='softmax')
])
model.build([None, 299, 299, 3])  # Batch input shape
model.summary()