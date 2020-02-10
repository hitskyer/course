# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/2/10 16:57
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: Logistic_sklearn_classify.py
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression

np.random.seed(520)
X = np.random.normal(0,1,size=(200,2))   # 正态分布，中心0，标准差1
y = np.array(X[:, 0]**2 + X[:, 1] < 1.5, dtype=int)

# 随机选取20个y值，令其值为1，作为噪声
for i in range(20):
    y[np.random.randint(200)] = 1

plt.scatter(X[y==0,0],X[y==0,1],c='b')
plt.scatter(X[y==1,0],X[y==1,1],c='r')

from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
def PolynomialLogisticRegression(deg):
    return Pipeline([('ploynomial',PolynomialFeatures(degree=deg)),
                     ('std_scaler',StandardScaler()),
                     ('log_regression',LogisticRegression())])

if __name__ == '__main__':
    poly_log_reg = PolynomialLogisticRegression(2)
    poly_log_reg.fit(X, y)
    print(poly_log_reg.score(X, y))