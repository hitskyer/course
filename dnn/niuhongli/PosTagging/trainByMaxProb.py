
def staForWordToPosDict(infile, word2posDict):
	fdi = open(infile)
	for line in fdi:
		infs = line.strip().split()
		for s in infs:
			w_p = s.split("/")
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
				# 两重字典 {word ： {pos, count}}
	fdi.close()
def getMaxProbPos(posDict):
	total = sum(posDict.values())
	max_num  = -1
	max_pos  = ""
	for pos in posDict:
		if posDict[pos] > max_num:
			max_num = posDict[pos]
			max_pos = pos
	return max_pos, max_num/total
def out4model(word2posDict, model_file):
	wordNumList = [[word, sum(word2posDict[word].values())] for word in  word2posDict]
	# [[word, counts]] 两重列表
	wordNumList.sort(key=lambda infs:(infs[1]), reverse=True)	# 按counts降序
	fdo = open(model_file, "w")
	for word, num in wordNumList:
		pos, prob = getMaxProbPos(word2posDict[word])	# 词性，及其最大的概率
		if word != "" and pos != "":
			fdo.write("%s\t%d\t%s\t%f\n" % (word, num, pos, prob))	# 写入文件
	fdo.close()
import sys
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file\n")
	sys.exit(-1)
word2posDict = {}
staForWordToPosDict(infile, word2posDict)	# 对训练文件进行统计
out4model(word2posDict, model_file)
