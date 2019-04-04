#include"ArrQueue.h"
#include<iostream>
using namespace std;
template<typename T> ArrQueue<T>::ArrQueue(void)
{
	m_nQueueSize = MAX_SIZE;
	m_pQueue = new T[m_nQueueSize];
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}

template<typename T> ArrQueue<T>::ArrQueue(const UINT & InitSize)
{
	m_nQueueSize = InitSize;
	m_pQueue = new T[m_nQueueSize];
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}

template<typename T> ArrQueue<T>::~ArrQueue(void)
{
	delete [] m_pQueue;
	m_pQueue = NULL;
}
 //入队
template<typename T> bool ArrQueue<T>::EnQueue(const T &data)
{
	if(m_nQueueSize == m_nQueueLen || !m_pQueue)
	{
		return false;
	}
	else if(m_nTail < m_nQueueSize)
	{
		m_pQueue[m_nTail++] = data;
		++m_nQueueLen;
		return true;
	}
	else
	{
		for(UINT i = 0; i < m_nQueueLen; ++i)
		{
			m_pQueue[i] = m_pQueue[m_nHead++];
		}
		m_nHead = 0;
		m_pQueue[m_nQueueLen++] = data;
		m_nTail = m_nQueueLen;
		return true;
	}
}
// 出队
template<typename T> bool ArrQueue<T>::DeQueue()
{
	if(0 == m_nQueueLen)
	{
		return false;
	}
	else
	{
		++m_nHead;
		--m_nQueueLen;
		return true;
	}
}
// 获得有效长度
template<typename T> UINT ArrQueue<T>::GetLength() const
{
	return m_nQueueLen;
}
// 判断是否为空
template<typename T> bool ArrQueue<T>::Empty() const
{
	return 0 == m_nQueueLen;
}
// 清空
template<typename T> void ArrQueue<T>::Erase()
{
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}
// 打印输出
template<typename T> void ArrQueue<T>::Print() const
{
	if(0 == m_nQueueLen)
	{
		std::cout << "this is an empty queue." << std::endl;
	}
	else
	{
		std::cout << "Head is here." << std::endl;
		UINT index = m_nHead;
		for(int i = 0; i < m_nQueueLen; ++i)
		{
			std:cout << "The " << i << "th element data is: " << m_pQueue[index++] << std::endl;
		}
		std::cout << "Tail is here." << std::endl;
	}
}
