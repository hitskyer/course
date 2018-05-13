#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s,news;
	bool flag;
	cout << "输入一个字符串，要求包含标点符号" << endl;
        getline(cin, s);
	for (string::size_type index=0; index!=s.size();++index)
	{
		if(!(ispunct(s[index])))
		news=news+s[index];
		else 
		flag=true;
	}
	if (flag)
	{
		cout << "输出新的字符串为: " << endl;
		cout << news << endl;
		return 0;
	}
	else
		cout << "输入字符串没有标点符号？！" << endl;
		return -1;
}
