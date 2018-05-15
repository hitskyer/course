#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1,str2;
	cout << "输入两个字符串: " << endl;
	cin >> str1 >> str2;
	if (str1>str2)
		cout << "str1 > str2" << endl;
	else if (str2<str2)
		cout << "str1 < str2" << endl;
	else
		cout << "str1=str2" << endl;
}
