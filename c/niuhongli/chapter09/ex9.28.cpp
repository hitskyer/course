#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> svec;
	char* sa[]={"Red", "Blue", "Green", "Yello", "White"};
	list<char*> clist(sa,sa+5);
	//赋值；
	svec.assign(clist.begin(),clist.end());
	
	//输出list中的元素
	for(list<char*>:: iterator iter=clist.begin(); iter!=clist.end(); ++iter)
		cout << *iter << " ";
	//输出vector中的元素
	for(vector<string>:: iterator it=svec.begin();it!=svec.end();++it)
		cout << *it << " ";

	return 0;

}
