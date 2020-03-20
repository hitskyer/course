# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/20 14:23
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 7.SupportVectorMachine.py
# @Reference: https://github.com/fengdu78/lihang-code

import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from sklearn.svm import SVC


def create_data():
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['label'] = iris.target
    data = np.array(df.iloc[:100, [0, 1, -1]])
    for i in range(len(data)):
        if (data[i, -1] == 0):
            data[i, -1] = -1
    return data[:, :2], data[:, -1]


X, y = create_data()
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25)
clf = SVC(C=2,kernel='linear')
clf.fit(X_train, y_train)
print(clf.score(X_test, y_test))

data = pd.DataFrame([[1, 2], [2, 3], [3, 3], [2, 1], [3, 2]])
label = pd.DataFrame([1, 1, 1, -1, -1])
plt.scatter(data[:3][0], data[:3][1], c='r', marker='o', label='+')
plt.scatter(data[3:][0], data[3:][1], c='g', marker='x', label='-')

X = data
y = label
clf.fit(X, y)

xi = np.linspace(-1, 4, 20)
yi = (clf.coef_[0][0] * xi + clf.intercept_) / (-clf.coef_[0][1])
plt.plot(xi, yi, 'b', label='分离超平面')
plt.legend()
plt.title("练习7.2")
plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
plt.rcParams['axes.unicode_minus'] = False  # 正常显示负号
plt.show()
print(clf.support_vectors_)
print(clf.coef_)
print(clf.intercept_)
print(clf.support_)
print(clf.n_support_)
