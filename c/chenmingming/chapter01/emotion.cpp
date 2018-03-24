#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	char a='y';
	while(a=='y'||a=='Y')
	{
		cout << "输入你此时的心情（中文或English） : " << endl;
		cin >> s;
		if (s == "高兴"|| s == "happy") 
		{
			cout << "因此我的心欢喜，我的灵（原文作荣耀）快乐。我的肉身也要安然居住。（诗篇16：9）" << endl;
		} 
		else if (s == "悲伤"||s == "sad"||s == "难过")
		{
			cout << "然而他知道我所行的路。他试炼我之后，我必如精金。（约伯记23:10）" << endl;
		}
		else 	
		{
			cout << "没有查到你的心情相关的经文！祝你喜乐平安！" << endl;
		}
		cout << "--------------------------------------------------------\n是否继续查询经文！输入y或Y继续，其他字符退出！" << endl;
		cin >> a;
		cin.ignore(1000,'\n');
	}
	return 0;
}
