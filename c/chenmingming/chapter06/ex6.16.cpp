#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1,v2;
	int x;
	bool res = false;
	cout << "请为v1输入一串整数：" << endl;
	while(cin>>x)
	{
		v1.push_back(x);
		if(cin.get()=='\n')
		break;
	}
	cout << "请为v2输入一串整数：" << endl;
	while(cin>>x)
	{
		v2.push_back(x);
		if(cin.get()=='\n')
		break;
	}
	for(vector<int>::size_type ix=0;ix != (v1.size()>v2.size()? v2.size():v1.size());++ix)
		{
			if(v1[ix]!= v2[ix])
			{	res = false;
				break;
			}
			else
			{
				res=true;
			}
		}
		if(res)
			if(v1.size()==v2.size())
			cout << "equal!"<<endl;
			else if(v1.size()<v2.size())
			cout << "v1 is v2's prefix" << endl;
			else
			cout << "v2 is v1's prefix" << endl;
		else
			cout << "the two are no relation !" << endl;
	return 0;
}
