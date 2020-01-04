# 输入：词性1，词性2，概率
# 输出：转移字典概率
def add2transDict(pos1, pos2, prob, transDict):
    if pos1 in transDict:
        transDict[pos1][pos2] = prob
    else:
        transDict[pos1] = {pos2: prob}


# 输入：词性、单词、概率
# 输出：发射概率
def add2emitDict(pos, word, prob, emitDict):
    if pos in emitDict:
        emitDict[pos][word] = prob
    else:
        emitDict[pos] = {word: prob}


# 输入: 输入文件，不应该写infile，应该写model_file。！！！！

def loadModel(infile, gPosList, transDict, emitDict):
    fdi = open(infile)  # 打开输入文件
    for line in fdi:    # 逐行进行
        infs = line.strip().split()    # 去掉首位空格，并由空格处切分
        if infs[0] == "pos_set":       # 没看明白
            pos = infs[1]
            if pos != "__start__" and pos != "__end__":
                gPosList.append(pos)
        if infs[0] == "trans_prob":
            pos1 = infs[1]
            pos2 = infs[2]
            prob = float(infs[3])
            add2transDict(pos1, pos2, prob, transDict)
        if infs[0] == "emit_prob":
            pos = infs[1]
            word = infs[2]
            prob = float(infs[3])
            add2emitDict(pos, word, prob, emitDict)
    fdi.close()


def getWords(infs):
    return [s.split("/")[0] for s in infs]


def getEmitProb(emitDict, pos, word):
    if word in emitDict[pos]:
        return emitDict[pos][word]
    else:
        return emitDict[pos]["__NEW__"]


def predict4one(words, gPosList, transDict, emitDict, results):
    if words == []:
        return
    prePosDictList = []
    for i in range(len(words)):
        prePosDict = {}
        for pos in gPosList:
            if i == 0:
                trans_prob = transDict["__start__"][pos]
                emit_prob = getEmitProb(emitDict, pos, words[i])
                total_prob = trans_prob + emit_prob
                prePosDict[pos] = [total_prob, "__start__"]
            else:
                emit_prob = getEmitProb(emitDict, pos, words[i])
                max_total_prob = -10000000.0
                max_pre_pos = ""
                for pre_pos in prePosDictList[i - 1]:
                    pre_prob = prePosDictList[i - 1][pre_pos][0]
                    trans_prob = transDict[pre_pos][pos]
                    total_prob = pre_prob + trans_prob + emit_prob
                    if max_pre_pos == "" or total_prob > max_total_prob:
                        max_total_prob = total_prob
                        max_pre_pos = pre_pos
                prePosDict[pos] = [max_total_prob, max_pre_pos]
        prePosDictList.append(prePosDict)
    # indx = -1
    # for prePosDict in prePosDictList:
    #	tmpList = []
    #	for pos in prePosDict:
    #		tmpList.append(prePosDict[pos]+[pos])
    #	tmpList.sort(reverse=True)
    #	indx += 1
    #	print("indx =", indx)
    #	for prob, pre_pos, pos in tmpList:
    #		print("%s\t%s\t%f" % (pre_pos, pos, prob))
    #	print("--------------------------------------")
    # sys.exit(0)
    max_total_prob = -10000000.0
    max_pre_pos = ""
    for pre_pos in prePosDictList[len(prePosDictList) - 1]:
        pre_prob = prePosDictList[len(prePosDictList) - 1][pre_pos][0]
        trans_prob = transDict[pre_pos]["__end__"]
        total_prob = pre_prob + trans_prob
        if max_pre_pos == "" or total_prob > max_total_prob:
            max_total_prob = total_prob
            max_pre_pos = pre_pos
    posList = [max_pre_pos]
    indx = len(prePosDictList) - 1
    max_pre_pos = prePosDictList[indx][max_pre_pos][1]
    indx -= 1
    while indx >= 0:
        posList.append(max_pre_pos)
        max_pre_pos = prePosDictList[indx][max_pre_pos][1]
        indx -= 1
    if len(posList) == len(words):
        posList.reverse()
        for i in range(len(posList)):
            results.append(words[i] + "/" + posList[i])
    else:
        sys.stderr.write("error : the number of pos is not equal to the number of words!\n")
        sys.exit(-1)


def predict(infile, gPosList, transDict, emitDict, outfile):
    fdi = open(infile)
    fdo = open(outfile, "w")
    for line in fdi:
        infs = line.strip().split()
        # 盖住答案，闭卷考试
        words = getWords(infs)
        results = []
        predict4one(words, gPosList, transDict, emitDict, results)
        fdo.write(" ".join(results) + "\n")
    fdo.close()
    fdi.close()


import sys
import math

try:
    infile = sys.argv[1]  # train
    model_file = sys.argv[2]  # model
    outfile = sys.argv[3]    # predict
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " infile model_file outfile\n")
    sys.exit(-1)

# 词性列表
gPosList = []
# 转移概率A+π
transDict = {}
# 发射概率
emitDict = {}

# 输入：model_file
loadModel(model_file, gPosList, transDict, emitDict)

# 输入：文件train，词性列表，转移字典，发射字典
# 输出：文件train.x.BiHMM.predict
predict(infile, gPosList, transDict, emitDict, outfile)
