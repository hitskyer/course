#include<iostream>
using namespace std;
int main()
{
	int sum=0;
	for(int i=0;i!=10;i++)
		sum+=i;
	cout<<"Sum from 0 to "<<i<<" is "<<sum<<endl;
	cout<<"程序运行中，i为10 ，但是打印输出时，却是40"<<endl;
	return 0;
}
