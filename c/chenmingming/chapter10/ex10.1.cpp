#include<string>
#include<utility>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	pair<string,int> pe;
	vector<pair<string,int> > pev;
	while(cin >> pe.first >> pe.second)
		pev.push_back(pe);
	return 0;
}