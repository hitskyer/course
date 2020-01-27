import sys
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
def getPosList(infs):
	return [s.split("/")[1] for s in infs]
def getWords(infs):
	return [s.split("/")[0] for s in infs]
def getEmitProb(emitDict, pos, word):
	if word in emitDict[pos]:
		return emitDict[pos][word]
	else:
		return emitDict[pos]["__NEW__"]
def getProb(transDict, emitDict, words, posList):
	prob = 0.0
	if len(words) == 0:
		return prob
	for i in range(len(words)):
		prob += getEmitProb(emitDict, posList[i], words[i])
	posList = ["__start__", "__start__"] + posList + ["__end__", "__end__"]
	for i in range(2, len(posList)):
		pos1 = posList[i-2]
		pos2 = posList[i-1]
		pos3 = posList[i]
		prob += transDict[pos1][pos2][pos3]
	return prob
def outProb(transDict, emitDict, words, labelList, predictList, i, fdo):
	if len(words) < 3:
		return
	for indx in range(i, i+3):
		if indx == 0:
			label4pos1 = "__start__"
			predict4pos1 = "__start__"
			label4pos2 = "__start__"
			predict4pos2 = "__start__"
			label4pos3 = labelList[indx]
			predict4pos3 = predictList[indx]
		elif indx == 1:
			label4pos1 = "__start__"
			predict4pos1 = "__start__"
			label4pos2 = labelList[0]
			predict4pos2 = predictList[0]
			label4pos3 = labelList[indx]
			predict4pos3 = predictList[indx]
		elif indx == len(words):
			label4pos1 = labelList[indx-2]
			predict4pos1 = predictList[indx-2]
			label4pos2 = labelList[indx-1]
			predict4pos2 = predictList[indx-1]
			label4pos3 = "__end__"
			predict4pos3 = "__end__"
		elif indx == len(words)+1:
			label4pos1 = labelList[indx-2]
			predict4pos1 = predictList[indx-2]
			label4pos2 = "__end__"
			predict4pos2 = "__end__"
			label4pos3 = "__end__"
			predict4pos3 = "__end__"
		else:
			label4pos1 = labelList[indx-2]
			predict4pos1 = predictList[indx-2]
			label4pos2 = labelList[indx-1]
			predict4pos2 = predictList[indx-1]
			label4pos3 = labelList[indx]
			predict4pos3 = predictList[indx]
		fdo.write("(label)%s->%s->%s : %.4f vs (predict)%s->%s->%s : %.4f\n" % (
			label4pos1, label4pos2, label4pos3, transDict[label4pos1][label4pos2][label4pos3],
			predict4pos1, predict4pos2, predict4pos3, transDict[predict4pos1][predict4pos2][predict4pos3]))
	fdo.write("(label)%s->%s : %.4f vs (predict)%s->%s : %.4f\n" % (
		labelList[i], words[i], getEmitProb(emitDict, labelList[i], words[i]),
		predictList[i], words[i], getEmitProb(emitDict, predictList[i], words[i])))
def sta(transDict, emitDict, label_file, predict_file, outfile):
	fdi1 = open(label_file)
	fdi2 = open(predict_file)
	fdo  = open(outfile, "w")
	while True:
		line1 = fdi1.readline()
		line2 = fdi2.readline()
		if line1 == "" and line2 == "":
			break
		elif line1 == "" or line2 == "":
			sys.stderr.write("the number of lines is not equal between %s and %s!\n" % (
				label_file, predict_file))
			break
			#sys.exit(-1)
		else:
			labelList = getPosList(line1.strip().split())
			predictList = getPosList(line2.strip().split())
			if len(labelList) != len(predictList):
				sys.stderr.write("the number of words is not equal between %s and %s!\n" % (
					label_file, predict_file))
				sys.exit(-1)
			else:
				errList = []
				words = getWords(line1.strip().split())
				for i in range(len(labelList)):
					if labelList[i] == predictList[i]:
						errList.append(labelList[i])
					else:
						outProb(transDict, emitDict, words, labelList, predictList, i, fdo)
						errList.append(labelList[i]+"-->"+predictList[i])
				oList = []
				for i in range(len(words)):
					oList.append(words[i]+"/"+errList[i])
				label_prob = getProb(transDict, emitDict, words, labelList)
				predict_prob = getProb(transDict, emitDict, words, predictList)
				fdo.write("\t".join(oList)+"(%.4f vs %.4f)\n" % (label_prob, predict_prob))
	fdo.close()
	fdi2.close()
	fdi1.close()
try:
	model_file   = sys.argv[1]
	label_file   = sys.argv[2]
	predict_file = sys.argv[3]
	outfile      = sys.argv[4]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" model_file label_file predict_file outfile\n")
	sys.exit(-1)
gPosList  = []
transDict = {}
emitDict  = {}
loadModel(model_file, gPosList, transDict, emitDict)
staDict = {}
errDict = {}
sta(transDict, emitDict, label_file, predict_file, outfile)
