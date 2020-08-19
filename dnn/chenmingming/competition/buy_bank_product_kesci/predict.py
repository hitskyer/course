import platform
import sys
import pandas
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import GradientBoostingClassifier

import matplotlib
from pylab import *
from sklearn.metrics import roc_curve, roc_auc_score
# from sklearn.externals import joblib
import joblib
from sklearn import metrics

def out(ID_test, prob_test, out_file):
	fdo = open(out_file, "w")
	fdo.write("ID,pred\n")
	for i in range(len(ID_test)):
		fdo.write("%d,%f\n" % (ID_test[i], prob_test[i]))
	fdo.close()
try:
	test_file  = sys.argv[1]
	model_file = sys.argv[2]
	out_file   = sys.argv[3]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" test_file model_file out_file\n")
	sys.exit(-1)
gbdt = joblib.load(model_file)
test = pandas.read_csv(test_file)
x_test = test.drop(['ID','y'], axis=1)
ID_test = test['ID']
prob_test = gbdt.predict_proba(x_test)[:, 1]
out(ID_test, prob_test, out_file)
