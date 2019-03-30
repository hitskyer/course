#include "DoubleCircleList.h"

using namespace std;		
template<typename ElmDataType>
DoubleCircleList<ElmDataType>::DoubleCircleList(void)
{
	ListNode pNewNode = new NodeType;
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	m_pHead = m_pTail = pNewNode;
	m_ListLen = 0;
}

template<typename ElmDataType>
DoubleCircleList<ElmDataType>::~DoubleCircleList(void)
{
	Erase();
	delete m_pHead;
	m_pHead = m_pTail = NULL;
	m_ListLen = 0;
}

template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::GetMidNode()  const
{
	/*ListNode TempNode = m_pHead->pNext;
	UINT i = 0;
	while(TempNode != m_pHead)
	{
		if(i == (m_ListLen - 1) / 2)
			return TempNode;
		++i;
		TempNode =TempNode->pNext;
	}
	return NULL;*/
	ListNode fast = m_pHead->pNext;
	ListNode slow = m_pHead->pNext;
	if(fast == NULL)
		return NULL;
	else
	{
		while(fast != m_pHead && fast->pNext != m_pHead)
		{
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
		return slow;
	}

}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::GetNode(const int &data) const
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode->data == data)
			return TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template<typename ElmDataType>
void DoubleCircleList<ElmDataType>::AddHead(const int &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead->pNext;
	pNewNode->pPrev = m_pHead;
	pNewNode->pPrev->pNext = pNewNode;
	++m_ListLen;
	if(!pNewNode->pNext)
	{
		m_pTail = pNewNode;
		m_pTail->pNext = m_pHead;
		m_pHead->pPrev = m_pTail;
		return;
	}
	pNewNode->pNext->pPrev = pNewNode;	
}


template<typename ElmDataType>
void DoubleCircleList<ElmDataType>::AddTail(const int &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pPrev = m_pTail;
	pNewNode->pNext = m_pHead;
	pNewNode->pPrev->pNext = pNewNode;
	pNewNode->pNext->pPrev = pNewNode;
	m_pTail = pNewNode;
	++m_ListLen;
}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::InsertAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			ListNode pNewNode = new NodeType;
			pNewNode->data = data;
			pNewNode->pPrev = TempNode->pPrev;
			pNewNode->pNext = TempNode;
			pNewNode->pPrev->pNext = pNewNode;
			pNewNode->pNext->pPrev = pNewNode;
			++m_ListLen;
			return pNewNode;
		}
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::ModifyAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			TempNode->data = data;
			TempNode;
		}
		TempNode = TempNode->pNext;
	}
	return TempNode == m_pHead ? NULL:TempNode;
}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::RemoveAt(ListNode pos)
{
	ListNode TempNode = m_pHead->pNext;
	ListNode RetNode = NULL;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			TempNode->pPrev->pNext = TempNode->pNext;
			TempNode->pNext->pPrev = TempNode->pPrev;
			RetNode = TempNode->pPrev;
			delete TempNode;
			if(--m_ListLen == 0)
			{
				m_pTail = m_pHead;
				m_pHead->pNext = NULL;
				m_pHead->pPrev = NULL;
				TempNode = NULL;
				break;
			}
			if(m_pTail == pos)
			{
				m_pTail = RetNode;
				TempNode = m_pTail->pNext->pNext;//不让访问到表头
				break;
			}
			else
			{
				TempNode = RetNode->pNext;
				break;
			}
		}
		TempNode = TempNode->pNext;
	}
	return TempNode == m_pHead ? NULL:TempNode;
}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::RemoveAt(UINT nCountBack)
{
	/*if(nCountBack > m_ListLen)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	ListNode RetNode = NULL;
	UINT i = 0;
	while(TempNode != m_pHead)
	{
		if(m_ListLen - nCountBack == i)
		{
			TempNode->pPrev->pNext = TempNode->pNext;
			TempNode->pNext->pPrev = TempNode->pPrev;
			RetNode = TempNode->pPrev;
			delete TempNode;
			if(--m_ListLen == 0)
			{
				m_pTail = m_pHead;
				m_pHead->pNext = NULL;
				m_pHead->pPrev = NULL;
				return NULL;
			}
			if(nCountBack == 1)
			{
				m_pTail = RetNode;
				return m_pTail->pNext->pNext;
			}
			return RetNode->pNext;
		}
		++i;
		TempNode = TempNode->pNext;
	}
	return NULL;*/
	if(nCountBack > m_ListLen || nCountBack == 0)
		return NULL;
	else if(m_pHead->pNext == NULL)
	{
		return NULL;
	}
	else
	{
		ListNode fast = m_pHead->pNext;
		ListNode slow = m_pHead->pNext;
		for(UINT i = 0; i < nCountBack - 1; ++i)
		{
			fast = fast->pNext;
		}
		while(fast != m_pHead && fast != m_pHead)
		{
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
		return slow;
	}

}


template<typename ElmDataType>
typename DoubleCircleList<ElmDataType>::
	ListNode DoubleCircleList<ElmDataType>::Find(const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode->data == data)
			break;
		TempNode = TempNode->pNext;
	}
	return TempNode == m_pHead ? NULL:TempNode;
}


template<typename ElmDataType>
void DoubleCircleList<ElmDataType>::Erase()
{
	ListNode TempNode = m_pHead->pNext;
	ListNode p = NULL;
	while(TempNode != m_pHead)
	{
		p = TempNode->pNext;
		TempNode->pPrev->pNext = TempNode->pNext;
		TempNode->pNext->pPrev = TempNode->pPrev;
		delete TempNode;
		TempNode = NULL;
		--m_ListLen;
		TempNode = p;
	}
	m_pTail = m_pHead;
	m_pTail->pNext = NULL;
	m_pTail->pPrev = NULL;
}


template<typename ElmDataType>
void DoubleCircleList<ElmDataType>::PrintList() const
{
	ListNode TempNode = m_pHead->pNext;
	UINT i = 1;
	while(TempNode != m_pHead)
	{
		cout << "The " << i << "th list node data is " << TempNode->data << endl;
		++i;
		TempNode = TempNode->pNext;
	}
}


template<typename ElmDataType>
void DoubleCircleList<ElmDataType>::Reverse()
{
	if(m_ListLen < 2)
		return;
	ListNode TempNode = m_pHead->pNext;
	m_pHead->pNext = m_pTail;
	m_pHead->pPrev = TempNode;
	m_pTail = TempNode;
	ListNode p = NULL;
	while(TempNode != m_pHead)
	{
		p = TempNode->pNext;
		TempNode->pNext = TempNode->pPrev;
		TempNode->pPrev = p;
		TempNode = p;
	}
}
