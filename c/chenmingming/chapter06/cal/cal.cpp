#include<iostream>
#include"cal.h"
using namespace std;
int main()
{
	cout << "请选择要做的运算类型：\n"
		 << "1.加法\n" 
		<< endl;
	int n;
	cin >> n;
	switch(n)
	{
		case 1 :
			double add(double x,double y);
			break;
		default:
			cout << "error  !" << endl;
	}
}

