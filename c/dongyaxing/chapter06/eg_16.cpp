#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec1,ivec2;
	int ival;
	cout<<"enter elements for the first vector:(32767 to end)"<<endl;
	cin>>ival;
	while(ival!=32767)
	{
		ivec1.push_back(ival);
		cin>>ival;
	}
	cout<<"enter elements for the second vector:(32767 to end)"<<endl;
	cin>>ival;
	while(ival!=32767)
	{
		ivec2.push_back(ival);
		cin>>ival;
	}
	
	vector<int>::size_type size1,size2;
	size1=ivec1.size();
	size2=ivec2.size();
	bool result=true;
	for(vector<int>::size_type ix=0;ix!=(size1>size2?size2:size1);ix++)
	{
		if(ivec1[ix]!=ivec2[ix])
		{
			result=false;
			break;
		}
	}
	if(result)
	{
		if(size1==size2)
		{
		cout<<"The first vector is equal to the second vector"<<endl;
		}
		else if(size1>size2)
		{cout<<"The first vector is bigger than the second vector"<<endl;}
		else
		{cout<<"The second vector is bigger than the second vector"<<endl;}
		
	}
	else
	{cout<<"No elements is equal"<<endl;}		
	return 0;
}
