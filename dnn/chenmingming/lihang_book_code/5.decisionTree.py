# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/13 19:36
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 5.decisionTree.py
# @Reference: https://github.com/fengdu78/lihang-code

import pandas as pd
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from collections import Counter
import math
from math import log
import pprint
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import export_graphviz
import graphviz
import pydotplus


def get_data():
    datasets = [['青年', '否', '否', '一般', '否'],
                ['青年', '否', '否', '好', '否'],
                ['青年', '是', '否', '好', '是'],
                ['青年', '是', '是', '一般', '是'],
                ['青年', '否', '否', '一般', '否'],
                ['中年', '否', '否', '一般', '否'],
                ['中年', '否', '否', '好', '否'],
                ['中年', '是', '是', '好', '是'],
                ['中年', '否', '是', '非常好', '是'],
                ['中年', '否', '是', '非常好', '是'],
                ['老年', '否', '是', '非常好', '是'],
                ['老年', '否', '是', '好', '是'],
                ['老年', '是', '否', '好', '是'],
                ['老年', '是', '否', '非常好', '是'],
                ['老年', '否', '否', '一般', '否'],
                ]
    labels = [u'年龄', u'有工作', u'有自己的房子', u'信贷情况', u'分类']
    # 字符串前加 u, 后面字符串以 Unicode 格式 进行编码，一般用在中文字符串前面，防止乱码
    return datasets, labels;


# ---------书上贷款例子-----------------
datasets, labels = get_data()
train_data = np.array(pd.DataFrame(datasets, columns=labels))
X_train, y_train = train_data[:, :-1], train_data[:, -1:]
encoder = preprocessing.OrdinalEncoder()  # 将字符转成浮点
encoder.fit(X_train)  # 先拟合
X_train = encoder.transform(X_train)  # 转换成数字
A = encoder.transform([['青年', '否', '是', '一般']])
B = encoder.transform([['中年', '是', '否', '好']])
C = encoder.transform([['老年', '否', '是', '一般']])

encoder = preprocessing.OrdinalEncoder()
encoder.fit(y_train)
y_train = encoder.transform(y_train)
# sklearn 决策树
clf = DecisionTreeClassifier()
clf.fit(X_train, y_train)
print(encoder.inverse_transform([clf.predict(A)]))
print(clf.predict_proba(B))
print(clf.predict_proba(C))

# --------------决策树可视化-------------
# 需要安装graphviz,添加path，可视化决策树
with open('mytree.dot', 'w', encoding='utf-8') as f:
    dot_data = export_graphviz(clf, out_file=None, feature_names=clf.feature_importances_,
                               filled=True, rounded=True, special_characters=True)
dot = graphviz.Source(dot_data)
# dot.view()
# 写入png , pdf
graph = pydotplus.graph_from_dot_data(dot_data)
graph.write_png('tree.png')


# cmd: dot -Tpdf tree.dot -o output.pdf，dot -Tpng tree.dot -o output.png

# -----------自编程，抄一遍---------------
# ----特征选择，基于信息增益----
def cal_entropy(datasets):  # 经验熵H(D)
    data_len = len(datasets)
    label_count = {}
    for i in range(data_len):
        label = datasets[i][-1]
        if label not in label_count:
            label_count[label] = 0
        label_count[label] += 1
    entropy = -sum([(p / data_len) * log(p / data_len, 2) for p in label_count.values()])
    return entropy


def cond_entropy(datasets, axis=0):  # 经验条件熵H(D|A)
    data_len = len(datasets)
    feature_set = {}
    for i in range(data_len):
        feature = datasets[i][axis]
        if feature not in feature_set:
            feature_set[feature] = []
        feature_set[feature].append(datasets[i])
    cond_ent = sum([(len(p) / data_len) * cal_entropy(p) for p in feature_set.values()])
    return cond_ent


def info_gain(entropy, cond_ent):  # 信息增益
    return entropy - cond_ent


def info_gain_train(datasets):  # 基于特征信息增益的特征选择
    count = len(datasets[0]) - 1
    entropy = cal_entropy(datasets)
    best_feature = []
    for i in range(count):
        info_gain_i = info_gain(entropy, cond_entropy(datasets, axis=i))
        best_feature.append((i, info_gain_i))
        print("特征（{}）- info_gain - {:.3f}".format(labels[i], info_gain_i))
    best_feature_i = max(best_feature, key=lambda x: x[-1])
    print("特征（{}）的信息增益最大，选为根节点的特征".format(labels[best_feature_i[0]]))


info_gain_train(np.array(datasets))


# -------ID3算法生成决策树---------

class Node():
    def __init__(self, root=True, label=None, feature_name=None, feature=None):
        self.root = root
        self.label = label
        self.feature_name = feature_name
        self.feature = feature
        self.tree = {}
        self.result = {
            'label:': self.label,
            'feature:': self.feature,
            'tree:': self.tree
        }

    def __repr__(self):  # 类似str方法，更侧重程序员调试
        print('{}'.format(self.result))

    def add_node(self, val, node):
        self.tree[val] = node

    def predict(self, features):
        if self.root is True:
            return self.label
        return self.tree[features[self.feature]].predict(features)


