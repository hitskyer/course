'''
	遇到不熟悉的库、模块、类、函数，可以依次：
	1）百度（google确实靠谱一些），如"matplotlib.pyplot"，会有不错的博客供学习参考
	2）"终端-->python-->import xx-->help(xx.yy)"，一开始的时候这么做没啥用，但作为资深工程师是必备技能
	3）试着修改一些参数，观察其输出的变化，在后面的程序中，会不断的演示这种办法
'''
# written by hitskyer
# modified by Michael Ming on 2020.2.12
import sys
import numpy as np
import matplotlib.pyplot as plt
# sklearn 中文文档 https://sklearn.apachecn.org/docs/0.21.3/
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn import metrics


def get_parabolic_curve_data_set(n):
    # 设置随机数的种子，以保证每回运行程序的随机结果一致
    np.random.seed(520)  # 520 可以随便写 Seed must be between 0 and 2**32 - 1
    # 随机生成200个样本，每个样本两维特征
    X = np.random.normal(0, 1, size=(n, 2))  # 正态分布，中心0，标准差1
    # 分类面（线）是y=-x^2+1.5，开口向下的抛物线，口内为1类，口外为0类
    y = np.array(X[:, 0] ** 2 + X[:, 1] < 1.5, dtype=int)  # 满足关系的为1，否则为0
    # 加入10%的噪声数据
    for _ in range(n // 10):  # //为整除
        y[np.random.randint(n)] = 1
    return X, y


def show_data_set(X, y):
    plt.scatter(X[y == 0, 0], X[y == 0, 1], c='r')
    # 散点图，分量1,为y==0的行的0列，分量2，y==0的行的1列，c表示颜色
    plt.scatter(X[y == 1, 0], X[y == 1, 1], c='b')
    plt.show()


def PolynomialLogisticRegression(degree=2, C=1.0, penalty='l2'):
    # 对输入特征依次做多项式转换、归一化转换、类别预测
    return Pipeline([
        # Pipeline 可以把多个评估器链接成一个。例如特征选择、标准化和分类
        # 以多项式的方式对原始特征做转换，degree次多项式
        ('poly', PolynomialFeatures(degree=degree)),
        # 对多项式转换后的特征向量做归一化处理，例如（数据-均值）/标准差
        ('std_scaler', StandardScaler()),
        # 用转换后的特征向量做预测，penalty是正则化约束，C正则化强度，值越小，强度大
        # solver 不同的求解器擅长的规模类型差异
        # 正则化 https://blog.csdn.net/zouxy09/article/details/24971995/
        ('log_reg', LogisticRegression(C=C, penalty=penalty, solver="liblinear"))
    ])


def plot_decision_boundary(x_min, x_max, y_min, y_max, pred_func):
    h = 0.01
    # 产生网格
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    # ravel将矩阵展平，np_c[a,b]将a,b按列拼在一起
    Z = pred_func(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)  # 填充等高线
    # 等高线参考 https://blog.csdn.net/lens___/article/details/83960810


def test(X_train, X_test, y_train, y_test, degree=2, C=1.0, penalty='l2'):
    poly_log_reg = PolynomialLogisticRegression(degree=degree, C=C, penalty=penalty)
    # 训练模型
    poly_log_reg.fit(X_train, y_train)
    # 在训练数据上做测试
    predict_train = poly_log_reg.predict(X_train)
    sys.stdout.write("LR(degree = %d, C=%.2f, penalty=%s) Train Accuracy : %.4g\n" % (
        degree, C, penalty, metrics.accuracy_score(y_train, predict_train)))
    # 在测试数据上做测试
    predict_test = poly_log_reg.predict(X_test)
    sys.stdout.write("LR(degree = %d, C=%.2f, penalty=%s) Test Accuracy : %.4g\n" % (
        degree, C, penalty, metrics.accuracy_score(y_test, predict_test)))
    print("--------------------------------------")
    # 展示分类边界
    plot_decision_boundary(-4, 4, -4, 4, lambda x: poly_log_reg.predict(x))
    plt.scatter(X_train[y_train == 0, 0], X_train[y_train == 0, 1], color='r')
    plt.scatter(X_train[y_train == 1, 0], X_train[y_train == 1, 1], color='b')
    plt.show()


if __name__ == '__main__':
    # 随机生成200个拥有2维实数特征 且 分类面（线）为y=-x^2+1.5(换言之，x2=-x1^2+1.5)的语料
    X, y = get_parabolic_curve_data_set(200)
    # 预留30%作为测试语料
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=0)
    # 展示所生成的数据
    show_data_set(X, y)
    # 测试不同的超参数组合
    print("准确率高，比较恰当的模型")
    test(X_train, X_test, y_train, y_test, degree=2, C=1.0, penalty='l2')
    print("准确率高，且恰当的模型")
    test(X_train, X_test, y_train, y_test, degree=2, C=0.1, penalty='l2')
    print("准确率高，但是过拟合的模型")
    test(X_train, X_test, y_train, y_test, degree=20, C=1.0, penalty='l2')
    print("准确率低，且过拟合的模型")
    test(X_train, X_test, y_train, y_test, degree=20, C=0.1, penalty='l2')
    print("准确率高，且恰当的模型")
    test(X_train, X_test, y_train, y_test, degree=20, C=0.05, penalty='l1')
