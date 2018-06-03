#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
// cin string 与getline string 的区别
	string s;
	cout << "输入单词，不考虑空格" << endl;
	cin >> s;
	cout << s << endl;
// 
	string s1;
	cout << "输入一句话:"  << endl;
	getline(cin,s1);
	cout << s1 << endl;
//输出字符串的长度
	string s3("I love my hometown!");
	cout << s3 << "的长度为: " << s3.size() << " characters." << endl;
//字符串相加
	string s4="Hello";
	string s5="World";
	string s6=s4+", "+s5;
	cout << s6 << endl;
//将字符串的小写字母改成大写字母
	cout << "输入新的字符串:" << endl;
	string s7;
	getline(cin,s7);
	for(string::size_type index=0;index!=s7.size();++index)
	{
		s7[index]=toupper(s7[index]);
	}
	cout << "字符串转换以后的新字符串为：" << s7 << endl;

// 赋值；
	string st1, st2=" I love my home!";
	st2=st1;
	cout << "st2= " << st2 << endl;
// 输出输入字符串每个位置上的字符/example P76
	string  str("Some string");
        cout << "字符串str每个位置的字符是:" << endl;
	for (string::size_type ix=0; ix!=str.size();++ix)
		cout << str[ix] << endl;
// 将字符替换*
	string sr("I love you");
	for (string::size_type j=0;j!=sr.size();++j)
		sr[j]='*';
	cout << " 每个字符替换成*后的新字符串为: " << sr <<  endl;
}

