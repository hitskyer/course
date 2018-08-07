// 指针形参交换两个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void fact(int *a,int *b)                         //指针形参可以改变实参的值
{
	int c = *a;
	*a = *b;
	*b = c;

}


int _tmain(int argc, _TCHAR* argv[])
{
	int i = 5;
	int j = 9;
	fact(&i, &j);
	printf("i是%d,j是%d", i, j);                  //输出结果正好相反
	
	return 0;
}

