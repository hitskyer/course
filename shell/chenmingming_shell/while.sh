end=1000
while [ $end -le 1003 ]
do
	echo "请输入$end 的信息！"
	echo -n "name:"
	read name
	echo -n "email:"
	read email
	echo "Name:$name Email:$email">> man.dat
	((end=$end+1))
done
