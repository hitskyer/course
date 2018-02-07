#include <iostream>
int main()
{
	using namespace std;
	int x=0 , y=0;			//定义两个变量
	string s;			//定义程序”是否继续“字符s
	do
	{
	cout << "-------------------------------\n请输入两个数做减法！\n";
		while(!(cin >> x >>y))	//判断是否都为数字
			{
			cout << "输入了非数字，请输入两个数字！！！" << endl;
			cin.clear();		//让错误标识改回为0,让我们可以继续输入
			cin.ignore(1000,'\n');  //清空已输入的数据
			}
	cout << "两数之差为：" << x-y << "\n";
	cout << "输入y或者Y继续计算\n输入其他任意字符退出程序。\n" << endl;
	//cin >> s;
	}
	while(cin.get() == 'y' || cin.get() == 'Y');		//输入y或Y继续执行程序
	return 0;
}
