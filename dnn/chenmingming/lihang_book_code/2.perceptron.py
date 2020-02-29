# -*- coding:utf-8 -*-
# @Python 3.7
# @Time: 2020/2/28 22:07
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 2.perceptron.py
# @Reference: https://github.com/fengdu78/lihang-code

import pandas as pd
import numpy as np
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt


class PerceptronModel():
    def __init__(self, X, y, eta):
        self.w = np.ones(len(X[0]), dtype=np.float)
        self.b = 0
        self.eta = eta
        self.dataX = X
        self.datay = y
        self.iterTimes = 0

    def sign(self, x, w, b):  # sign函数
        y = np.dot(w, x) + b
        return y

    def fit(self):
        stop = False
        while not stop:
            wrong_count = 0
            for i in range(len(self.dataX)):
                X = self.dataX[i]
                y = self.datay[i]
                if (y * self.sign(X, self.w, self.b)) <= 0:
                    self.w += self.eta * np.dot(X, y)
                    self.b += self.eta * y
                    wrong_count += 1
                    self.iterTimes += 1
            if wrong_count == 0:
                stop = True
        print("分类完成！步长：%.4f, 共迭代 %d 次" % (self.eta, self.iterTimes))


if __name__ == '__main__':
    # 读取鸢尾花数据
    iris = load_iris()
    # 将鸢尾花4个特征，以4列存入pandas的数据框架
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    # 在最后一列追加 加入标签（分类）列数据
    df['lab'] = iris.target

    # df.columns=[iris.feature_names[0], iris.feature_names[1], iris.feature_names[2], iris.feature_names[3], 'lab']
    # df['lab'].value_counts()
    # 选取前两种花进行划分（每种数据50组）
    plt.scatter(df[:50][iris.feature_names[0]], df[:50][iris.feature_names[1]], label=iris.target_names[0])
    plt.scatter(df[50:100][iris.feature_names[0]], df[50:100][iris.feature_names[1]], label=iris.target_names[1])
    plt.xlabel(iris.feature_names[0])
    plt.ylabel(iris.feature_names[1])

    # 选取数据,前100行，前两个特征，最后一列标签
    data = np.array(df.iloc[:100, [0, 1, -1]])
    # X是除最后一列外的所有列，y是最后一列
    X, y = data[:, :-1], data[:, -1]
    # 生成感知机的标签值，+1， -1, 第一种-1，第二种+1
    y = np.array([1 if i == 1 else -1 for i in y])

    # 调用感知机进行分类，学习率eta
    perceptron = PerceptronModel(X, y, eta=0.01)
    perceptron.fit()

    # 绘制分类超平面
    x_points = np.linspace(4, 7, 100)
    y_ = -(perceptron.w[0] * x_points + perceptron.b) / perceptron.w[1]
    plt.rcParams['font.sans-serif'] = 'SimHei' # 消除中文乱码
    plt.plot(x_points, y_, label='分类线')
    plt.legend()
    plt.show()

    eta_iterTime = []
    for eta in np.linspace(0.01, 1.01, 50):
        perceptron = PerceptronModel(X, y, eta)
        perceptron.fit()
        eta_iterTime.append([eta, perceptron.iterTimes])
    for i in range(len(eta_iterTime)):
        plt.plot(eta_iterTime[i][0], eta_iterTime[i][1], 'b+')
    plt.xlabel('步长(学习率)')
    plt.ylabel('迭代次数')
    plt.show()


