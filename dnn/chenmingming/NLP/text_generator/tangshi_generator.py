#!/usr/bin/env python
# coding: utf-8

# In[2]:


# 读取文本
file = "tangshi300.txt"
with open(file,'r',encoding='utf-8') as f:
    text = f.read()
print(len(text))
print(text[:180])


# In[3]:


# 创建字符序号索引
words = sorted(list(set(text)))
print("字和符号数量：{}".format(len(words)))

word_idx = {w : i for (i, w) in enumerate(words)}
idx_word = {i : w for (i, w) in enumerate(words)}


# In[4]:


# 根据文本，创建序列
sample_maxlen = 40
sentences = []
next_word = []
for i in range(len(text)-sample_maxlen):
    sentences.append(text[i : i+sample_maxlen])
    next_word.append(text[i+sample_maxlen])
print("样本数量：{}".format(len(sentences)))


# In[5]:


# 将文本序列转化成数字序列（矩阵）,实际上就是一个one_hot 编码
import numpy as np
X = np.zeros((len(sentences), sample_maxlen, len(words)),dtype=np.bool)
y = np.zeros((len(sentences), len(words)), dtype=np.bool)

for i in range(len(sentences)):
    for t, w in enumerate(sentences[i]):
        X[i, t, word_idx[w]] = 1
    y[i, word_idx[next_word[i]]] = 1


# In[7]:


# 建模
from keras.models import Sequential
from keras.layers import GRU, Dense
from keras.optimizers import Adam
model = Sequential()
model.add(GRU(units=128,input_shape=(sample_maxlen, len(words))))
model.add(Dense(units=len(words), activation='softmax'))

optimizer = Adam(learning_rate=0.001)
model.compile(optimizer=optimizer,
              loss='categorical_crossentropy',
              metrics=['accuracy'])
history = model.fit(X, y, batch_size=128,epochs=500)
model.save("tangshi_generator_model.h5")

import pandas as pd
import matplotlib.pyplot as plt
pd.DataFrame(history.history).plot(figsize=(8, 5))
plt.grid(True)
plt.gca().set_ylim(0, 1) # set the vertical range to [0-1]
plt.show()


# In[8]:


def sampling(preds, temperature=1.0):
    preds = np.asarray(preds).astype('float64')
    preds = np.log(preds)/temperature
    exp_preds = np.exp(preds)
    preds = exp_preds/np.sum(exp_preds)
    probs = np.random.multinomial(1, preds, 1)
    return np.argmax(probs)

from keras.models import load_model
import random
model = load_model("tangshi_generator_model.h5")

def generate_tangshi(model, generate_len=200):
    start_idx = random.randint(0, len(text)-sample_maxlen-1)
    generated = ""
    sentence = text[start_idx : start_idx + sample_maxlen]
    generated += sentence
    print("随机选取的开始句子为：{}".format(generated))
    for i in range(generate_len):
        x_pred = np.zeros((1, sample_maxlen, len(words)))
        for t, w in enumerate(sentence):
            x_pred[0, t, word_idx[w]] = 1
        preds = model.predict(x_pred)[0]
        next_idx = sampling(preds, 1)
        next_w = idx_word[next_idx]
        generated += next_w
        sentence = sentence[1:] + next_w
    return generated

generate_tangshi(model, 100)


# In[ ]:




