#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> ilist;
	int iv;
	cout << "输入元素到list容器: " << endl;
	while(cin >> iv)
	{
		ilist.push_back(iv);
		if(cin.get()=='\n')
			break;
	}
	if(ilist.empty())
		cout << "No element ? " << endl;
	else
	{
		list<int>::iterator iter1=ilist.begin(), iter2=ilist.end();
		while(iter2!=iter1);
		{
			cout << *(--iter2) << " ";
		}
	}
	return 0;
}
