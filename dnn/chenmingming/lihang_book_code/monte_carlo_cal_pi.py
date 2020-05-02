# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/5/2 9:02
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: monte_carlo_cal_pi.py
# @Reference: 
import random
import matplotlib.pyplot as plt

simulations = [100, 1000, 10000]
plt.figure()
plt.rcParams['font.sans-serif'] = 'SimHei'  # 消除中文乱码
plotid = 1
color = ['r', 'b']
for i in range(len(simulations)):
    f = plt.subplot(1, 3, plotid)
    plotid += 1
    count = 0
    t = simulations[i]
    time = simulations[i]
    while time > 0:
        time -= 1
        x = random.random()  # [0,1)
        y = random.random()  # [0,1)
        val = x ** 2 + y ** 2
        pos = 1
        if (val < 1):
            pos = 0
            count += 1
        f.scatter(x, y, c=color[pos])
    pi = 4 * count / t
    f.set_title("模拟次数{},pi的值{:.4f}".format(t, pi))
plt.suptitle("蒙特卡罗法近似求解圆周率pi")
plt.show()
