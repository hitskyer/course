#include <iostream>
#include <string>
using namespace std;
int main()
{
	//遇到空值，则停止输入。
	string s;
	cin>>s;
	cout<<s<<endl;
	//将一串字符，以空值为分割点，分割为若干行
	string word;
	while(cin>>word)
		cout<<word<<endl;
	//整行输出，不论是否有空值
	string line;
	while(getline(cin,line))
		cout<<line<<endl;
	return 0;
}
