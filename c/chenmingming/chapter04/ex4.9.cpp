#include<iostream>
using namespace std;
int main()
{
	int arr1[10];
	size_t ix = 0;
	for(;ix != 10;++ix)
	{
		arr1[ix]=ix+1;
	}
	for(ix=0; ix != 10;++ix)
	{
		cout << arr1[ix] << " ";
	}
	return 0;
}
