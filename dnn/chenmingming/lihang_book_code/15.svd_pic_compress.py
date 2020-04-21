# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/4/21 23:38
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: 15.svd_pic_compress.py
# @Reference: https://blog.csdn.net/weixin_44344462/article/details/89401727

import numpy as np
import matplotlib.pyplot as plt


def zip_img_by_svd(img, rate=0.8):
    plt.figure(figsize=(10, 10))
    plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
    # plt.title()
    f1 = plt.subplot(121)
    f1.imshow(img)
    f1.set_title("原始图片")
    zip_img = np.zeros(img.shape)
    u_shape = 0
    sigma_shape = 0
    vT_shape = 0
    for chanel in range(3):
        u, sigma, v = np.linalg.svd(img[:, :, chanel])
        sigma_i = 0
        temp = 0

        while (temp / np.sum(sigma)) < rate:
            temp += sigma[sigma_i]
            sigma_i += 1
        SigmaMat = np.zeros((sigma_i, sigma_i))
        for i in range(sigma_i):
            SigmaMat[i, i] = sigma[i]
        zip_img[:, :, chanel] = u[:, 0:sigma_i].dot(SigmaMat).dot(v[0:sigma_i, :])
        u_shape = u[:, 0:sigma_i].shape
        sigma_shape = SigmaMat.shape
        vT_shape = v[0:sigma_i, :].shape

    for i in range(3):
        MAX = np.max(zip_img[:, :, i])
        MIN = np.min(zip_img[:, :, i])
        zip_img[:, :, i] = (zip_img[:, :, i] - MIN) / (MAX - MIN)
    zip_img = np.round(zip_img * 255).astype("uint8")  # 不乘255是黑的，数据类型uint8
    plt.imsave("zip_svd_img.jpg", zip_img)
    # plt.figure(figsize=(10, 10))
    # plt.imshow(zip_img)
    # plt.title("压缩图片")
    f2 = plt.subplot(122)
    f2.imshow(zip_img)
    f2.set_title("压缩图片")
    plt.suptitle('对比')
    plt.show()

    zip_rate = (img.size - 3 * (
            u_shape[0] * u_shape[1] + sigma_shape[0] * sigma_shape[1] + vT_shape[0] * vT_shape[1])) / (zip_img.size)
    print("设置的压缩率：", rate)
    print("使用的奇异值数量：", sigma_i)
    print("原始图片大小：", img.shape)
    print("压缩后用到的矩阵大小：3x({}+{}+{})".format(u_shape, sigma_shape, vT_shape))
    print("压缩率为：", zip_rate)


if __name__ == '__main__':
    imgfile = "svd_img.jpg"
    img = plt.imread(imgfile)

    zip_img_by_svd(img, rate=0.8)
