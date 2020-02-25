import sys
import pandas
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
from sklearn.multiclass import OneVsRestClassifier
from sklearn.multiclass import OneVsOneClassifier
import joblib
from FeaExtractor import *
try:
	train_file = sys.argv[1]
	test_file  = sys.argv[2]
	fig_file   = sys.argv[3]
	fnumber    = int(sys.argv[4])
	model_file = sys.argv[5]
except:
	sys.stderr.write("\tpython "+sys.argv[0]+" train_file test_file fig_file fnumber model_file\n")
	sys.exit(-1)
print("step 1 : 获取特征key列表")
fe = FeaExtractor(fig_file, fnumber)
features = []
fe.getFeaKeyList(features)
print("step 2 : 读取语料&&分离出标签与特征向量")
train_corpus = pandas.read_csv(train_file)
test_corpus  = pandas.read_csv(test_file)
label_column = "label"
TRAIN_FEATURE = train_corpus[features]
TRAIN_LABEL = train_corpus[label_column]
TEST_FEATURE = test_corpus[features]
TEST_LABEL = test_corpus[label_column]
print("step 3 : 训练")
log_reg = LogisticRegression(solver='liblinear')
ovr = OneVsRestClassifier(log_reg)
ovr.fit(TRAIN_FEATURE, TRAIN_LABEL)
joblib.dump(ovr, model_file)
ovr = joblib.load(model_file)
print("step 4 : 测试")
predict_train=ovr.predict(TRAIN_FEATURE)
sys.stdout.write("LR(ovr) Train Accuracy : %.4g\n" % (
	metrics.accuracy_score(TRAIN_LABEL, predict_train)))
predict_test=ovr.predict(TEST_FEATURE)
sys.stdout.write("LR(ovr) Test  Accuracy : %.4g\n" % (
	metrics.accuracy_score(TEST_LABEL, predict_test)))
