#include<iostream>
#include<vector>
using namespace std;
int main()
{
	const int sz = 5;
	int arr1[sz],arr2[sz];
	size_t ix = 0;
	bool equal;
	cout << "enter " << sz << " numbers for arr1 :" << endl;
	for(ix=0;ix!=sz;++ix)
	{
		cin >> arr1[ix];
	}
	cin.ignore(10000,'\n');
	cout << "enter " << sz << " numbers for arr2 :" << endl;
	for(ix=0;ix!=sz;++ix)
	{
		cin >> arr2[ix];
	}
	for(ix=0;ix != sz;++ix)
	{
		equal = false;
		if(arr1[ix]==arr2[ix])
		{
			equal = true;
		}
	}
	if(equal)
		cout << "2 array equal!" << endl;
	else
		cout << "2 array different !" << endl;
	return 0;
}
