#include<iostream>
using namespace std;
long int power(int a,int b)
{
	long int res = 1;
	for(int i=0;i != b;++i)
	{
		res *= a;
	}
	return res;
}

int main()
{
	long int z=0;
	cout << "输入两个数，求幂指数。" << endl;
	int x,y;
	cin >> x >>y;
	z=power(x,y);
	cout << x << " 的 "  << y << " 次幂是： " << z <<endl;
	return 0;
}
