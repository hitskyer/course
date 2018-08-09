#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ivec(ia,ia+11);
	list<int> ilist(ia,ia+11);
	
	for(list<int>::iterator iter =ilist.begin(); iter!=ilist.end(); ++iter)
	{
		if (*iter % 2!=0)
		{
			iter=ilist.erase(iter);//返回删除元素后面的迭代器；
			--iter;
		}
	}
	for(vector<int>::iterator vt=ivec.begin(); vt!=ivec.end();++vt)
	{
		if(*vt % 2 ==0)
		{
			vt=ivec.erase(vt);
			--vt;
		}
	}
	cout << "List 中的元素为："  << endl;
	for (list<int>::iterator it=ilist.begin(); it!=ilist.end(); ++it)
		cout << *it << " ";
	cout << "Vector 中的元素为: " << endl;
	for (vector<int>:: iterator iv= ivec.begin(); iv!=ivec.end();++iv)
		cout << *iv << " ";

	return 0;
}
