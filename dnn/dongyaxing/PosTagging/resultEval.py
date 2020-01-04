import sys

# 去掉词性，只保留词性，并返回词性列表
def getPosList(infs):
    return [s.split("/")[1] for s in infs]


#
def add2staDict(pos, indx, staDict):
    if pos not in staDict:
        staDict[pos] = [pos, 0, 0, 0]
    staDict[pos][indx] += 1


def add2errDict(mykey, errDict):
    if mykey in errDict:
        errDict[mykey] += 1
    else:
        errDict[mykey] = 1

# 判断两个文件不一致的地方
def sta(label_file, predict_file, staDict, errDict):
    fdi1 = open(label_file)    # 打开标签文件
    fdi2 = open(predict_file)    # 打开待预测文件
    while True:
        line1 = fdi1.readline()    # 取一行带标签的句子
        line2 = fdi2.readline()    # 取一行待对比的句子
        if line1 == "" and line2 == "":
            break
        elif line1 == "" or line2 == "":
            sys.stderr.write("the number of lines is not equal between %s and %s!\n" % (
                label_file, predict_file))
            sys.exit(-1)
        else:
            labelList = getPosList(line1.strip().split())    # 将带标签的句子，进行切分，保留词性
            predictList = getPosList(line2.strip().split())  # 将待测试的句子，进行切分，保留词性
            if len(labelList) != len(predictList):
                sys.stderr.write("the number of words is not equal between %s and %s!\n" % (
                    label_file, predict_file))
                sys.exit(-1)
            else:
                for i in range(len(labelList)):
                    label = labelList[i]  # 本身的label
                    predict = predictList[i]  # 预测得到的label
                    add2staDict(label, 1, staDict)  # 第一列是label的个数。staDict={pos:[pos, label_count, predict_count, '相等的个数']}
                    add2staDict(predict, 2, staDict)  # 第二列是predict的个数
                    add2staDict("all", 1, staDict)  # 记录label总个数
                    add2staDict("all", 2, staDict)  # 记录predict总个数
                    if label == predict:
                        add2staDict(label, 3, staDict)
                        add2staDict("all", 3, staDict)
                    else:
                        add2errDict("%s-->%s" % (label, predict), errDict)  # 记录label被写成predict的次数
                        add2errDict("all-->all", errDict)
    fdi2.close()
    fdi1.close()


# 输入正确的字典，和错误的字典，输出结果。
def out(staDict, errDict, outfile):
    staList = list(staDict.values())  # 把staDict的值，转化为staList
    staList.sort(key=lambda infs: (infs[1]), reverse=True)    # 按照标签值的顺序，由大到小进行排序
    errList = list(errDict.items())    # 把errDict的值，转化为errList
    errList.sort(key=lambda infs: (infs[1]), reverse=True)    # 按照值的顺序，由大到小进行排序
    fdo = open(outfile, "w")
    total = staList[0][1]    # 取出all的总数，也就是扫描label的所有个数
    # 这里的nright值，肯定是小于等于npredict 和 nlabel的值，
    # 由于初始的时候npredict 和 nlabel 是0，所以需要判断是否为0
    # 当npredict 和 nlabel 是0，此时nright 也是0
    for pos, nlabel, npredict, nright in staList:
        fdo.write("pos_%s\t%.4f\t%.4f\t%.4f\n" % (pos,
                                                  nlabel / total,
                                                  nright / (npredict if npredict > 0 else 100),
                                                  nright / (nlabel if nlabel > 0 else 100)))
    # 总的错误的个数
    total = errList[0][1]
    for errKey, num in errList:
        fdo.write("err_%s\t%.4f\n" % (errKey, num / total))
    fdo.close()


try:
    label_file = sys.argv[1]
    predict_file = sys.argv[2]
    outfile = sys.argv[3]
except:
    sys.stderr.write("\tpython " + sys.argv[0] + " label_file predict_file outfile\n")
    sys.exit(-1)

# 状态字典
staDict = {}
# 错误字典
errDict = {}
# 输入：标签，测试文件
# 输出： 状态字典，错误字典
sta(label_file, predict_file, staDict, errDict)
# 输入： 状态字典，错误字典
# 输出： 结果文件
out(staDict, errDict, outfile)
