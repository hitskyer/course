
def add2transDict(pos1, pos2, pos3, transDict):
	if pos1 in transDict:
		if pos2 in transDict[pos1]:
			if pos3 in transDict[pos1][pos2]:
				transDict[pos1][pos2][pos3] += 1
			else:
				transDict[pos1][pos2][pos3]  = 1
		else:
			transDict[pos1][pos2] = {pos3:1}
	else:
		transDict[pos1] = {pos2:{pos3:1}}
def add2emitDict(pos, word, emitDict):
	if pos in emitDict:
		if word in emitDict[pos]:
			emitDict[pos][word] += 1
		else:
			emitDict[pos][word]  = 1
	else:
		emitDict[pos] = {word:1}
def sta(infile, transDict, emitDict):
	fdi = open(infile)
	for line in fdi:
		infs = line.strip().split()
		wpList = [["__NONE__", "__start__"], ["__NONE__", "__start__"]] + [s.split("/") for s in infs] + [["__NONE_", "__end__"], ["__NONE_", "__end__"]]
		for i in range(2, len(wpList)):
			pos1 = wpList[i-2][1]
			pos2 = wpList[i-1][1]
			pos3 = wpList[i][1]
			word = wpList[i][0]
			if word == "" or pos1 == "" or pos2 == "" or pos3 == "":
				continue
			add2transDict(pos1, pos2, pos3, transDict)
			add2emitDict(pos3, word, emitDict)
		add2transDict("__end__", "__end__", "__end__", transDict)
		add2emitDict("__start__", "__NONE_", emitDict)
		add2emitDict("__start__", "__NONE_", emitDict)
	fdi.close()
def getPosNumList(transDict):
	pnList = []
	for pos1 in transDict:
		num = sum([sum(transDict[pos1][pos2].values()) for pos2 in transDict[pos1]])
		pnList.append([pos1, num])
	pnList.sort(key=lambda infs:(infs[1]), reverse=True)
	return pnList
def getTotalWordNum(emitDict):
	return sum([sum(emitDict[pos].values()) for pos in emitDict])
def out4model(transDict, emitDict, model_file):
	pnList = getPosNumList(transDict)
	# 状态集合
	fdo = open(model_file, "w")
	total = sum([num for pos, num in pnList])
	for pos, num in pnList:
		fdo.write("pos_set\t%s\t%d\t%f\n" % (pos, num, num/total))
	# 转移概率
	total_word_num = getTotalWordNum(emitDict)
	for pos1,_ in pnList:
		tmpList = []
		for pos2, _ in pnList:
			if pos2 in transDict[pos1]:
				for pos3, num3 in pnList:
					smoothing_factor = num3/total_word_num
					if pos3 in transDict[pos1][pos2]:
						tmpList.append([pos2, pos3, transDict[pos1][pos2][pos3] + smoothing_factor])
					else:
						tmpList.append([pos2, pos3, smoothing_factor])
			else:
				for pos3, num3 in pnList:
					smoothing_factor = num3/total_word_num
					tmpList.append([pos2, pos3, smoothing_factor])
		denominator = sum([infs[2] for infs in tmpList])
		for pos2, pos3, numerator in tmpList:
			fdo.write("trans_prob\t%s\t%s\t%s\t%f\n" % (pos1, pos2, pos3, math.log(numerator/denominator)))
	# 发射概率
	for pos,_ in pnList:
		wnList = list(emitDict[pos].items())
		wnList.sort(key=lambda infs:infs[1], reverse=True)
		num = sum([num for _, num in wnList])
		smoothing_factor = num/total_word_num # 平滑方案1
		tmpList = []
		for word, num in wnList:
			tmpList.append([word, num+smoothing_factor])
		tmpList.append(["__NEW__", smoothing_factor])
		denominator = sum([infs[1] for infs in tmpList])
		for word, numerator in tmpList:
			fdo.write("emit_prob\t%s\t%s\t%f\n" % (pos, word, math.log(numerator/denominator)))
	fdo.close()
import sys
import math
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file\n")
	sys.exit(-1)
transDict = {}
emitDict  = {}
sta(infile, transDict, emitDict)
out4model(transDict, emitDict, model_file)
