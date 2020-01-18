echo "将python的路径改为当前机器环境下的路径"
alias python='/usr/local/bin/python3.7'
for ((i=0; i<=17; i++))
do
	alias python='/usr/local/bin/python3.7'
	# step 3 : TriHMM模型
	# step 3.1 : 训练模型
	python trainByTriHMM.py ./data/train.${i} ./data/model.TriHMM.${i}
	# step 3.2 : 在训练集上做评估
	python predictByTriHMM.py ./data/train.${i} ./data/model.TriHMM.${i} ./data/train.${i}.TriHMM.predict
	python resultEval.py ./data/train.${i} ./data/train.${i}.TriHMM.predict ./data/train.${i}.TriHMM.eval
	# step 3.3 : 在开发集上做评估
	python predictByTriHMM.py ./data/dev.txt ./data/model.TriHMM.${i} ./data/dev.${i}.TriHMM.predict
	python resultEval.py ./data/dev.txt ./data/dev.${i}.TriHMM.predict ./data/dev.${i}.TriHMM.eval
	# step 3.4 : 在测试集上做评估
	python predictByTriHMM.py ./data/test.txt ./data/model.TriHMM.${i} ./data/test.${i}.TriHMM.predict
	python resultEval.py ./data/test.txt ./data/test.${i}.TriHMM.predict ./data/test.${i}.TriHMM.eval
done
echo "FINISH !!!"