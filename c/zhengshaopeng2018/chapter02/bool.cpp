#include<iostream>
using namespace std;
bool test;
int main()

{
//	bool test;
	cout<<"bool型的存储大小为  :"<<sizeof(bool)<<"bytes"<<endl;
	cout<<test<<endl;//未定义变量时输出的数值
	test = 0;
	cout<<"bool赋值为0，输出是  ："<<test<<endl;
	test = 1;
	cout<<"bool赋值为1，输出是  ："<<test<<endl;
	test = 2;
	cout<<"bool赋值为2，输出是  ："<<test<<endl;
	return 0;	
}		

