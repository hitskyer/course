fnumber=512
snumber=20480
alias python="/usr/local/bin/python3"
# step 1 : 基于信息增益选择特征 && 输出词性到词性标号的映射表
python FeaSelector.py ../data/train.0 ./data/fig.0 ./data/pos.0
# step 2 : 将语料格式化
python CorpusFormtor.py ../data/train.0 ./data/pos.0 ./data/fig.0 ${fnumber} ./data/train.0.csv
python CorpusFormtor.py ../data/dev.txt ./data/pos.0 ./data/fig.0 ${fnumber} ./data/dev.0.csv
python CorpusFormtor.py ../data/test.txt ./data/pos.0 ./data/fig.0 ${fnumber} ./data/test.0.csv
# step 3 : 只用部分训练语料（否则运行速度太慢）
head -${snumber} ./data/train.0.csv > ./data/train.0.${snumber}.csv
head -${snumber} ./data/dev.0.csv > ./data/dev.0.${snumber}.csv
head -${snumber} ./data/test.0.csv > ./data/test.0.${snumber}.csv
# step 4 : 训练
python train.py ./data/train.0.${snumber}.csv ./data/test.0.${snumber}.csv ./data/fig.0 ${fnumber} ./data/model.0.${snumber}_${fnumber}.ovr
# step 5 : 预测
python predict.py ../data/test.txt ./data/pos.0 ./data/fig.0 ${fnumber} ./data/model.0.${snumber}_${fnumber}.ovr ./data/test.0.${snumber}_${fnumber}.predict
# step 5 : 评估
python ../PosTagging/resultEval.py ../data/test.txt ./data/test.0.${snumber}_${fnumber}.predict ./data/test.0.${snumber}_${fnumber}.eval
