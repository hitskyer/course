#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1, s2;
	cout << "请输入两个字符串: " << endl;
// 输入单词比较 
	cin >> s1 >> s2;
//输入文本行比较
//	getline(cin,s1);
//	getline(cin,s2);
	if (s1==s2)
		cout << "s1 与 s2 相等 " << endl;
	else if (s1.size() > s2.size())
		cout << "s1 > s2" << endl;
		else 
			cout << "s1 < s2 " << endl;
	return 0;
}
