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

	slist1=slist2;
	//等价于
	slist1=assign(slist2.begin(),slist.end());

	slist1.assign(10,"Hello");
	//等价于
	slist1.clear();
	slist1.insert(slist1.begin(),10,"Hello");
	return 0;
}
