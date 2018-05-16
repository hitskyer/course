#include<iostream>
using namespace std;
int main()
{
	string s1,s_all;
	cout << "请输入若干字符串，ctrl D 结束！"<< endl;
	cin >> s_all;
	while(cin >> s1)
	{
		s_all +=" "+ s1;
	}
	cout << "连接后的字符为:"<< s_all<< endl;
	return 0;
}
