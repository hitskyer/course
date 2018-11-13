#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string sval, searchValue;
	list<string> slst;
	cout<<"enter some string: "<<endl;
	while(cin>>sval)
	{
		slst.push_back(sval);
	}
	
	cin.clear();

	cout<<"enter a string you want to search: "<<endl;
	cin>>searchValue;
	cout<<count(slst.begin(), slst.end(), searchValue)<<" elements in the list are "<<searchValue<<endl;
	return 0;
}
