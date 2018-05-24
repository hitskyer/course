#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	vector<int> vint;
	int x;
	while(cin >> x)
		vint.push_back(x);
	
	int *arr = new int[vint.size()];
	size_t index = 0;
	for(vector<int>::iterator it=vint.begin();it != vint.end();++it)
	{
		arr[index] = *it;
		cout << arr[index] << " ";
		++index;
	}
	delete[]arr;
	return 0;
}
