#include<iostream>
#include"Queue.h"

template<typename T> ListQueue<T>::ListQueue(void)
{
	m_pHead = m_pTail = NULL;
	m_nQueueLen = 0;
}

template<typename T> ListQueue<T>::~ListQueue(void)
{
	erase();
}
// 入栈
template<typename T> bool ListQueue<T>::enqueue(const T &data)
{
	bool flag = false;
	QNode newnode = new SNode<T>;
	if(NULL == newnode)
	{
		flag = false;
	}
	else
	{
		newnode->data = data;
		newnode->pNext = NULL;
		if(0 == m_nQueueLen)
		{
			m_pHead = newnode;
			m_pTail = newnode;
		}
		else
		{
			m_pTail->pNext = newnode;
			m_pTail = m_pTail->pNext;
		}
		++m_nQueueLen;
		flag = true;
	}
	return flag;
}
// 出栈
template<typename T> bool ListQueue<T>::dequeue()
{
	bool flag = false;
	if(0 == m_nQueueLen)
	{	
		flag = false;
	}
	else
	{
		QNode p;
		p = m_pHead->pNext;
		delete m_pHead;
		m_pHead = p;
		--m_nQueueLen;
		flag = true;
	}
	return flag;
}
// 得到长度
template<typename T> UINT ListQueue<T>::getlength() const
{
	return m_nQueueLen;
}
// 判断是否为空
template<typename T> bool ListQueue<T>::empty() const
{
	return 0 == m_nQueueLen;
}
// 清空
template<typename T> void ListQueue<T>::erase()
{
	while(m_nQueueLen)
	{
		dequeue();
	}
}

// 打印
template<typename T> void ListQueue<T>::print() const
{
	if(0 == m_nQueueLen)
	{
		std::cout << "This is an empty Queue!" << std::endl;
	}
	else
	{
		QNode p = m_pHead;
		int i = 1;
		std::cout << "head is here." << std::endl;
		while(p)
		{
			std::cout << "The " << i << "th element data is : " << p->data << std::endl;
			++i;
			p = p->pNext;
		}
		std::cout << "tail is here." << std::endl;
	}
}

