#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1;
	vector<int> v2;
	int s;
	cout << "please enter v1 ";
	while(cin >> s)
	{
		v1.push_back(s);
	}
	for(vector<int>::size_type ix=0;ix <v1.size();++ix)
	{
		v2.push_back(v1[ix]);
	}
	cout << "v2 is ";
	for(vector<int>::size_type ix=0;ix < v2.size();++ix)
	{
		cout << v2[ix] << " ";
	}
	return 0;
}
