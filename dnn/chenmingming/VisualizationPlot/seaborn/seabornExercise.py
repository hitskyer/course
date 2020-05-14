# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/14 0:10
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: seabornExercise.py
# @Reference: https://www.kaggle.com/learn/data-visualization


import pandas as pd

pd.plotting.register_matplotlib_converters()
import matplotlib.pyplot as plt
import seaborn as sns

"""
# 线图
filepath = "spotify.csv"
data = pd.read_csv(filepath, index_col='Date', parse_dates=True)
print(data.head())
print(data.tail())
print(list(data.columns))
print(data.index)
plt.figure(figsize=(12, 6))
sns.lineplot(data=data)  # 单个数据可以加 label="label_test"
plt.title("title")
plt.xlabel("Data_test")
# plt.show()
sns.lineplot(data=data['Shape of You'], label='Shape of You')
# plt.show()

# 柱状图
filepath = "flight_delays.csv"
flight_data = pd.read_csv(filepath, index_col="Month")
print(flight_data)

plt.figure(figsize=(10, 6))
plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
plt.title("Spirit Airlines Flights月度晚点")
sns.barplot(x=flight_data.index, y=flight_data['NK'])
# 错误用法 x=flight_data['Month']
plt.ylabel("到达晚点（分钟）")
# plt.show()

# 热图
plt.figure(figsize=(14,7))
plt.title("所有航班月度平均到达晚点（分钟）")
sns.heatmap(data=flight_data,annot=True)
# annot = True 每个单元格的值都显示在图表上
# （不选择此项将删除每个单元格中的数字！）
plt.xlabel("航班")
# plt.show()


# 散点图
filepath = "insurance.csv"
insurance_data = pd.read_csv(filepath)
sns.scatterplot(x=insurance_data['bmi'], y=insurance_data['charges'])
# plt.show()
# sns.regplot(x=insurance_data['bmi'], y=insurance_data['charges'])
# plt.show()
# sns.scatterplot(x=insurance_data['bmi'], y=insurance_data['charges'],
#                 hue=insurance_data['smoker'])
# sns.lmplot(x='bmi',y='charges',hue='smoker',data=insurance_data)
sns.swarmplot(x=insurance_data['smoker'],y=insurance_data['charges'])
plt.show()

"""

#

