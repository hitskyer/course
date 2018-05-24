echo "我们提供以下服务:"
echo -n "1)ls"

echo -n "2)ls -l"

echo -n "3)Exit"

echo "please choice[1-3]"

read ch

case $ch in
	1) ls;;
	2) ls -l;;
	3) exit;;
	*) echo "wrong choice!!";;
esac
