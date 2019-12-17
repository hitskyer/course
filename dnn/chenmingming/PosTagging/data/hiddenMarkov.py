# -*- coding:utf-8 -*-
# python3.7
# @Time: 2019/12/17 22:33
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: hiddenMarkov.py

class HiddenMarkov:
    def forward(self, Q, V, A, B, O, PI):   # 前向算法
        N = len(Q)  # 隐藏状态数量