#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<string> slist;
	string str;
	cout << "Please enter string to List: " << endl;
	while(cin >> str)
	{
		slist.push_back(str);
		if(cin.get()=='\n')
			break;
	}
	//读入要删除的特殊值
	cout << "Please enter the special string you want to delete: " << endl;
	cin >> str;
	// 找到特殊值，并将其删掉
	for(list<string>::iterator iter=slist.begin(); iter!=slist.end(); ++iter)
	{
		if(*iter==str)
		{
			iter=slist.erase(iter);// 删除，迭代器指向被删除元素后面的迭代器；
			--iter;
		}
	}
	for(list<string>::iterator it=slist.begin(); it!=slist.end();++it)
		cout<< *it <<  " ";
	return 0;
}
