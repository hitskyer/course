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


if __name__ == '__main__':
    # ---------书上贷款例子-----------------
    datasets, labels = get_data()
    train_data = np.array(pd.DataFrame(datasets, columns=labels))
    X_train, y_train = train_data[:, :-1], train_data[:, -1:]
    encoder = preprocessing.OrdinalEncoder()
    encoder.fit(X_train)
    X_train = encoder.transform(X_train)
    A = encoder.transform([['青年', '否', '是', '一般']])
    B = encoder.transform([['中年', '是', '否', '好']])
    C = encoder.transform([['老年', '否', '是', '一般']])

    encoder = preprocessing.OrdinalEncoder()
    encoder.fit(y_train)
    y_train = encoder.transform(y_train)

    clf = DecisionTreeClassifier()
    clf.fit(X_train, y_train)
    print(encoder.inverse_transform([clf.predict(A)]))
    print(clf.predict_proba(B))
    print(clf.predict_proba(C))

    # 需要安装graphviz,添加path，可视化决策树
    with open('mytree.dot', 'w', encoding='utf-8') as f:
        dot_data = export_graphviz(clf, out_file=None, feature_names=clf.feature_importances_,
                                   filled=True, rounded=True, special_characters=True)
    dot = graphviz.Source(dot_data)
    dot.view()
    # 写入png , pdf
    graph = pydotplus.graph_from_dot_data(dot_data)
    graph.write_png('tree.png')
    # cmd: dot -Tpdf tree.dot -o output.pdf，dot -Tpng tree.dot -o output.png
