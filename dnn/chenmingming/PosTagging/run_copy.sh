do
	python trainByMaxProb.py ./data/train.0 ./data/model.MaxProb.0
	python predictByMaxProb.py ./data/train.0 ./data/model.MaxProb.0 ./data/train.0.MaxProb.predict
	python resultEval.py ./data/train.0 ./data/train.0.MaxProb.predict ./data/train.0.MaxProb.eval
	python predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.0 ./data/dev.0.MaxProb.predict
	python resultEval.py ./data/dev.txt ./data/dev.0.MaxProb.predict ./data/dev.0.MaxProb.eval
	python predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.0 ./data/test.0.MaxProb.predict
	python resultEval.py ./data/test.txt ./data/test.0.MaxProb.predict ./data/test.0.MaxProb.eval

	python trainByMaxProb.py ./data/train.1 ./data/model.MaxProb.1
	python predictByMaxProb.py ./data/train.1 ./data/model.MaxProb.1 ./data/train.1.MaxProb.predict
	python resultEval.py ./data/train.1 ./data/train.1.MaxProb.predict ./data/train.1.MaxProb.eval
	python predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.1 ./data/dev.1.MaxProb.predict
	python resultEval.py ./data/dev.txt ./data/dev.1.MaxProb.predict ./data/dev.1.MaxProb.eval
	python predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.1 ./data/test.1.MaxProb.predict
	python resultEval.py ./data/test.txt ./data/test.1.MaxProb.predict ./data/test.1.MaxProb.eval

	python trainByMaxProb.py ./data/train.2 ./data/model.MaxProb.2
	python predictByMaxProb.py ./data/train.2 ./data/model.MaxProb.2 ./data/train.2.MaxProb.predict
	python resultEval.py ./data/train.2 ./data/train.2.MaxProb.predict ./data/train.2.MaxProb.eval
	python predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.2 ./data/dev.2.MaxProb.predict
	python resultEval.py ./data/dev.txt ./data/dev.2.MaxProb.predict ./data/dev.2.MaxProb.eval
	python predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.2 ./data/test.2.MaxProb.predict
	python resultEval.py ./data/test.txt ./data/test.2.MaxProb.predict ./data/test.2.MaxProb.eval
done