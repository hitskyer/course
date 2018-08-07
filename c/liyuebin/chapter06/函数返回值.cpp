// 函数返回值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//用到静态局部变量的知识
int fact()
{
	static int i=0;
	return i++;
}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << fact() << endl;					//第一次返回0
	cout << fact() << endl;					//	以后调用都加1
	return 0;
}

