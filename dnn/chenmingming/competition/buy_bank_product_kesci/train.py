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
from sklearn.model_selection import StratifiedShuffleSplit
try:
	train_file = sys.argv[1]
	model_file = sys.argv[2]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" train_file model_file\n")
	sys.exit(-1)
corpus = pandas.read_csv(train_file)
x_corpus = corpus.drop(['ID','y'], axis=1)
y_corpus = corpus['y']

#ss = StratifiedShuffleSplit(n_splits=2, test_size=0.2, random_state=1)
#for train_index, test_index in ss.split(x_corpus, y_corpus):
#	print("ok")
#	x_train, x_test = x_corpus[train_index], x_corpus[test_index]
#	y_train, y_test = y_corpus[train_index], y_corpus[test_index]
splt = StratifiedShuffleSplit(n_splits=1, test_size=0.2, random_state=1)
for train_idx, test_idx in splt.split(corpus,corpus['y']):
	train = corpus.loc[train_idx]
	test  = corpus.loc[test_idx]
	print("ok")
x_train = train.drop(['ID','y'], axis=1)
y_train = train['y']
x_test  = test.drop(['ID','y'], axis=1)
y_test  = test['y']


gbdt = GradientBoostingClassifier(learning_rate=0.1, n_estimators=130, max_features='sqrt', max_depth=5, min_samples_split=1200, min_samples_leaf=60, subsample=0.8, random_state=10)
gbdt.fit(x_train, y_train)
prob_train = gbdt.predict_proba(x_train)[:, 1]
print("GBDT Train AUC Score: %f \n" % metrics.roc_auc_score(y_train, prob_train))

prob_test = gbdt.predict_proba(x_test)[:, 1]
print("GBDT Test AUC Score : %f \n" % metrics.roc_auc_score(y_test, prob_test))

gbdt = GradientBoostingClassifier(learning_rate=0.1, n_estimators=130, max_features='sqrt', max_depth=5, min_samples_split=1200, min_samples_leaf=60, subsample=0.8, random_state=10)
gbdt.fit(x_corpus, y_corpus)

joblib.dump(gbdt, model_file)
