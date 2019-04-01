#include "ListQueue.h"

template<typename T>
ListQueue<T>::ListQueue(void)
{
	m_pHead = m_pTail = NULL;
	m_QueueLen = 0;
}

template<typename T>
ListQueue<T>::~ListQueue(void)
{
	erase();
}


/****************************************!
*@brief  入队(入队更新尾)
*@author liuyanfu
*@date   2019年3月31日	23:06
*@param[out] 
*@param[in]  const T & data  
*@return     bool  
****************************************/
template<typename T>
bool ListQueue<T>::enqueue(const T& data)
{
	QueueNode pNewNode = new SNode<T>;
	if(pNewNode == NULL)
		return false;
	else
	{
		pNewNode->data = data;
		pNewNode->pNext = NULL;
		if(m_pHead == NULL)
		{
			m_pHead = pNewNode;
			m_pTail = pNewNode;
		}
		else
		{
			m_pTail->pNext = pNewNode;
			m_pTail = pNewNode;
		}
		
		++m_QueueLen;
		return true;
	}
}


/****************************************!
*@brief  出队(出队更新头)
*@author liuyanfu
*@date   2019年3月31日	23:06
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ListQueue<T>::dequeue()
{
	if(m_QueueLen == 0)
		return false;
	else
	{
		QueueNode TempNode = m_pHead->pNext;
		delete m_pHead;
		m_pHead = TempNode;
		--m_QueueLen;
		return true;
	}
}



/****************************************!
*@brief  
*@author liuyanfu
*@date   2019年3月31日	22:47
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ListQueue<T>::print() const
{
	if(m_QueueLen == 0)
		std::cout << "Current queue is empty!" << std::endl;
	else
	{
		QueueNode TempNode = m_pHead;
		UINT i = 1;
		while(TempNode)
		{
			std::cout << "The " << i << "th element data is " << TempNode->data << std::endl;
			++i;
			TempNode = TempNode->pNext;
		}
		std::cout << "All elements are printed." << std::endl;
	}
}



/****************************************!
*@brief  
*@author liuyanfu
*@date   2019年3月31日	22:47
*@param[out] 
*@return     UINT  
****************************************/
template<typename T>
UINT ListQueue<T>::getlength() const
{
	return m_QueueLen;
}



/****************************************!
*@brief  
*@author liuyanfu
*@date   2019年3月31日	22:47
*@param[out] 
*@return     bool  
****************************************/
template<typename T>
bool ListQueue<T>::empty() const
{
	return m_QueueLen == 0;
}


/****************************************!
*@brief  
*@author liuyanfu
*@date   2019年3月31日	22:47
*@param[out] 
*@return     void  
****************************************/
template<typename T>
void ListQueue<T>::erase()
{
	while(!empty())
	{
		dequeue();
	}
	m_pHead = m_pTail = NULL;
}