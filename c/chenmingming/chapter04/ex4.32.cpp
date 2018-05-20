#include<iostream>
#include<vector>
using namespace std;
int main()
{
	cout << "enter 5 numbers(int) for arr " << endl;
	size_t n =5;
	int x;
	int arr[n];
	size_t ix =0;
	while(cin >> x)
	{
		arr[ix] = x;
		++ix;
		if(ix ==  n)
			break;
	}
	vector<int> iv;
//	vector<int> iv(arr,arr+n);//????
	ix=0;
	for(vector<int>::size_type index =0; index != n;++index)
	{
		iv.push_back(arr[ix]);
		++ix;
	}
	cout << "vector is ";
	for(vector<int>::iterator it=iv.begin();it!=iv.end();++it)
	{
		cout << *it <<" ";
	}
	return 0;
}
