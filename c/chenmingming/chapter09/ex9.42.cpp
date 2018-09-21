#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<string> string_stack;
	string str;
	cout << "enter string: " << endl;
	while(cin >> str)
	{
		string_stack.push(str);
		cout << string_stack.top() << endl;
	}
	return 0;
}