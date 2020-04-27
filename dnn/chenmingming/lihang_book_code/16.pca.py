# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/4/27 12:45
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 16.pca.py
# @Reference: 

import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

X = np.array([[-1, -1], [-2, -1], [-3, -2], [1, 1], [2, 1], [3, 2]])
plt.scatter(X[:, 0], X[:, 1])
plt.show()
for n in range(1, 3):
    print("PCA n_components = {}".format(n))
    pca = PCA(n_components=n)
    pca.fit(X)
    print("特征方差")
    print(pca.explained_variance_)
    print("特征方差占比")
    print(pca.explained_variance_ratio_)
    print("主成分奇异值")
    print(pca.singular_values_)
    print("主成分")
    print(pca.components_)
    print("主成分个数")
    print(pca.n_components_)
