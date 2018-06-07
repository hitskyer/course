#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector <int> ivec;
	int ival;
	//读入数据到vector对象
	cout<<"enter numbers(any char to end):"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);

	//计算收尾和，并输出
	if(ivec.size()==0)
	{
		cout<<"No elements!"<<endl;
		//system("pause");
		return -1;
	}
	if(ivec.size()==1)
	{
		cout<<"Only one element:"<<ivec[0]<<endl;
		//system("pause");
		return -1;
	}
	cout<<"Sum of each pair of counterpart element in the vector:"<<endl;
	vector<int>::size_type cnt =0;
	for(vector<int>::size_type first =0,last=ivec.size()-1;first<last;++first,--last)
	{
		cout<<ivec[first]+ivec[last]<<"\t";
		++cnt;
		if(cnt%6==0)
		{cout<<endl;}
		
	}
	return 0;
}
