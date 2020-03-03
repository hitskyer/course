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
import time


def L_p(xi, xj, p=2):
    if len(xi) == len(xj) and len(xi) > 0:
        sum = 0
        for i in range(len(xi)):
            sum += math.pow(abs(xi[i] - xj[i]), p)
        return math.pow(sum, 1 / p)
    else:
        return 0


class KNearNeighbors():
    def __init__(self, X_train, y_train, neighbors=3, p=2):
        self.n = neighbors
        self.p = p
        self.X_train = X_train
        self.y_train = y_train

    def predict(self, X):
        knn_list = []
        # 先在训练集中取n个点出来，计算距离
        for i in range(self.n):
            dist = np.linalg.norm(X - self.X_train[i], ord=self.p)
            knn_list.append((dist, self.y_train[i]))
        # 再在剩余的训练集中取出剩余的，计算距离，有距离更近的，替换knn_list里最大的
        for i in range(self.n, len(self.X_train)):
            max_index = knn_list.index(max(knn_list, key=lambda x: x[0]))
            dist = np.linalg.norm(X - self.X_train[i], ord=self.p)
            if knn_list[max_index][0] > dist:
                knn_list[max_index] = (dist, self.y_train[i])
        # 取出所有的n个最近邻点的标签
        knn = [k[-1] for k in knn_list]
        count_pairs = Counter(knn)

        # 次数最多的标签，排序后最后一个 标签：出现次数
        max_count = sorted(count_pairs.items(), key=lambda x: x[1])[-1][0]
        return max_count

    def score(self, X_test, y_test):
        right_count = 0
        for X, y in zip(X_test, y_test):  # zip 同时遍历多个对象
            label = self.predict(X)
            if math.isclose(label, y, rel_tol=1e-5):  # 浮点型相等判断
                right_count += 1
        print("准确率：%.4f" % (right_count / len(X_test)))
        return right_count / len(X_test)


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
    # ---------鸢尾花K近邻----------------
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['label'] = iris.target
    plt.scatter(df[:50][iris.feature_names[0]], df[:50][iris.feature_names[1]], label=iris.target_names[0])
    plt.scatter(df[50:100][iris.feature_names[0]], df[50:100][iris.feature_names[1]], label=iris.target_names[1])
    plt.xlabel(iris.feature_names[0])
    plt.ylabel(iris.feature_names[1])

    data = np.array(df.iloc[:100, [0, 1, -1]])  # 取前2种花，前两个特征
    X, y = data[:, :-1], data[:, -1]

    # 切分数据集，留20%做测试数据
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
    # KNN算法，近邻选择20个，距离度量L2距离
    clf = KNearNeighbors(X_train, y_train, 20, 2)
    # 预测测试点，统计正确率
    clf.score(X_test, y_test)

    # 随意给一个点，用KNN预测其分类
    test_point = [4.75, 2.75]
    test_point_flower = '测试点' + iris.target_names[int(clf.predict(test_point))]
    print("测试点的类别是：%s" % test_point_flower)
    plt.plot(test_point[0], test_point[1], 'bx', label=test_point_flower)
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
    plt.rcParams['axes.unicode_minus'] = False  # 正常显示负号
    plt.legend()
    plt.show()
    # ---------sklearn KNN----------
    from sklearn.neighbors import KNeighborsClassifier
    clf_skl = KNeighborsClassifier(n_neighbors=50, p=4, algorithm='kd_tree')
    start = time.time()
    sum = 0
    for i in range(100):
        clf_skl.fit(X_train, y_train)
        sum += clf_skl.score(X_test, y_test)
    end = time.time()
    print("平均准确率：%.4f" % (sum/100))
    print("花费时间：%0.4f ms" % (1000*(end - start)/100))
