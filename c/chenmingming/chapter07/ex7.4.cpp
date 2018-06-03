#include<iostream>
using namespace std;
double abs(double a)
{
	if(a < 0)
		a = -a;
	return a;
}

int main()
{
	cout << "输入一个数，求其绝对值！"<< endl;
	double x;
	cin >> x;
	cout << x << " 的绝对值是 " << abs(x) << endl;
	return 0;
}
