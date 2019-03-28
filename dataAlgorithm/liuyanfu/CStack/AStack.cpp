#include "AStack.h"
#include <iostream>
#include <string.h>

AStack::AStack(void)
{
	m_nStackSize = 20;
	m_nStackLen = 0;
	m_pStack = new int[m_nStackSize];
	memset(m_pStack, 0, sizeof(int)* m_nStackSize);
	m_nTop = -1;
}

AStack::AStack(UINT &nSize):m_nStackSize(nSize)
{
	m_pStack = new int[m_nStackSize];
	m_nStackLen = 0;
	memset(m_pStack, 0, sizeof(int)* m_nStackSize);
	m_nTop = -1;
}

AStack::~AStack(void)
{
	delete [] m_pStack;
	m_pStack = NULL;
	m_nStackSize = 0;
	m_nStackLen = 0;
	m_nTop = 0;
}

/****************************************!
*@brief  判断栈是否为空
*@author liuyanfu
*@date   2019年3月27日	23:25
*@param[out] 
*@return     bool  
****************************************/
bool AStack::Empty() const
{
	return m_nStackLen == 0;
}


/****************************************!
*@brief  清空栈
*@author liuyanfu
*@date   2019年3月27日	23:26
*@param[out] 
*@return     void  
****************************************/
void AStack::Clear()
{
	memset(m_pStack, 0, sizeof(int) * m_nStackLen);
	m_nStackLen = 0;
	m_nTop = -1;
}

/****************************************!
*@brief  获得栈顶的数据
*@author liuyanfu
*@date   2019年3月27日	23:29
*@param[out] 
*@return     const int*  
****************************************/
const int* AStack::GetTop() const
{
	if(-1 == m_nTop)
		return NULL;
	return &m_pStack[m_nTop];
}


/****************************************!
*@brief  返回栈中有效数据所占用的长度
*@author liuyanfu
*@date   2019年3月27日	23:42
*@param[out] 
*@return     UINT  
****************************************/
UINT AStack::GetLength() const
{
	return m_nStackLen;
}


/****************************************!
*@brief  压栈
*@author liuyanfu
*@date   2019年3月27日	23:43
*@param[out] 
*@param[in]  const UINT &data  
*@return     void  
****************************************/
void AStack::Push(const UINT &data)
{
	if(isFull())
		ExpandStack();
	m_pStack[++m_nTop] = data;
	++m_nStackLen;
}


/****************************************!
*@brief  出栈
*@author liuyanfu
*@date   2019年3月27日	23:47
*@param[out] 
*@return     void  
****************************************/
void AStack::Pop()
{
	memset(&m_pStack[m_nTop], 0, sizeof(int));
	--m_nTop;
	--m_nStackLen;
}


/****************************************!
*@brief  栈的动态扩容
*@author liuyanfu
*@date   2019年3月27日	23:51
*@param[out] 
*@return     void  
****************************************/
void AStack::ExpandStack()
{
	int *pTemp = new int[m_nStackSize * 2];
	memcpy(pTemp, m_pStack, m_nStackLen * sizeof(int));
	delete []m_pStack;
	m_pStack = pTemp;
	m_nStackSize = m_nStackSize * 2;
}


/****************************************!
*@brief  判断当前栈是否已满
*@author liuyanfu
*@date   2019年3月27日	23:56
*@param[out] 
*@return     bool  
****************************************/
bool AStack::isFull()
{
	return m_nStackLen == m_nStackSize;
}


/****************************************!
*@brief  打印栈中的数据
*@author liuyanfu
*@date   2019年3月28日	0:00
*@param[out] 
*@return     void  
****************************************/
void AStack::PrintStack()
{
	if(Empty())
	{
		std::cout << "Current Stack is Empty!" << std::endl;
		return;
	}
	UINT i = 1;
	std::cout << "The data from stack top to stack buttom is :" << std::endl;
	int index = m_nTop;
	while(index != -1)
	{
		std::cout << "The " << i << "th node data is : " << m_pStack[index--] << std::endl;
		++i;
	}
	std::cout << "----------------Print Stack data is over-------------" << std::endl;
}
