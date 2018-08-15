#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<string> slist;
	string str;
	cout << "Please enter string to vector: " << endl;
	while(cin >> str)
	{
		slist.push_back(str);
		if(cin.get()=='\n')
			break;
	}
	cout << "Output elements in list:" << endl;
	for(list<string>::iterator iter=slist.begin();iter!=slist.end();++iter)
		cout << *iter << " ";
	return 0;
}