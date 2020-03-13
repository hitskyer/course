# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/13 19:36
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 5.decisionTree.py
# @Reference: https://github.com/fengdu78/lihang-code

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from collections import Counter
import math
from math import log
import pprint


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
    train_data = pd.DataFrame(datasets, columns=labels)
   