echo "对原始train文件，和预测之后的结果文件，进行对比，输出不同"
alias python='/usr/local/bin/python3.7'
for ((i = 0; i <= 17; i++))
do
  python findDiff.py ../data/train.${i} ../data/train.${i}.BiHMM.predict ../data/mark.diff.${i}
done
