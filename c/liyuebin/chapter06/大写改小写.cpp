// 大写改小写.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

//大写字母改变小写字母
void faction1(string  &MyString)		//需要改变实参
{
	for (int i = 0; i < MyString.size(); i++)
	{
		if (MyString[i] >= 'A' && MyString[i] <= 'Z')
		{
			MyString[i] = MyString[i] + 32;
			
		}

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输入字符串" << endl;
	string MyString;
	cin >> MyString;
	faction1(MyString);
		
	cout << "改变之后是" << MyString<<endl;
	

	return 0;
}

