alias python='/usr/local/bin/python3.7'
python3 trainByMaxProb.py ./data/train.0 ./data/model.MaxProb.0
python3 predictByMaxProb.py ./data/train.0 ./data/model.MaxProb.0 ./data/train.0.MaxProb.predict
python3 resultEval.py ./data/train.0 ./data/train.0.MaxProb.predict ./data/train.0.MaxProb.eval
python3 predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.0 ./data/dev.0.MaxProb.predict
python3 resultEval.py ./data/dev.txt ./data/dev.0.MaxProb.predict ./data/dev.0.MaxProb.eval
python3 predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.0 ./data/test.0.MaxProb.predict
python3 resultEval.py ./data/test.txt ./data/test.0.MaxProb.predict ./data/test.0.MaxProb.eval
python3 trainByMaxProb.py ./data/train.1 ./data/model.MaxProb.1
python3 predictByMaxProb.py ./data/train.1 ./data/model.MaxProb.1 ./data/train.1.MaxProb.predict
python3 resultEval.py ./data/train.1 ./data/train.1.MaxProb.predict ./data/train.1.MaxProb.eval
python3 predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.1 ./data/dev.1.MaxProb.predict
python3 resultEval.py ./data/dev.txt ./data/dev.1.MaxProb.predict ./data/dev.1.MaxProb.eval
python3 predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.1 ./data/test.1.MaxProb.predict
python3 resultEval.py ./data/test.txt ./data/test.1.MaxProb.predict ./data/test.1.MaxProb.eval
python3 trainByMaxProb.py ./data/train.2 ./data/model.MaxProb.2
python3 predictByMaxProb.py ./data/train.2 ./data/model.MaxProb.2 ./data/train.2.MaxProb.predict
python3 resultEval.py ./data/train.2 ./data/train.2.MaxProb.predict ./data/train.2.MaxProb.eval
python3 predictByMaxProb.py ./data/dev.txt ./data/model.MaxProb.2 ./data/dev.2.MaxProb.predict
python3 resultEval.py ./data/dev.txt ./data/dev.2.MaxProb.predict ./data/dev.2.MaxProb.eval
python3 predictByMaxProb.py ./data/test.txt ./data/model.MaxProb.2 ./data/test.2.MaxProb.predict
python3 resultEval.py ./data/test.txt ./data/test.2.MaxProb.predict ./data/test.2.MaxProb.eval