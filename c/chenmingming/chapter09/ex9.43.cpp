#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<char> string_stack;
	string str;
	cout << "enter exp: " << endl;
	cin >> str;
	string::iterator iter = str.begin();
	while(iter != str.end())
	{
		if(*iter != ')')
		{
			string_stack.push(*iter);
			cout << string_stack.top() << endl;
		}
		else
		{
			while(!string_stack.empty() && string_stack.top() != '(')
			{
				cout << string_stack.top() << endl;
				string_stack.pop();
				// cout << string_stack.top() << endl;
			}
			if(string_stack.empty())
			{
				cout << "end£¬À¨ºÅ²»Æ¥Åä£¡" << endl;
				// cout << string_stack.top() << endl;
			}
			else
			{
				cout << string_stack.top() << endl;
				string_stack.pop();
				string_stack.push('@');
				cout << string_stack.top() << endl;
			}
		}
		++iter;
	}
	return 0;
}