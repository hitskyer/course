#include<iostream>

using namespace std;

int abs(int a)
{
	if(a>0)
		return a;
	else
		return -a;
}

int main()
{
	cout<<"get a abs number"<<endl;
	cout<<"input one number: "<<endl;
	int x;
	cin>>x;
	cout<<abs(x)<<endl;
	return 0;
}
