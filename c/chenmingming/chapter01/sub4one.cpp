#include <iostream>
int main()
{
	using namespace std;
	int x=0 , y=0;
	string s;
	do
	{
	cout << "-------------------------------\n请输入两个数做减法！\n";
	cin >> x >> y;
	cout << "两数之差为：" << x-y << "\n";
	cout << "输入y或者Y继续计算\n输入其他任意字符退出程序。\n" << endl;
	cin >> s;
	}
	while(s == "y" || s == "Y");
	return 0;
}
