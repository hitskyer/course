#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1=("hello world");
	string s2=("how are you");
	if(s1==s2)
	{cout<<"s1==s2"<<endl;}
	else if(s1>s2)
	{
		cout<<"s1大"<<s1<<endl;
	}
	else
		cout<<"s2大"<<s2<<endl;
	string::size_type size_long=0;
	if(s1.size()==s2.size())
	{
		size_long=s1.size();
		cout<<size_long<<endl;
		cout<<"s1与s2长度相等"<<endl;
	}
	else if(s1.size()>s2.size())
	{
		cout<<"s1比s2长"<<endl;
	}
	else
	{
		cout<<"s2比s1长"<<endl;
	}
	
	return 0;
}
