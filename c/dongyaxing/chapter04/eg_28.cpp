#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	vector<int>ivec;
	int ival;
	cout<<"Enter numbers:"<<endl;
	while(cin>>ival)
	{
		ivec.push_back(ival);
	}
	int *pia =new int[ivec.size()];
	int *tp = pia;
	for(vector<int>::iterator iter =ivec.begin();iter!=ivec.end();iter++,tp++)
	{
		*tp=*iter;
		cout<<*tp<<" ";
	}
	delete [] pia;
	return 0;
}





