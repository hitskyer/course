#include <iostream>

using namespace std;

void bucketsort(int* arr, size_t dsize)
{
	int div   = 1000;
	int maxval=arr[0];
	int minval=arr[0];
	for(size_t i=1;i<dsize;++i)
	{
		maxval = maxval<arr[i]?arr[i]:maxval;
		minval = minval>arr[i]?arr[i]:minval;
	}
}
