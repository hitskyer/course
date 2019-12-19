
def staForWordToPosDict(infile, word2posDict):
	fdi = open(infile)    # 打开文件
	for line in fdi:
		infs = line.strip().split()    # 删掉首尾空格，然后对句子以空格进行分割
		for s in infs:
			w_p = s.split("/")   # 将每个词用 / 分割
			if len(w_p) == 2:
				word = w_p[0]
				pos  = w_p[1]
				if word in word2posDict:
					if pos in word2posDict[word]:
						word2posDict[word][pos] += 1
					else:
						word2posDict[word][pos]  = 1
				else:
					word2posDict[word] = {pos:1}
	fdi.close()


# 计算某个单词，出现的词性的最大概率
def getMaxProbPos(posDict):
	total = sum(posDict.values())
	max_num  = -1
	max_pos  = ""
	for pos in posDict:
		if posDict[pos] > max_num:
			max_num = posDict[pos]
			max_pos = pos
	return max_pos, max_num/total


# 统计文本中：单词、次数、词性、概率
def out4model(word2posDict, model_file):
	# 求单词出现的次数，键：单词，值：次数
	wordNumList = [[word, sum(word2posDict[word].values())] for word in  word2posDict]
	# 按照次数，对键值对进行排序，由大到小
	wordNumList.sort(key=lambda infs:(infs[1]), reverse=True)
	fdo = open(model_file, "w")
	# fdo.write("单词，\t出现的次数，\t词性，\t该词性在所有可能的词性中的占比")   # 添加说明
	for word, num in wordNumList:
		pos, prob = getMaxProbPos(word2posDict[word])  # 词性+概率
		if word != "" and pos != "":
			fdo.write("%s\t%d\t%s\t%f\n" % (word, num, pos, prob))
	fdo.close()


import sys
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file\n")
	sys.exit(-1)

# 声明一个字典，键1：word, 键2：pos ， 值：同时满足两个键的个数
word2posDict = {}
# 分割句子，填充字典
staForWordToPosDict(infile, word2posDict)
# 计算每一个词性的个数。
out4model(word2posDict, model_file)
