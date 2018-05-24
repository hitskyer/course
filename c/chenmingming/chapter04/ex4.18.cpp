#include<iostream>
using namespace std;
int main()
{
	int arr[5]={1,2,3,4,5};
	int *p=arr;
	size_t ix=0;
	for(;ix != 5;++ix)
	{
		*p = 0;
		cout << arr[ix] << " ";
		++ p;
	}
	return 0;
}
