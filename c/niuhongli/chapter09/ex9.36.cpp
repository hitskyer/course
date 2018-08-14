#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<char> cvec(10,'h');
	string str(cvec.begin(),cvec.end());
	for(string::iterator iter=str.begin();iter!=str.end();++iter)
		cout << *iter << " ";
	return 0;
}

