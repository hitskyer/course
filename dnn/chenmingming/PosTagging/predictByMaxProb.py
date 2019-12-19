# predictByMaxProb.py
def loadModel(model_file, word2posDict):	# 加载训练模型
	fdi = open(model_file, 'r', encoding='utf-8')
	for line in fdi:
		infs = line.strip().split()
		if len(infs) == 4:
			word = infs[0]
			pos  = infs[2]
			word2posDict[word] = pos	# 从模型读取单词，和其最大概率的词性
		else:
			sys.stderr.write("format error in "+model_file+"\n")
			sys.stderr.write(line)
			sys.exit(-1)
	fdi.close()

def getWords(infs):
	return [s.split("/")[0] for s in infs]

def predict(infile, word2posDict, outfile):
	fdi = open(infile, 'r', encoding='utf-8')
	fdo = open(outfile, 'w', encoding='utf-8')
	for line in fdi:
		infs = line.strip().split()
		# 盖住答案，闭卷考试
		words = getWords(infs)	# 只获取输入文件的单词
		results = []
		for word in words:
			if word in word2posDict:	# 从模型中获取它的最大概率词性
				results.append(word + "/" + word2posDict[word])
			else:
				results.append(word + "/unknown")
		fdo.write(" ".join(results)+"\n")	# 写入输出文件
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
loadModel(model_file, word2posDict)	# 加载训练模型
predict(infile, word2posDict, outfile)	# 输出