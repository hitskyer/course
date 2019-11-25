echo "将python的路径改为当前机器环境下的路径"
alias python='/usr/local/bin/python3.7'
for ((i=0; i<=17; i++))
do
	# step 1 : 训练模型
	python trainByMaxProb.py ../data/train.${i} ../data/model.${i}
	# step 2 : 在训练集上做评估
	python predictByMaxProb.py ../data/train.${i} ../data/model.${i} ../data/train.${i}.predict
	python resultEval.py ../data/train.${i} ../data/train.${i}.predict ../data/train.${i}.eval
	# step 3 : 在开发集上做评估
	python predictByMaxProb.py ../data/dev.txt ../data/model.${i} ../data/dev.${i}.predict
	python resultEval.py ../data/dev.txt ../data/dev.${i}.predict ../data/dev.${i}.eval
	# step 4 : 在测试集上做评估
	python predictByMaxProb.py ../data/test.txt ../data/model.${i} ../data/test.${i}.predict
	python resultEval.py ../data/test.txt ../data/test.${i}.predict ../data/test.${i}.eval
done
