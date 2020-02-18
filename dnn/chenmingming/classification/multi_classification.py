'''
	遇到不熟悉的库、模块、类、函数，可以依次：
	1）百度（google确实靠谱一些），如"matplotlib.pyplot"，会有不错的博客供学习参考
	2）"终端-->python-->import xx-->help(xx.yy)"，一开始的时候这么做没啥用，但作为资深工程师是必备技能
	3）试着修改一些参数，观察其输出的变化，在后面的程序中，会不断的演示这种办法
'''
# written by hitskyer, I just wanna say thank you !
# modified by Michael Ming on 2020.2.18
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


def show_data_set(X, y):
    plt.scatter(X[y == 0, 0], X[y == 0, 1], c='r')
    plt.scatter(X[y == 1, 0], X[y == 1, 1], c='b')
    plt.scatter(X[y == 2, 0], X[y == 2, 1], c='g')
    plt.show()


def plot_decision_boundary(x_min, x_max, y_min, y_max, pred_func):
    h = 0.01
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    Z = pred_func(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)


def test1(X_train, X_test, y_train, y_test, multi_class='ovr', solver='liblinear'):
    log_reg = LogisticRegression(multi_class=multi_class, solver=solver)
    log_reg.fit(X_train, y_train)
    predict_train = log_reg.predict(X_train)
    sys.stdout.write("LR(multi_class = %s, solver = %s) Train Accuracy : %.4g\n" % (
        multi_class, solver, metrics.accuracy_score(y_train, predict_train)))
    predict_test = log_reg.predict(X_test)
    sys.stdout.write("LR(multi_class = %s, solver = %s) Test  Accuracy : %.4g\n" % (
        multi_class, solver, metrics.accuracy_score(y_test, predict_test)))
    plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: log_reg.predict(x))
    plt.scatter(X_train[y_train == 0, 0], X_train[y_train == 0, 1], color='r')
    plt.scatter(X_train[y_train == 1, 0], X_train[y_train == 1, 1], color='b')
    plt.scatter(X_train[y_train == 2, 0], X_train[y_train == 2, 1], color='g')
    plt.show()


def test2(X_train, X_test, y_train, y_test):
    log_reg = LogisticRegression(solver='liblinear')
    ovr = OneVsRestClassifier(log_reg)
    ovr.fit(X_train, y_train)
    predict_train = ovr.predict(X_train)
    sys.stdout.write("LR(ovr) Train Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_train, predict_train)))
    predict_test = ovr.predict(X_test)
    sys.stdout.write("LR(ovr) Test  Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_test, predict_test)))
    plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: ovr.predict(x))
    plt.scatter(X_train[y_train == 0, 0], X_train[y_train == 0, 1], color='r')
    plt.scatter(X_train[y_train == 1, 0], X_train[y_train == 1, 1], color='b')
    plt.scatter(X_train[y_train == 2, 0], X_train[y_train == 2, 1], color='g')
    plt.show()


def test3(X_train, X_test, y_train, y_test):
    log_reg = LogisticRegression(multi_class='multinomial', solver='newton-cg')
    ovo = OneVsOneClassifier(log_reg)
    ovo.fit(X_train, y_train)
    predict_train = ovo.predict(X_train)
    sys.stdout.write("LR(ovo) Train Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_train, predict_train)))
    predict_test = ovo.predict(X_test)
    sys.stdout.write("LR(ovo) Test  Accuracy : %.4g\n" % (
        metrics.accuracy_score(y_test, predict_test)))
    plot_decision_boundary(4, 8.5, 1.5, 4.5, lambda x: ovo.predict(x))
    plt.scatter(X_train[y_train == 0, 0], X_train[y_train == 0, 1], color='r')
    plt.scatter(X_train[y_train == 1, 0], X_train[y_train == 1, 1], color='b')
    plt.scatter(X_train[y_train == 2, 0], X_train[y_train == 2, 1], color='g')
    plt.show()


if __name__ == '__main__':
    iris = datasets.load_iris()
    X = iris.data[:, :2]
    y = iris.target
    show_data_set(X, y)
    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=777)
    test1(X_train, X_test, y_train, y_test, multi_class='ovr', solver='liblinear')
    test2(X_train, X_test, y_train, y_test)
    test1(X_train, X_test, y_train, y_test, multi_class='multinomial', solver='newton-cg')
    test3(X_train, X_test, y_train, y_test)
