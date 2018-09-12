#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
	list<int> ilst;
	vector<int> ivec;
	int ival;
	cout<<"input some value to list(ctrl+d to end): "<<endl;
	while(cin>>ival)
	{
		ilst.push_back(ival);
	}
	cin.clear();
	
	cout<<"input some value to vector(ctrl+d to end): "<<endl;
	while(cin>>ival)
	{
		ivec.push_back(ival);
	}
	cin.clear();
	
	//compare;
	list<int>::iterator its=ilst.begin();
	vector<int>::iterator itv=ivec.begin();
	while(its!=ilst.end() && itv!=ivec.end())
	{
		if(*its!=*itv)
			break;
		else
			++its;
			++itv;
	}
	if(its==ilst.end() && itv==ivec.end())
		cout<<"list = vector"<<endl;
	else
		cout<<"list != vector"<<endl;
	
	return 0;
}

