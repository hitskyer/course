#include <iostream>
using namespace std;

void insertsort(int *arr,size_t len)
{
	size_t i = 1;
	size_t j = 0;
	int temp = 0;
	for(;i<len;++i)
	{
		temp = arr[i];
		for (j=i-1;j>=0 && j<len && temp < arr[j];--j)
		{
				arr[j+1] = arr[j];	
		}
		arr[j+1] = temp;
	}	
}

int main()
{
	int a[10] = {12,2,34,56,7,8,52,21,34,30};
	for(int i =0;i<10;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	insertsort(a,10);
	for(int i=0;i<10;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
