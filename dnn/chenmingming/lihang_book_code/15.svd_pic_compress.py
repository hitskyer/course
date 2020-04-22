# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/4/21 23:38
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 15.svd_pic_compress.py
# @Reference: https://blog.csdn.net/weixin_44344462/article/details/89401727

import numpy as np
import matplotlib.pyplot as plt


def zip_img_by_svd(img, plotId, rate=0.8):
    zip_img = np.zeros(img.shape)
    u_shape = 0
    sigma_shape = 0
    vT_shape = 0

    for chanel in range(3):  # 3个图层
        u, sigma, v = np.linalg.svd(img[:, :, chanel])  # numpy svd函数
        sigma_i = 0
        temp = 0

        while (temp / np.sum(sigma)) < rate:  # 选取的奇异值和需要达到设定的权重
            temp += sigma[sigma_i]
            sigma_i += 1
        SigmaMat = np.zeros((sigma_i, sigma_i))  # 选取了sigma_i 最大的奇异值
        for i in range(sigma_i):
            SigmaMat[i, i] = sigma[i]  # 将奇异值填充到Sigma对角矩阵
        zip_img[:, :, chanel] = u[:, 0:sigma_i].dot(SigmaMat).dot(v[0:sigma_i, :])
        # 将分解得到的3个矩阵相乘，得到压缩后的近似矩阵
        u_shape = u[:, 0:sigma_i].shape
        sigma_shape = SigmaMat.shape
        vT_shape = v[0:sigma_i, :].shape

    for i in range(3):  # 对三个通道的矩阵数值进行归一化处理
        MAX = np.max(zip_img[:, :, i])
        MIN = np.min(zip_img[:, :, i])
        zip_img[:, :, i] = (zip_img[:, :, i] - MIN) / (MAX - MIN)

    zip_img = np.round(zip_img * 255).astype("uint8")  # 不乘255图片是黑的，数据类型uint8
    plt.imsave("zip_svd_img.jpg", zip_img)  # 保存压缩后的图片
    zip_rate = (img.size - 3 * (
            u_shape[0] * u_shape[1] + sigma_shape[0] * sigma_shape[1] + vT_shape[0] * vT_shape[1])) / (zip_img.size)

    f = plt.subplot(3, 3, plotId)
    f.imshow(zip_img)
    f.set_title("SVD压缩率 %.4f,奇异值数量：%d" % (zip_rate, sigma_i))

    print("设置的压缩率：", rate)
    print("使用的奇异值数量：", sigma_i)
    print("原始图片大小：", img.shape)
    print("压缩后用到的矩阵大小：3x({}+{}+{})".format(u_shape, sigma_shape, vT_shape))
    print("压缩率为：", zip_rate)


if __name__ == '__main__':
    imgfile = "svd_img.jpg"
    plt.figure(figsize=(12, 12))
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
    img = plt.imread(imgfile)
    f1 = plt.subplot(331)  # 绘制子图，3行3列，3*3个子图，现在画第1幅
    f1.imshow(img)
    f1.set_title("原始图片")
    for i in range(8):  # 再画8个子图
        rate = (i + 1) / 10.0  # 压缩率 10% - 80%
        zip_img_by_svd(img, i + 2, rate)
    plt.suptitle('图片SVD效果对比', fontsize=17, y=0.02)  # y偏移距离
    plt.show()
