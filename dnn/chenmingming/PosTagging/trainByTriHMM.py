# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/1/13 21:05
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: trainByTriHMM.py

def add2transDict(pp_pos, p_pos, cur_pos, transDict):
    if pp_pos in transDict:
        if p_pos in transDict[pp_pos]:
            if cur_pos in transDict[pp_pos][p_pos]:
                transDict[pp_pos][p_pos][cur_pos] += 1
            else:
                transDict[pp_pos][p_pos][cur_pos] = 1
        else:
            transDict[pp_pos][p_pos] = {cur_pos : 1}
    else:
        transDict[pp_pos] = {p_pos : {cur_pos : 1}}
def add2emitDict(cur_pos, word, emitDict):
    if cur_pos in emitDict:
        if word in emitDict[cur_pos]:
            emitDict[cur_pos][word] += 1
        else:
            emitDict[cur_pos][word] = 1
    else:
        emitDict[cur_pos] = {word : 1}

def sta(infile, transDict, emitDict):
    f = open(infile, 'r', encoding='utf-8')
    for line in f:
        infos = line.strip().split()
    wpList = [["__NONE__", "__start__"]] + [["__NONE__", "__start__"]] + [s.split("/") for s in infos] \
             + [["__NONE__", "__end__"]] + [["__NONE__", "__end__"]]
    for i in range(2, len(wpList)):
        pp_pos = wpList[i-2][1]
        p_pos = wpList[i-1][1]
        cur_pos = wpList[i][1]
        word = wpList[i][0]
        if word == "" or cur_pos == "" or p_pos == "" or pp_pos == "":
            continue
        add2transDict(pp_pos, p_pos, cur_pos, transDict)
        add2emitDict(cur_pos, word, emitDict)
    f.close()

def getPosNumList(transDict):
    pnList = []
    for pp_pos in transDict:
        num = 0
        for p_pos in transDict[pp_pos]:
            num += sum(transDict[pp_pos][p_pos].values())
        pnList.append([pp_pos, num])
    pnList.sort(key=lambda infs:(infs[1]), reverse=True)
    return pnList

def getTotalWordNum(emitDict):
    total_word_num = 0
    for pos in emitDict:
        total_word_num += sum(list(emitDict[pos].values()))
    return total_word_num

def out4model(transDict, emitDict, model_file):
    pnList = getPosNumList(transDict)

    # 状态集合
    f = open(model_file, 'w', encoding='utf-8')
    total = sum([num for pos, num in pnList])
    for pos, num in pnList:
        f.write("pos_set\t%s\t%s\t%s\n" %(pos, num, num/total))

    # 转移概率
    total_word_num = getTotalWordNum(emitDict)
    for pp_pos, num1 in pnList:
        if pp_pos == "__end__":
            continue
        tmpList = []
        smoothing_factor = num1 / total_word_num
        for p_pos, num2 in pnList:
            if (pp_pos != "__start__") and (p_pos == "__start__"):
                continue
            smoothing_factor *= num2 / total_word_num
            for cur_pos, _ in pnList:
                if cur_pos == "__start__":
                    continue
                if p_pos not in transDict[pp_pos]:
                    tmpList.append([cur_pos, smoothing_factor])
                else:
                    if cur_pos in transDict[pp_pos][p_pos]:
                        tmpList.append([cur_pos, transDict[pp_pos][p_pos][cur_pos]])
                    else:
                        tmpList.append([cur_pos, smoothing_factor])
            denominator = sum([infs[1] for infs in tmpList])
            for cur_pos, number in tmpList:
                if cur_pos == "__start__":
                    continue
                f.write("trans_prob\t%s\t%s\t%s\t%f\n" % (pp_pos, p_pos, cur_pos, math.log(number/denominator)))
    # 发射概率
    for pos, _ in pnList:
        if pos == "__start__" or pos == "__end__":
            continue
        wnList = list(emitDict[pos].items())
        wnList.sort(key=lambda infs:infs[1], reverse=True)
        num = sum([num for _, num in wnList])
        smoothing_factor = num/total_word_num
        tmpList = []
        for word, n in wnList:
            tmpList.append([word, n+smoothing_factor])
        tmpList.append(["__NEW__", smoothing_factor])

        denominator = sum([infs[1] for infs in tmpList])
        for word, number in tmpList:
            f.write("emit_prob\t%s\t%s\t%f\n" % (pos, word, math.log(number/denominator)))
    f.close()

import sys
import math
try:
    infile = sys.argv[1]
    model_file = sys.argv[2]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " infile model_file\n")
    sys.exit(-1)
transDict = {}
emitDict = {}

sta(infile, transDict, emitDict)
out4model(transDict, emitDict, model_file)