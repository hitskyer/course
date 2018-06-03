#include<iostream>
using namespace std;
int fac(int n)
{
	int res = 1;
	for(int i =1;i<=n;++i)
		res *= i;
	return res;
}

int main()
{
	cout << "输入n："<< endl;
	int n;
	cin >> n;
	cout << "n的阶乘是："<< fac(n) << endl;
	return 0;
}
