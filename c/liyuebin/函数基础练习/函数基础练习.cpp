// 函数基础练习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



//定义一个阶层函数
int fact(int val)                   //返回值类型 跟形参
{
	int ret = 1;                    //定义局部变量
	while (val > 1)
		ret *= val--;               //循环 求阶层
	return ret;                     //返回值
}





// int _tmain(int argc, _TCHAR* argv[])
// {
// 
// 	
// 	//调用一下函数
//  	int j = fact(5);                //实参 并用j来接收
//  	printf("%d", j);                //打印
// 	return 0;                       //主函数返回值
// 
// }


//6.1课后作业

//练习6.1 形参实参区别？
//形参是函数声明时候的值 作用域只能是只能是这个函数范围 
//实参是调用函数的时候传递的值

//练习6.2 指出函数的错误 并改正
//(1) 返回值的类型不匹配   int s;
//(2) 没有返回值类型       void
//(3) 传递两个相同的形参   int calc(int v1, int v2);
//(4) 返回值带有表达式     x=x*x;  return x;

//练习6.3 以上

//练习6.4

// int jiaohu()
// {
// 	int a;
// 	printf("请输入一个数");
// 	scanf_s("%d", &a);
// 
// 	int j = fact(a);
// 	printf("%d", j);
// 
// 	return 0;
// }

//练习6.5
// void jueduizhi(int i)
// {
// 	if (i < 0)
// 	{
// 		i = -i;
// 	}
// 	printf("%d\n", i);
// }



