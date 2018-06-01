#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s4= "in love";
	string s2(3,'a');
	string s3(s2);
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<" s2+s1+s3 ="<<(s2+s1+s3)<<endl;
	cout<<"the size of s4 is "<<s4.size()<<endl;
	cout<<"enter some nubers to s1  :"<<endl;
	getline(cin,s1);
	cout<<"s1 = "<<s1<<endl;
	cout<<"the size of "<<s1<<" is "<<s1.size()<<" characters, including the newline"<<endl;
	string s5 ="hello "+ s2+" and "+ s3;
	cout<<"s5 = "<<s5<<endl; 
	for(string::size_type ix =0; ix != s1.size();ix++)
	{
		s1[ix]='0';
	}
	cout<<"s1 = "<<s1<<endl;
	cout<<(s2==s3)<<(s5>s2)<<endl;
	return 0;
}
