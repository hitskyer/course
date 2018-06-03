#include <iostream>
using namespace std;
int main()
{
	string s1,s2;
	cout << "请输入两个字符："<<endl;
	cin >> s1 >> s2;
	if(s1.size() == s2.size())
	{
		cout << "s1 == s2 !" << endl;
	}
	else
	{
		if(s1.size() > s2.size())
		{
			cout << "s1 longer !"<<endl;
		}
		else
		{
			cout << "s2 longer !"<<endl;
		}
	}
	return 0;
}
