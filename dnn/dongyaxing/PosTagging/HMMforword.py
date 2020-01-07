# coding=utf-8
import numpy as np


class HiddenMarkov:
    def forward(self, Q, V, A, B, X, PI):
        N = len(Q)  # 状态集合的长度（几个盒子）
        M = len(X)  # 观测序列的长度（实验进行了几次）
        alphas = np.zeros((N, M))  # 前向概率矩阵 alphas 矩阵
        T = M  # 时刻长度，即观测序列的长度
        for t in range(T):  # 第 t 次
            indexOfXi = V.index(X[t])  # 观测值Xi 对应的 V中的索引，即是白球还是红球
            for i in range(N):  # 对每个状态(盒子)进行遍历
                if t == 0:  # 计算初值
                    alphas[i][t] = PI[t][i] * B[i][indexOfXi]  # 填充alphas的第0列，为第一次的概率计算
                    print("alphas_1(%d) = p%d * B%d(x1) = %f" % (i, i, i, alphas[i][t]))
                else:
                    # 计算两个数组的点积(行*列，求和)
                    alphas[i][t] = np.dot([alpha[t - 1] for alpha in alphas], [a[i] for a in A]) * B[i][indexOfXi]
                    print("alpha_%d(%d) = [sigma(i=0,..,%d ) alpha_%d(i)*ai%d] * B%d(x%d) = %f" % (
                    t, i, len(A), t - 1, i, i, t, alphas[i][t]))
            print(alphas)

        P = sum(alpha[M - 1] for alpha in alphas)  # alphas的最后一列求和
        print("P = %f" % P)

    def viterbi(self, Q, V, A, B, X, PI):
        N = len(Q)  # 状态集合的长度（几个盒子）
        M = len(X)  # 观测序列的长度（实验进行了几次）
        deltas = np.zeros((N, M))  # 前向概率矩阵 alphas 矩阵
        psis = np.zeros((N, M))  # 记录路径, 存储的每一次概率最大的值盒子
        Y = np.zeros((1, M))  # 最优(概率最大)的状态序列
        for t in range(M):  # 第t次
            realT = t + 1  # 状态号从1开始
            indexofXi = V.index(X[t])
            for i in range(N):  # 第 i 个盒子
                realI = i + 1   # 盒子号从1开始
                if t == 0:    # 第一次取球
                    deltas[i][0] = PI[0][i] * B[i][indexofXi]    # 初始值
                    psis[i][0] = 0  # 第一次初始psis[i][0]为0
                    print("delta_1(%d) = pi_%d * B%d(x1) = %.2f * %.2f = %.2f" % (realI, realI, realI, PI[0][i], B[i][indexofXi], deltas[i][0]))
                    print('psis_1(%d) = 0' % realT)    # 第一次没有决定从哪个盒子取，所以先定为0
                    print()
                else:
                    deltas[i][t] = np.max(
                        np.multiply([delta[t-1] for delta in deltas], [a[i] for a in A])
                    ) * B[i][indexofXi]
                    temp = np.max(np.multiply([delta[t-1] for delta in deltas], [a[i] for a in A]))  # 保存最大值
                    print("delta_%d(%d) = max[delta_%d(j) * Aj%d] * B%d(x%d) = %.2f * %.2f = %.5f" % (realT, realI, t, realI, realI, realT, temp, B[i][indexofXi], deltas[i][t]))
                    psis[i][t] = np.argmax(np.multiply([delta[t-1] for delta in deltas], [a[i] for a in A])) + 1
                    print("psis_%d(%d) = argmax[delta_%d(j)Aj%d] = %d" % (realT, realI, t, realI, psis[i][t]))
                    print()
        print("deltas: \n", deltas)
        print("psis:\n", psis)
        print()
        # 最后一列的最大值的索引
        Y[0][M-1] = np.argmax([delta[M-1] for delta in deltas]) + 1  # 序号从1开始， 沿着给定轴，返回最大值的索引。
        print("Y[0][M-1]: \n", Y[0][M-1])
        print("Y%d=argmax[deltaT(i)]=%d" % (M, Y[0][M-1]))  # 最优路径的终点
        print()
        for t in range(M-2, -1, -1):  # 逆向推导最优路径， 倒着扫描，间隔为1。填充Y时，也倒着填充
            Y[0][t] = psis[int(Y[0][t+1]) - 1][t+1]    # psis的索引
            print("Y%d = psis%d(Y%d) = %d" % (t+1, t+2, t+2, Y[0][t]))
            print()
        print("最大概率的状态序列 Y 是：", Y)





Q = [1, 2, 3]
V = ['红', '白']
A = [[0.5, 0.2, 0.3], [0.3, 0.5, 0.2], [0.2, 0.3, 0.5]]
B = [[0.5, 0.5], [0.4, 0.6], [0.7, 0.3]]
X = ['红', '白', '红']
PI = [[0.2, 0.4, 0.4]]  # 声明为列数组，1行3列

hmm = HiddenMarkov()
# hmm.forward(Q, V, A, B, X, PI)
hmm.viterbi(Q, V, A, B, X, PI)


