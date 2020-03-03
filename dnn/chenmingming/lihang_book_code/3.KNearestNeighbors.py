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


class KdNode():
    def __init__(self, dom_elt, split, left, right):
        self.dom_elt = dom_elt  # k维向量节点(k维空间中的一个样本点)
        self.split = split  # 整数（进行分割维度的序号）
        self.left = left  # 该结点分割超平面左子空间构成的kd-tree
        self.right = right  # 该结点分割超平面右子空间构成的kd-tree


class KdTree():
    def __init__(self, data):
        k = len(data[0])  # 实例的向量维度

        def CreatNode(split, data_set):
            if not data_set:
                return None
            data_set.sort(key=lambda x: x[split])
            split_pos = len(data_set) // 2  # 整除
            median = data_set[split_pos]
            split_next = (split + 1) % k

            return KdNode(median, split,
                          CreatNode(split_next, data_set[:split_pos]),
                          CreatNode(split_next, data_set[split_pos + 1:]))

        self.root = CreatNode(0, data)

    def preorder(self, root):
        if root:
            print(root.dom_elt)
        self.preorder(root.left)
        self.preorder(root.right)


from math import sqrt
from collections import namedtuple

# 定义一个namedtuple,分别存放最近坐标点、最近距离和访问过的节点数
result = namedtuple("Result_tuple",
                    "nearest_point  nearest_dist  nodes_visited")


def find_nearest(tree, point):
    k = len(point)  # 数据维度

    def travel(kd_node, target, max_dist):
        if kd_node is None:
            return result([0] * k, float("inf"),
                          0)  # python中用float("inf")和float("-inf")表示正负无穷

        nodes_visited = 1

        s = kd_node.split  # 进行分割的维度
        pivot = kd_node.dom_elt  # 进行分割的“轴”

        if target[s] <= pivot[s]:  # 如果目标点第s维小于分割轴的对应值(目标离左子树更近)
            nearer_node = kd_node.left  # 下一个访问节点为左子树根节点
            further_node = kd_node.right  # 同时记录下右子树
        else:  # 目标离右子树更近
            nearer_node = kd_node.right  # 下一个访问节点为右子树根节点
            further_node = kd_node.left

        temp1 = travel(nearer_node, target, max_dist)  # 进行遍历找到包含目标点的区域

        nearest = temp1.nearest_point  # 以此叶结点作为“当前最近点”
        dist = temp1.nearest_dist  # 更新最近距离

        nodes_visited += temp1.nodes_visited

        if dist < max_dist:
            max_dist = dist  # 最近点将在以目标点为球心，max_dist为半径的超球体内

        temp_dist = abs(pivot[s] - target[s])  # 第s维上目标点与分割超平面的距离
        if max_dist < temp_dist:  # 判断超球体是否与超平面相交
            return result(nearest, dist, nodes_visited)  # 不相交则可以直接返回，不用继续判断

        # ----------------------------------------------------------------------
        # 计算目标点与分割点的欧氏距离
        temp_dist = sqrt(sum((p1 - p2) ** 2 for p1, p2 in zip(pivot, target)))

        if temp_dist < dist:  # 如果“更近”
            nearest = pivot  # 更新最近点
            dist = temp_dist  # 更新最近距离
            max_dist = dist  # 更新超球体半径

        # 检查另一个子结点对应的区域是否有更近的点
        temp2 = travel(further_node, target, max_dist)

        nodes_visited += temp2.nodes_visited
        if temp2.nearest_dist < dist:  # 如果另一个子结点内存在更近距离
            nearest = temp2.nearest_point  # 更新最近点
            dist = temp2.nearest_dist  # 更新最近距离

        return result(nearest, dist, nodes_visited)

    return travel(tree.root, point, float("inf"))  # 从根节点开始递归


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
    print("平均准确率：%.4f" % (sum / 100))
    print("花费时间：%0.4f ms" % (1000 * (end - start) / 100))
    # ---------KD Tree--------------
    data = [[2, 3], [5, 4], [9, 6], [4, 7], [8, 1], [7, 2]]
    kd = KdTree(data)
    kd.preorder(kd.root)