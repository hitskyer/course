本文为[《机器学习实战：基于Scikit-Learn和TensorFlow》](https://book.douban.com/subject/30317874/)的读书笔记。



## 1. 项目介绍

利用加州普查数据，建立一个加州房价模型。

数据包含每个街区组的人口、收入中位数、房价中位数等指标。

利用这个数据进行学习，然后根据其它指标，预测任何街区的的房价中位数。



## 2. 性能指标

 均方根误差（RMSE）:

$$\operatorname{RMSE}(\mathbf{X}, h)=\sqrt{\frac{1}{m} \sum\limits_{i=1}^{m}\left(h\left(\mathbf{x}^{(i)}\right)-y^{(i)}\right)^{2}}$$

平均绝对误差（MAE）

 $$\operatorname{MAE}(\mathbf{X}, h)=\frac{1}{m} \sum\limits_{i=1}^{m}\left|h\left(\mathbf{x}^{(i)}\right)-y^{(i)}\right|$$

范数的**指数越高**，就**越关注大的值**而忽略小的值。这就是为什么 RMSE 比 MAE 对异常值更敏感。但是当异常值是指数分布的（类似正态曲线），RMSE 就会表现很好。

## 3. 确定任务类型

是分类？（房子便宜、中等、昂贵）

是回归？（预测房子价格），本任务是回归。