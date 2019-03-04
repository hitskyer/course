#include<iostream>
#include<list>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	list<string> slst;
	string str;
	cout<<"enter some string s (ctrl+d to end):"<<endl;
	
	while(cin>>str)
	{
		slst.push_back(str);
	}
	cin.clear();
	
	cout<<"enter some string you want to find(ctrl+d to end):"<<endl;
	string str1;
	
	cin>>str1;
	
	/*list<string>::iterator iter;
	iter=find(slst.begin(),slst.end(),str);
	--iter;
	slst.erase(iter);
	*/
	
	for(list<string>::iterator iter=slst.begin();iter!=slst.end();++iter)
	{
		if(*iter == str)
		{
			iter = slst.erase(iter);
			--iter;
		}
	}
	
	for(list<string>::iterator iter2=slst.begin();iter2!=slst.end();++iter2)
	{
		cout<<*iter2<<"  ";
	}
	cout<<endl;
	return 0;
}
