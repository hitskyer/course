#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	cout<<"Enter numbers (ctrl + d to end)"<<endl;
	
	int ix;
	while(cin>>ix)
	{
		ivec.push_back(ix);
	}
	for(vector<int>::iterator iter = ivec.begin();iter!=ivec.end();++iter)
	{
		if(*iter % 2!=0)
			*iter *=2;
		cout<<*iter<<endl;
	}
	return 0;
}
