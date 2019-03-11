#ifndef _SINGLELISTWITHHEAD_H
#define _SINGLELISTWITHHEAD_H

typedef unsigned int UINT;

template <typename ElmDataType>
struct SNode
{
	ElmDataType data;
	SNode<ElmDataType>* pNext;
};

template <typename ElmDataType>
class SingleListWithHead
{
	typedef SNode<ElmDataType>* ListNode;
	typedef SNode<ElmDataType>  NodeType;
public:
	SingleListWithHead(void);
	SingleListWithHead(SingleListWithHead<ElmDataType> &c)
	{
		this->m_pHead = c.m_pHead;
		this->m_pTail = c.m_pTail;
	}
	SingleListWithHead(ListNode begin_pos, ListNode end_pos);
	SingleListWithHead(UINT nCount, ElmDataType &data);
	SingleListWithHead(UINT nCount);
	SingleListWithHead();

	~SingleListWithHead(void);

	ListNode GetHeadNode() const
	{
		return m_pHead->pNext;
	}
	ListNode GetTailNode() const
	{
		return m_pTail;
	}
	UINT GetSize() const
	{
		return m_ListLen;
	}
	bool IsEmpty() const
	{
		return m_ListLen == 0;
	}

	void AddHead(const ElmDataType &data);
	void AddTail(const ElmDataType &data);

	ListNode Remove(ListNode pos);
	ListNode Remove(ListNode begin_pos, ListNode end_pos);

	ListNode Insert(ListNode pos, const ElmDataType &data);
	ListNode Insert(ListNode pos, UINT nCount, const ElmDataType &data);
	ListNode Insert(ListNode pos, ListNode begin_pos, ListNode end_pos);

	ListNode Erase(ListNode pos);
	ListNode Erase(ListNode begin_pos, ListNode end_pos);

	void Clear();

	ListNode Find(const ElmDataType &data) const;
	ListNode GetNodePos(const ElmDataType &data) const;

	void PrintList() const;

private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_ListLen;
	bool JudgeOrder(ListNode, ListNode);
};


#endif //_SINGLELISTWITHHEAD_H

template<typename ElmDataType>
SingleListWithHead<ElmDataType>::SingleListWithHead()
{
	m_pHead  = new NodeType;
	m_pHead->pNext = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;
}

template<typename ElmDataType>
	bool SingleListWithHead<ElmDataType>::JudgeOrder(ListNode Left_pos, ListNode Right_pos)
{
	if(!Left_pos)
		return false;

	ListNode p = Left_pos;
	while(p)
	{
		if(p == Right_pos)
			return true;
		p = p->pNext;
	}
	if(p == Right_pos)
		return true;
	return false;
}

template<typename ElmDataType>
SingleListWithHead<ElmDataType>::SingleListWithHead(ListNode begin_pos, ListNode end_pos)
{
	if(!JudgeOrder(begin_pos, end_pos))
		return;

	m_pHead  = new NodeType;
	m_pHead->pNext = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;

	ListNode p = begin_pos;
	m_pHead->pNext = p;
	while(p)
	{
		m_pTail = new NodeType;
		m_pTail = p;
		++ m_ListLen;
		if(m_pTail == end_pos)
		{
			break;
		}
		p = p->pNext;
	}
}


template<typename ElmDataType>
SingleListWithHead<ElmDataType>::SingleListWithHead(UINT nCount, ElmDataType &data)
{
	if(nCount == 0)
		return;

	m_pHead  = new NodeType;
	m_pHead->pNext = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;

	ListNode pNew = new NodeType;
	m_pHead->pNext = pNew;
	pNew->data = data;
	m_pTail = pNew;

	UINT Index = 1;
	for(;Index < nCount; ++Index)
	{
		pNew = new NodeType;
		pNew->data = data;
		m_pTail->pNext = pNew;
		m_pTail = pNew;
	}

	m_ListLen = Index - 1;
}


template<typename ElmDataType>
SingleListWithHead<ElmDataType>::SingleListWithHead(UINT nCount)
{
	if(nCount == 0)
		return;

	m_pHead  = new NodeType;
	m_pHead->pNext = NULL;
	m_pTail = m_pHead;
	m_ListLen = 0;

	ListNode pNew = new NodeType;
	m_pHead->pNext = pNew;
	m_pTail = pNew;

	UINT Index = 1;
	for(;Index < nCount; ++Index)
	{
		pNew = new NodeType;
		m_pTail->pNext = pNew;
		m_pTail = pNew;
	}

	m_ListLen = Index - 1;
}


