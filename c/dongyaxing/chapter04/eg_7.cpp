#include <iostream>
#include <string>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	cout<<"原始数据："<<endl;
	const size_t arr_size=10;
	int ia[arr_size];
	for(size_t i=0;i!=arr_size;i++)
	{
		ia[i]=i+1;
		cout<<ia[i]<<" ";
	}
	cout<<endl;
	cout<<"ia[]赋值给ib[]"<<endl;
	int ib[arr_size];
	for(size_t j=0;j!=arr_size;j++)
	{
		ib[j]=ia[j];
		cout<<ib[j]<<" ";
	}
	cout<<endl;
	cout<<"原始数据："<<endl;
	vector<int> avec,bvec;
	for(vector<int>::size_type xi=0;xi!=10;xi++)
	{
		avec.push_back(xi);
		cout<<avec[xi]<<" ";
	}
	cout<<endl;
	cout<<"方案一：avec[]赋值给bvec[]"<<endl;
	for(vector<int>::size_type xj=0;xj!=10;xj++)
	{
		bvec.push_back(avec[xj]);
		cout<<bvec[xj]<<" ";
	}
	cout<<endl;
	cout<<"方案二：用iterator方法，avec[]赋值给bvec[],且倒序"<<endl;
	for(vector<int>::iterator xj=avec.end()-1;xj>=avec.begin();xj--)
	{
		bvec.push_back(*xj);
		cout<<*xj<<" ";
	}
	cout<<endl;
	return 0;
}
