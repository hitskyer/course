import sys
def add2posDict(pos, pDict):
	if pos in pDict:
		pDict[pos] += 1
	else:
		pDict[pos]  = 1
def sta(infile, pDict):
	fdi = open(infile)
	for line in fdi:
		infs = line.strip().split()
		posList = [s.split("/")[1] for s in infs]	# 词性list
		for pos in posList:
			add2posDict(pos, pDict)	# 统计各个词性的次数
			add2posDict("all", pDict)	# 总的次数
	fdi.close()
def out(pDict):
	oList = list(pDict.items())
	oList.sort(key=lambda infs:(infs[1]), reverse=True)	# 按匿名函数排序
	total = oList[0][1]
	for pos, num in oList:
		print("%s\t%.4f" % (pos, num/total))	# 打印 词性，对应频率
try:
	infile = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile\n")
	sys.exit(-1)
pDict = {}
sta(infile, pDict)	# 统计训练集中的语料出现频率
out(pDict)
