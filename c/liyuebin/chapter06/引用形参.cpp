// 引用形参.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>											//C++中输入输出string类型变量
using namespace std;



//测试引用传参
int reset(string &MyString,char c,int &val)
{
	bool MyBool = true;										//局部变量
	int FirstPosition =0;									//局部变量 定义第一个位置

	for (int i = 0; i < MyString.size();i++)				
	{
		if (MyString[i] == c)
		{
			if (MyBool)
			{
				FirstPosition = i;
				MyBool = false;
			}
			
			val++;											//隐私返回指定字符出现的个数
		}
		
	}
	return FirstPosition+1;									//返回指定字符第一次出现的位置
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输入字符串";
	string MyString;
	cin >> MyString;

	cout << "请输入目标字符";
	char MyChar;
	cin >> MyChar;

	int MyVal=0;
	int Pos = reset(MyString,MyChar,MyVal);
	cout << "目标字符第一次出现的位置是:"<<Pos << endl;
	cout << "目标字符出现的次数为:" << MyVal << endl;

	return 0;
}

