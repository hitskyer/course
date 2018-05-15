#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1,s2;
	cout << "请输入两字符：" << endl;
	cin >> s1 >> s2;
	string s3 = s1 + s2 ;
	string s4 = s1 + "   " + s2;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	return 0;
}
