#include "stdafx.h"
#include <iostream>

//局部静态变量

size_t count_calls()
{
	static size_t ctr = 0;       //局部静态变量 只初始化一次
	return ++ctr;
}

int main()
{

	for (size_t i = 0; i != 10;i++)
	{
		int j = count_calls();
		printf("%d", j);
	}
	return 0;
}

