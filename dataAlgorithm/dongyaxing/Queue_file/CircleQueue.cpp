#include"CircleQueue.h"
#include<iostream>
using namespace std;

template<typename T> CircleQueue<T>::CircleQueue(void)
{
	CQueue = new T[MAX_SIZE];
	m_nCQueueSize = MAX_SIZE;
	m_nHead = 0;
	m_nTail = 0;
	m_nCQueueLen = 0;
}

template<typename T> CircleQueue<T>::~CircleQueue(void)
{
	delete [] CQueue;
	CQueue = NULL;
}

template<typename T> CircleQueue<T>::CircleQueue(const UINT &InitSize):m_nCQueueSize(InitSize)
{
	CQueue = new T[m_nCQueueSize];
	m_nHead = 0;
	m_nTail = 0;
	m_nCQueueLen = 0;
}

template<typename T> UINT CircleQueue<T>::GetLength() const
{
	return m_nCQueueLen;
}

template<typename T> bool CircleQueue<T>::Empty() const
{
	return 0 == m_nCQueueLen;
}

template<typename T> bool CircleQueue<T>::EnQueue(const T &data)
{
	if((m_nTail+1)%m_nCQueueSize == m_nHead)
		return false;
	else
	{
		CQueue[m_nTail] = data;
		m_nTail = (m_nTail + 1) % m_nCQueueSize;
		++m_nCQueueLen;
		return true;
	}
}

template<typename T> bool CircleQueue<T>::DeQueue()
{
	if(0 == m_nCQueueLen)
		return false;
	else
	{
		m_nHead = (m_nHead + 1)%m_nCQueueSize; 
		--m_nCQueueLen;
		return true;
	}
}

template<typename T> void CircleQueue<T>::Erase()
{
	m_nHead = m_nTail = 0;
	//m_pCQueue[m_nHead] = 0;
	m_nCQueueLen = 0;
}

template<typename T> void CircleQueue<T>::Print() const
{
	if(0 == m_nCQueueLen)
	{
		std::cout << "This is an empty Queue! " << std::cout;
	}
	else
	{
		UINT index = m_nHead;
		std::cout << "This is Queue head : " << std::endl; 
		for(UINT i = 0; i < m_nCQueueLen; ++i)
		{
			std::cout << "The " << i+1 << "th element is : " << CQueue[index] << std::endl;
			++index;
			index %= m_nCQueueLen;
		}
		std::cout << "This is Queue Tail." << std::endl;
	}
}
