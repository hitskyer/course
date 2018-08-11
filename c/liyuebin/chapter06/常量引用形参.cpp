// 常量引用形参.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//判断是否有大写字母
bool faction1(string const &MyString)		//不需要改变实参
{
	for (int i = 0; i < MyString.size();i++)
	{
		if (MyString[i] >= 'A' && MyString[i] <= 'Z')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}





int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输入字符串" << endl;
	string MyString;
	cin >> MyString;

	if (faction1(MyString))
	{
		cout << "含有大写字符" << endl;
	}
	else
	{
		cout << "不含有大写字符串" << endl;
	}


	return 0;
}

