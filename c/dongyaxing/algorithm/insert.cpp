#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//插入排序
void insertfun(int *arr,size_t length)
{
	int i,j;
	for(i=2;i<length;++i)
	{
		if(arr[i]<arr[i-1])
		{
			arr[0]=arr[i];
			for(j=i-1;arr[0]<arr[j];--j)
			{
				arr[j+1]=arr[j];
			}
			arr[j+1]=arr[0];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL)); //随机数
	int n;
	n=rand()%100+1;
	int arr[21]={0};
	for(int i=1;i<21;++i)
	{
		n=rand()%100+1;
		arr[i]=n;
	}
	insertfun(arr,21);
	for(int i=1;i<21;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
