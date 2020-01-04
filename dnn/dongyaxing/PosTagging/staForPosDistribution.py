import sys
# 如果这个词性，在词性列表中，则数量+1， 否则，赋值为1.
def add2posDict(pos, pDict):
	if pos in pDict:
		pDict[pos] += 1
	else:
		pDict[pos]  = 1


def sta(infile, pDict):
	fdi = open(infile)  # 打开文件
	for line in fdi:    # 逐行读取
		infs = line.strip().split()    # 去掉开头和结尾的空格，然后分割单词，例如：仅剩下：苹果/n
		posList = [s.split("/")[1] for s in infs]    # 只取后面的词性，把词性放在词性列表中
		for pos in posList:    # 逐个操作词性列表中的词性
			add2posDict(pos, pDict)    # 统计每个词出现的次数，并在字典中记录
			add2posDict("all", pDict)  # 添加一个all。记录所有词性出现的个数
	fdi.close()

# 把统计的词性，写进文件
def out(pDict):
	oList = list(pDict.items())  # items方法，以 列表 返回可遍历的(键, 值) 元组数组
	oList.sort(key=lambda infs:(infs[1]), reverse=True)    # 按照词性出现次数的由多到少，进行排序
	total = oList[0][1]  # 只取了第一个词性all和 , 为基准，其他以此为概率，进行统计。
	for pos, num in oList:  # 词性与数量一起取
		print("%s\t%.4f" % (pos, num/total))    # 直接打印到了屏幕上

try:
	infile = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile\n")
	sys.exit(-1)

# 词性字典
pDict = {}

# 输入：文件
# 输出：词性字典
sta(infile, pDict)

# 把词性字典写入文件
out(pDict)
