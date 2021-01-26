import tensorflow as tf
import numpy as np


class Dataloader():
    def __init__(self):
        path = tf.keras.utils.get_file('nietzsche.txt',
                                       origin='https://s3.amazonaws.com/text-datasets/nietzsche.txt')
        with open(path, encoding='utf-8') as f:
            self.raw_text = f.read().lower()
            self.chars = sorted(list(set(self.raw_text)))
            self.char_idx = dict((c, i) for i, c in enumerate(self.chars))
            self.idx_char = dict((i, c) for i, c in enumerate(self.chars))
            self.text = [self.char_idx[c] for c in self.raw_text]  # 原始文本的 ids

    def get_batch(self, seq_len, batch_size):
        seq = []
        next_char = []
        for i in range(batch_size):
            idx = np.random.randint(0, len(self.text) - seq_len)
            seq.append(self.text[idx: idx + seq_len])
            next_char.append(self.text[idx + seq_len])
        return np.array(seq), np.array(next_char)  # [batch_size, seq_len] [batch_size]


class myRNN(tf.keras.Model):
    def __init__(self, num_chars, batch_size, seq_len):
        super().__init__()
        self.num_chars = num_chars
        self.seq_len = seq_len
        self.batch_size = batch_size
        self.cell = tf.keras.layers.LSTMCell(units=256)
        self.dense = tf.keras.layers.Dense(units=self.num_chars)

    def call(self, inputs, from_logits=False):
        inputs = tf.one_hot(inputs, depth=self.num_chars)  # [batch_size, seq_len, num_chars]
        state = self.cell.get_initial_state(batch_size=self.batch_size, dtype=tf.float32)  # [batch_size, 256]
        for t in range(self.seq_len):
            output, state = self.cell(inputs[:, t, :], state)
        logits = self.dense(output)  # [batch_size, num_chars]
        if from_logits:
            return logits
        else:
            return tf.nn.softmax(logits)

    def predict(self, inputs, temperature=1.0): # temperature调节词汇的丰富度，对概率进行调整
        batch_size, _ = tf.shape(inputs)
        logits = self(inputs, from_logits=True)  # self 调用 __call()__, __call()__ 调用 call()
        prob = tf.nn.softmax(logits / temperature).numpy()  # [batch_size 64, num_chars]
        return np.array([np.random.choice(self.num_chars, p=prob[i, :])
                         for i in range(batch_size.numpy())])  # 按概率随机采样


num_batches = 1000
seq_len = 40
batch_size = 64
learning_rate = 1e-3

data_loader = Dataloader()
model = myRNN(num_chars=len(data_loader.chars),
              batch_size=batch_size,
              seq_len=seq_len)
optimizer = tf.keras.optimizers.Adam(learning_rate=learning_rate)
for i in range(num_batches):
    X, y = data_loader.get_batch(seq_len, batch_size)
    with tf.GradientTape() as tape:
        y_pred = model(X)
        loss = tf.keras.losses.sparse_categorical_crossentropy(y, y_pred)
        loss = tf.reduce_mean(loss)
        print("batch：{}, loss {}".format(i, loss.numpy()))
    grads = tape.gradient(loss, model.variables)
    optimizer.apply_gradients(zip(grads, model.variables))

X_, _ = data_loader.get_batch(seq_len, 1)
for diversity in [0.2, 0.5, 1.0, 1.2]: # 词汇丰富度
    X = X_
    print('diversity {}'.format(diversity))
    for t in range(400):
        y_pred = model.predict(X, diversity)
        print(data_loader.idx_char[y_pred[0]], end='', flush=True) # 输出预测的字符
        X = np.concatenate([X[:, 1:], np.expand_dims(y_pred, axis=1)], axis=-1) # 滑动1位，作为新的输入
    print("\n")