class DTree():
    def __init__(self, epsilon=0.1):  # 信息增益阈值， < epsilon 时，结束决策树展开
        self.epsilon = epsilon
        self._tree = {}

    @staticmethod
    def cal_entropy(datasets):  # 经验熵H(D)
        data_len = len(datasets)
        label_count = {}
        for i in range(data_len):
            label = datasets[i][-1]
            if label not in label_count:
                label_count[label] = 0
            label_count[label] += 1
        entropy = -sum([(p / data_len) * log(p / data_len, 2) for p in label_count.values()])
        return entropy

    def cond_entropy(self, datasets, axis=0):  # 经验条件熵H(D|A)
        data_len = len(datasets)
        feature_set = {}
        for i in range(data_len):
            feature = datasets[i][axis]
            if feature not in feature_set:
                feature_set[feature] = []
            feature_set[feature].append(datasets[i])
        cond_ent = sum([(len(p) / data_len) * self.cal_entropy(p) for p in feature_set.values()])
        return cond_ent

    @staticmethod
    def info_gain(entropy, cond_ent):  # 信息增益
        return entropy - cond_ent

    def info_gain_train(self, datasets):  # 基于特征信息增益的特征选择
        count = len(datasets[0]) - 1
        entropy = self.cal_entropy(datasets)
        best_feature = []
        for i in range(count):
            info_gain_i = info_gain(entropy, cond_entropy(datasets, axis=i))
            best_feature.append((i, info_gain_i))
            print("特征（{}）- info_gain - {:.3f}".format(labels[i], info_gain_i))
        best_feature_i = max(best_feature, key=lambda x: x[-1])
        return best_feature_i

    def train(self, train_data):
        '''
        :input: 数据集D(DataFrame格式)，特征集A，阈值eta
        :return: 决策树DT
        '''
        _, y_train, features = train_data.iloc[:, :-1], train_data.iloc[:, -1], train_data.columns[:-1]

        # 1. 若所有D实例都属于同一分类，不用分了，直接返回那个类
        if len(y_train.value_counts()) == 1:
            return Node(root=True, label=y_train.iloc[0])
        # 2. 若没有特征A，返回D中数量最多的分类
        if len(features) == 0:
            return Node(root=True, label=y_train.value_counts().sort_values(
                ascending=False).index[0])
        # 3. 计算最大信息增益，取为特征
        max_feature, max_info_gain = self.info_gain_train(np.array(train_data))
        max_feature_name = features[max_feature]

        # 4. 如果信息增益小于阈值epsilon，置为单节点，将实例数最大的类作为节点标记
        if max_info_gain < self.epsilon:
            return Node(root=True, label=y_train.value_counts().sort_values(
                ascending=False).index[0])
        # 5. 构建Ag子集
        node_tree = Node(root=False, feature_name=max_feature_name, feature=max_feature)

        feature_list = train_data[max_feature_name].value_counts().index
        for f in feature_list:
            sub_train_df = train_data.loc[train_data[max_feature_name] == f].drop([max_feature_name], axis=1)

            # 6. 递归生成树
            sub_tree = self.train(sub_train_df)
            node_tree.add_node(f, sub_tree)
        return node_tree

    def fit(self, train_data):
        self._tree = self.train(train_data)
        return self._tree

    def predict(self, X_test):
        return self._tree.predict(X_test)


train_data = pd.DataFrame(datasets, columns=labels)
dt = DTree()
tree = dt.fit(train_data)
print(dt.predict(['老年', '否', '否', '一般']))
print(dt.predict(['青年', '否', '是', '一般']))
print(dt.predict(['中年', '是', '否', '好']))
print(dt.predict(['老年', '否', '是', '一般']))

# ------------鸢尾花---------------
iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['label'] = iris.target
df.columns = ['sepal length', 'sepal width', 'petal length', 'petal width', 'label']
data = np.array(df.iloc[:100, [0, 1, -1]])
X = data[:, :2]
y = data[:, -1]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
clf = DecisionTreeClassifier()
print(clf)
clf.fit(X_train, y_train)
print(clf.score(X_test, y_test))
# --------------决策树可视化-------------
# 需要安装graphviz,添加path，可视化决策树
with open('mytree.dot', 'w', encoding='utf-8') as f:
    dot_data = export_graphviz(clf, out_file=None, feature_names=df.columns[:2],
                               filled=True, rounded=True, special_characters=True,
                               class_names=iris.target_names)
dot = graphviz.Source(dot_data)
dot.view()
# 写入png , pdf
graph = pydotplus.graph_from_dot_data(dot_data)
graph.write_png('tree.png')
# cmd: dot -Tpdf tree.dot -o output.pdf，dot -Tpng tree.dot -o output.png
