
def getPosList(pos_file, posList):
	fdi = open(pos_file)
	for line in fdi:
		pos, indx = line.strip().split()
		indx = int(indx)
		if indx == len(posList):
			posList.append(pos)
		else:
			sys.stderr.write("getPosList(..) failed.\n")
			sys.exit(-1)
	fdi.close()
def predict(test_file, posList, fe, ovr, out_file):
	fdi = open(test_file)
	fdo = open(out_file, "w")
	for line in fdi:
		wps = [s.split("/") for s in line.strip().split()]
		df  = fe.getFeaDataFrame(wps)
		predict_poses = ovr.predict(df)
		olst = []
		for windx in range(predict_poses.shape[0]):
			pindx = predict_poses[windx]
			olst.append(wps[windx][0]+"/"+posList[pindx])
		fdo.write(" ".join(olst)+"\n")
	fdo.close()
	fdi.close()
import sys
from sklearn.externals import joblib
from FeaExtractor import *
try:
	test_file = sys.argv[1]
	pos_file  = sys.argv[2]
	fig_file  = sys.argv[3]
	fnumber   = int(sys.argv[4])
	model_file= sys.argv[5]
	out_file  = sys.argv[6]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" test_file pos_file fig_file fnumber model_file out_file\n")
	sys.exit(-1)
posList = []
getPosList(pos_file, posList)
fe = FeaExtractor(fig_file, fnumber)
ovr = joblib.load(model_file)
predict(test_file, posList, fe, ovr, out_file)
