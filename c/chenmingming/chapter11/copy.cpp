#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
int main()
{
	vector<int> ivec;
	ivec.push_back(9);
	list<int> ilist;
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(2);
	ilist.push_back(3);
	replace_copy(ilist.begin(),ilist.end(),back_inserter(ivec),2,6);
	for(list<int>::iterator it = ilist.begin();it != ilist.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	for(vector<int>::iterator it = ivec.begin();it != ivec.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}