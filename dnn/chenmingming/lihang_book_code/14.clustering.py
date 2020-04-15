# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/4/14 23:24
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 14.clustering.py
# @Reference: https://scikit-learn.org/stable/modules/clustering.html#

from sklearn.cluster import KMeans
import numpy as np

# 书上例子
X = np.array([[0, 2], [0, 0], [1, 0], [5, 0], [5, 2]])
kms = KMeans(n_clusters=2).fit(X)
print(kms.labels_)
print(kms.cluster_centers_)

# 官网层次聚类例子
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import dendrogram
from sklearn.datasets import load_iris
from sklearn.cluster import AgglomerativeClustering


def plot_dendrogram(model, **kwargs):
    counts = np.zeros(model.children_.shape[0])
    n_samples = len(model.labels_)
    for i, merge in enumerate(model.children_):
        cur_count = 0
        for child_idx in merge:
            if child_idx < n_samples:
                cur_count += 1
            else:
                cur_count += counts[child_idx - n_samples]
        counts[i] = cur_count
    linkage_matrix = np.column_stack([model.children_, model.distances_, counts]).astype(float)
    dendrogram(linkage_matrix, **kwargs)


iris = load_iris()
X = iris.data

model = AgglomerativeClustering(distance_threshold=0, n_clusters=None)
model = model.fit(X)
plt.title('Hierarchical Clustering Dendrogram')
plot_dendrogram(model, truncate_mode='level', p=3)
plt.xlabel("Number of points in node (or index of point if no parenthesis).")
plt.show()