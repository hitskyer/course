#include<vector>
#include<list>
using namespace std;
#include<iostream>
int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	std::vector<int> vec(ia,ia+11);
	list<int> ilist(ia,ia+11);
	for(list<int>::iterator listiter = ilist.begin();listiter != ilist.end();++listiter)
	{
		if(*listiter%2 != 0)
		{
			listiter = ilist.erase(listiter);
			--listiter;
		}
	}
	for(list<int>::iterator listiter = ilist.begin();listiter != ilist.end();++listiter)
	{
		cout << *listiter << " ";
	}
	cout << endl;
	for(vector<int>::iterator vit = vec.begin();vit != vec.end();++vit)
	{
		if(*vit%2 == 0)
		{
			vit = vec.erase(vit);
			--vit;
		}
	}
	for(vector<int>::iterator vit = vec.begin();vit != vec.end();++vit)
	{
		cout << *vit << " ";
	}
	cout << endl;
	return 0;
}