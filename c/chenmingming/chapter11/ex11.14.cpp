#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main(int argc, char **argv)
{
	int ia[] = {1,2,3,4,99,5,99};
	vector<int> ivec(ia,ia+7);
	list<int> ilist;
	replace_copy(ivec.begin(),ivec.end(),inserter(ilist,ilist.begin()),99,88);
	for(list<int>::iterator iter = ilist.begin();iter != ilist.end();++iter)
		cout << *iter << " ";
	cout << endl;
	ilist.clear();
	replace_copy(ivec.begin(),ivec.end(),back_inserter(ilist),99,88);
	for(list<int>::iterator iter = ilist.begin();iter != ilist.end();++iter)
		cout << *iter << " ";
	cout << endl;
	ilist.clear();
	replace_copy(ivec.begin(),ivec.end(),front_inserter(ilist),99,88);
	for(list<int>::iterator iter = ilist.begin();iter != ilist.end();++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}