#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int main()
{
	const char* sa[]={"a","b","c","d"};
	list<char*> slst(sa,sa+4);
	vector<string> svec;
	string str;
	
	//将list所有对象赋值给vector对象
	svec.assign(slst.begin(),slst.end());
	
	//输出list对象中的元素
	for(list<char*>::iterator iter=slst.begin();iter!=slst.end();++iter)
	{
		cout<<*iter<<"  ";
	}
	cout<<endl;

	for(vector<string>::iterator iter2=svec.begin();iter2!=svec.end();++iter2)
	{
		cout<<*iter2<<"  ";
	}
	cout<<endl;
	return 0;

}
