
def loadModel(model_file, word2posDict):
	fdi = open(model_file)
	for line in fdi:
		infs = line.strip().split()
		if len(infs) == 4:
			word = infs[0]
			pos  = infs[2]
			word2posDict[word] = pos
		else:
			sys.stderr.write("format error in "+model_file+"\n")
			sys.stderr.write(line)
			sys.exit(-1)
	fdi.close()
def getWords(infs):
	return [s.split("/")[0] for s in infs]
def predict(infile, word2posDict, outfile):
	fdi = open(infile)
	fdo = open(outfile, "w")
	for line in fdi:
		infs = line.strip().split()
		# 盖住答案，闭卷考试
		words = getWords(infs)
		results = []
		for word in words:
			if word in word2posDict:
				results.append(word + "/" + word2posDict[word])
			else:
				results.append(word + "/unknown")
		fdo.write(" ".join(results)+"\n")
	fdo.close()
	fdi.close()
import sys
try:
	infile     = sys.argv[1]
	model_file = sys.argv[2]
	outfile    = sys.argv[3]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile model_file outfile\n")
	sys.exit(-1)
word2posDict = {}
loadModel(model_file, word2posDict)
predict(infile, word2posDict, outfile)
