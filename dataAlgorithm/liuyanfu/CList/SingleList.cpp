#include "SingleList.h"
#include "Single_List_Err.h"


template <typename ElmDataType>
SingleList<ElmDataType>::SingleList(void)
 {
	 m_nListLen = 0;
	 m_pHead = m_pTail = NULL;
 }


template <typename ElmDataType>
SingleList<ElmDataType>::~SingleList(void)
 {
	 m_nListLen = 0;
	 m_pHead = m_pTail = NULL;
 }

template <typename ElmDataType>
void SingleList<ElmDataType>::AddHead(const ElmDataType &data)
 {
	 ListNode pNewNode = new NodeType;
	 pNewNode->data = data;
	 if(NULL == m_pHead)//插入第一个节点时
	 {
		 pNewNode->pNext = NULL;
		 m_pTail = pNewNode;
	 }
	 else
	 {
		 pNewNode->pNext = m_pHead;
	 }
	 m_pHead = pNewNode;
	 ++m_nListLen;

 }


template <typename ElmDataType>
void SingleList<ElmDataType>::AddTail(const ElmDataType &data)
 {
	 ListNode pNewNode = new NodeType;
	 pNewNode->data = data;
	 pNewNode->pNext = NULL;
	 if(NULL == m_pTail)
	 {
		 m_pHead = pNewNode;
	 }
	 else
	 {
		 m_pTail->pNext = pNewNode;
	 }
	 m_pTail = pNewNode;
	 ++m_nListLen;
 }


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::InsertAt(ListNode pos, const ElmDataType &data)
{
	if(NULL == pos)
		return NULL;
	ListNode p = m_pHead;
	if(pos == p)
	{
		AddHead(data);
		return m_pHead;
	}

	ListNode prev = NULL;
	while(p)
	{
		if(p == pos)
		{
			ListNode pNewNode = new NodeType;
			pNewNode->data = data;
			pNewNode->pNext = p;
			prev->pNext = pNewNode;
			++m_nListLen;
			return pNewNode;
		}
		prev = p;
		p = p->pNext;
	}

	return NULL;
}

template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::RemoveAt(ListNode pos)
{
	if(NULL == pos)
		return NULL;
	ListNode p = m_pHead;
	ListNode prev = NULL;
	if(pos == m_pHead)
	{
		p = p->pNext;
		delete pos;
		m_pHead = p;
		return p;
	}
	else
	{
		while(p)
		{
			if(p == pos)
			{
				prev->pNext = p->pNext;
				delete p;
				--m_nListLen;
				if(pos == m_pTail)
					m_pTail = prev;
				return prev->pNext;
			}
			prev = p;
			p = p->pNext;
		}
	}
	return NULL;
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::ModifyAt(ListNode pos, const ElmDataType &data)
{
	if(NULL == pos)
		throw(PARA_ERR);
	ListNode p = m_pHead;
	while(p)
	{
		if(p == pos)
		{
			p->data = data;
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::Find(const ElmDataType &data)
{
	ListNode p = GetHeadNode();
	while(p)
	{
		if(p->data == data)
			return p;
		p = p->pNext;
	}
	return NULL;
}


template <typename ElmDataType>
void SingleList<ElmDataType>::Erase()
{
	ListNode p = m_pHead;
	ListNode q = p;
	while(p)
	{
		p = p->pNext;
		delete q;
		q = p;
	}
	m_nListLen = 0;
}


template <typename ElmDataType>
void SingleList<ElmDataType>::PrintList() const
{
	ListNode p = m_pHead;
	UINT Index = 1;
	while(p)
	{
		std::cout <<"The " << Index << "th of current list is:  "<< p->data << std::endl;
		p = p->pNext;
		++Index;
	}
}

template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::GetNode(const ElmDataType &data) const
{
	ListNode p = m_pHead;
	while(p)
	{
		if(p->data == data)
			return p;
		p = p->pNext;
	}
	return NULL;
}
