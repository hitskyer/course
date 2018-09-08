#include<iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
	list<int> intlist;
	int val;
	deque<int> intdeque1, intdeque2;
	while(cin >> val)
	{
		intlist.push_back(val);
	}
	for(list<int>::iterator iter = intlist.begin(); iter != intlist.end();++iter)
	{
		if(*iter%2==1)
			intdeque1.push_back(*iter);
		else
			intdeque2.push_back(*iter);
	}
	deque<int>::iterator it;
	it = intdeque1.begin();
	cout << "奇数队列： " << endl;
	while(it != intdeque1.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
	it = intdeque2.begin();
	cout << "偶数队列： " << endl;
	while(it != intdeque2.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
	return 0;
}