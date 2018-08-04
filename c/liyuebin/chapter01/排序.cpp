// 排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int a, b, c;
	printf("请输入三个数\n");
	scanf_s("%d %d %d", &a, &b, &c);
	if (a>b)
	{
		if (b>c)
		{
			printf("%d %d %d",c, b, a);
		}
		else
		{
			if (a>c)
			{
				printf("%d %d %d", b, c, a);
			}
			else
			{
				printf("%d %d %d", c, a, b);
			}
		}
	}
	else
	{
		if (a > c)
		{
			printf("%d %d %d", c, a, b);

		}
		else
		{
			if (c > b)
			{
				printf("%d %d %d", a, b, c);
			}
			else
			{
				printf("%d %d %d", a, c, b);
			}
		}
	}
	return 0;
}

