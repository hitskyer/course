#include<iostream>
#include<vector>
using namespace std;
int main()
{
	cout<<"vector对象，初始化的四种方式"<<endl;

	cout<<"1.  vector<int> ivec1(10)"<<endl;
	
	cout<<"2.  vector<int> ivec2(10,1)"<<endl;

	cout<<"3.  int a[]={0,1,2,3,4,5,6,7,8,9};vector<int> ivec3(a,a+10)"<<endl;

	cout<<"4.  vector<int> ivec4(ivec2)"<<endl;
	
	return 0;
}
