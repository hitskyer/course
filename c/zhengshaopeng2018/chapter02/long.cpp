#include<iostream>
using namespace std;
//long a;
int main()
{
	cout<<"long的存储大小为  : "<<sizeof(long)<<" bytes"<<endl;
	long  sum1=1,pow=2;
	for(int i = 0;i != 63; i++)
	sum1 *=pow ;	//sum1=sum1*pow
	long max =0;
	max =sum1-1;
	cout<<"long的最大赋值是  : "<<max<<endl;
	++max;		//max加一再赋值
	cout<<"long的最大赋值加1是  : "<<max<<endl;
	long min =0;
	min = -sum1;
	cout<<"long的最小赋值是  : "<<min<<endl;
	--min;
	cout<<"long的最小赋值减1是  : "<<min<<endl;
//	cout<<a<<endl;
	return 0;
}
