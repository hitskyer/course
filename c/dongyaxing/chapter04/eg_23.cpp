#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string str1,str2;
	cout<<"Enter two strings"<<endl;
	cin>>str1>>str2;
	if(str1>str2)
	{
		cout<<"str1 is bigger than str2"<<endl;
	}
	else if(str2>str1)
	{
		cout<<"str2 is bigger than str2"<<endl;
	}
	else
	{
		cout<<"str1 is equal to str2"<<endl;
	}
	return 0;
}
