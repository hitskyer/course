# -*- coding:utf-8 -*-
# python3.7
# @Time: 2019/12/20 23:03
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: resultView.py

trainEval = []
devEval = []
testEval = []
for i in range(2):
    filename1 = "./data/train." + str(i) + ".MaxProb.eval"
    filename2 = "./data/dev." + str(i) + ".MaxProb.eval"
    filename3 = "./data/test." + str(i) + ".MaxProb.eval"
    with open(filename1, 'r', encoding='utf-8') as f1:
        trainEval.append(float(f1.readline().split()[2]))
    with open(filename2, 'r', encoding='utf-8') as f2:
        devEval.append(float(f2.readline().split()[2]))
    with open(filename3, 'r', encoding='utf-8') as f3:
        testEval.append(float(f3.readline().split()[2]))

import matplotlib.pyplot as plt
plt.title("不同大小语料下的结果对比")
plt.xlabel("语料")
plt.ylabel("准确率")
plt.plot(trainEval, 'r-', devEval, 'b-', testEval, 'g-')
plt.show()