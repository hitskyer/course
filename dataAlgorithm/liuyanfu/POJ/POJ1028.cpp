#include <iostream>
#include <stack>
#include <string>
using namespace std;

class WebNavi
{
public:
	WebNavi()
	{
		defaultWeb = "http://www.acm.org/";
	}
	~WebNavi()
	{

	}

	void visit(string webaddr)
	{
		while(!forward_stack.empty())
			forward_stack.pop();
		back_stack.push(webaddr);
		print(webaddr);
	}

	bool back()
	{
		if(back_stack.empty())
		{
			return false;
		}
		else
		{
			forward_stack.push(back_stack.top());
			back_stack.pop();
			if(back_stack.empty())
				print(defaultWeb);
			else
				print(back_stack.top());
			return true;
		}
	}

	bool forward()
	{
		if(forward_stack.empty())
			return false;
		else
		{
			back_stack.push(forward_stack.top());
			forward_stack.pop();
			print(back_stack.top());
			return true;
		}
	}
private:
	void print(string webaddr)
	{
		cout << webaddr.c_str() << endl;
	}
private:
	string defaultWeb;
	stack<string> forward_stack;
	stack<string> back_stack;
};

int main()
{
	WebNavi w;
	string webaddr;
	string command;
	while(true)
	{
		cin >> command;
		if(command == "VISIT")
		{
			cin >> webaddr;
			w.visit(webaddr);
		}
		else if(command == "BACK")
		{
			if(!w.back())
				cout << "Ignored" << endl;
		}
		else if(command == "FORWARD")
		{
			if(!w.forward())
				cout << "Ignored" << endl; 
		}
		else if(command == "QUIT")
		{
			break;
		}
		command.clear();
		webaddr.clear();
	}
	return 0;
}