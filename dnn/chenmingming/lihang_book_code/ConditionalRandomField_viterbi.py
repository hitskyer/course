# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/2/6 20:42
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: ConditionalRandomField_viterbi.py
import numpy as np


def viterbi(s, t):
    time = len(s)
    y_state = [0, 1]  # 表示状态 1，2
    m = len(y_state)  # 状态数量
    y_star = np.zeros((time))  # 最优路径
    delta = np.zeros((time, m))  # 最大概率矩阵(可以DP状态压缩)
    psi = np.zeros((time, m), dtype=np.int32)  # 记录最优路径

    # 初始化delta
    delta[0][0] = s[0][0]
    delta[0][1] = s[0][1]

    # 递推
    for i in range(1, time):
        for j in range(m):
            temp = [delta[i - 1][k] + s[i][j] + t[i][k][j] for k in range(m)]
            # i表示时间，从k状态转移到j状态
            psi[i][j] = np.argmax(temp)  # 返回最大值的下标
            delta[i][j] = temp[psi[i][j]]  # 最大的概率填入

    # 终止
    y_star[time - 1] = np.argmax(delta[time - 1])

    # 返回
    for i in range(time - 2, -1, -1):
        y_star[i] = psi[i + 1][int(y_star[i + 1])]
    return y_star, delta, psi


def crf_viterbi():
    # 状态特征
    s = np.array([[1, 0.5],
                  [0.8, 0.5],
                  [0.8, 0.5]])
    # 转移特征
    t = np.array([[[0, 0],
                   [0, 0]],  # 辅助，使得后面序号方便
                  [[0.6, 1],
                   [1, 0]],
                  [[0, 1],
                   [1, 0.2]]])
    y_star, delta, psi = viterbi(s, t)

    print("最优路径:", y_star + 1)  # +1表示所有的都+1，序号从1开始
    print("概率矩阵：\n", delta)
    psi[1:] += 1  # 序号从1开始
    print("Psi路径：\n", psi)


if __name__ == '__main__':
    crf_viterbi()
