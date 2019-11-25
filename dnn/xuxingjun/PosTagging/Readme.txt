# step 1 : 分割并生成训练语料、开发语料、测试语料
python corpusSplit.py ../../data/corpus4pos_tagging.txt ../data/
# step 2 : 训练、验证-评估、测试-评估
sh run.sh
