#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	vector<string> vecs;
	string s;
	while(cin>>s)
	{
		vecs.push_back(s);
	}
	string prewd,curwd,maxwd;
	int maxnum=1,curnum=0;
	for(vector<string>::iterator it = vecs.begin();it != vecs.end();++it)
	{
		if(prewd== *it)
		{
			++curnum;
		}
		else
		{
			if(curnum>maxnum)
			{
				maxnum=curnum;
				maxwd= prewd;
			}
			curnum=1;
		}
		prewd= *it;
	}
	if(maxnum != 1)
	cout << maxnum << " words " << maxwd << " occured!" << endl;
	else
	cout << "no repeated word." <<endl;
	return 0;
}
