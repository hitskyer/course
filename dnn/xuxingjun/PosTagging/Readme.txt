# step 1 : 分割并生成训练语料、开发语料、测试语料
python corpusSplit.py ../../data/corpus4pos_tagging.txt ../data/
# step 2 : 统计词性分布
python staForPosDistribution.py ../data/train.17
# step 3 : 训练、验证-评估、测试-评估
sh run.sh
# step 4 : 错误分析脚本
python resultErr.py ../data/model.TriHMM.17 ../data/test.txt ../data/test.17.TriHMM.predict ../data/test.17.TriHMM.err
