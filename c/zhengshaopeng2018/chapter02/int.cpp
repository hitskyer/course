#include<iostream>
using namespace std;
//int a; 未有变化
int main()
{
	cout<<"int的存储大小是  :"<<sizeof(int)<<"bytes"<<endl;
	int a, min , max;
	cout<<"int型变量未初始化，输出  :"<<a<<endl;
	int sum1=1,sum2=1,pow=2;
	for(int i=0; i !=31; i++)
	sum1 *=pow;  //sum1=sum1*pow
	max  =sum1-1;
	cout<<"int类型的最大值是  : "<<max<<endl;
	++max;//max+1再赋值max
	cout<<"int类型的最大值加1是  : "<<max<<endl;
	for(int a=0 ;a !=31 ; a++)
	sum2 *=pow;
	min  = -sum2;
	cout<<"int类型的最小值是  : "<<min<<endl;
	--min;//min减1再赋值min
	cout<<"int类型的最小值减1  : "<<min<<endl;	
	return 0;
}
