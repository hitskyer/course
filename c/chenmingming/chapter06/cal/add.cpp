#include<iostream>
using namespace std;
double add(double x,double y)
{
	cout << "请输入两个数做加法：" << endl;
	cin >> x >> y;
	double sum;
	sum = x+y;
	return sum;
}
