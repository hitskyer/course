#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	string name;
	string address;
public:
	string getName() const
	{return name;}  
	string getAddress() const
	{return address;}
public:
	// construct function
	Person(const string &nm, const string &addr):name(nm), address(addr)
	{
	}
};

int main()
{
	Person p;
	string name=p.getName();
	cout<<name<<endl;
	return 0;
}

