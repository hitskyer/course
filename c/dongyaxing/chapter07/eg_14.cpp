#include<iostream>
#include<vector>

using namespace std;

double Sum(vector<double>::const_iterator begin,vector<double>::const_iterator end);

int main()
{
	cout<<"input some double numbers:"<<endl;
	vector<double> dvec;
	double dx;
	while(cin>>dx)
	{
		dvec.push_back(dx);
	}
	cout<<Sum(dvec.begin(),dvec.end())<<endl;
	return 0;
}
//用const_iterator or interator 均可实现功能
double Sum(vector<double>::const_iterator begin,vector<double>::const_iterator end)
{
	double sum=0.0;//若sum=0，则和为整数，小数均被省略
	while(begin!=end)
	{
		sum+=*begin;
		begin++;
	}
	return sum;
}
