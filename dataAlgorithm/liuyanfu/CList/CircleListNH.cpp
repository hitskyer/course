#include "CircleListNH.h"



template<typename ElmDataType>
CircleListNH<ElmDataType>::CircleListNH(void)
{
	m_pTail = m_pHead = NULL;
	m_ListLen = 0;
}

template<typename ElmDataType>
CircleListNH<ElmDataType>::~CircleListNH(void)
{
	Erase();
	m_pHead = m_pTail = NULL;
	m_ListLen = 0;
}


template<typename ElmDataType>
UINT CircleListNH<ElmDataType>::GetLength()
{
	if(!m_pHead)
	{
		m_ListLen = 0;
		return m_ListLen;
	}
	if(!m_pHead->pNext)
	{
		m_ListLen = 1;
		return m_ListLen;
	}
	ListNode TempNode = m_pHead->pNext;
	UINT nCount = 1;
	while(TempNode != m_pHead)
	{
		++nCount;
		TempNode = TempNode->pNext;
	}
	m_ListLen = nCount;
	return m_ListLen;
}

template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::GetMidNode()
{
	if(!m_pHead)
		return NULL;
	ListNode TempNode = m_pHead;
	UINT i = 0;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(i == (m_ListLen -1)/2)
			break;
		TempNode = TempNode->pNext;
	}
	return TempNode;
}


template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::GetNode(const int &data) const
{
	ListNode TempNode = m_pHead;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(TempNode->data == data)
			return TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}

template<typename ElmDataType>
void CircleListNH<ElmDataType>::AddHead(const int &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead;
	if(!m_pTail)
	{
		pNewNode->pNext = pNewNode;
		m_pTail = pNewNode;
	}
	else	
		m_pTail->pNext = pNewNode;
	m_pHead = pNewNode;
	++m_ListLen;
}


template<typename ElmDataType>
void CircleListNH<ElmDataType>::AddTail(const int &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead;
	if(!m_pHead)
	{
		pNewNode->pNext = pNewNode;
		m_pHead = pNewNode;
	}
	else
		m_pTail->pNext = pNewNode;
	m_pTail = pNewNode;
	++m_ListLen;
}


template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::
	InsertAt(ListNode pos, const int &data)
{
	if(pos == m_pHead)
	{
		AddHead(data);
		return m_pHead;
	}
	ListNode TempNode = m_pHead;
	ListNode prevNode = NULL;
	UINT nTime = 1;

	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(TempNode == pos)
		{
			ListNode pNewNode = new NodeType;
			pNewNode->data = data;
			pNewNode->pNext = TempNode;
			prevNode->pNext = pNewNode;
			++ m_ListLen;
			return pNewNode;
		}
		prevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}

template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::
	ModifyAt(ListNode pos, const int &data)
{
	if(IsEmpty())
		return NULL;
	ListNode TempNode = m_pHead;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(TempNode == pos)
		{
			TempNode->data = data;
			return TempNode;
		}
		TempNode = TempNode->pNext;
	}
	return NULL;
}

template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::RemoveAt(ListNode pos)
{
	if(IsEmpty())
		return NULL;
	if(pos == m_pHead)
	{
		m_pTail->pNext = m_pHead->pNext;
		delete m_pHead;
		if(--m_ListLen == 0)
		{
			m_pHead = m_pTail = NULL;
			return NULL;
		}
		m_pHead = m_pTail->pNext;
		return m_pHead;
	}
	ListNode TempNode = m_pHead;
	ListNode prevNode = TempNode;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(pos == TempNode)
		{
			prevNode->pNext = TempNode->pNext;
			delete TempNode;
			--m_ListLen;
			if(pos == m_pTail)
				m_pTail = prevNode;
			return prevNode->pNext;
		}
		prevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::RemoveAt(UINT nCountBack)
{
	if(IsEmpty())
		return NULL;
	if(nCountBack > m_ListLen)
		return NULL;
	if(nCountBack == m_ListLen)
	{
		m_pTail->pNext = m_pHead->pNext;
		delete m_pHead;
		if(--m_ListLen == 0)
		{
			m_pHead = m_pTail = NULL;
			return NULL;
		}
		m_pHead = m_pTail->pNext;
		return m_pHead;
	}
	ListNode TempNode =	m_pHead->pNext;
	ListNode prevNode = TempNode;
	UINT i = 1;
	while(TempNode != m_pHead)
	{
		if(i == m_ListLen - nCountBack)
		{
			prevNode->pNext = TempNode->pNext;
			delete TempNode;
			--m_ListLen;
			if(nCountBack == 1)
				m_pTail = prevNode;
			return prevNode->pNext;
		}
		++i;
		prevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template<typename ElmDataType>
void CircleListNH<ElmDataType>::Erase()
{
	if(IsEmpty())
		return ;
	ListNode TempNode;
	ListNode prevNode = m_pHead;
	while(m_ListLen)
	{
		TempNode = prevNode->pNext;
		delete prevNode;
		--m_ListLen;
		prevNode = TempNode;
	}
}


template<typename ElmDataType>
typename CircleListNH<ElmDataType>::ListNode CircleListNH<ElmDataType>::Find(const int &data)
{
	if(IsEmpty())
		return NULL;
	ListNode TempNode = m_pHead;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime !=2)
	{
		if(TempNode == m_pHead)
			++nTime;
		if(TempNode->data == data)
			return TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}

template<typename ElmDataType>
void CircleListNH<ElmDataType>::PrintList() const
{
	ListNode TempNode = m_pHead;
	UINT nTime = 1;
	UINT i = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		cout << "The " << i << "th list node data is: " << TempNode->data << endl;
		++i;
		TempNode = TempNode->pNext;
	}
}


template<typename ElmDataType>
void CircleListNH<ElmDataType>::Reverse()
{
	if(m_ListLen < 2)
		return;
	ListNode TempNode = m_pHead;
	ListNode pNode, qNode = m_pTail;
	UINT nTime = 1;
	while(TempNode != m_pHead || nTime != 2)
	{
		if(TempNode == m_pHead)
			++nTime;
		pNode = TempNode->pNext;
		TempNode->pNext = qNode;
		qNode = TempNode;
		TempNode = pNode;
	}
	m_pTail = m_pHead;
	m_pHead = qNode;
}