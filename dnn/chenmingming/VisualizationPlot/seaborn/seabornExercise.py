# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/14 0:10
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: seabornExercise.py
# @Reference: https://www.kaggle.com/learn/data-visualization


import pandas as pd
# %matplotlib inline # notebook绘图直接显示
pd.plotting.register_matplotlib_converters()
import matplotlib.pyplot as plt
import seaborn as sns

plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码

# 线图
filepath = "spotify.csv"
data = pd.read_csv(filepath, index_col='Date', parse_dates=True)
print(data.head())
print(data.tail())
print(list(data.columns))
print(data.index)
style = ["dark", "darkgrid", "white", "whitegrid", "ticks"]
plt.figure(figsize=(12, 6))
for i in range(5):
    sns.set_style(style[i])
    f = plt.subplot(2, 3, i + 1)
    sns.lineplot(data=data)  # 单个数据可以加 label="label_test"
    f.set_title("style_" + style[i])
    f.legend()
plt.show()

sns.lineplot(data=data['Shape of You'], label='Shape of You')
# plt.show()

# 柱状图
filepath = "flight_delays.csv"
flight_data = pd.read_csv(filepath, index_col="Month")
print(flight_data)

plt.figure(figsize=(10, 6))
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



# 直方图 Histogram
filepath = "iris.csv"
iris_data = pd.read_csv(filepath, index_col='Id')
print(iris_data.head())
sns.distplot(a=iris_data['Petal Length (cm)'], kde=False)
plt.show()

# 密度图
sns.kdeplot(data=iris_data['Petal Length (cm)'], shade=False)
plt.show()
sns.jointplot(x=iris_data['Petal Length (cm)'], y=iris_data['Sepal Width (cm)'],
              kind='kde')
plt.show()

# 直方 颜色图
iris_set_file = "iris_setosa.csv"
iris_ver_file = "iris_versicolor.csv"
iris_vir_file = "iris_virginica.csv"

iris_set_data = pd.read_csv(iris_set_file, index_col="Id")
iris_ver_data = pd.read_csv(iris_ver_file, index_col="Id")
iris_vir_data = pd.read_csv(iris_vir_file, index_col="Id")
sns.distplot(a=iris_set_data["Petal Length (cm)"], label="iris_setosa", kde=False)
sns.distplot(a=iris_ver_data['Petal Length (cm)'], label="Iris-versicolor", kde=False)
sns.distplot(a=iris_vir_data['Petal Length (cm)'], label="Iris-virginica", kde=False)
plt.title("不同种系Petal Lengths直方图")
plt.legend()
plt.show()

# 密度颜色图
sns.kdeplot(data=iris_set_data['Petal Length (cm)'], label="Iris-setosa", shade=True)
sns.kdeplot(data=iris_ver_data['Petal Length (cm)'], label="Iris-versicolor", shade=True)
sns.kdeplot(data=iris_vir_data['Petal Length (cm)'], label="Iris-virginica", shade=True)
plt.title("不同种系Petal Lengths分布")
plt.show()

