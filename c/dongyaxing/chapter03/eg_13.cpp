
#include<string>
#include<iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	vector<int> sum_vec1,sum_vec2;
	//输入数据
	cout<<"原始数据"<<endl;
	for(vector<int>::size_type i=0; i!=11;++i)
	{
		ivec.push_back(i);
		cout<<ivec[i]<<endl;
		
	}
	//输出相邻和
	cout<<"输出相邻和"<<endl;
	for(vector<int>::size_type i_1=0;i_1<11;i_1+=2)
	{
		int temp;
		if(i_1<10)
		{	
		temp = ivec[i_1]+ivec[i_1+1];
		sum_vec1.push_back(temp);
		}
		else
		continue;
	}
	for(int j_1=0;j_1<11/2;j_1++)
	{
		cout<<sum_vec1[j_1]<<endl;
	}
	cout<<"输出首尾和："<<endl;
	for(vector<int>::size_type ii=0,jj=10;ii<=jj;ii++,jj--)
	{
		int temp;
		temp=ivec[ii]+ivec[jj];
		sum_vec2.push_back(temp);
		cout<<sum_vec2[ii]<<endl;
	}
	return 0;
}
