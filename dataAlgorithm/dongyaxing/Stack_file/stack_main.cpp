/*
* 创建者：	dongyaxing
* 创建时间：2019/3/26   20:22
*/


#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	Stack stk;
	// 空栈测试
	stk.GetLength();
	stk.GetTop();
	stk.Clear();
	stk.Empty();
	stk.Pop();
	
	// 非空栈测试
	int arr[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 0; i < 10; ++i)
	{
		stk.Push(arr[i]);
	}
	stk.PrintStack();
	std::cout << "长度是：" << stk.GetLength() << std::endl;
	stk.GetTop();
	//std::cout << "栈顶元素是： " << stk.GetTop()->data << std::endl;		// 报错，不能看第一个元素
	stk.Pop();

	stk.Clear();
	stk.GetLength();

	system("pause");
	return 0;
}