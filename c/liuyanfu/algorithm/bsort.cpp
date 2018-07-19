#include <iostream>
using namespace std;

void bsort(int *arr,size_t len)
{
	size_t i    = 0;
	size_t j    = 0;
	int    temp = 0;
	for(;i<len-1;++i)
	{
		for(j=0;j<len-i-1;++j)
		{
			if(arr[j]>arr[j+1])
			{
				temp   = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int a[10] = {12,2,45,29,31,3,15,67,49,23};
	for(int i=0;i<10;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	bsort(a,10);
	for(int i=0;i<10;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
