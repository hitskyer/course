#include<iostream>
using namespace std;
char flag;
int main()
{
	cout<<"char的存储大小  ："<<sizeof(char)<<"bytes"<<endl;
//	char flag;
	cout<<"char未初始化，输出  ："<<flag<<endl;
	flag ='\115';
	cout<<flag<<endl;
	return 0;
}

