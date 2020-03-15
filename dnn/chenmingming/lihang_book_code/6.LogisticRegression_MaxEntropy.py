# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/15 23:27
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 6.LogisticRegression_MaxEntropy.py
# @Reference: https://github.com/fengdu78/lihang-code

from math import exp
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split


def create_data():
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['label'] = iris.target
    data = np.array(df.iloc[:100, [0, 1, -1]])
    return data[:, :2], data[:, -1]
X,y = create_data()
X_train,X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)

class LRclassifier():
    def __init__(self,max_iter=200, learning_rate=0.01):
        self.max_iter = max_iter
        self.learning_rate = learning_rate
    def sigmoid(self,x):
        return 1/(1+exp(-x))
    def data_matrix(self,X):
        data_mat = []
        for d in X:
            data_mat.append([1.0, *d])
        return data_mat
    def fit(self,X,y):
        data_mat = self.data_matrix(X)
        self.weights =
