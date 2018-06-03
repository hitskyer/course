#include <iostream>
using namespace std;
void print(const char*p)//表示指向常变量的指针，即不能通过指针对该变量进行修改，只能读取
{
	cout << p << endl;
}
const int sum(int a,int b)//返回常量类型的量
{
	return a+b;
}

//const 型的变量只能读取它的值，但是不能通过任何方式改变它的值，比如不能把一个const类型的指针指向变量
//const 类型的变量必须初始化
//const 类型可以加在成员函数的后边，表示该成员函数不能改变成员变量的值
//const 类型的指针不能赋值给一个一般的变量的指针，防止通过一般变量的指针修改const类型指针指向的地址的内容
//如果想保证某个变量的值不被修改，那就将其定义成const类型的
//const void *p 常量指针：即指向常量的指针    void* const p 指针常量：即指向某一固定地址的指针
int main()
{
	const int a=10; //const常量定义的时候必须初始化
	print((const char*)&a);
	int b=100;
	print((const char*)&b);
	int *q;
	int const *p=&b;
	print((const char*)p);
	b=200;
	print((const char*)p);
	//int *p1=p;这个是错误的,不能讲一个const型的指针赋给变量指针，这样会改变它的值违背const型指针的定义
	//*p=200;不能通过这种方式改变指针常量所指的内容
	return 0;
}
