#include <iostream>
using namespace std;

void shellsort(int *arr, size_t len)
{
	size_t i = 0;
	size_t j = 0;
	size_t step = 0;
	int temp = 0;
	for(step=len/2;step>0;step /=2)
	{
		for(i=step;i<len;++i)
		{
			temp = arr[i];
			for(j=i-step;j>=0 && j<len && arr[j]>temp;j=j-step)
			{
				arr[j+step] = arr[j];
			}
			arr[j+step] = temp;
		}
	}
}

int main()
{
	int a[10] = {23,112,34,5,2,15,29,12,78,90};
	for(int i = 0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	shellsort(a,sizeof(a)/sizeof(a[0]));
	for(int i = 0;i<sizeof(a)/sizeof(a[0]);++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
