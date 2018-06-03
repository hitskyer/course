#include<iostream>
using namespace std;
int main()
{
	int a=1 ,b=2;
	int &c=a ,&d=b, &e=a;
	cout<<"c = "<<c<<endl;
	cout<<"d = "<<d<<endl;
	cout<<"请输入两个数字 ："<<endl;
	cin>>c>>d;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"请输入一个数字 ："<<endl;
	cin>>e;
	cout<<"a = "<<a<<endl;
	cout<<"c = "<<c<<endl;
	return 0;
}

	
