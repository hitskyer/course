#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1,s2,s3;
	do
	{
		cout << "enter two strings!" << endl;
		cin >> s1 >> s2;
		if(s1<s2)
		cout << "firsr string is smaller!"<<endl;
		else if(s1==s2)
		cout << "the two string equal!" << endl;
		else
		cout << "the second string is smaller"<< endl;
		cout << "N or n stop,others to continue !" <<endl;
		cin >> s3;
	}
	while(s3[0]!='N'&& s3[0]!='n');
	return 0;
}
