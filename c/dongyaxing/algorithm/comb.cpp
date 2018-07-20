#include<iostream>
#include<stdio.h>
using namespace std;

/*typedef struct paike
{
	int c[40];
	int a[5];
	int b[6];	
}pk;
*/
int main()
{
	int a[5]={0,1,2,3,4};
	int b[6]={5,6,7,8,9,10};
	int c[60],i,j,index=0;
	cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
	cout<<b[0]<<b[1]<<b[2]<<b[3]<<b[4]<<b[5]<<endl;
	for(i=0;i!=5;++i)
	{
		for(j=0;j!=6;++j)
		{
		c[index++]=a[i];
		c[index++]=b[j];
		}
	}
	for(index=0;index!=60;++index)
	{
		cout<<c[index]<<",";
	}
	cout<<endl;
	return 0;
}



