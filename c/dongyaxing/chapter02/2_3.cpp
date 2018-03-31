#include<iostream>
using namespace std;
int main()
{
	unsigned u=10,u2=42;
	cout<<u2-u<<endl;
	cout<<u-u2<<endl;

	int i=10,i2=42;
	cout<<i2-i<<endl;
	cout<<i-i2<<endl;

	cout<<i-u<<endl;
	cout<<u-i<<endl;
	cout<<i-u2<<endl;
	cout<<u-i2<<endl;
	cout<<"带符号的转换为无符号，然后输出视主机int所占位数而定"<<endl;
	cout <<"32bits系统，结果为：2^32+10-42=4294967264"<<endl;
	return 0;
}
