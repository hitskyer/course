# mkdir ./good/bad
#echo $HOME
#expr 4 + 5
#echo "the date is `date`"
#read fa
#echo ${fa}
#i=xxx
#echo $i
#echo "hah ,you did it !"
read a
read b
echo $((a-b))
if [ $a -lt 80 ]
then
	echo "wrong!!!"
elif [ $a -ge 80 -a $a -lt 90 ]
then 
	echo "good!!!"
else
	echo "very good!!!"
fi
