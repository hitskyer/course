# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/14 0:10
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: seabornExercise.py
# @Reference: 

import pandas as pd
pd.plotting.register_matplotlib_converters()
import matplotlib.pyplot as plt
import seaborn as sns

filepath = "spotify.csv"
data = pd.read_csv(filepath, index_col='Date', parse_dates=True)
print(list(data.columns))
print(data.index)
plt.figure(figsize=(12,6))
sns.lineplot(data=data,label="label_test")
plt.title("title")
plt.xlabel("Data_test")
plt.show()