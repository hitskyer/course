#include "DoubleList.h"
using namespace std;
template<typename ElmDataType>
DoubleList<ElmDataType>::DoubleList(void)
{
	ListNode HeadNode = new NodeType;
	HeadNode->pNext = NULL;
	HeadNode->pPrev = NULL;
	m_pHead = HeadNode;
	m_pTail = m_pHead;
	m_ListLen = 0;
}


template<typename ElmDataType>
DoubleList<ElmDataType>::~DoubleList(void)
{
	Erase();
	delete m_pHead;
	m_pHead = m_pTail = NULL;
	m_ListLen = 0;
}

template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::GetMidNode()
{
	/*ListNode TempNode = m_pHead->pNext;
	UINT i = 0;
	while(TempNode)
	{
		if(i == (m_ListLen - 1) / 2)
		{
			return TempNode;
		}
		i++;
		TempNode = TempNode->pNext;
	}
	return NULL;*/

	ListNode fast = m_pHead->pNext;
	ListNode slow = m_pHead->pNext;
	while(fast && fast->pNext)
	{
		fast = fast->pNext->pNext;
		slow = slow->pNext;
	}
	return slow;

	
}

template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::GetNode(const int &data) const
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode)
	{
		if(TempNode->data == data)
			break;
		TempNode = TempNode->pNext;
	}
	return TempNode;
}


template<typename ElmDataType>
void DoubleList<ElmDataType>::AddHead(const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	ListNode pNewNode = new NodeType;
	pNewNode->pNext = TempNode;
	pNewNode->pPrev = m_pHead;
	pNewNode->data = data;
	pNewNode->pPrev->pNext = pNewNode;
	if(!m_ListLen)
	{
		m_ListLen = 1;
		m_pTail = pNewNode;
		return;
	}
	pNewNode->pNext->pPrev = pNewNode;
	++m_ListLen;
}


template<typename ElmDataType>
void DoubleList<ElmDataType>::AddTail(const int &data)
{
	ListNode pNewNode = new NodeType;
	pNewNode->data = data;
	pNewNode->pNext = NULL;
	pNewNode->pPrev = m_pTail;
	pNewNode->pPrev->pNext = pNewNode;
	m_pTail = pNewNode;
	++m_ListLen;
}
template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::InsertAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode)
	{
		if(TempNode == pos)
		{
			ListNode pNewNode = new NodeType;
			pNewNode->data = data;
			pNewNode->pNext = TempNode;
			pNewNode->pPrev = TempNode->pPrev;
			pNewNode->pPrev->pNext = pNewNode;
			pNewNode->pNext->pPrev = pNewNode;
			++m_ListLen;
			TempNode = pNewNode;
			break;
		}
		TempNode = TempNode->pNext;
	}
	return TempNode;
}



template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::ModifyAt(ListNode pos, const int &data)
{
	ListNode TempNode = m_pHead->pNext;
	while(TempNode)
	{
		if(TempNode == pos)
		{
			TempNode->data = data;
			break;
		}
		TempNode = TempNode->pNext;
	}
	return TempNode;
}


template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::RemoveAt(ListNode pos)
{
	ListNode TempNode = m_pHead->pNext;
	ListNode RetNode;
	while(TempNode)
	{
		if(pos == TempNode)
		{
			TempNode->pPrev->pNext = TempNode->pNext;
			if(TempNode->pNext)
				TempNode->pNext->pPrev = TempNode->pPrev;
			--m_ListLen;
			if(TempNode == m_pTail)
			{
				m_pTail = TempNode->pPrev;
			}
			RetNode = TempNode->pNext;
			delete TempNode;
			TempNode = NULL;
			TempNode = RetNode;
			break;
		}
		TempNode = TempNode->pNext;
	}
	return TempNode;
}


template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::Find(const int &data)
{
	ListNode TempNode = m_pHead;
	while(TempNode)
	{
		if(TempNode->data == data)
		{
			break;
		}
		TempNode = TempNode->pNext;
	}
	return TempNode;
}


template<typename ElmDataType>
void DoubleList<ElmDataType>::Erase()
{
	ListNode TempNode = m_pHead->pNext;
	ListNode PrevNode;
	while(TempNode)
	{
		//RemoveAt(TempNode);//可以直接调用删除单个节点的接口
		PrevNode = TempNode;
		TempNode->pPrev->pNext = TempNode->pNext;
		if(TempNode->pNext)
			TempNode->pNext->pPrev = TempNode->pPrev;		
		TempNode = TempNode->pNext;
		delete PrevNode;
		PrevNode = NULL;
	}
	PrevNode = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;
}


template<typename ElmDataType>
void DoubleList<ElmDataType>::PrintList() const
{
	ListNode TempNode = m_pHead->pNext;
	UINT i = 1;
	while(TempNode)
	{
		cout << "The " << i << "th ListNode data is " << TempNode->data << endl;
		++i;
		TempNode = TempNode->pNext;
	}
}


template<typename ElmDataType>
void DoubleList<ElmDataType>:: Reverse()
{
	if(m_ListLen < 2)
		return;
	ListNode TempNode = m_pHead->pNext;
	m_pTail = TempNode;
	ListNode p,q;
	while(TempNode)
	{
		p = TempNode;
		q = TempNode->pNext;
		TempNode->pNext = TempNode->pPrev;
		TempNode->pPrev = q;
		TempNode = q;
	}
	
	m_pTail->pNext = NULL;
	m_pHead->pNext = p;
	p->pPrev = m_pHead;
}


template<typename ElmDataType>
typename DoubleList<ElmDataType>::ListNode DoubleList<ElmDataType>::RemoveAt(UINT nCountBack)
{
	/*if(nCountBack > m_ListLen)
		return NULL;
	ListNode TempNode = m_pHead->pNext;
	UINT i = 0;
	while(TempNode)
	{
		if(i == m_ListLen - nCountBack)
		{
			return RemoveAt(TempNode);
		}
		++i;
		TempNode = TempNode->pNext;
	}*/
	if(nCountBack > m_ListLen || nCountBack ==0)
		return NULL;
	else
	{
		ListNode fast = m_pHead->pNext;
		ListNode slow = m_pHead->pNext;
		for(UINT i =0; i< nCountBack - 1; ++i)
		{
			fast = fast->pNext;
		}
		while(fast && fast->pNext)
		{
			fast = fast->pNext;
			slow = slow->pNext;
		}
		return slow;
	}

}
