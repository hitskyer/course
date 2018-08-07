// 绝对值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//输出绝对值

void absolute(int a)
{

	if (a<0)
	{
		printf("绝对值是%d",-a);
	}
	else
	{
		printf("绝对值是%d", a);
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	//调用绝对值函数
	absolute(-5);
	return 0;
}

