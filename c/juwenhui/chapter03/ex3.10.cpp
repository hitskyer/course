#include <string>
#include <iostream>
using namespace std;

int main ()
{
	string s;s_new;
	cout << "请输入一个带标点符号的字符串：" << endl;
	cin >> s >> endl;
	if (ispunct(s))
		cout << s << endl;
	else
		cout << "请输入一个带标点符号的字符串：“ << endl;
	for (string :: size_type num =0; num !=s.size();++num)
	{
		s_new += s[num];
}		cout << "去掉字符串的字符为：" << s_new << endl;
		return 0;
}
