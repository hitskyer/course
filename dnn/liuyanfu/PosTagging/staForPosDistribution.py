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
		posList = [s.split("/")[1] for s in infs]
		for pos in posList:
			add2posDict(pos, pDict)
			add2posDict("all", pDict)
	fdi.close()
def out(pDict):
	oList = list(pDict.items())
	oList.sort(key=lambda infs:(infs[1]), reverse=True)
	total = oList[0][1]
	for pos, num in oList:
		print("%s\t%.4f" % (pos, num/total))
try:
	infile = sys.argv[1]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" infile\n")
	sys.exit(-1)
pDict = {}
sta(infile, pDict)
out(pDict)
