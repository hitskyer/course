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
	typedef multimap<string,string>::iterator author_iter;
	pair<author_iter,author_iter> author_range = authors.equal_range(key);
	if(author_range.first != author_range.second)
		authors.erase(key);
	else
		cout << "can not find the author:" << key << endl;
	cout << "anthor\t\t work:" << endl;
	for(author_iter iter = authors.begin();iter != authors.end();++iter)
	{
		cout << iter->first << "\t\t " << iter->second << endl;
	}
	return 0;
}