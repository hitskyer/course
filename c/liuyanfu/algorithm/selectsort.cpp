#include <iostream>
using namespace std;

void selectsort(int *arr,size_t len)
{
	size_t i = 0;
	size_t j = 0;
	int temp = 0;
	size_t k = 0;
	for(;i<len-1;++i)
	{
		k = i;
		for(j=i+1;j<len;++j)
		{
			if(arr[k]>arr[j])
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp   = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}	
}

int main()
{	
	int a[10] = {12,2,34,22,15,56,62,45,29,10};
	for(int i = 0;i<10;++i)
	{
		cout << a[i] << " ";
	
	}
	cout << endl;
	selectsort(a,10);
	for(int i =0;i<10;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
