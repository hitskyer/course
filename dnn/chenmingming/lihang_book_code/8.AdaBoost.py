# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/24 23:13
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: AdaBoost.py
# @Reference: 
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import AdaBoostClassifier
data = [[0,1,3,-1],
        [0,3,1,-1],
        [1,2,2,-1],
        [1,1,3,-1],
        [1,2,3,-1],
        [0,1,2,-1],
        [1,1,2,1],
        [1,1,1,1],
        [1,3,1,-1],
        [0,2,1,-1]]
data = pd.DataFrame(np.array(data))
X, y = data.iloc[:,0:-1], data.iloc[:,-1]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
clf = AdaBoostClassifier(n_estimators=100, learning_rate=0.5)
clf.fit(X_train, y_train)
print(clf.score(X_test, y_test))