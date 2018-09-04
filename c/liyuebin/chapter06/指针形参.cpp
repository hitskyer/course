// 指针形参.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//  
//   int   faction1(int a)                 //函数形参
//   {
//   	return a;
//   }
// 
// 
//   
// 

//求阶层的函数
void jiaohu()
{

	int a;
	printf("求输入一个数字\n");
	scanf_s("%d",&a,sizeof(a));

	for (int i = a-1; i >1; i--)
	{
		a = a*i;
	}
	printf("阶层是%d", a);
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*faction1(50);  */                  //函数实参
	jiaohu();
	return 0;
}

