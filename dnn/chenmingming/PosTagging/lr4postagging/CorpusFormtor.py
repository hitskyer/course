
class CorpusFormtor:
	def __init__(self, pos_file, fig_file, fnumber):
		self.__posDict = {}
		self.__loadPosDict(pos_file, self.__posDict)
		self.__fe = FeaExtractor(fig_file=fig_file, fnumber=fnumber)
	def format4label_file(self, label_file, format_file):
		fdi = open(label_file, 'r', encoding='utf-8')
		fdo = open(format_file, "w", encoding='utf-8')
		feaKeyList = ["label"]
		self.__fe.getFeaKeyList(feaKeyList)
		fdo.write(",".join(feaKeyList)+"\n")
		for line in fdi:
			wps = [s.split("/") for s in line.strip().split()]
			for indx in range(len(wps)):
				word, pos = wps[indx]
				if pos in self.__posDict:
					pindx = self.__posDict[pos]
					feaList = [str(pindx)]
					self.__fe.getFeaList(wps, indx, feaList)
					fdo.write(",".join(feaList)+"\n")
		fdi.close()
		fdo.close()
	def __loadPosDict(self, pos_file, posDict):
		fdi = open(pos_file, 'r', encoding='utf-8')
		for line in fdi:
			pos, indx = line.strip().split()
			indx = int(indx)
			posDict[pos] = indx
		fdi.close()

from FeaExtractor import *
if __name__ == "__main__":
	try:
		corpus_file = sys.argv[1]
		pos_file    = sys.argv[2]
		fig_file    = sys.argv[3]
		fnumber     = int(sys.argv[4])
		outfile     = sys.argv[5]
	except:
		sys.stderr.write("\tpython "+sys.argv[0]+" corpus_file pos_file fig_file fnumber outfile\n")
		sys.exit(-1)
	cf = CorpusFormtor(pos_file, fig_file, fnumber)
	cf.format4label_file(corpus_file, outfile)
