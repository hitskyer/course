#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int val;
	vector<int> v1;
	while(cin>>val)
		v1.push_back(val);
	vector<int>::iterator pv = v1.begin();
	int arr[v1.size()];
	int *pa =arr;
	for(;pv != v1.end();++pv,++pa)
	{
		*pa = *pv;
		cout << *pa << " ";
	}
//	delete[]pa;
	return 0;
}
