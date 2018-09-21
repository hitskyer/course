#include<iostream>
#include<vector>
using namespace std;

int main()
{
// vector int 对象的4种初始化方式

// 1: 定义大小为10的int型容器
	vector<int> ivec1(10);
	for (vector<int>:: size_type it=0; it!=10; ++it)
		ivec1[it]=2;
	for(vector<int>::iterator iter=ivec1.begin(); iter!=ivec1.end();++iter)
		cout << *iter << " ";
	cout << endl;
// 2:
	vector<int> ivec2(10,1);
	for (vector<int>::iterator iter=ivec2.begin();iter!=ivec2.end();++iter)
		cout << *iter << " ";
	cout << endl;
// 3:
	vector<int> ivec3(ivec2);
	for(vector<int>::iterator iter=ivec3.begin();iter!=ivec3.end();++iter)
		cout << *iter << " ";
	cout  << endl;
// 4:
	int array[]={1,2,3,4,5,6,7,8};
	vector<int> ivec4(array, array+4);
	for(vector<int>::iterator iter=ivec4.begin();iter!=ivec4.end();++iter)
		cout<< *iter << " ";
	cout << endl;
}

