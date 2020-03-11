# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/1/19 22:08
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: naiveBayes.py

import numpy as np

data = [[1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3],
        ['S', 'M', 'M', 'S', 'S', 'S', 'M', 'M', 'L', 'L', 'L', 'M', 'M', 'L', 'L'],
        [-1, -1, 1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1]]
X1 = []
X2 = []
Y = []
for i in range(len(data[0])):  # 统计数据种类
    if data[0][i] not in X1:
        X1.append(data[0][i])
    if data[1][i] not in X2:
        X2.append(data[1][i])
    if data[2][i] not in Y:
        Y.append(data[2][i])
nY = [0] * len(Y)
for i in range(len(data[0])):  # 统计Yi的数量
    nY[Y.index(data[2][i])] += 1
PY = [0.0] * len(Y)
for i in range(len(Y)):
    PY[i] = (nY[i] + 1) / (len(data[0]) + len(Y))  # Yi的概率,+1为平滑
PX1_Y = np.zeros((len(X1), len(Y)))  # 条件概率
PX2_Y = np.zeros((len(X2), len(Y)))

for i in range(len(data[0])):
    PX1_Y[X1.index(data[0][i])][Y.index(data[2][i])] += 1  # 统计频数
    PX2_Y[X2.index(data[1][i])][Y.index(data[2][i])] += 1
for i in range(len(Y)):
    PX1_Y[:, i] = (PX1_Y[:, i] + 1) / (nY[i] + len(X1))  # 转成条件概率,带平滑
    PX2_Y[:, i] = (PX2_Y[:, i] + 1) / (nY[i] + len(X2))
x = [2, 'S']
PX_Y = [PX1_Y, PX2_Y]
X = [X1, X2]
ProbY = [0.0] * len(Y)
for i in range(len(Y)):
    ProbY[i] = PY[i]
    for j in range(len(x)):
        ProbY[i] *= PX_Y[j][X[j].index(x[j])][i]
maxProb = -1
idx = -1
for i in range(len(Y)):  # 取最大的概率
    if ProbY[i] > maxProb:
        maxProb = ProbY[i]
        idx = i
print(Y)
print(ProbY)
print(x, ", 最有可能对应的贝叶斯估计 y = %d" % (Y[idx]))

# ---------------------------
import pandas as pd
from sklearn.naive_bayes import GaussianNB
from sklearn.naive_bayes import BernoulliNB
from sklearn.naive_bayes import MultinomialNB

for i in range(len(data[0])):
    data[1][i] = ord(data[1][i])  # 将字符转成ASCII数字
data = np.array(pd.DataFrame(data).T)
X_train, y_train = data[:, :-1], data[:, -1]

clf = GaussianNB()
clf.fit(X_train, y_train)
print(x, "的高斯贝叶斯预测是", clf.predict([[2, ord('S')]]), clf.predict_proba([[2, ord('S')]]))

clf = BernoulliNB()
clf.fit(X_train, y_train)
print(x, "的伯努利贝叶斯预测是", clf.predict([[2, ord('S')]]), clf.predict_proba([[2, ord('S')]]))

clf = MultinomialNB()
clf.fit(X_train, y_train)
print(x, "的多项式贝叶斯预测是", clf.predict([[2, ord('S')]]), clf.predict_proba([[2, ord('S')]]))

# -------抄一遍，高斯朴素贝叶斯--------------------------------
import math


class GausNB():
    def __init__(self):
        self.model = None

    @staticmethod
    def mean(X):  # 均值
        return sum(X) / float(len(X))

    def std(self, X):  # 标准差
        avg = self.mean(X)
        return np.sqrt(sum([pow(x - avg, 2) for x in X]) / float(len(X)))

    def gaus_prob(self, x, mean, std):  # 高斯概率密度
        exponent = math.exp(-(math.pow(x - mean, 2) / (2 * math.pow(std, 2))))
        return (1 / (math.sqrt(2 * math.pi) * std)) * exponent

    def summarize(self, train_data):
        summaries = [(self.mean(i), self.std(i)) for i in zip(*train_data)]
        return summaries  # 返回 [(各特征的均值，标准差),(),()...]]

    def fit(self, X, y):
        labels = list(set(y))
        data = {label: [] for label in labels}
        for x, label in zip(X, y):
            data[label].append(x)
        self.model = {
            label: [len(data[label]) / float(len(X)), self.summarize(value)]
            for label, value in data.items()
        }  # model写入字典 label : [[label概率],[(各特征的均值，标准差),(),()...]]
        return 'GuassNB train Done !'

    def cal_prob(self, input_data):
        prob = {}
        for label, value in self.model.items():
            prob[label] = value[0]  # P(Y=Ck), 此处修正了原作者的初始概率均等问题
            for i in range(len(value[1])):
                mean, std = value[1][i]
                prob[label] *= self.gaus_prob(input_data[i], mean, std)
                # 分类器概率公式
        return prob

    def predict(self, X_test):
        label = sorted(self.cal_prob(X_test).items(), key=lambda x: x[-1])[-1][0]
        # {label : prob},按照概率排序，取最后（最大）的【0】标签
        return label

    def predict_prob(self, X_test):
        prob = sorted(self.cal_prob(X_test).items(), key=lambda x: x[-1])[-1][1]
        s = sum(i for i in self.cal_prob(X_test).values())
        return prob / s  # 预测概率

    def score(self, X_test, y_test):
        right = 0
        for X, y in zip(X_test, y_test):
            label = self.predict(X)
            if label == y:
                right += 1
        return right / float(len(X_test))


clf = GausNB()
clf.fit(X_train, y_train)
x = [2, ord('S')]
print(x, "自编程高斯贝叶斯预测", clf.predict(x), clf.predict_prob(x))
