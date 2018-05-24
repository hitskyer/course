#include<iostream>
using namespace std;
//short a;
int main()
{
	cout<<"short的存储大小为  ："<<sizeof(short)<<"bytes"<<endl;
	short a,max,min;
	cout<<"short未初始化，输出值是  ："<<a<<endl;
	
	int sum1 =1,sum2 =1,pow =2;
	for(int i = 0; i != 15 ; i++)
	sum1 *=pow;   //sum1 =sum1*pow	
	max =sum1-1;
	cout<<"short的最大取值为  ："<<max<<endl;
	max++;
	cout<<"short的最大值加1为 ："<<max<<endl;
	for(int a = 0;a!= 15 ; a++)
	sum2 *=pow;
	min  =-sum2;
	cout<<"short的最小值为  ："<<min<<endl;
	min--;
	cout<<"short的最小值减1为  :"<<min<<endl;
	return 0;
}
