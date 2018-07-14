#include<iostream>
using namespace std;

int max(int i, int * j)
{
	if(i>*j)
		return i;
	else
		return *j;
}

int main()
{
	int a,b;
	int * p;
	p=&b;
	cin>>a>>b;
	cout<<max(a,b)<<endl;
	return 0;
}
