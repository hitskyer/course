// 形参 局部变量 静态局部变量.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <vector>
using namespace std;



int fact()									//如果有形参
{
	static int ctr = 0;						//局部静态变量 函数结束依然存在 只初始化一次
	ctr++;
	return ctr;
}


int _tmain(int argc, _TCHAR* argv[])
{

	for (int i=1; i <=10;i++)				//i就是局部变量 随着for循环的结束销毁
	{
		cout << fact() << endl;            
	}

	cout << fact() << endl;					//静态局部变量没有被销毁 贯穿整个程序 结果是11
	return 0;

}

