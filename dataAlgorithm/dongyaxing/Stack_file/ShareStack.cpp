#include "ShareStack.h"
#include <iostream>
#include <string.h>
using namespace std;

template<typename DATA> ShareStack<DATA>::ShareStack(void)
{
	m_pStack = new DATA[INIT_SIZE];
	m_nStackSize = INIT_SIZE;
	m_nTop1 = -1;
	m_nTop2 = m_nStackSize;
	m_nStackLen = 0;
}

template<typename DATA> ShareStack<DATA>::ShareStack(const UINT &nStackSize)
{
	m_pStack = new DATA[nStackSize];
	m_nStackSize = nStackSize;
	m_nTop1 = -1;
	m_nTop2 = m_nStackSize;
	m_nStackLen = 0;
}

template<typename DATA> ShareStack<DATA>::~ShareStack(void)
{
	delete []m_pStack;
	m_pStack = NULL;
	m_nTop1 = 0;
	m_nTop2 = 0;
	m_nStackSize = 0;
	m_nStackLen = 0;
}

template<typename DATA> bool ShareStack<DATA>::IsEmpty() const
{
	return m_nStackLen == 0;
}

template<typename DATA> void ShareStack<DATA>::Clear()
{
	//memset(m_pStack, 0, sizeof((DATA)*m_nStackSize));		// 功能同下
	memset(m_pStack, 0, sizeof(m_pStack));
	m_nStackLen = 0;
	m_nTop1 = -1;
	m_nTop2 = m_nStackSize;
}

template<typename DATA> const DATA* ShareStack<DATA>::GetLeftStackTop() const
{
	if(-1 == m_nTop1)
		return NULL;
	return &m_pStack[m_nTop1];
}

template<typename DATA> UINT ShareStack<DATA>::GetLength() const
{
	return m_nStackLen;
}

template<typename DATA> void ShareStack<DATA>::LeftStackPush(const DATA &data)
{
	if(IsFull())
		Expand();
	m_pStack[++m_nTop1] = data;
	++m_nStackLen;
}

template<typename DATA> void ShareStack<DATA>::LeftStackPop()
{
	if(-1 != m_nTop1)
	{
		memset(&m_pStack[m_nTop1--], 0, sizeof(DATA));		// m-- 先运算，后自减
		--m_nStackLen;
	}
}

template<typename DATA> bool ShareStack<DATA>::IsFull() const
{
	return ((m_nTop1 + 1) == m_nTop2);
}

template<typename DATA> void ShareStack<DATA>::Expand()
{
	//m_nStackSize*=2;
	int *pTemp = new int[m_nStackSize*2];
	memset(pTemp, 0, sizeof(DATA)*(m_nTop1 + 1));
	memcpy(pTemp, m_pStack, sizeof(DATA)*(m_nTop1 + 1));
	memcpy(&pTemp[m_nStackSize*2 -1 - (m_nStackSize - m_nTop2 - 1)],			// ???
		&m_pStack[m_nTop2], sizeof(DATA)* (m_nStackSize - m_nTop2));
	delete []m_pStack;
	m_pStack = pTemp;
	m_nTop2 += m_nStackSize; 
	m_nStackSize *= 2;
}

template<typename DATA> const DATA* ShareStack<DATA>::GetRightStackTop() const
{
	if(m_nStackSize == m_nTop2)
		return NULL;
	return &m_pStack[m_nTop2];
}

template<typename DATA> void ShareStack<DATA>::RightStackPush(const DATA& data)
{
	if(IsFull())
		Expand();
	m_pStack[--m_nTop2] = data;
	++m_nStackLen;
}

template<typename DATA> void ShareStack<DATA>::RightStackPop()
{
	if(m_nStackSize != m_nTop2)
	{
		memset(&m_pStack[m_nTop2++], 0, sizeof(DATA));
		--m_nStackLen;
	}
}

template<typename DATA> void ShareStack<DATA>::PrintStack() const
{
	if(-1 != m_nTop1)
	{
		std::cout << "Left Stack context: " << std::endl;
		int index = m_nTop1;
		while(index >= 0)
		{
			std::cout << "No." << index << " Elem is : " << m_pStack[index] << std::endl;
			--index;
		}
	}
	if(m_nStackSize != m_nTop2)
	{
		std::cout <<"Right Stack context: " << std::endl;
		int index = m_nTop2;
		while(index != m_nStackSize)
		{
			std::cout << "No." << index << " Elem is : " << m_pStack[index] << std::endl;
			++index;
		}
	}
	else
	{
		std::cout << "Empty Stack!" << std::endl;
	}
}
