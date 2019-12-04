echo "将python的路径改为当前机器环境下的路径"
alias python='/usr/local/bin/python3.7'
for ((i=0; i<=17; i++))
do
	# step 1 : 最大概率模型
	# step 1.1 : 训练模型
	python trainByMaxProb.py ./data/train.${i} ./data/model.MaxProb.${i}
	# step 1.2 : 在训练集上做评估
	python predictByMaxProb.py ./data/train.${i} ./data/model.MaxProb.${i} ./data/train.${i}.MaxProb.predict
	python resultEval.py ./data/train.${i} ./data/train.${i}.MaxProb.predict ./data/train.${i}.MaxProb.eval
	# step 1.3 : 在开发集上做评估
	python predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.${i} ./data/dev.${i}.MaxProb.predict
	python resultEval.py ./data/dev.txt ./data/dev.${i}.MaxProb.predict ./data/dev.${i}.MaxProb.eval
	# step 1.4 : 在测试集上做评估
	python predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.${i} ./data/test.${i}.MaxProb.predict
	python resultEval.py ./data/test.txt ./data/test.${i}.MaxProb.predict ./data/test.${i}.MaxProb.eval
	
	# step 2 : BiHMM模型
	# step 2.1 : 训练模型
	python trainByBiHMM.py ./data/train.${i} ./data/model.BiHMM.${i}
	# step 2.2 : 在训练集上做评估
	python predictByBiHMM.py ./data/train.${i} ./data/model.BiHMM.${i} ./data/train.${i}.BiHMM.predict
	python resultEval.py ./data/train.${i} ./data/train.${i}.BiHMM.predict ./data/train.${i}.BiHMM.eval
	# step 2.3 : 在开发集上做评估
	python predictByBiHMM.py ./data/dev.txt ./data/model.BiHMM.${i} ./data/dev.${i}.BiHMM.predict
	python resultEval.py ./data/dev.txt ./data/dev.${i}.BiHMM.predict ./data/dev.${i}.BiHMM.eval
	# step 2.4 : 在测试集上做评估
	python predictByBiHMM.py ./data/test.txt ./data/model.BiHMM.${i} ./data/test.${i}.BiHMM.predict
	python resultEval.py ./data/test.txt ./data/test.${i}.BiHMM.predict ./data/test.${i}.BiHMM.eval
done
