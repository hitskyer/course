# -*- coding:utf-8 -*-
# python3.7
# @Time: 2019/12/20 23:03
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: resultView.py

trainEval_maxProb = []
devEval_maxProb = []
testEval_maxProb = []
trainEval_BiHMM = []
devEval_BiHMM = []
testEval_BiHMM = []
trainEval_TriHMM = []
devEval_TriHMM = []
testEval_TriHMM = []
for i in range(18):
    filename1 = "./data/train." + str(i) + ".MaxProb.eval"
    filename2 = "./data/dev." + str(i) + ".MaxProb.eval"
    filename3 = "./data/test." + str(i) + ".MaxProb.eval"
    filename4 = "./data/train." + str(i) + ".BiHMM.eval"
    filename5 = "./data/dev." + str(i) + ".BiHMM.eval"
    filename6 = "./data/test." + str(i) + ".BiHMM.eval"
    filename7 = "./data/train." + str(i) + ".TriHMM.eval"
    filename8 = "./data/dev." + str(i) + ".TriHMM.eval"
    filename9 = "./data/test." + str(i) + ".TriHMM.eval"
    with open(filename1, 'r', encoding='utf-8') as f1:
        trainEval_maxProb.append(float(f1.readline().split()[2]))
    with open(filename2, 'r', encoding='utf-8') as f2:
        devEval_maxProb.append(float(f2.readline().split()[2]))
    with open(filename3, 'r', encoding='utf-8') as f3:
        testEval_maxProb.append(float(f3.readline().split()[2]))
    with open(filename4, 'r', encoding='utf-8') as f4:
        trainEval_BiHMM.append(float(f4.readline().split()[2]))
    with open(filename5, 'r', encoding='utf-8') as f5:
        devEval_BiHMM.append(float(f5.readline().split()[2]))
    with open(filename6, 'r', encoding='utf-8') as f6:
        testEval_BiHMM.append(float(f6.readline().split()[2]))
    with open(filename7, 'r', encoding='utf-8') as f7:
        trainEval_TriHMM.append(float(f7.readline().split()[2]))
    with open(filename8, 'r', encoding='utf-8') as f8:
        devEval_TriHMM.append(float(f8.readline().split()[2]))
    with open(filename9, 'r', encoding='utf-8') as f9:
        testEval_TriHMM.append(float(f9.readline().split()[2]))

import matplotlib.pyplot as plt

# plt.rcParams['font.family'] = 'sans-serif'	# 消除中文乱码
plt.rcParams['font.sans-serif'] = 'SimHei'	# 消除中文乱码
plt.title("最大概率模型 & BiHMM模型 & TriHMM模型 在不同大小语料下的准确率对比")
plt.xlabel("语料")
plt.ylabel("准确率")
plt.plot(trainEval_maxProb, 'r-', devEval_maxProb, 'b-', testEval_maxProb, 'g-',
	trainEval_BiHMM, 'r--', devEval_BiHMM, 'b--', testEval_BiHMM, 'g--',
	trainEval_TriHMM, 'r*', devEval_TriHMM, 'b*', testEval_TriHMM, 'g*',)
plt.legend(('train_maxProb', 'dev_maxProb', 'test_maxProb', 
	'train_BiHMM', 'dev_BiHMM', 'test_BiHMM',
	'train_TriHMM', 'dev_TriHMM', 'test_TriHMM'), loc=0)
plt.savefig('resultView.jpg')
plt.show()