#include<iostream>
using namespace std;

int factorial(int a);

int main()
{
	cout<<sizeof(int)<<endl;
	cout<<"input one number,you can get its factorial"<<endl;
	int n;
	cin>>n;
	cout<<factorial(n)<<endl;
	return 0;
}

int factorial(int a)
{
	int result=1;
	for(int i=1;i<=a;++i)
	{
		result*=i;
	}
	return result;
}
