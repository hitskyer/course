#include "CircleList.h"

using namespace std;
template <typename ElmDataType>
CCircleList<ElmDataType>::CCircleList(void)
{
	m_pHead = new NodeType;
	m_pHead->data = 0;
	m_pHead->pNext = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;
}

template <typename ElmDataType>
CCircleList<ElmDataType>::~CCircleList(void)
{
	//Erase();
	delete m_pHead;
	m_ListLen = 0;
	m_pHead = m_pTail = NULL;
}


template <typename ElmDataType>
void CCircleList<ElmDataType>::PushBack(const ElmDataType &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead;
	m_pTail->pNext = pNewNode;
	m_pTail = pNewNode;
	++m_ListLen;
}

template <typename ElmDataType>
void CCircleList<ElmDataType>::PushFront(const ElmDataType &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = m_pHead->pNext;
	m_pHead->pNext = pNewNode;
	++m_ListLen;
}


template <typename ElmDataType>
void CCircleList<ElmDataType>::Reverse()
{
	if (m_ListLen == 0 || m_ListLen == 1)
	{
		return;
	}
	ListNode preNode = m_pHead;
	m_pTail = m_pHead->pNext;
	ListNode MidNode = preNode->pNext;
	ListNode NextNode = MidNode->pNext;
	while(MidNode != m_pHead)
	{
		MidNode->pNext = preNode;
		preNode = MidNode;
		MidNode = NextNode;
		NextNode = MidNode->pNext;
	}
	MidNode->pNext = preNode;
}

template <typename ElmDataType>
typename CCircleList<ElmDataType>::ListNode CCircleList<ElmDataType>::RemoveAt(ListNode pos)
{
	if(pos == NULL)
		return NULL;
	if(m_ListLen == 0)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	ListNode PrevNode = m_pHead;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			PrevNode->pNext = TempNode->pNext;
			delete TempNode;
			TempNode = NULL;
			--m_ListLen;
			if(pos == m_pTail)
			{
				m_pTail = PrevNode;
			}
			return PrevNode->pNext;
		}
		PrevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
typename CCircleList<ElmDataType>::ListNode CCircleList<ElmDataType>::InsertAt(ListNode pos, const ElmDataType &data)
{
	if(pos == NULL)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	ListNode PrevNode = m_pHead;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			ListNode pNewNode = new NodeType;
			pNewNode->data = data;
			pNewNode->pNext = TempNode;
			PrevNode->pNext = pNewNode;
			++m_ListLen;
		}
		PrevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
typename CCircleList<ElmDataType>::ListNode CCircleList<ElmDataType>::Find(const ElmDataType &data) const
{
	if(m_ListLen == 0)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode->data == data)
			return TempNode;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
typename CCircleList<ElmDataType>::ListNode CCircleList<ElmDataType>::FindByIndex(UINT Index) const
{
	if(m_ListLen == 0 || Index > m_ListLen)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	UINT nCount = 1;
	while(TempNode != m_pHead)
	{
		if(nCount == Index)
			return TempNode;
		++nCount;
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
void CCircleList<ElmDataType>::Erase()
{
	if(m_ListLen == 0)
		return;
	ListNode TempNode = m_pHead->pNext;
	ListNode PrevNode = m_pHead;
	while(TempNode != m_pHead)
	{
		PrevNode->pNext = TempNode->pNext;
		delete TempNode;
		TempNode = PrevNode->pNext;
		--m_ListLen;
	}
}


template <typename ElmDataType>
void CCircleList<ElmDataType>::PrintList() const
{
	if(m_ListLen == 0)
		return;
	ListNode TempNode = m_pHead->pNext;
	UINT nCount = 1;
	while(TempNode != m_pHead)
	{
		cout << "The " << nCount << "th ListNode data is " << TempNode->data << endl;
		++nCount;
		TempNode = TempNode->pNext;
	}
}


template <typename ElmDataType>
void CCircleList<ElmDataType>::MergeList(CCircleList<ElmDataType> &lst)
{
	if(lst.IsEmpty())
		return;
	ListNode TempNode = lst.GetHead()->pNext;
	this->m_pTail->pNext = TempNode;
	lst.GetTail()->pNext = this->m_pHead;
	this->m_pTail = lst.GetTail();
	m_ListLen += lst.m_ListLen;
	//delete lst.GetHead();
}


template <typename ElmDataType>
typename CCircleList<ElmDataType>::
	ListNode CCircleList<ElmDataType>::ModifyAt(ListNode pos, const ElmDataType &data)
{
	if(pos == NULL)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	while(TempNode != m_pHead)
	{
		if(TempNode == pos)
		{
			TempNode->data = data;
			return TempNode;
		}
		TempNode = TempNode->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
typename CCircleList<ElmDataType>::
	ListNode CCircleList<ElmDataType>::RemoveAt(UINT nCountBack)
{
	if(nCountBack > m_ListLen)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	ListNode PrevNode = m_pHead;
	UINT nCount = 0;
	for(;nCount < m_ListLen - nCountBack; ++nCount)
	{
		PrevNode = TempNode;
		TempNode = TempNode->pNext;
	}
	PrevNode->pNext = TempNode->pNext;
	delete TempNode;
	--m_ListLen;
	return 	PrevNode->pNext;
}
