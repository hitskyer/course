#include<iostream>
#include<vector>
using namespace std;

int main()
{
	const size_t array_size=6;
	int arr[array_size];
	
	for (size_t ix=0; ix<array_size;++ix)
		cin >> arr[ix];
	
	vector<int> ive(arr,arr+array_size);
	
	for (vector<int>::iterator iter=ive.begin();iter<ive.end();++iter)
		cout << *iter;
}
