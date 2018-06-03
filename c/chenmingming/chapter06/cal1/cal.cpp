#include<iostream>
#include"./box/cal.h"
using namespace std;
//double add(double,double);
int main()
{
	char ch;
	do
	{
		cout << "请选择要做的运算类型：\n"
			 << "1.加法\n" 
			<< endl;
		int n;
		cin >> n;
		double x,y;
		switch(n)
		{
			case 1 :
				cout << "两数之和为：" << add(x,y) << endl;
				break;
			default:
				cout << "error  !" << endl;
		}
		cout << "请输入Y或者y继续计算，其他字符退出！"<< endl;
		cin >> ch;
	}
	while(ch == 'Y'||ch == 'y');
}