template<typename ElmDataType>
void SingleListWithHead<ElmDataType>::AddHead(const ElmDataType &data)
{
	ListNode pNew = new NodeType;
	pNew->data = data;
	pNew->pNext = m_pHead->pNext;	
	m_pHead->pNext = pNew;
	++m_ListLen;
}

template<typename ElmDataType>
void SingleListWithHead<ElmDataType>::AddTail(const ElmDataType &data)
{
	ListNode pNew = new NodeType;
	pNew->data = data;
	pNew->pNext = NULL;
	m_pTail->pNext = pNew;
	m_pTail = pNew;
	++m_ListLen;
}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::ListNode SingleListWithHead<ElmDataType>::Remove(ListNode pos)
{
	ListNode p = m_pHead;
	ListNode q = p;
	while(p)
	{
		if(pos == p)
		{
			q->pNext = p->pNext;
			delete p;
			--m_ListLen;

			if(pos == m_pTail)
				m_pTail = q;
			return q->pNext;
		}
		q = p;
		p = p->pNext;		
	}
	return NULL;
}

template<typename ElmDataType>
typename ListNode SingleListWithHead<ElmDataType>::
	SingleListWithHead<ElmDataType>::Remove(ListNode begin_pos, ListNode end_pos)
{
	if(!JudgeOrder())
		return;
	ListNode p = m_pHead;
	ListNode q = begin_pos;
	while(p)
	{
		if(p == q)
		{
			Remove(p);
			if(p == end_pos)
				return end_pos->pNext;			
			q = q->pNext;
		}
		p = p->pNext;
	}
	return NULL;
}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::
	ListNode SingleListWithHead<ElmDataType>::Insert(ListNode pos, const ElmDataType &data)
{
	if(pos == NULL)
		return;
	ListNode prev = m_pHead;
	ListNode p = prev;
	while(p)
	{
		if(p = pos)
		{
			prev->pNext = new ElmDataType;
			prev->pNext->data = data;
			prev->pNext->pNext = p;
			++m_ListLen;
			break;
		}
		prev = p;
		p = p->pNext;
	}
	return prev->pNext;
}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::
	ListNode SingleListWithHead<ElmDataType>::Insert(ListNode pos, UINT nCount, const ElmDataType &data)
{
	if(pos == NULL)
		return;
	ListNode prev = m_pHead;
	ListNode p = prev;
	while (p)
	{
		if(p == pos)
		{
			UINT i = 0;
			for(; i < nCount; ++i)
			{
				prev->pNext = new ElmDataType;
				prev->pNext->data = data;
				prev->pNext->pNext = p;
				++m_ListLen;
			}
			if(i == nCount)
				break;
		}
		prev = p;
		p = p->pNext;
	}
	return prev->pNext;
}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::
	ListNode SingleListWithHead<ElmDataType>::Insert(ListNode pos, ListNode begin_pos, ListNode end_pos)
{

}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::
	ListNode SingleListWithHead<ElmDataType>::Erase(ListNode pos)
{
	if(pos == NULL)
		return;
	ListNode prev = m_pHead;
	ListNode p = prev;
	while(p)
	{
		if(p == pos)
		{
			prev->pNext = p->pNext;
			delete p;
			--m_ListLen;
			if(pos == m_pTail)
				m_pTail = prev;
		}
		prev = p;
		p = p->pNext;
	}
	return prev->pNext;
}

template<typename ElmDataType>
typename SingleListWithHead<ElmDataType>::
	ListNode SingleListWithHead<ElmDataType>::Erase(ListNode begin_pos, ListNode end_pos)
{
	if(begin_pos == NULL);
		return;
	if(!JudgeOrder())
		return;
	ListNode prev = m_pHead;
	ListNode q = begin_pos;
	ListNode retNode;
	while(p)
	{
		if(p = q)
		{
			retNode = Erase(q);
		}
		q = q->pNext;
		p = p->pNext;
	}
	return retNode;
}


template<typename ElmDataType>
ListNode SingleListWithHead<ElmDataType>::Clear()
{
	ListNode prev = m_pHead;
	ListNode p = prev;
	while(p)
	{
		prev = p;
		p = p->pNext;
		delete prev;
	}
}