'''
	遇到不熟悉的库、模块、类、函数，可以依次：
	1）百度（google确实靠谱一些），如"matplotlib.pyplot"，会有不错的博客供学习参考
	2）"终端-->python-->import xx-->help(xx.yy)"，一开始的时候这么做没啥用，但作为资深工程师是必备技能
	3）试着修改一些参数，观察其输出的变化，在后面的程序中，会不断的演示这种办法
'''
# written by hitskyer, I just wanna say thank you !
# modified by Michael Ming on 2020.2.20
# Python 3.7
import sys
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier


def show_data_set(X, y, data):
    plt.plot(X[y == 0, 0], X[y == 0, 1], 'rs', label=data.target_names[0])
    plt.plot(X[y == 1, 0], X[y == 1, 1], 'bx', label=data.target_names[1])
    plt.plot(X[y == 2, 0], X[y == 2, 1], 'go', label=data.target_names[2])
    plt.xlabel(data.feature_names[0])
    plt.ylabel(data.feature_names[1])
    plt.title("鸢尾花2维数据")
    plt.legend()
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
    plt.show()


def plot_data(X, y):
    plt.plot(X[y == 0, 0], X[y == 0, 1], 'rs', label='setosa')
    plt.plot(X[y == 1, 0], X[y == 1, 1], 'bx', label='versicolor')
    plt.plot(X[y == 2, 0], X[y == 2, 1], 'go', label='virginica')
    plt.xlabel("sepal length (cm)")
    plt.ylabel("sepal width (cm)")
    # plt.xlabel("petal length (cm)")
    # plt.ylabel("petal width (cm)")
    plt.title("预测分类边界")
    plt.legend()
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
    plt.show()


def plot_decision_boundary(x_min, x_max, y_min, y_max, pred_func):
    h = 0.01
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    Z = pred_func(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)


def test1(X_train, X_test, y_train, y_test, multi_class='ovr', solver='liblinear'):
    log_reg = LogisticRegression(multi_class=multi_class, solver=solver)  # 调用ovr多分类
    log_reg.fit(X_train, y_train)
    predict_train = log_reg.predict(X_train)
    sys.stdout.write("LR(multi_class = %s, solver = %s) Train Accuracy : %.4g\n" % (
        multi_class, solver, metrics.accuracy_score(y_train, predict_train)))
    predict_test = log_reg.predict(X_test)
    sys.stdout.write("LR(multi_class = %s, solver = %s) Test  Accuracy : %.4g\n" % (
        multi_class, solver, metrics.accuracy_score(y_test, predict_test)))
    # plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: log_reg.predict(x))  # 4个特征下注释掉，前两特征
    # plot_decision_boundary(0.5, 7.5, 0, 3, lambda x: log_reg.predict(x))  # 4个特征下注释掉，后两特征
    plot_data(X_train, y_train)


def test2(X_train, X_test, y_train, y_test):
    #  multi_class默认auto
    # 'auto' selects 'ovr' if the data is binary, or if solver='liblinear',
    #  and otherwise selects 'multinomial'.
    #  看完help知道auto选择的是ovr，因为下面求解器选的是 liblinear
    #  所以test1和test2是同种效果，不一样的写法
    # log_reg = LogisticRegression(solver='liblinear')
    log_reg = LogisticRegression(multi_class='multinomial', solver='newton-cg')
    ovr = OneVsRestClassifier(log_reg)
    ovr.fit(X_train, y_train)
    predict_train = ovr.predict(X_train)
    sys.stdout.write("LR(ovr) Train Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_train, predict_train)))
    predict_test = ovr.predict(X_test)
    sys.stdout.write("LR(ovr) Test  Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_test, predict_test)))
    # plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: ovr.predict(x))  # 4个特征下注释掉，前两特征
    # plot_decision_boundary(0.5, 7.5, 0, 3, lambda x: ovr.predict(x))  # 4个特征下注释掉，后两特征
    plot_data(X_train, y_train)


def test3(X_train, X_test, y_train, y_test):
    # For multiclass problems, only 'newton-cg', 'sag', 'saga' and 'lbfgs' handle multinomial loss;
    # log_reg = LogisticRegression(multi_class='multinomial', solver='newton-cg')
    log_reg = LogisticRegression(multi_class='ovr', solver='liblinear')
    ovo = OneVsOneClassifier(log_reg)  # ovo多分类，传入LR(multinomial,newton-cg or lbfgs)
    ovo.fit(X_train, y_train)
    predict_train = ovo.predict(X_train)
    sys.stdout.write("LR(ovo) Train Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_train, predict_train)))
    predict_test = ovo.predict(X_test)
    sys.stdout.write("LR(ovo) Test  Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_test, predict_test)))
    # plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: ovo.predict(x))  # 4个特征下注释掉,前两特征
    # plot_decision_boundary(0.5, 7.5, 0, 3, lambda x: ovo.predict(x))  # 4个特征下注释掉,后两特征
    plot_data(X_train, y_train)


if __name__ == '__main__':
    iris = datasets.load_iris()
    # print(dir(iris))    # 查看data所具有的属性或方法
    # print(iris.data)    # 数据
    # print(iris.DESCR)   # 数据描述
    X = iris.data[:, :2]  # 取前2列特征sepal（平面只能展示2维）
    # X = iris.data[:, 2:4]   # petal两个特征
    # X = iris.data  # 全部4个特征
    y = iris.target  # 分类
    show_data_set(X, y, iris)
    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=777)  # 默认test比例0.25
    test1(X_train, X_test, y_train, y_test, multi_class='ovr', solver='liblinear')
    test2(X_train, X_test, y_train, y_test)
    test1(X_train, X_test, y_train, y_test, multi_class='multinomial', solver='newton-cg')
    test3(X_train, X_test, y_train, y_test)
