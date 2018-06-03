#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s2,s1;
	cin >> s1;
	do	
	{
		if(s1==s2)
		{
			cout << s1 << "连续出现两次" << endl;
			return 1;
		}
		s2=s1;
	}
	while(cin>>s1);
	cout << "no repeated word!" << endl;
	return 0;
}
