/**
* 概述：	数组-栈
* 作者：	dongyaxing
* 版本：	1.0
* 创建时间：2019/3/27   10:30
*/

#ifndef _ARRSTACK_H
#define _ARRSTACK_H

#define MAX_SIZE 20
#define INIT_VALUE -1
#include <iostream>
using namespace std;

struct ArrStack
{
	int arr_stack[MAX_SIZE];		// 栈的大小
	int top;						// 栈顶指针
	ArrStack()
	{
		memset(arr_stack, 0, sizeof(arr_stack));
		top = -1;
	}
};
typedef ArrStack *stack;
typedef unsigned int UINT;
class AStack
{
public:
	AStack(void);
	~AStack(void);
	bool Empty() const;			// 判断是否为空
	void Clear();				// 清空栈

	int GetTop() const;		// 得到栈顶元素
	UINT GetLength() const;		// 返回栈的长度，有效元素个数

	bool Push(int &data);		// 往栈中压入数据
	bool Pop();					// 将栈顶数据弹出

	void PrintStack();			// 打印栈内容
private :
	bool IsFull() const;		// 判断是否满
	bool Transfer() const;		// 栈满，则转移数据

private:
	stack m_pTop;				// 栈顶元素
	//UINT m_nStackLen;			// 栈长度
};



#endif \\_ARRSTACK_H