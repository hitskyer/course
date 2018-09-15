#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	int ia[] = {0,1,2,3,4,5,6,0,8,9};
	list<int> ilist(ia,ia+10);
	list<int>::reverse_iterator r_iter;
	r_iter = find(ilist.rbegin(),ilist.rend(),0);
	if(r_iter != ilist.rend())
		cout << *r_iter << endl;
	return 0;
}