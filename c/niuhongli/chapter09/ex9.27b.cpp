#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
	deque<string> sdeq;
	string str;
	cout << "Please enter string to deque: " << endl;
	while(cin>>str)
	{
		sdeq.push_back(str);
		if(cin.get()=='\n')
			break;
	}
	//输入要删除的特殊值
	cout << "Please enter the string that you want to delete: " << endl;
	cin>> str;
	//找到特殊值并删除
	for(deque<string>::iterator iter=sdeq.begin(); iter!=sdeq.end();++iter)
	{
		if(*iter==str)
		{
			iter=sdeq.erase(iter); //迭代器指向被删除元素的后面元素
			--iter;
		}
	}
	for(deque<string>::iterator it=sdeq.begin();it!=sdeq.end();++it)
		cout << *it << " ";
	return 0;
}
