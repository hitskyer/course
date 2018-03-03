#include <iostream>

#include <string>

int main()

{

	using namespace std;

	double x=0 , y=0;			//定义两个变量

	char s;			//定义程序”是否继续“字符s

	do

	{

	cout << "-------------------------------\n请输入两个数做减法！\n";

		while(!(cin >> x >>y))	//判断是否都为数字

			{

			cout << "输入了非数字，请输入两个数字！！！" << endl;

			cin.clear();		//让错误标识改回为0,让我们可以继续输入

			cin.ignore(1000,'\n');  //清空已输入的数据

			}

	cout << x<< " 和 "<< y<< "两数之差为：" << double(x-y) << "\n";

	cout << "输入y或者Y继续计算\n输入其他任意字符退出程序。" << endl;

	cin.ignore(1000,'\n');	//清空2个数，后面多余的输入（比如输入3个数字）

	s=cin.get();

	cin.ignore(1000,'\n');  //清空已输入的数据(比如一长串字符，无效的，多余的

	}

	while(s == 'y' || s == 'Y');	//输入y或Y继续执行程序

	return 0;

}
