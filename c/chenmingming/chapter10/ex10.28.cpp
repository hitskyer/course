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
	typedef multimap<string,string>::iterator author_iter;
	author_iter iter = authors.begin();
	if(iter == authors.end())
	{
		cout << "empty multimap!" << endl;
		return 0;
	}
	string currauthor,preauthor;
	do
	{
		currauthor = iter->first;
		if(preauthor.empty() || currauthor[0] != preauthor[0])
			cout << "Author names beginning with '" << iter->first[0] << "':" << endl;
		cout << currauthor;
		pair<author_iter,author_iter> author_range = authors.equal_range(iter->first);
		while(author_range.first != author_range.second)
		{
			cout << ", " << author_range.first->second;
			++author_range.first;
		}
		cout << endl;
		iter = author_range.second;
		preauthor = currauthor;
	}
	while(iter != authors.end());
	return 0;
}