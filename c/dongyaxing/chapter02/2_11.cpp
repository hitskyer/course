#include<iostream>
using namespace std;
int main()
{
	int base,exponent;
	long long result=1;
	cout<<"请输入一个底数，一个指数："<<endl;
	cin>>base>>exponent;
	for(int i=1;i<=exponent;i++)
	{
		result*=base;
	}
	cout<<base<<"^"<<exponent<<"="<<result<<endl;
	return 0;
}
