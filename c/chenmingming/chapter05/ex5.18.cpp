#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	vector<string*> vecs;
	cout << "enter some strings !" << endl;
	string s;
	while(cin >> s)
	{	
		string *p = new string;
		*p = s;
		vecs.push_back(p);
	}
	for(vector<string*>::iterator it= vecs.begin(); it != vecs.end(); ++it)
	{
		cout << **it << (**it).size() << endl;
	}
	for(vector<string*>::iterator it= vecs.begin(); it != vecs.end(); ++it)
	{
		delete *it;
	}
	return 0;
}
