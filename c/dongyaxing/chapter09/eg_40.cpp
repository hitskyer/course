#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	stack<string> sstack;
	string str;
	cout<<"输入单词，并存储在stack对象中："<<endl;
	while(cin >> str)
	{
		sstack.push(str);
	}
	cout<<endl<<endl;

	cout<<"显示stack对象中的栈顶单词："<<endl;
	string str2;
	str2=sstack.top();
	cout<<str2;
	
	cout<<endl<<endl;
	return 0;
}
