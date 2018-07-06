#include<iostream>
using namespace std;

int fac(int x) //形参 
{
	static int result=1; // static 变量
	result*=x;
	return result;
}

int main()
{
	int LimValue;
	cout << "The upper limit  value is : " << endl;
	cin >> LimValue;
	int frac=1;
	for (int i=1;i<=LimValue;++i)
		frac=fac(i);
	cout << LimValue << "!= " << frac << endl;
	return 0;
}
