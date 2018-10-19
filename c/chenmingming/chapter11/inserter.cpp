#include<list>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	list<int> ilist,ilist2,ilist3;
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);
	// vector<int> ivec;
	// ivec.push_back(6);
	// ivec.push_back(7);
	//list<int>::iterator it = find(ilist.begin(),ilist.end(),2);
	copy(ilist.begin(),ilist.end(),front_inserter(ilist2));
	for(list<int>::iterator it = ilist2.begin(); it != ilist2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	copy(ilist.begin(),ilist.end(),inserter(ilist3,ilist3.begin()));
	for(list<int>::iterator it = ilist3.begin(); it != ilist3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}