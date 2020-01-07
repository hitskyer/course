# trainByMaxProb.py
# -*- coding: UTF-8 -*-
def staForWordToPosDict(infile, word2posDict):
	fdi = open(infile, 'r', encoding='utf-8')
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
				# 统计文本中：单词、  词性、 频次
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
	# [[word, counts]] 两重列表，单词 & 其所有词性下的频次总和
	wordNumList.sort(key=lambda infs:(infs[1]), reverse=True)	# 按counts降序
	fdo = open(model_file, "w", encoding='utf-8')
	for word, num in wordNumList:
		pos, prob = getMaxProbPos(word2posDict[word])	
		# 单词可能有多个词性，出现最多的词性，及其概率(最大)
		if word != "" and pos != "":
			fdo.write("%s\t%d\t%s\t%f\n" % (word, num, pos, prob))	
			# 写入文件			单词、 出现次数、出现最多的词性、该词性的概率
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
sys.stdout.write("MaxProb训练统计完成！\n")
out4model(word2posDict, model_file)	# 输出到文件
sys.stdout.write("MaxProb训练输出到模型文件！\n")