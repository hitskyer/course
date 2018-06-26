#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<string*> spvec;
	cout<<"Enter strings (ctrl+d to end)"<<endl;
	string str;
	while(cin>>str)
	{
		string *pstr = new string;
		*pstr=str;
		spvec.push_back(pstr);
	}
	vector<string*>::iterator iter = spvec.begin();
	while(iter!=spvec.end())
	{
		cout<<**iter<<" 's size is "<<(**iter).size()<<endl;
		iter++;
	}
	iter=spvec.begin();
	while(iter!=spvec.end())
	{
		delete * iter;
		iter++;
	}
	return 0;
}
