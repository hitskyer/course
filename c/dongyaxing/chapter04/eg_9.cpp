#include <iostream>
#include <string>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	vector<int>avec,bvec;
	vector<int>::size_type ix;
	int val;
	cout<<"enter numbers into avec[](-1 stop put into)"<<endl;
	cin>>val;
	while(val!=-1)
	{
		avec.push_back(val);
		cin>>val;
	}
	cout<<"enter numbers into bvec[](-1 stop put into)"<<endl;
	cin>>val;
	while(val!=-1)
	{
		bvec.push_back(val);
		cin>>val;
	}
	for(vector<int>::iterator jx=avec.begin(),kx=bvec.begin();jx!=avec.end(),kx!=bvec.end();jx++,kx++)
	{
		if(avec.size()!=bvec.size())
		{
			cout<<"两个数组不相等"<<endl;
			return 0;
		}
		else if(*jx!=*kx)
		{
			cout<<"两个数组不相等"<<endl;
			return 0;
		}
	}
	cout<<"两个数组相等"<<endl;
	return 0;
}





