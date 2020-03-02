# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/2 22:44
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 3.KNearestNeighbors.py
# @Reference: https://github.com/fengdu78/lihang-code
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from collections import Counter


def L_p(xi, xj, p=2):
    if len(xi) == len(xj) and len(xi) > 0:
        sum = 0
        for i in range(len(xi)):
            sum += math.pow(abs(xi[i] - xj[i]), p)
        return math.pow(sum, 1 / p)
    else:
        return 0


def KNN():
    def __init__(self, X_train, y_train, neighbors=3, p=2):
        self.n = neighbors
        self.p = p
        self.X_train = X_train
        self.y_train = y_train

    def predict(self, X):
        knn_list = []
        for i in range(self.n):
            dist = np.linalg.norm(X - self.X_train[i], ord=self.p)
            knn_list.append((dist, self.y_train[i]))


if __name__ == '__main__':
    # ---------计算距离----------------
    x1 = [1, 1]
    x2 = [5, 1]
    x3 = [4, 4]
    X = [x1, x2, x3]
    for i in range(len(X)):
        for j in range(i + 1, len(X)):
            for p in range(1, 5):
                print("x%d,x%d的L%d距离是：%.2f" % (i + 1, j + 1, p, L_p(X[i], X[j], p)))
    # ---------计----------------
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['label'] = iris.target
    plt.scatter(df[:50][iris.feature_names[0]], df[:50][iris.feature_names[1]], label=iris.target_names[0])
    plt.scatter(df[50:100][iris.feature_names[0]], df[50:100][iris.feature_names[1]], label=iris.target_names[1])
    plt.xlabel(iris.feature_names[0])
    plt.ylabel(iris.feature_names[1])
    plt.legend()
    plt.show()

    data = np.array(df.iloc[:100, [0, 1, -1]])
    X, y = data[:, :-1], data[:, -1]
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
