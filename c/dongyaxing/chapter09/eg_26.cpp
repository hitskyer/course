#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	list<int> ilst(arr,arr+10);
	vector<int> ivec(arr,arr+10);
	
	list<int>::iterator its=ilst.begin();
	vector<int>::iterator itv=ivec.begin();
	
	for(;its!=ilst.end();++its)
	{
		if(*its % 2 == 1)
		{
			ilst.erase(its);
			--its;
		}
	}
	for(;itv!=ivec.end();++itv)
	{	
		if(*itv % 2 == 0)
		{
			ivec.erase(itv);
			--itv;
		}
	}
	
	its=ilst.begin();
	itv=ivec.begin();
	
	while(its!=ilst.end())
	{
		cout<<*its<<endl;
		its++;
	}
	while(itv!=ivec.end())
	{
		cout<<*itv<<endl;
		itv++;
	}
	return 0;
}
