# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/12/17 20:53
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: date_format.py
# @Reference: 

#%%

from faker import Faker
from babel.dates import format_date
import random
fake = Faker()
fake.seed(123)
random.seed(321)

# 各种日期格式
FORMATS = ['short',
           'medium',
           'long',
           'full',
           'full',
           'full',
           'full',
           'full',
           'full',
           'full',
           'full',
           'full',
           'full',
           'd MMM YYY',
           'd MMMM YYY',
           'dd MMM YYY',
           'd MMM, YYY',
           'd MMMM, YYY',
           'dd, MMM YYY',
           'd MM YY',
           'd MMMM YYY',
           'MMMM d YYY',
           'MMMM d, YYY',
           'dd.MM.YY']

# LOCALES = ['en_US']

#%%

def load_date():
    # 加载一些日期数据
    dt = fake.date_object()
    human_readable = format_date(dt, format=random.choice(FORMATS),
                                 locale='en_US')
    # 使用随机选取的格式，生成日期
    human_readable = human_readable.lower().replace(',','')
    machine_readable = dt.isoformat()
    return human_readable, machine_readable, dt

test_date = load_date()

#%%

from tqdm import tqdm # 显示进度条
def load_dateset(num_of_data):
    human_vocab = set()
    machine_vocab = set()
    dataset = []
    Tx = 30 # 日期最大长度
    for i in tqdm(range(num_of_data)):
        h, m, _ = load_date()
        if h is not None:
            dataset.append((h, m))
            human_vocab.update(tuple(h))
            machine_vocab.update(tuple(m))
    human = dict(zip(sorted(human_vocab)+['<unk>', '<pad>'],
                     list(range(len(human_vocab)+2))))
    # x 字符：idx 的映射
    inv_machine = dict(enumerate(sorted(machine_vocab)))
    # idx ： y 字符
    machine = {v : k for k, v in inv_machine.items()}
    # y 字符 ： idx
    return dataset, human, machine, inv_machine

m = 10000
dataset, human_vocab, machine_vocab, inv_machine_vocab = load_dateset(m)

#%%

import numpy as np
from keras.utils import to_categorical

def string_to_int(string, length, vocab):
    string = string.lower().replace(',','')
    if len(string) > length: # 长了，截断
        string = string[:length]
    rep = list(map(lambda x : vocab.get(x, '<unk>'), string))
    # 对string里每个char 使用 匿名函数 获取映射的id，没有的话，使用unk的id，map返回迭代器，转成list
    if len(string) < length:
        rep += [vocab['<pad>']]*(length-len(string))
        # 长度不够，加上 pad 的 id
    return rep # 返回 [ids,...]

def process_data(dataset, human_vocab, machine_vocab, Tx, Ty):
    X,Y = zip(*dataset)
    print("处理前 X：{}".format(X))
    print("处理前 Y：{}".format(Y))
    X = np.array([string_to_int(date, Tx, human_vocab) for date in X])
    Y = [string_to_int(date, Ty, machine_vocab) for date in Y]
    print("处理后 X的shape：{}".format(X.shape))
    print("处理后 Y: {}".format(Y))

    Xoh = np.array(list(map(lambda x : to_categorical(x, num_classes=len(human_vocab)), X)))
    Yoh = np.array(list(map(lambda x : to_categorical(x, num_classes=len(machine_vocab)), Y)))
    return X, np.array(Y), Xoh, Yoh
Tx = 30
Ty = 10
X, Y, Xoh, Yoh = process_data(dataset, human_vocab, machine_vocab, Tx, Ty)

#%%

print(X.shape)
print(Y.shape)
print(Xoh.shape)
print(Yoh.shape)

#%%

from keras import backend as K
def softmax(x, axis=1):
    ndim = K.ndim(x)
    if ndim == 2:
        return K.softmax(x)
    elif ndim > 2:
        e = K.exp(x - K.max(x, axis=axis, keepdims=True))
        s = K.sum(e, axis=axis, keepdims=True)
        return e/s
    else:
        raise ValueError('维度不对，不能是1维')

# prob = softmax(np.array([[1]]))

#%%

from keras.layers import RepeatVector, LSTM, Concatenate, \
    Dense, Activation, Dot, Input, Bidirectional

repeator = RepeatVector(Tx) # 重复 Tx 次
# 重复器
# Input shape:
#     2D tensor of shape `(num_samples, features)`.
#
# Output shape:
#     3D tensor of shape `(num_samples, n, features)`.
concator = Concatenate(axis=-1) # 拼接器
densor1 = Dense(10, activation='tanh') #
densor2 = Dense(1, activation='relu')
activator = Activation(softmax, name='attention_weights')
dotor = Dot(axes=1)


#%%

def one_step_attention(h, s_prev):
    s_prev = repeator(s_prev) #
    concat = concator([h, s_prev])
    e = densor1(concat)
    energies = densor2(e)
    alphas = activator(energies)
    context = dotor([alphas, h])
    return context

# 解码器
n_h = 32
n_s = 64
post_activation_LSTM_cell = LSTM(n_s, return_state=True)
output_layer = Dense(len(machine_vocab), activation=softmax)

from keras.models import Model
def model(Tx, Ty, n_h, n_s, human_vocab_size, machine_vocab_size):
    X = Input(shape=(Tx,human_vocab_size), name='input_first')
    s0 = Input(shape=(n_s,),name='s0')
    c0 = Input(shape=(n_s,),name='c0')
    s = s0
    c = c0
    outputs = []
    h = Bidirectional(LSTM(n_h, return_sequences=True))(X)
    for t in range(Ty):
        context = one_step_attention(h, s)
        s, _, c = post_activation_LSTM_cell(context, initial_state=[s,c])
        out = output_layer(s)
        outputs.append(out)
    model = Model(inputs=[X,s0,c0], outputs=outputs)
    return model
model = model(Tx,Ty,n_h,n_s,len(human_vocab), len(machine_vocab))
model.summary()

from keras.utils import plot_model
plot_model(model, to_file='model.png')

#%%

from keras.optimizers import Adam
opt = Adam(learning_rate=0.005, decay=0.01)
model.compile(optimizer=opt, loss='categorical_crossentropy',
              metrics=['accuracy'])
s0 = np.zeros((m, n_s))
c0 = np.zeros((m, n_s))
outputs = list(Yoh.swapaxes(0, 1))
history = model.fit([Xoh, s0, c0], outputs,
                    epochs=10, batch_size=128,
                    validation_split=0.1)

from matplotlib import pyplot as plt
loss = history.history['loss']
val_loss = history.history['val_loss']
acc = history.history['accuracy']
val_acc = history.history['val_accuracy']

plt.plot(loss, label='train Loss')
plt.plot(val_loss, label='valid Loss')
plt.title('Training and Validation Loss')
plt.legend()
plt.grid()
plt.show()

plt.plot(acc, label='train Acc')
plt.plot(val_acc, label='valid Acc')
plt.title('Training and Validation Accuracy')
plt.legend()
plt.grid()
plt.show()

#%%

s0 = np.zeros((1, n_s))
c0 = np.zeros((1, n_s))
test_data,_,_,_ = load_dateset(10)
for x,y in test_data:
    print(x + " ==> " +y)
for x,_ in test_data:
    source = string_to_int(x, Tx, human_vocab)
    source = np.array(list(map(lambda a : to_categorical(a, num_classes=len(human_vocab)), source)))
    source = source[np.newaxis, :]
    pred = model.predict([source, s0, c0])
    pred = np.argmax(pred, axis=-1)
    output = [inv_machine_vocab[int(i)] for i in pred]
    print('source:',x)
    print('output:',''.join(output))
