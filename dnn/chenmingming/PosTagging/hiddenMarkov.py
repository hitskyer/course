# -*- coding:utf-8 -*-
# python3.7
# @Time: 2019/12/17 22:33
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: hiddenMarkov.py
import numpy as np
class HiddenMarkov:
    def forward(self, Q, V, A, B, X, PI):   # 前向算法
        N = len(Q)  # 隐藏状态数量
        M = len(X)  # 观测序列大小
        alphas = np.zeros((N, M))   # 前向概率 alphas 矩阵
        T = M   # 时刻长度，即观测序列长度
        for t in range(T):  # 遍历每个时刻，计算前向概率 alphas
            indexOfXi = V.index(X[t])   # 观测值Xi对应的V中的索引
            for i in range(N):  # 对每个状态进行遍历
                if t == 0: # 计算初值
                    alphas[i][t] = PI[t][i] * B[i][indexOfXi]   # a1(i)=πi B(i,x1)
                    print("alphas1(%d)=p%dB%d(x1)=%f" %(i,i,i,alphas[i][t]))
                else:
                    alphas[i][t] = np.dot(
                        [alpha[t-1] for alpha in alphas],   #  取的alphas的t-1列
                        [a[i] for a in A]) *B[i][indexOfXi]    # 递推公式
                    print("alpha%d(%d)=[sigma alpha%d(i)ai%d]B%d(x%d)=%f"
                        %(t, i, t-1, i, i, t, alphas[i][t]))
                    print(alphas)
        P = sum(alpha[M-1] for alpha in alphas)  # 最后一列概率的和
        print("P=%f" % P)

    def backward(self, Q, V, A, B, X, PI):  # 后向算法
        N = len(Q)  # 隐藏状态数量
        M = len(X)  # 观测序列大小
        betas = np.ones((N, M))    # 后向概率矩阵 betas
        for i in range(N):
            print("beta%d(%d)=1" %(M, i))   # 后向概率初始为1
        for t in range(M-2, -1, -1):
            indexOfXi = V.index(X[t+1])     # 观测值Xi对应的V中的索引
            for i in range(N):
                betas[i][t] = np.dot(
                    np.multiply(A[i], [b[indexOfXi] for b in B]),   # A的i行 B的Xi列 = 行
                    [beta[t+1] for beta in betas])  # 递推公式
                realT = t+1 # 真实的时间，t从1开始
                realI = i+1 # 状态标号，从1开始
                print("beta%d(%d)=[sigma A%djBj(x%d)beta%d(j)]=("
                      %(realT, realI, realI, realT+1, realT+1), end='') # end,表示以该符号空开，不换行
                for j in range(N):
                    print("%.2f*%.2f*%.2f+" %(A[i][j], B[j][indexOfXi],betas[j][t+1]), end=' ')
                print("0)=%.3f" % betas[i][t])
        print(betas)
        indexOfXi = V.index(X[0])
        P = np.dot(
            np.multiply(PI, [b[indexOfXi] for b in B]),
            [beta[0] for beta in betas])
        print("P(X|lambda)=", end=" ")
        for i in range(N):
            print("%.1f*%.1f*%.5f+" % (PI[0][i], B[i][indexOfXi], betas[i][0]), end=" ")
        print("0=%f" % P)

    def viterbi(self, Q, V, A, B, X, PI):   # 维特比算法，求最优状态序列
        N = len(Q)  # 隐藏状态数量
        M = len(X)  # 观测序列大小
        deltas = np.zeros((N, M))
        psis = np.zeros((N, M))
        Y = np.zeros((1, M))    # 最优（概率最大）状态序列
        for t in range(M):
            realT = t+1 # 真实时刻，从1开始
            indexOfXi = V.index(X[t])   # 观测值Xi对应的V中的索引
            for i in range(N):
                realI = i+1 # 状态序号，从1开始
                if t == 0:
                    deltas[i][t] = PI[0][i]* B[i][indexOfXi]    # 初始值
                    psis[i][t] = 0
                    print("delta1(%d)=pi_%d * B%d(x1)=%.2f * %.2f=%.2f" %
                          (realI, realI, realI, PI[0][i], B[i][indexOfXi], deltas[i][t]))
                    print('psis1(%d)=0' % realI)
                else:
                    deltas[i][t] = np.max(
                        np.multiply([delta[t-1] for delta in deltas],[a[i] for a in A])) \
                                   * B[i][indexOfXi]    # 递推公式
                    print("delta%d(%d)=max[delta%d(j)Aj%d]B%d(x%d)=%.2f*%.2f=%.5f"
                          % (realT, realI, realT-1, realI, realI, realT,
                             np.max(np.multiply([delta[t-1] for delta in deltas], [a[i] for a in A])),
                             B[i][indexOfXi], deltas[i][t]))
                    psis[i][t] = np.argmax(
                        np.multiply([delta[t-1] for delta in deltas],[a[i] for a in A])) + 1    # 序号从1开始
                    print("psis%d(%d)=argmax[delta%d(j)Aj%d]=%d" %
                          (realT, realI, realT-1, realI, psis[i][t]))
        print(deltas)
        print(psis)
        Y[0][M-1] = np.argmax([delta[M-1] for delta in deltas]) +1  # 序号从1开始
        print("Y%d=argmax[deltaT(i)]=%d" %(M, Y[0][M-1]))   # 最优路径的终点
        for t in range(M-2, -1, -1):    # 逆序推导前面的路径
            Y[0][t] = psis[int(Y[0][t+1])-1][t+1] # 寻找前面路径
            print("Y%d=psis%d(Y%d)=%d" %(t+1, t+2, t+2, Y[0][t]))
        print("最大概率的状态序列Y是: ", Y)

Q = [1, 2, 3]
V = ['红', '白']
A = [[0.5, 0.2, 0.3], [0.3, 0.5, 0.2], [0.2, 0.3, 0.5]]
B = [[0.5, 0.5], [0.4, 0.6], [0.7, 0.3]]
# X = ['红', '白', '红', '红', '白', '红', '白', '白']
X = ['红', '白', '红']    # 书上的例子
PI = [[0.2, 0.4, 0.4]]

hmm = HiddenMarkov()
hmm.forward(Q, V, A, B, X, PI)
hmm.backward(Q, V, A, B, X, PI)
hmm.viterbi(Q, V, A, B, X, PI)