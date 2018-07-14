#include<iostream>
using namespace std;

int fac(int n);

int main()
{
	cout<<"input one number"<<endl;
	int a;
	cin>>a;
	for(int i=1;i<=a;++i)
	{
		cout<<i<<"! = "<<fac(i)<<endl;
	}
	return 0;
}

int fac(int n)
{
	static int result=1;
	return result*=n;
}
