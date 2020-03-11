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
print(x, "的高斯贝叶斯预测是", clf.predict([[2, ord('S')]]))

clf = BernoulliNB()
clf.fit(X_train, y_train)
print(x, "的伯努利贝叶斯预测是", clf.predict([[2, ord('S')]]))

clf = MultinomialNB()
clf.fit(X_train, y_train)
print(x, "的多项式贝叶斯预测是", clf.predict([[2, ord('S')]]))

# -------抄一遍，高斯朴素贝叶斯--------------------------------
import math
class GausNB():
    def __init__(self):
        self.model = None
    @staticmethod
    def mean(X):
        return sum(X)/float(len(X))
    def std(self,X):
        avg = self.mean(X)
        return math.sqrt(sum([pow(x-avg,2) for x in X])/float(len(X)))
    def gaus_prob(self,x,mean,std):
        exponent = math.exp(-(math.pow(x-mean,2)/(2*math.pow(std,2))))
        return (1/(math.sqrt(2*math.pi)*std))*exponent
    def summarize(self,train_data):
        summaries = [(self.mean(i),self.std(i)) for i in zip(*train_data)]
        return summaries
    def fit(self,X,y):
        labels = list(set(y))
        
