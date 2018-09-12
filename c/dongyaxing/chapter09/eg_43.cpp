#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<char> sexp;  //处理表达式的stack对象
	string exp;

	//读入表达式
	cout<<"enter a expression:"<<endl;
	cin>>exp;
	
	//处理表达式
	string::iterator iter = exp.begin();
	while(iter!=exp.end())
	{
		if(*iter != ')')
			sexp.push(*iter);
		else
		{
			while(sexp.top() != '(' && !sexp.empty())
			{
				sexp.pop();
			}
			if(sexp.empty())
				cout<<"parentheses are not matched"<<endl;
			else
				sexp.pop();
				sexp.push('@');
		}
		++iter;
	}
	return 0;
}
