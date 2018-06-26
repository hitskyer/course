#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	vector<int> ivec;
	int val;
	while(cin>>val)
	{
		ivec.push_back(val);
	}
		
	int *pa=new int[ivec.size()];
	size_t ix=0;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();iter++,ix++)
	{
		pa[ix]=*iter;
		cout<<pa[ix]<<" "; 
	}
	delete []pa;
	return 0;
}



