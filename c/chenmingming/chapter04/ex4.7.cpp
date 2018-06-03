#include<iostream>
using namespace std;
int main()
{
	const int sz = 5;
	int arr1[sz] = {2,3,4,5};
	int arr2[sz];
	cout << "arr1 is ";
	for(size_t ix=0;ix < sz;++ix)
	{
		cout << arr1[ix] << " ";
	}
	cout << "arr2 is ";
	for(size_t ix=0;ix < sz;++ix)
	{
		cout << arr2[ix] << " ";
	}
	cout << "copy arr1 to arr2, so arr2 is ";
	for(size_t ix=0;ix < sz;++ix)
	{
		arr2[ix] = arr1[ix];
		cout << arr2[ix] << " ";
	}
	return 0;
}
