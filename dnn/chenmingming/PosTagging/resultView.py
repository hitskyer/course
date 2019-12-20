# -*- coding:utf-8 -*-
# python3.7
# @Time: 2019/12/20 23:03
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: resultView.py

trainEval = []
devEval = []
testEval = []
for i in range(18):
    filename1 = "train." + str(i) + ".MaxProb.eval"
    filename2 = "dev." + str(i) + ".MaxProb.eval"
    filename3 = "test." + str(i) + ".MaxProb.eval"
    with open(filename1, 'r', encoding='utf-8') as f1:
        trainEval.append(float(f1.readline().split()[2]))
    with open(filename2, 'r', encoding='utf-8') as f2:
        devEval.append(float(f2.readline().split()[2]))
    with open(filename3, 'r', encoding='utf-8') as f3:
        testEval.append(float(f3.readline().split()[2]))

import matplotlib.pyplot as plt
plt.plot(trainEval, 'r--', devEval, 'bs', testEval, 'g^')
plt.show()