#include "CircleQueue.h"
#define INITQUEUELEN 5

template<typename T>
CircleQueue<T>::CircleQueue(void)
{
	m_nQueueSize = INITQUEUELEN;
	m_pQueue = new T[m_nQueueSize];
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}


template<typename T>
CircleQueue<T>::~CircleQueue(void)
{
	delete []m_pQueue;
	m_pQueue = NULL;
}


template<typename T>
CircleQueue<T>::CircleQueue(const UINT &InitSize):m_nQueueSize(InitSize)
{
	m_pQueue = new T[m_nQueueSize];
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}



/****************************************!
*@brief  入队
*@author liuyanfu
*@date   2019年4月2日	23:49
*@param[out] 
*@param[in]  const T & data  
*@return     bool  
****************************************/
template<typename T>
bool CircleQueue<T>::enqueue(const T& data)
{
	if((m_nTail + 1) % m_nQueueSize == m_nHead)
		return false;
	else
	{
		m_pQueue[m_nTail] = data;
		m_nTail = (m_nTail + 1) % m_nQueueSize;
		++m_nQueueLen;
		return true;
	}
}


/****************************************!
*@brief  出队
*@author liuyanfu
*@date   2019年4月2日	23:53
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool CircleQueue<T>::dequeue()
{
	if(m_nHead == m_nTail)
		return false;
	else
	{
		m_nHead = (m_nHead + 1) / m_nQueueSize;
		--m_nQueueLen;
		return true;
	}
}



/****************************************!
*@brief  获取队列中有效数据的长度
*@author liuyanfu
*@date   2019年4月2日	23:54
*@param[out] 
*@return     UINT  
****************************************/
template<typename T>
UINT CircleQueue<T>::getlength() const
{
	return m_nQueueLen;
}



/****************************************!
*@brief  
*@author liuyanfu
*@date   2019年4月2日	23:54
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool CircleQueue<T>::empty() const
{
	return m_nHead == m_nTail; //m_nQueueLen == 0;
}



/****************************************!
*@brief  清空队列
*@author liuyanfu
*@date   2019年4月2日	23:55
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void CircleQueue<T>::erase()
{
	m_nHead = 0;
	m_nTail = 0;
	m_nQueueLen = 0;
}


/****************************************!
*@brief  打印队列中的有效数据
*@author liuyanfu
*@date   2019年4月2日	23:56
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void CircleQueue<T>::print() const
{
	if(empty())
		std::cout << "Current queue is empty!" << std::endl;
	else
	{
		UINT index = m_nHead;
		int i = 1;
		while(index != m_nTail) 
		{
			std::cout << "The " << i << "th element data is " << m_pQueue[index] << std::endl;
			index = (index + 1) / m_nQueueSize; //索引需要通过对模取余的方式确定
			++i;
		}

		std::cout << "All elements are printed." << std::endl;
	}
}