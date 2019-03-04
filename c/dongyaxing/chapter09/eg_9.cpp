#include<iostream>
#include<list>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	list<int> ilst(arr,arr+9);
	
	list<int>::iterator first = ilst.begin(), last = ilst.end();

	cout<<"将list<int> ilst 顺序输出："<<endl;
	while(first!=last)
	{
		cout<<*first<<endl;
		first++;
	}
	
	first = ilst.begin(), last = ilst.end();	//再次将first last 初始化
	cout<<"将list<int> ilst 逆序输出："<<endl;
	while(last!=first)
	{
		//last--;
		cout<<*(--last)<<endl;
	}

	return 0;
}
