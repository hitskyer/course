#include<iostream>
using namespace std;
int main()
{
	cout << "请输入一个带标点的字符串：" << endl;
	string s,s_new;
	cin >> s;
	bool has_fh = false;
	for(string::size_type num = 0; num != s.size();++num)
	{
		if(ispunct(s[num]))
		{
			has_fh = true;
		}
		else
			s_new += s[num];
	}
	if(has_fh)
		cout << "去掉符号的字符为：" << s_new << endl;
	else
		cout << "字符不含符号！" << endl;
	return 0;
}
