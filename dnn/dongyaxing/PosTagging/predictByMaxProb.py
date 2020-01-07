# 最大概率训练
# model_file 中，有4列，分别是：单词，次数，词性，概率
# 输出 单词-词性 的对照表
def loadModel(model_file, word2posDict):
    fdi = open(model_file)  # 打开模型文件
    # 逐行处理
    for line in fdi:
        infs = line.strip().split()  # 删掉首尾空格，然后对句子以空格进行分割
        if len(infs) == 4:    # 单词，次数，词性，概率
            word = infs[0]
            pos = infs[2]
            word2posDict[word] = pos  # 组建 单词-词性 的字典
        else:
            sys.stderr.write("format error in " + model_file + "\n")
            sys.stderr.write(line)
            sys.exit(-1)
    fdi.close()


# 返回word列表
def getWords(infs):
    return [s.split("/")[0] for s in infs]


# 输出测试文件，单词-词性，
# 输出文件
def predict(infile, word2posDict, outfile):
    fdi = open(infile)
    fdo = open(outfile, "w")    # 写入这个文件
    for line in fdi:
        infs = line.strip().split()    # infs 为 列表
        # 盖住答案，闭卷考试
        words = getWords(infs)    # 对infs 的列表，只返回列表中的单词，放在words列表中
        results = []
        for word in words:
            if word in word2posDict:    # 如果这个词在上面的字典里，就加入词性
                results.append(word + "/" + word2posDict[word])
            else:
                results.append(word + "/unknown")    # 这个单词没有遇见过，词性就不知道
        fdo.write(" ".join(results) + "\n")    # 把统计结果写入文件
    fdo.close()
    fdi.close()


import sys

try:
    infile = sys.argv[1]
    model_file = sys.argv[2]
    outfile = sys.argv[3]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " infile model_file outfile\n")
    sys.exit(-1)

# 声明一个字典
word2posDict = {}
# 加载一个model, 文件，此文件中写好了 word-num-pos-prob 的对照关系，处理一下填充字典
loadModel(model_file, word2posDict)

# 预测输入文件中，每个单词的词性
predict(infile, word2posDict, outfile)
