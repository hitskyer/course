//未完待续。。。

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> svec;
	vector<int> ivec;
	string str;
	int cnt=0;
	while(cin>>str)
	{
		svec.push_back(str);
		if(str==quit)
			continue;
	}
	for(vector<int>::size_type ix=0;ix!=svec.size();++ix)
	{
		for(vector<int>::size_type jx=1;jx!=svec.size();++jx)
		{
			if(svec[ix]==svec[jx])
			{
				ivec.push_back(1);
			}
			
		}
		if(svec[ix]==svec[ix+1])
			ivec.push_back(ix++);
	}
	return 0;

}
