# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/3/14 13:14
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: Valentine'sDay.py
# @Reference: 
import matplotlib.pyplot as plt
import numpy as np
from decimal import Decimal
from decimal import getcontext
import time


def heartfunc(x, y):
    return (x ** 2 + y ** 2 - 1) ** 3 - x ** 2 * y ** 3 <= 0


def cal_pi(precision):
    getcontext().prec = precision
    return sum(1 / Decimal(16) ** k *
               (Decimal(4) / (8 * k + 1) -
                Decimal(2) / (8 * k + 4) -
                Decimal(1) / (8 * k + 5) -
                Decimal(1) / (8 * k + 6)) for k in range(precision))


def printer(text, delay=0.1314):
    """打字机效果"""
    for ch in text:
        print(ch, end='', flush=True)
        time.sleep(delay)


if __name__ == '__main__':
    n = 1314
    x = np.linspace(-2, 2, n)
    y = np.linspace(-2, 2, n)
    X, Y = np.meshgrid(x, y)
    plt.contourf(X, Y, heartfunc(X, Y), cmap=plt.cm.autumn)
    # 颜色查询 https://matplotlib.org/examples/color/colormaps_reference.html
    plt.show()

    loveInPi = str(cal_pi(1314))
    heart = ['5', '2', '0', '1', '3', '1', '4']
    iloveyou = "5201314"
    love = ""
    i, j = 0, 0
    while love != iloveyou:
        if loveInPi[i] == heart[j]:
            love += loveInPi[i]
            j += 1
        i += 1
    printer("Michael在圆周率中找到了爱的誓言：" + love + " to my love!")
