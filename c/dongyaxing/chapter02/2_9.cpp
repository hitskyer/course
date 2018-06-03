#include<iostream>
using namespace std;
int main()
{
	cout<<"cin>>int input_value;非法，不能编译"<<endl;
	int i=3;
	cout<<i<<endl;
	cout<<"int i={3.14};丢失数据，只保留整形"<<endl;
	int i1=3;
	cout<<i1<<endl;
	cout<<"int i1=3.14;丢失数据，只保留整形"<<endl;
	double salary=9999.99;
	double wage=salary;
	cout<<"double salary=wage=9999.99;非法，不能编译\n\r"<<endl;
	cout<<"可以去掉wage=，另外重新定义wage，并赋值"<<endl;
	return 0;
}
