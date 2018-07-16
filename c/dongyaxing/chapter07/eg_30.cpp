#include<iostream>
using namespace std;

inline bool isShorter(const string &str1, const string &str2)
{
	return str1.size()<str2.size()?true:false;
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	cout<<isShorter(str1,str2)<<endl;
	return 0;
}
