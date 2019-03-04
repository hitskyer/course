#include<iostream>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int main()
{
	string str;
	int ival;
	pair<string,int> sipr;
	vector<pair<string, int> > pvec;

	cout<<"input string and int value(enter + ctrl +d to end)"<<endl;
	
	while(cin>>str>>ival)
	{
		//1 方案：
		//sipr.first = str;
		//sipr.second = ival;

		//2 方案：
		sipr = make_pair(str, ival);
		
		//3 方案：
		//pair<string, int> sipr(str,ival);
		
		pvec.push_back(sipr);	
	}
	
	cout<<"output vector content:"<<endl;
	
	for(vector<pair<string, int> > ::iterator iter = pvec.begin(); iter!=pvec.end();++iter)
	{
		cout<<(*iter).first<<","<<(*iter).second<<endl;
	}
	cout<<endl;
	return 0;
}
