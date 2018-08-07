#include<iostream>

using namespace std;
//交换函数
void swap(int &i, int &j)
{
	int temp;
	temp=i;
	i=j;
	j=temp;
}
//冒泡方案--0
void bobsort0(int *r, size_t length)
{
	int i,j;
	for(i=0; i<length-1;++i)
	{
		for(j=i+1; j<length; ++j)
		{
			if(r[i]>r[j])
			{ swap(r[i], r[j]); }
		}
	}
}
//冒泡方案--1
void bobsort1(int *r, size_t length)
{
	for(int i=0; i<length-1;++i)
	{
		for(int j=length-1; j>=i;--j)
		{
			if(r[j-1]>r[j])
				swap(r[j-1],r[j]);
		}
	}
}
//冒泡方案--2   加标签flag ，判断后面是否全部排好
void bobsort2(int *r, size_t length)
{
	int i,j;
	bool flag=true;
	for(i=0; i<length && flag; ++i)
	{
		flag=false;
		for(j=length-1; j>=i; --j)
		{
			if(r[j-1]>r[j])
			{
				swap(r[j-1], r[j]);
				flag=true;
			}
		}
	}
}
//选择排序
void selectsort(int *r, size_t length)
{
	int i,j,min;
	for(i=0; i<length-1; ++i)
	{
		min=i;
		for(j=i+1; j<length; ++j)
		{
			if(r[min]>r[j])
			{	min=j;}
		}
		if(i!=min)
		{
			swap(r[i],r[min]);
		}
	}
}


int main()
{
	int arr[10]={32,34,45,30,28,39,53,56,48,40};
	//bobsort0(arr,10);
	//bobsort1(arr,10);
	//bobsort2(arr,10);
	selectsort(arr,10);
	for(int i=0;i<10;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
