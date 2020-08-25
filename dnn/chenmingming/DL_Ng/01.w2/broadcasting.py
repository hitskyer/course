# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/8/25 19:56
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: broadcasting.py
# @Reference: 

import numpy as np

A = np.array([
    [56, 0, 4.4, 68],
    [1.2, 104, 52, 8],
    [1.8, 135, 99, 0.9]
])

cal = A.sum(axis=0)  # 按列求和
print(cal)

percentage = 100 * A / cal.reshape(1, 4)
print(percentage)

A = np.array([[1, 2, 3, 4]])
b = 100
print(A + b)

A = np.array([[1, 2, 3],
              [4, 5, 6]])
B = np.array([100, 200, 300])
print(A + B)

A = np.array([[1, 2, 3],
              [4, 5, 6]])
B = np.array([[100], [200]])
print(A + B)

a = np.random.randn(5,1)
print(a.shape)
print(np.dot(a, a.T))
print(np.dot(a.T, a))