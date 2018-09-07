#include<iostream>
#include<vector>
#include<exception>
using namespace std;

int main()
{
	int arr[]={1,2,3,4,5};
	vector<int> ivec1(arr,arr+5);
	vector<int> ivec2;

	cout<<ivec1.front()<<endl;
	cout<<ivec1.back()<<endl;
	cout<<ivec1[0]<<endl;

	if(ivec2.empty())
	{
		cout<<"ivec2 is empty"<<endl;
	}
	return 0;
}
