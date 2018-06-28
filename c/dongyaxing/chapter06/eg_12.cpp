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
	while(cin>>str)
	{
		svec.push_back(str);
		ivec.push_back(1);
	}
	for(vector<int>::size_type ix=0;ix!=svec.size();++ix)
	{
		for(vector<int>::size_type jx=1;jx!=svec.size();++jx)
		{
			if(svec[ix]==svec[jx])
			
		}
		if(svec[ix]==svec[ix+1])
			ivec.push_back(ix++);
	}
	return 0;

}
