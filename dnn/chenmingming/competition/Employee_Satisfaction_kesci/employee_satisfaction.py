#%%

# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/16 21:10
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: employee_satisfaction.ipynb
# @Reference:

#%%

%matplotlib inline
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['figure.facecolor']=(1,1,1,1) # pycharm 绘图白底，看得清坐标
import pandas as pd
import seaborn as sns
from sklearn import preprocessing
from sklearn.linear_model import LinearRegression as lr
from sklearn.ensemble import RandomForestRegressor as rf
from sklearn.ensemble import AdaBoostRegressor
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import train_test_split,cross_val_score
from sklearn.metrics import *
from sklearn.preprocessing import OneHotEncoder,LabelEncoder,OrdinalEncoder

#%%

# 读取数据
tr_data = pd.read_csv("train.csv",index_col='id')
X_test = pd.read_csv("test.csv",index_col='id') # 不含标签

tr_data.head(10)

#%%

tr_data.corr()
sns.regplot(x=tr_data.index, y=tr_data['satisfaction_level'])

#%%

X = tr_data.drop(['satisfaction_level'], axis=1)
y = tr_data['satisfaction_level']
X_train, X_valid, y_train, y_valid = train_test_split(X, y,test_size=0.2,random_state=1)
X_train
feature = X_train.columns
print(feature)
s = (X_train.dtypes == 'object')
object_cols = list(s[s].index)
print(object_cols)
y_train
# 查看标签值，是一系列的浮点数
pd.unique(y_train)



#%%

# 数字特征
num_X_train = X_train.drop(object_cols, axis=1)
num_X_valid = X_valid.drop(object_cols, axis=1)
num_X_test = X_test.drop(object_cols, axis=1)

X_scale = preprocessing.StandardScaler()
X_scale.fit_transform(num_X_train)
print(num_X_train.shape)
num_X_train_data = X_scale.fit_transform(num_X_train)
num_X_valid_data = X_scale.transform(num_X_valid)
num_X_test_data = X_scale.transform(num_X_test)
print(type(num_X_train_data))

num_X_train_scale = pd.DataFrame(num_X_train_data)
num_X_train_scale.columns = num_X_train.columns
num_X_valid_scale = pd.DataFrame(num_X_valid_data)
num_X_valid_scale.columns = num_X_valid.columns
num_X_test_scale = pd.DataFrame(num_X_test_data)
num_X_test_scale.columns = num_X_test.columns
num_X_train_scale.index = num_X_train.index
num_X_valid_scale.index = num_X_valid.index
num_X_test_scale.index = num_X_test.index

#%%

# 检查是否有列中，数据集之间的值的种类有差异，防止编码transform出错，经检查没有bad
good_label_cols = [col for col in object_cols if
                   set(X_train[col]) == set(X_valid[col])]
good_label_cols
# Problematic columns that will be dropped from the dataset
bad_label_cols = list(set(object_cols)-set(good_label_cols))
bad_label_cols

good_label_cols = [col for col in object_cols if
                   set(X_train[col]) == set(X_test[col])]
good_label_cols
# Problematic columns that will be dropped from the dataset
bad_label_cols = list(set(object_cols)-set(good_label_cols))
bad_label_cols

#%%

# 文字特征
cat_X_train = X_train[good_label_cols]
cat_X_valid = X_valid[good_label_cols]
cat_X_test = X_test[good_label_cols]
cat_X_train

#%%

# 文字特征转换成数字特征
labEncoder = LabelEncoder()
for f in set(good_label_cols):
    cat_X_train[f] = labEncoder.fit_transform(cat_X_train[f])
    cat_X_valid[f] = labEncoder.transform(cat_X_valid[f])
    cat_X_test[f] = labEncoder.transform(cat_X_test[f])
cat_X_train

#%%

cat_X_train.index = X_train.index
X_train_final = pd.concat([num_X_train_scale, cat_X_train], axis=1)
X_train_final
# for i in feature:
#     sns.regplot(x=X_train_final[i],y=y_train)
#     plt.show()

cat_X_valid.index = X_valid.index
X_valid_final = pd.concat([num_X_valid_scale, cat_X_valid], axis=1)

cat_X_test.index = X_test.index
cat_X_test
X_test_final = pd.concat([num_X_test_scale, cat_X_test], axis=1)
X_test_final

#%%

n = [25,50,100,200]
r = [0.2,0.4,0.6,0.8,1]
param = dict(n_estimators=n, learning_rate=r)

model1 = AdaBoostRegressor(base_estimator=rf(n_estimators=100),n_estimators=100,learning_rate=1,random_state=1)
model1.fit(X_train_final, y_train)
# grid = GridSearchCV(model1,param,cv=10,scoring='neg_mean_squared_error')
# grid.fit(X_train_final,y_train)
# model1.fit(X_train_final, y_train)
# cross_val_score(model1,X_train_final,y_train,cv=10,scoring='neg_mean_squared_error')

# model = grid.best_estimator_
y_pred_valid = model1.predict(X_valid_final)
mean_absolute_error(y_pred_valid, y_valid)

#%%

y_pred_test = model1.predict(X_test_final)
result = pd.DataFrame()
result['id'] = X_test.index
result['satisfaction_level'] = y_pred_test
result.to_csv('lr_with_num_scale.csv',index=False)
