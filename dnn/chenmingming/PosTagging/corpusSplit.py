def corpusSplit(infile, sentenceList):  # 将语料分割为句子
    fdi = open(infile, 'r', encoding='utf-8')  # 打开原始数据
    fullStopDict = {"。": 1, "；": 1, "？": 1, "！": 1}
    for line in fdi:
        text = line.strip()  # 删除左右空格
        if text == "":
            continue
        else:
            infs = text.split() # 将所有单词分开
            sentence = []
            flag = True
            for s in infs:
                w_p = s.split("/")  # 返回分割后的字符串列表
                if len(w_p) == 2:
                    word = w_p[0]
                    if word.startswith("["):
                        word = word.replace("[", "")  # 以[开始的，删除[
                    pos = w_p[1]
                    pos = re.sub("].*", "", pos)  # re正则表达式模块替换掉后面的]
                    if word == "" or pos == "":
                        flag = False
                    else:
                        sentence.append(word + "/" + pos)
                    if word in fullStopDict:
                        if flag == True:
                            sentenceList.append(" ".join(sentence)) # 序列中元素用空格隔开
                        flag = True
                        sentence = []
                else:
                    flag = False
            if sentence != [] and flag == True:
                sentenceList.append(" ".join(sentence))
    fdi.close()


def out(sentenceList, out_dir): # 将句子分别写到20个文件中，18个训练文件
    fdo_train_list = []
    for i in range(18):
        fdo_train = open(out_dir + "/train.%d" % (i), "w", encoding='utf-8')
        fdo_train_list.append(fdo_train)
    fdo_dev = open(out_dir + "/dev.txt", "w", encoding='utf-8')
    fdo_test = open(out_dir + "/test.txt", "w", encoding='utf-8')
    for sindx in range(len(sentenceList)):
        if sindx % 20 < 18:
            for i in range(sindx % 20, 18): # 后面的文件语料多
                fdo_train_list[i].write(sentenceList[sindx] + "\n")
        elif sindx % 20 == 18:
            fdo_dev.write(sentenceList[sindx] + "\n")   # 1个开发集
        elif sindx % 20 == 19:
            fdo_test.write(sentenceList[sindx] + "\n")  # 1个测试集
    for i in range(18):
        fdo_train_list[i].close()   # 文件有开，有关
    fdo_dev.close()
    fdo_test.close()


import sys
import re
import random
'''
try:
    infile = sys.argv[1]
    out_dir = sys.argv[2]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " infile out_dir\n")
    sys.exit(-1)
'''
# step 1 : 将语料分割为句子
infile = "./data/corpus4pos_tagging.txt"
out_dir = "./splitData"
sentenceList = []
corpusSplit(infile, sentenceList)
# step 2 : 输出
out(sentenceList, out_dir)
