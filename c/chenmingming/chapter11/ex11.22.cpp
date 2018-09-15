#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> ivec(ia,ia+10);
	vector<int>::reverse_iterator r_iter = ivec.rbegin()+3;
	vector<int>::reverse_iterator r_iter1 = ivec.rbegin()+8;
	list<int> ilist;
	copy(r_iter,r_iter1,inserter(ilist,ilist.begin()));
	list<int>::iterator iter = ilist.begin();
	for(;iter != ilist.end();++iter)
		cout << *iter << " ";
	return 0;
}