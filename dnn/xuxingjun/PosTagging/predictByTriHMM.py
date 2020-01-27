
def add2transDict(pos1, pos2, pos3, prob, transDict):
	if pos1 in transDict:
		if pos2 in transDict[pos1]:
			transDict[pos1][pos2][pos3]  = prob
		else:
			transDict[pos1][pos2] = {pos3:prob}
	else:
		transDict[pos1] = {pos2:{pos3:prob}}
def add2emitDict(pos, word, prob, emitDict):
	if pos in emitDict:
		emitDict[pos][word]  = prob
	else:
		emitDict[pos] = {word:prob}
def loadModel(infile, gPosList, transDict, emitDict):
	fdi = open(infile)
	for line in fdi:
		infs = line.strip().split()
		if infs[0] == "pos_set":
			pos = infs[1]
			if pos != "__start__" and pos != "__end__":
				gPosList.append(pos)
		if infs[0] == "trans_prob":
			pos1 = infs[1]
			pos2 = infs[2]
			pos3 = infs[3]
			prob = float(infs[4])
			add2transDict(pos1, pos2, pos3, prob, transDict)
		if infs[0] == "emit_prob":
			pos = infs[1]
			word = infs[2]
			prob = float(infs[3])
			add2emitDict(pos, word, prob, emitDict)
	fdi.close()
def getWords(infs):
	return [s.split("/")[0] for s in infs]
def getEmitProb(emitDict, pos, word):
	if word in emitDict[pos]:
		return emitDict[pos][word]
	else:
		return emitDict[pos]["__NEW__"]
def getPosList(preProbDictList, posList):
	cpos1 = None
	cpos2 = "__end__"
	cpos3 = "__end__"
	for i in range(len(preProbDictList), 2, -1):
		i -= 1
		pos = preProbDictList[i][cpos2][cpos3][1]
		posList.append(pos)
		cpos3 = cpos2
		cpos2 = pos
	posList.reverse()
def getMaxProb(preProbDict, pos1, pos2):
	if pos1 not in preProbDict or pos2 not in preProbDict[pos1]:
		return -10000000.0
	else:
		return preProbDict[pos1][pos2][0]
def add2preProbDict(preProbDict, pos2, pos3, pos1, total_prob):
	if pos2 not in preProbDict:
		preProbDict[pos2] = {pos3:[total_prob, pos1]}
	else:
		preProbDict[pos2][pos3] = [total_prob, pos1]
def predict4one(words, gPosList, transDict, emitDict, results):
	if words == []:
		return
	preProbDictList = []
	for i in range(len(words)):
		preProbDict = {}
		for pos3 in gPosList:
			emit_prob  = getEmitProb(emitDict, pos3, words[i])
			if i == 0:
				trans_prob = transDict["__start__"]["__start__"][pos3]
				total_prob = trans_prob + emit_prob
				add2preProbDict(preProbDict, "__start__", pos3, "__start__", total_prob)
			elif i == 1:
				for pos2 in gPosList:
					max_pre_prob = getMaxProb(preProbDictList[i-1], "__start__", pos2)
					trans_prob = transDict["__start__"][pos2][pos3]
					total_prob = max_pre_prob + trans_prob + emit_prob
					add2preProbDict(preProbDict, pos2, pos3, "__start__", total_prob)
			else:
				for pos2 in gPosList:
					max_total_prob = -10000000.0
					for pos1 in gPosList:
						max_pre_prob = getMaxProb(preProbDictList[i-1], pos1, pos2)
						trans_prob = transDict[pos1][pos2][pos3]
						total_prob = max_pre_prob + trans_prob + emit_prob
						if total_prob > max_total_prob:
							max_total_prob = total_prob
							add2preProbDict(preProbDict, pos2, pos3, pos1, total_prob)
		preProbDictList.append(preProbDict)
	
	preProbDict = {}
	pos3 = "__end__"
	i    = len(words)
	for pos2 in gPosList:
		max_total_prob = -10000000.0
		if len(words) == 1:
			max_pre_prob = getMaxProb(preProbDictList[i-1], "__start__", pos2)
			trans_prob = transDict["__start__"][pos2][pos3]
			total_prob =  max_pre_prob + trans_prob
			if  total_prob > max_total_prob:
				max_total_prob = total_prob
				add2preProbDict(preProbDict, pos2, pos3, "__start__", total_prob)
		else:
			for pos1 in gPosList:
				max_pre_prob = getMaxProb(preProbDictList[i-1], pos1, pos2)
				trans_prob = transDict[pos1][pos2][pos3]
				total_prob = max_pre_prob + trans_prob
				if total_prob > max_total_prob:
					max_total_prob = total_prob
					add2preProbDict(preProbDict, pos2, pos3, pos1, total_prob)
	preProbDictList.append(preProbDict)
	
	preProbDict = {}
	pos3 = "__end__"
	pos2 = "__end__"
	i    = len(words)+1
	max_total_prob = -10000000.0
	for pos1 in gPosList:
		max_pre_prob = getMaxProb(preProbDictList[i-1], pos1, pos2)
		trans_prob = transDict[pos1][pos2][pos3]
		total_prob = max_pre_prob + trans_prob
		if total_prob > max_total_prob:
			max_total_prob = total_prob
			add2preProbDict(preProbDict, pos2, pos3, pos1, total_prob)
	preProbDictList.append(preProbDict)

	posList = []
	getPosList(preProbDictList, posList)
	if len(posList) == len(words):
		for i in range(len(posList)):
			results.append("%s/%s" % (words[i], posList[i]))
	else:
		sys.stderr.write("len(posList) != len(words)!")
		sys.exit(-1)
def predict(infile, gPosList, transDict, emitDict, outfile):
	fdi = open(infile)
	fdo = open(outfile, "w")
	for line in fdi:
		infs = line.strip().split()
		# 盖住答案，闭卷考试
		words = getWords(infs)
		results = []
		predict4one(words, gPosList, transDict, emitDict, results)
		fdo.write(" ".join(results)+"\n")
		fdo.flush()
	fdo.close()
	fdi.close()
import sys
import math
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
	outfile    = sys.argv[3]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file outfile\n")
	sys.exit(-1)
gPosList  = []
transDict = {}
emitDict  = {}
loadModel(model_file, gPosList, transDict, emitDict)
print("ok")
predict(infile, gPosList, transDict, emitDict, outfile)
