#include<iostream>
#include<list>
#include<string>
using namespace std;

int main()
{
	list<string> slist;
	string word;
	while(cin >> word)
	{
		slist.push_back(word);
		if(cin.get()=='\n')
			break;
	}
	for(list<string>::iterator iter=slist.begin();iter!=slist.end();++iter)
		cout << *iter << " ";
	cout << endl;
	list<string>:: iterator elem1, elem2;
	string val1("wo"),val2("ni");
	elem1=find(slist.begin(),slist.end(), val1);
	elme2=find(elem1,slist.end(),val2);
	slist.erase(elem1,elem2);
	for(list<string>::iterator iter=slist.begin();iter!=slist.end();++iter)
		cout << *iter << " ";
	cout << endl;
}
