import numpy as np
import tensorflow as tf
import json
import requests
import matplotlib.pyplot as plt


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


size = 6
dataloader = MNistLoader()
data = json.dumps({
    'instances': dataloader.test_data[0:size].tolist()
})

headers = {'content-type': 'application/json'}
json_response = requests.post(
    url='http://localhost:8501/v1/models/mymodel:predict',
    data=data, headers=headers
)
pred = np.array(json.loads(json_response.text)['predictions'])
print("预测结果：", np.argmax(pred, axis=-1))

plt.subplots(1, size)
idx = 1
for img in dataloader.test_data[0:size]:
    plt.subplot(1, size, idx)
    plt.imshow(img)
    idx += 1
plt.show()
