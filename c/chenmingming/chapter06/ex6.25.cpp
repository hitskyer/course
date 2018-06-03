#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s2,s1;
	cin >> s1;
	do	
	{
		#ifndef NDEBUG
		cout << s1 << " ";
		#endif
		if(!isupper(s1[0]))
			continue;
		if(s1==s2)
		{
			cout << s1 << "(大写字母开头的)连续出现两次" << endl;
			return 1;
		}
		s2=s1;
	}
	while(cin>>s1);
	cout << "no repeated word!" << endl;
	return 0;
}
