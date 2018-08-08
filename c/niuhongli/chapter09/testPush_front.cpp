#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> ilist;
	for (list<int>::size_type ix=0;ix!=4;++ix)
		ilist.push_back(ix);
	for (list<int>::size_type ix=0;ix!=4;++ix)
		ilist.push_front(ix);
	for (list<int>::iterator iter=ilist.begin(); iter!=ilist.end();++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
