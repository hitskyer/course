#include<iostream>
using namespace std;

string global_str;
int global_int;

int main()
{
	int local_int;
	string local_str;
	cout<<sizeof(global_str)<<endl;
	cout<<sizeof(global_int)<<endl;
	cout<<sizeof(local_int)<<endl;
	cout<<sizeof(local_str)<<endl;
	cout<<"必须初始化，不然报错。int 默认为0."<<endl;
	
	return 0;
}
