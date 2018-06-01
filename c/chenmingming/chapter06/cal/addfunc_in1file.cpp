#include<iostream>
#include"cal.h"
using namespace std;
double add(double x,double y)
{
	cout << "请输入两个数做加法：" << endl;
	cin >> x >> y;
	double sum;
	sum = x+y;
	return sum;
}
int main()
{
	double x,y;
	cout << "两数之和为：" << add(x,y) <<endl;
}
