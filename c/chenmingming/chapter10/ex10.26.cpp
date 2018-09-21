#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	multimap<string,string> authors;
	string name,work,key;
	do
	{
		cout << "enter author name :" << endl;
		cin >> name;
		if(!cin)
			break;
		cin.clear();
		cin.ignore(1024,'\n');
		cout << "enter author's works: " << endl;
		while(cin >> work)
			authors.insert(make_pair(name,work));
		cin.clear();
	}
	while(cin);
	cin.clear();

	cout << "who is the author you want erase :" << endl;
	cin >> key;
	multimap<string,string>::iterator iter = authors.find(key);
	if(iter != authors.end())
		authors.erase(key);
	else
		cout << "can not find the author:" << key << endl;
	cout << "anthor\t\t work:" << endl;
	for(iter = authors.begin();iter != authors.end();++iter)
	{
		cout << iter->first << "\t\t " << iter->second << endl;
	}
	return 0;
}