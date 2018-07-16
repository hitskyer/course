#include<iostream>

using namespace std;

int power(int a, int b)
{
	int temp=1;
	for(int i=1;i<=b;++i)
	{
		temp*=a;
	}
	return temp;
}

int main()
{
	cout<<"input two numbers: "<<endl;
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
	return 0;
}
