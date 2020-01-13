# -*- coding:utf-8 -*-
# Python 3.7
# @Time: 2020/1/13 21:05
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: trainByTriHMM.py

import sys
import math
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
        transDict[pp_pos] = {pp_pos : {cur_pos : 1}}
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
    wpList = [["__NONE__", "__start__"]] + [s.split("/") for s in infos] + [["__NONE__", "__end__"]]
    for i in range(1, len(wpList)):
        pp_pos = p_pos = ""
        if i == 1:
            pp_pos = p_pos = wpList[i-1][1]
        else:
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
    for pp_pos, dict in transDict.items():

        num = sum(transDict[pp_pos])

def out4model(transDict, emitDict, model_file):
    pnList = getPosNumList(transDict)
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
if __name__ == '__main__':
    pass
