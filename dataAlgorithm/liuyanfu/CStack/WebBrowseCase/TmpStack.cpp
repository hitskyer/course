#include "TmpStack.h"
#include <iostream>
template<typename DATA>
TmpStack<DATA>::TmpStack(void)
{
	m_pTop = NULL;
	m_nStackLen = 0;	
}


template<typename DATA>
TmpStack<DATA>::~TmpStack(void)
{
	Clear();
	m_pTop = NULL;
	m_nStackLen = 0;
}

/****************************************!
*@brief  判断栈是否为空
*@author liuyanfu
*@date   2019年3月28日	22:10
*@param[out] 
*@return     bool  
****************************************/
template<typename DATA>
bool TmpStack<DATA>::Empty() const
{
	return m_nStackLen == 0;
}


/****************************************!
*@brief  清空栈
*@author liuyanfu
*@date   2019年3月28日	22:15
*@param[out] 
*@return     void  
****************************************/
template<typename DATA>
void TmpStack<DATA>::Clear()
{
	while(m_pTop)
	{
		StackNode TempNode = m_pTop->pNext;
		delete m_pTop;
		m_pTop = TempNode;
	}
	m_nStackLen = 0;
}

/****************************************!
*@brief  获取栈顶
*@author liuyanfu
*@date   2019年3月28日	22:19
*@param[out] 
*@return     const SNode<DATA>* 
****************************************/
template<typename DATA>
const SNode<DATA>* TmpStack<DATA>::GetTop() const
{
	return m_pTop;
}


/****************************************!
*@brief  获得栈的有效长度
*@author liuyanfu
*@date   2019年3月28日	22:19
*@param[out] 
*@return     UINT  
****************************************/
template<typename DATA>
UINT TmpStack<DATA>::GetLength() const
{
	return m_nStackLen;
}


/****************************************!
*@brief  压栈
*@author liuyanfu
*@date   2019年3月28日	22:20
*@param[out] 
*@param[in]  const DATA & data  
*@return     void  
****************************************/
template<typename DATA>
void TmpStack<DATA>::Push(const DATA& data)
{
	StackNode pNewNode = new SNode<DATA>;
	pNewNode->data = data;
	pNewNode->pNext = m_pTop;
	m_pTop = pNewNode;
	++m_nStackLen;
}


/****************************************!
*@brief  出栈
*@author liuyanfu
*@date   2019年3月28日	22:23
*@param[out] 
*@return     void
****************************************/
template<typename DATA>
void TmpStack<DATA>::Pop()
{
	if(m_pTop != NULL)
	{
		StackNode TempNode = m_pTop->pNext;
		delete m_pTop;
		m_pTop = TempNode;
		--m_nStackLen;
	}
	
}

/****************************************!
*@brief  从栈顶到栈底依次打印数据
*@author liuyanfu
*@date   2019年3月28日	22:41
*@param[out] 
*@return     void  
****************************************/
template<typename DATA>
void TmpStack<DATA>::PrintStack()
{
	StackNode TempNode = m_pTop;
	UINT i = 1;
	while(TempNode)
	{
		std::cout << "the " << i << "th Stack Node data is: " << TempNode->data << std::endl;
		++i;
		TempNode = TempNode->pNext;
	}
	if(Empty())
		cout << "This Stack is Empty Stack!";
}