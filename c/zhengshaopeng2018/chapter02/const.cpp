#include<iostream>
using namespace std;
extern const int a=1;
int main()
{
	const int c =2;	
	int b=0,d=0 ;
	b=a;
	d=c;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
	cout<<"d = "<<d<<endl;
	b =5,d= 6;//改变c与d的变量，确定a有无变化
	cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
	cout<<"c = "<<c<<endl;
	cout<<"d = "<<d<<endl;
	return 0;
}

