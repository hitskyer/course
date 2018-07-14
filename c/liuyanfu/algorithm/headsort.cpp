#include <iostream>
using namespace std;

void AdjustDown(int *arr, size_t i, size_t len)
{
	size_t k = 0;
	int temp = 0;
	for(k=2*i+1;k<len;k=2*k+1)
	{
		if(k+1<len && arr[k]<arr[k+1])
			++k;
		if(arr[i] >= arr[k])
			break;
		temp    = arr[i];
		arr[i]  = arr[k];
		arr[k]  = temp;
		i       = k;
	}
}

void MakeMaxHead(int *arr, size_t len)
{
	int i = len / 2 - 1;
	for(;i>=0;--i)
	{
		AdjustDown(arr,i,len);
	}
}

void HeadSort(int *arr, size_t len)
{
	MakeMaxHead(arr,len);
	for(size_t i=0;i<len;++i)
	{
		cout << arr[i] << " " ;
	}
	cout << endl << "最大堆建立完成！" << endl;
	int temp = 0;
	for(size_t i = len-1;i>=0 && i<len;--i)
	{
		temp        = arr[i];
		arr[i]  = arr[0];
		arr[0]      = temp;
		AdjustDown(arr,0,i);
	}
}

