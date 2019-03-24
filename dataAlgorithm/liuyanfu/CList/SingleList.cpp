#include "SingleList.h"
#include "Single_List_Err.h"

using namespace std;
template <typename ElmDataType>
SingleList<ElmDataType>::SingleList(void)
 {
	 m_nListLen = 0;
	 m_pHead = m_pTail = NULL;
 }


template <typename ElmDataType>
SingleList<ElmDataType>::~SingleList(void)
 {
	Erase();
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
	else if(pos == m_pHead)
	{
		AddHead(data);
		return m_pHead;
	}
	else
	{
		ListNode p = m_pHead;
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
				p = pNewNode;
				break;
			}
			prev = p;
			p = p->pNext;
		}
		return p;
	}
}

template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::RemoveAt(ListNode pos)
{
	ListNode p = m_pHead;
	if(NULL == pos)
		return NULL;
	else if(pos == m_pHead)
	{
		p = p->pNext;
		delete p;
		m_pHead = p;
		return p;
	}
	else
	{
		ListNode prev = NULL;
		while(p)
		{
			if(p == pos)
			{
				prev->pNext = p->pNext;
				delete p;
				--m_nListLen;
				if(pos == m_pTail)
					m_pTail = prev;
				p = prev->pNext;
				break;
			}
			prev = p;
			p = p->pNext;
		}
	}
	return p;
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::ModifyAt(ListNode pos, const ElmDataType &data)
{
	if(NULL == pos)
		return NULL;
	else
	{
		ListNode p = m_pHead;
		while(p)
		{
			if(p == pos)
			{
				p->data = data;
				break;
			}
			p = p->pNext;
		}
		return p;
	}
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::Find(const ElmDataType &data)
{
	ListNode p = m_pHead;
	while(p)
	{
		if(p->data == data)
		{
			break;
		}
		p = p->pNext;
	}
	return p;
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
		q = NULL;
		q = p;
	}
	m_pHead = m_pTail = NULL;
	m_nListLen = 0;
}


template <typename ElmDataType>
void SingleList<ElmDataType>::PrintList() const
{
	ListNode p = m_pHead;
	UINT Index = 1;
	while(p)
	{
		cout << "The " << Index << "th list node data is :  " << p->data << endl;
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

template <typename ElmDataType>
void SingleList<ElmDataType>::ReverseList()
{
	if(IsEmpty())
		return;
	m_pTail = m_pHead;
	ListNode p = m_pHead->pNext;
	m_pTail->pNext = NULL;
	ListNode pTemp = p;
	while(p)
	{
		pTemp = p->pNext;
		p->pNext = m_pHead;
		m_pHead = p;
		p = pTemp;
	}
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::RemoveAt(UINT nCountBack)
{
	/*ListNode p = m_pHead;
	if(nCountBack == m_nListLen)
	{
		m_pHead = m_pHead->pNext;
		delete p;
		--m_nListLen;
		return m_pHead;
	}
	ListNode prev = p;
	UINT nCount = 0;
	while(p)
	{
		if(nCount == m_nListLen - nCountBack)
		{
			prev->pNext = p->pNext;
			delete p;
			--m_nListLen;
			if(nCountBack == 1)
				m_pTail = prev;
			return prev->pNext;
		}
		++nCount;
		prev = p;
		p = p->pNext;
	}
	return NULL;*/
	if(nCountBack > m_nListLen || nCountBack == 0)
		return NULL;
	else
	{
		ListNode fast = m_pHead;
		ListNode slow = m_pHead;
		for(UINT i = 0; i < nCountBack -1; ++i)
		{
			fast = fast->pNext;
		}
		while(fast->pNext)
		{
			fast = fast->pNext;
			slow = slow->pNext;
		}
		return slow;
	}
	
}


template <typename ElmDataType>
typename SingleList<ElmDataType>::ListNode SingleList<ElmDataType>::GetMidNode()
{
	/*if(m_nListLen == 0)
		return NULL;
	ListNode p = m_pHead;
	UINT Index = 0;
	while(p)
	{
		if(Index == (m_nListLen  - 1)/ 2)
		{
			return p;
		}
		++Index;
		p = p->pNext;
	}
	return NULL;*/

	ListNode fast = m_pHead;
	ListNode slow = m_pHead;
	while(fast != NULL && fast->pNext != NULL)
	{
		fast = fast->pNext->pNext;
		slow = slow->pNext;
	}
	return slow;
}
