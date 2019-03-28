#include "ArrStack.h"
#include<iostream>
using namespace std;

AStack::AStack(void)
{
	//m_pTop.top = -1;	// -1表示未存数据，top = 0，则表示有一个数据，对应于数组的下标
}

AStack::~AStack(void)
{
	Clear();
}

// 判断是否为空
bool AStack::Empty() const
{
	if(-1 == m_pTop.top)
		return true;
	else
		return false;
}

// 清空栈，只要不为空，就一直出栈
void AStack::Clear()
{
	while(!Empty())
	{
		Pop();
	}
}

int AStack::GetTop() const
{
	if(IsFull())		// 满栈
	{
		return 0;
	}
	else
	{
		return m_pTop.arr_stack[m_pTop.top];
	}
}

UINT AStack::GetLength() const
{
	return m_pTop.top + 1;
}

bool AStack::Push(int &data)
{
	if(IsFull())		// 满栈
	{
		return false;
	}
	else				// 非满栈
	{
		++m_pTop.top;
		m_pTop.arr_stack[m_pTop.top] = data;
		return true;
	}
}

bool AStack::Pop()
{
	if(Empty())
	{
		return false;
	}
	else
	{
		int temp;
		temp = m_pTop.arr_stack[m_pTop.top];
		--m_pTop.top;
		return true;
	}
}

void AStack::PrintStack()
{
	int index = m_pTop.top + 1;
	while(index)
	{
		std::cout << "第 " << index << " 个元素是：" << m_pTop.arr_stack[index - 1] << std::endl;
		--index;
	}
}

bool AStack::IsFull() const
{
	return ((MAX_SIZE - 1) == m_pTop.top);
}
// 重新开辟一个2倍的数组，将原数据导入新的数组。
//bool AStack::ExpendStack()
//{
//	return false;
//}
