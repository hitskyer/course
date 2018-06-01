#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string s;
	vector<string> vs;
	while(cin >> s)
		vs.push_back(s);
	char **ps = new char *[vs.size()];
	size_t ix =0;
	for(vector<string>::iterator it= vs.begin();it != vs.end();++it,++ix)
	{
		char *p = new char [(*it).size()+1];
		strcpy(p,(*it).c_str());
		cout << p << " ";
		ps[ix]=p;
	}
	for(ix=0;ix != vs.size();++ix)
	{
		delete [] ps[ix];
	}
	delete [] ps;
	return 0;
}


