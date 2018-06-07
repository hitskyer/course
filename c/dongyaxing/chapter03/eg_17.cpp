#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	cout<<"print ten original elements:"<<endl;
	for(vector<int>::size_type ix=0;ix!=10;ix++)
	{
		
		ivec.push_back(ix+1);
		cout<<ivec[ix]<<" "<<endl;
	}
	cout<<"print ten processed elements:"<<endl;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();iter++)
	{
		
		*iter *=2;
		cout<<*iter<<" "<<endl;
	}
	return 0;
}
