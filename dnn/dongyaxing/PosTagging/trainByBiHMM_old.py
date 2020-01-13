# 根据词性1，词性2，填充转移字典，没有计算概率
def add2transDict(pos1, pos2, transDict):
	if pos1 in transDict:
		if pos2 in transDict[pos1]:
			transDict[pos1][pos2] += 1
		else:
			transDict[pos1][pos2]  = 1
	else:
		transDict[pos1] = {pos2:1}


# 填充发射字典，还没有计算概率
def add2emitDict(pos, word, emitDict):
	if pos in emitDict:
		if word in emitDict[pos]:
			emitDict[pos][word] += 1
		else:
			emitDict[pos][word]  = 1
	else:
		emitDict[pos] = {word:1}


# 输入：文件
# 输出：统计该文件的转移概率、发射概率
def sta(infile, transDict, emitDict):
	fdi = open(infile)  # 打开文件
	for line in fdi:    # 逐行读取
		infs = line.strip().split()    # 去掉首尾空格，再以空格分词，成为列表
		wpList = [["__NONE__", "__start__"]] + [s.split("/") for s in infs] + [["__NONE_", "__end__"]]    # 每行首有start，尾有end
		for i in range(1, len(wpList)):    # 跳过start
			pre_pos = wpList[i-1][1]    # start开始，
			cur_pos = wpList[i][1]      # 单词的词性
			word    = wpList[i][0]      # 单词
			if word == "" or cur_pos == "" or pre_pos == "":
				continue
			add2transDict(pre_pos, cur_pos, transDict)    # 构造转移A+π字典（开头有start)
			add2emitDict(cur_pos, word, emitDict)		  # 构造发射B字典
		add2transDict("__end__", "__end__", transDict)    # 统计end的转移概率
	fdi.close()


# 统计每一个词性，出现的次数，
# 词性+次数。由多到少输出到pnList。
def getPosNumList(transDict):
	pnList = []
	for pos in transDict:
		# if pos == "__start__" or pos == "__end__":
		#     continue
		num = sum(transDict[pos].values())    # 统计某个词性的出现次数
		pnList.append([pos, num])             # 追加为词性+次数的，二维数组
	pnList.sort(key=lambda infs:(infs[1]), reverse=True)    # 按照词性的有多到少，进行排序
	return pnList


# 根据输入的发射概率，统计所有词性的和
def getTotalWordNum(emitDict):
	total_word_num = 0
	for pos in emitDict:
		total_word_num += sum(list(emitDict[pos].values()))
	return total_word_num


# 根据已有的转移概率和发射概率
# 得到模型文件，并输出
def out4model(transDict, emitDict, model_file):
	pnList = getPosNumList(transDict)  # 统计每一个词性，出现的次数，词性+次数
	
	# 状态集合
	fdo = open(model_file, "w")  # 打开model文件，写入处理结果
	total = sum([num for pos, num in pnList])    # 统计所有词性的次数和
	for pos, num in pnList:
		fdo.write("pos_set\t%s\t%d\t%f\n" % (pos, num, num/total))  # 文件中存储 pos, num, 概率。这个词性在整篇文章中出现的概率
	# 转移概率
	total_word_num = getTotalWordNum(emitDict)  # 统计所有单词的和(词性对应的单词个数相加)
	for pos1, num1 in pnList:
		if pos1 == "__end__":
			continue
		num1 += len(pnList)-1  # 对自身的数量+词性的种类和-1 ？？
		for pos2, _ in pnList:
			if pos2 == "__start__":
				continue
			num2 = 1
			if pos2 in transDict[pos1]:
				num2 = transDict[pos1][pos2] + 1
				fdo.write("trans_prob\t%s\t%s\t%f\n" % (pos1, pos2, math.log(num2/num1)))
			else:   # 转移频次为0的，需要进行概率平滑，避免概率为0， 给其一个概率，相应的上面出现的概率减小，保证概率和为1
				fdo.write("trans_prob\t%s\t%s\t%f\n" % (pos1, pos2, math.log(1/total_word_num)))
	# 发射概率
	for pos, _ in pnList:
		if pos == "__start__" or pos == "__end__":
			continue
		wnList = list(emitDict[pos].items())  # eg: 转化pos1的值，为： [(word1, count), (word2, count)]
		wnList.sort(key=lambda infs:infs[1], reverse=True)  # 按照上面word中值的多少，排序。
		num1 = sum([num for _, num in wnList])+len(wnList)+1  # num1 为该词性下，所有单词的个数和，+ 元组个数，+1  ？？
		for word, num2 in wnList:
			fdo.write("emit_prob\t%s\t%s\t%f\n" % (pos, word, math.log((num2+1)/num1)))
		fdo.write("emit_prob\t%s\t%s\t%f\n" % (pos, "__NEW__", math.log(1/total_word_num)))
	fdo.close()


import sys
import math
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file\n")
	sys.exit(-1)

# 转移字典，A+， pos1转移到pos2的概率
# transDict = {pos1:{pos2:count, pos3:count, ...}, pos2:{pos3:count, ...}, ...}
transDict = {}
# 发射字典 B。也就是word是pos词性的概率。
# emitDict = {pos1:{word1:count, word2:count, ...}, pos2:{word1:count, ...}, ...}
emitDict  = {}

# 输入：train文件
# 输出：转移字典，发射字典
# 将训练文件进行处理，得出转移字典A+π，和 发射字典B
sta(infile, transDict, emitDict)

# 根据转移字典和发射字典
# 统计文本中：单词、次数、词性、概率
out4model(transDict, emitDict, model_file)
