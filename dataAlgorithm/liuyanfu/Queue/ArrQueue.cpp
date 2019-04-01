#include "ArrQueue.h"
#include <string.h>
#define INITQUEUELEN 5


template<typename T>
ArrQueue<T>::ArrQueue(void)
{
	m_nQueueSize = INITQUEUELEN;
	m_pQueue = new T[m_nQueueSize];
	m_nHead =  -1;
	m_nTail = 0;
	m_nQueueLen = 0;
	
}


template<typename T>
ArrQueue<T>::ArrQueue(const UINT& InitSize):m_nQueueSize(InitSize)
{
	m_pQueue = new T[m_nQueueSize];
	m_nHead  = -1;
	m_nTail = 0;
	m_nQueueLen = 0;
}

template<typename T>
ArrQueue<T>::~ArrQueue(void)
{
	delete [] m_pQueue;
	m_pQueue = NULL;
}



/****************************************!
*@brief  入队
*@author liuyanfu
*@date   2019年4月1日	21:12
*@param[out] 
*@param[in]  const T & data  
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::enqueue(const T& data)
{
	if(!m_pQueue || (m_nTail == m_nQueueSize && m_nHead == 0)) //如果队列满了或者空间的地址无效
		return false;
	else if(m_nTail <  m_nQueueSize)
	{
		m_pQueue[m_nTail++] = data;
		if(++m_nQueueLen == 1)
		{
			m_nHead = 0;
		}
		return true;
	}
	else
	{
		//memcpy(m_pQueue, &m_pQueue[m_nHead], sizeof(T) * m_nQueueLen);//目标位置与源位置存在重叠
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


/****************************************!
*@brief  出队
*@author liuyanfu
*@date   2019年4月1日	21:17
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::dequeue()
{
	if(m_nQueueLen == 0) //队列为空时
		return false;
	else
	{
		m_nHead += 1;
		--m_nQueueLen;
		return true;
	}
}


/****************************************!
*@brief  获取队列有效长度
*@author liuyanfu
*@date   2019年4月1日	21:31
*@param[out] 
*@return     UINT  
****************************************/
template<typename T>
UINT ArrQueue<T>::getlength() const
{
	return m_nQueueLen;
}


/****************************************!
*@brief  判断队列是否为空
*@author liuyanfu
*@date   2019年4月1日	21:32
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ArrQueue<T>::empty() const
{
	return m_nQueueLen == 0;
}



/****************************************!
*@brief  清空队列
*@author liuyanfu
*@date   2019年4月1日	21:32
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ArrQueue<T>::erase()
{
	m_nHead = -1;
	m_nTail = 0;
	m_nQueueLen = 0;
}


/****************************************!
*@brief  打印队列中的数据
*@author liuyanfu
*@date   2019年4月1日	21:48
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ArrQueue<T>::print() const
{
	if(empty())
		std::cout << "Current queue is empty!" << std::endl;
	else
	{
		int index = m_nHead;
		int i = 1;
		while(index != m_nTail)
		{
			std::cout << "The " << i << "th element data is " << m_pQueue[index++] << std::endl;
		}

		std::cout << "All elements are printed." << std::endl;
	}
}