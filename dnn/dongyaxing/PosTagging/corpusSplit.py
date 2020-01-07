# coding=utf-8
def corpusSplit(infile, sentenceList):
    # 打开文件，open(filename, model = 'r'), 默认只读模式
    fdi = open(infile)
    # 建立一个字典，标点符号，用于分割句子
    fullStopDict = {"。": 1, "；": 1, "？": 1, "！": 1}
    # line 关键字，逐行读取
    for line in fdi:
        text = line.strip()  # strip()函数 == lstrip()，截掉字符串左边的空格 + rstrip()，删掉字符串末尾的空格
        if text == "":
            continue
        else:
            infs = text.split()  # 将字符串从空格处分开，成数组
            sentence = []  # 初始化为一组词组，然后将其放入sentenceList，再清空sentence
            flag = True
            # 处理 infs 单词列表
            for s in infs:
                w_p = s.split("/")  # 将单词用/分割。例如：苹果/n
                # 通常来说，分割以后，会是长度为2的数组
                if len(w_p) == 2:
                    word = w_p[0]
                    # 判断这个单词是否有 [] 包起来，专有名词：[亚/j  太/j  经合/j  组织/n]
                    if word.startswith("["):
                        word = word.replace("[", "")  # 去掉 [
                    pos = w_p[1]  # 标注
                    pos = re.sub("].*", "", pos)  # sub(旧的 新的 谁 替换次数(默认全部替换))。]及后面的内容都用空替换，返回pos本身
                    if word == "" or pos == "":
                        flag = False
                    else:
                        sentence.append(word + "/" + pos)  # 把单词和标注再链接在一起
                    # 检查单词是否为标点符号，直到遇到标点符号，才清空sentence，且标点符号与词性均追加上去。
                    if word in fullStopDict:
                        if flag:
                            sentenceList.append(" ".join(sentence))  # 碰到特殊标点，用空格替换。
                        flag = True
                        sentence = []
                else:
                    flag = False  # 没有分割成功，没有单词或者没有词性，不进行处理。
            # 每一组都添加进去
            if sentence != [] and flag:
                sentenceList.append(" ".join(sentence))  # 每一个句子，开头都存在一个空格，所以后面处理的时候，需要先去空格
    fdi.close()


# 把处理好的句子，分成20份，18份用于训练，1份用于测试，1份用于开发集
def out(sentenceList, out_dir):
    # 定义一个数组，存储开辟的文件名称
    fdo_train_list = []
    for i in range(18):
        fdo_train = open(out_dir + "/train.%d" % (i), "w")  # 创建18个文件train，并打开，用于写入内容
        fdo_train_list.append(fdo_train)
    fdo_dev = open(out_dir + "/dev.txt", "w")  # 开发集，用于反复测试训练的参数。
    fdo_test = open(out_dir + "/test.txt", "w")  # 测试集，用于最后测试训练的参数。
    for sindx in range(len(sentenceList)):
        if sindx % 20 < 18:
            for i in range(sindx % 20, 18):  # 将18份句子预料，再分进18个文件，且容量依次递增。
                fdo_train_list[i].write(sentenceList[sindx] + "\n")  # 一行一行的存储
        elif sindx % 20 == 18:
            fdo_dev.write(sentenceList[sindx] + "\n")
        elif sindx % 20 == 19:
            fdo_test.write(sentenceList[sindx] + "\n")
    # 依次关闭所有文件。
    for i in range(18):
        fdo_train_list[i].close()
    fdo_dev.close()
    fdo_test.close()


import sys
import re  # re模块，正则表达式
import random

try:
    infile = sys.argv[1]
    out_dir = sys.argv[2]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " infile out_dir\n")
    sys.exit(-1)
# step 1 : 将语料分割为句子
# 声明一个变量，用来存储进行第一次处理之后的句子
sentenceList = []
# infile ：输入文件名称
# sentenceList : 输出处理好的句子
corpusSplit(infile, sentenceList)
# step 2 : 输出
# out_dir : 将句子处理之后的输出
out(sentenceList, out_dir)
