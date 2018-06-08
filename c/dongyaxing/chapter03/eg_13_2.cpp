#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;
	vector<int> sum;
	//读入数据到vector对象
	cout<<"enter numbers(any char to end):"<<endl;
	while(cin>>ival)
	{
			ivec.push_back(ival);
	}
	//计算相邻和，并输出
	if(ivec.size()==0)
	{
		cout<<"No elements!?"<<endl;
		return -1;
	}
	cout<<"Sum of each pair of adjacent elements in the vector:"
		<<endl;
	for(vector<int> ::size_type ix=0;ix<ivec.size()-1;ix+=2)
	{
		cout<<ivec[ix]+ivec[ix+1]<<"\t";
		if((ix+1)%6==0)
		{
			cout<<endl; //每行输出6个和
		}
	}
	
	if(ivec.size()%2!=0)
	{
		cout<<endl<<"The last element is not been summed "
			<<"and its value is "<<ivec[ivec.size()-1]<<endl;
	}
	return 0;
}
