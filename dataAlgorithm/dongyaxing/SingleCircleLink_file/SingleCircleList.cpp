#include"SingleCircleList.h"
SingleCircleList::SingleCircleList(void)
{
	m_nSCListLen = 0;
	m_pHead = m_pTail = NULL;
}
SingleCircleList::~SingleCircleList(void)
{
	if(m_nSCListLen == 0)
		return;
	else if(m_nSCListLen == 1)
	{
		delete m_pHead;
		m_nSCListLen = 0;
		return;
	}
	else if(m_nSCListLen == 2)
	{
		delete m_pHead;
		delete m_pTail;
		m_nSCListLen = 0;
		return;
	}
	else
	{
		SCLNode p, q;
		p = m_pHead;
		q = m_pHead->pNext;
		while(m_pHead)
		{
			delete p;
			p = q;
			q = q->pNext;
			if(q == m_pHead)
				return;
		}
		m_nSCListLen = 0;
	}
}

bool SingleCircleList::IsEmpty() const
{
	if(m_nSCListLen == 0)
	{
		std::cout << "This is an empty List!" << std::endl;
		return true;
	}
	return false;
}

UINT SingleCircleList::GetLength() const
{
	if(m_nSCListLen == 0)
	{
		std::cout << "This is an empty List!" << std::endl;
		return 0; 
	}
	return m_nSCListLen;
}

SCLNode SingleCircleList::GetHeadNode() const
{
	if(m_pHead == NULL)
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	return m_pHead;
}

SCLNode SingleCircleList::GetTailNode() const
{
	if(m_pTail == NULL)
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	return m_pTail;
}

SCLNode SingleCircleList::GetMidNode()
{
	if(m_pTail == NULL)
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	if(m_nSCListLen == 1 || m_nSCListLen == 2)
		return m_pHead;
	int n = m_nSCListLen / 2;
	int remainder = m_nSCListLen % 2;
	SCLNode p;
	p = m_pHead;
	if(remainder == 1)
	{
		while(n)
		{
			p = p->pNext;
			--n;
		}
		return p;
	}
	else				// 返回偶数中的第一个
	{
		--n;
		while(n)
		{
			p = p->pNext;
			--n;
		}
		return p;
	}
	
	return NULL;
}

void SingleCircleList::AddHead(const int &data)
{
	SCLNode p = new SCNode;
	p->data = data;
	p->pNext = NULL;
	if(m_nSCListLen == 0)
	{	
		m_pHead = p;
		//m_pHead->pNext = m_pHead;
		m_pTail = m_pHead;
		++m_nSCListLen;
		return;
	}
	else
	{
		p->pNext = m_pHead;
		m_pTail->pNext = p;
		m_pHead = p;
		++m_nSCListLen;
		return;
	}
}

void SingleCircleList::AddTail(const int &data)
{
	SCLNode p = new SCNode;
	p->data = data;
	p->pNext = NULL;
	if(m_nSCListLen == 0)
	{	
		m_pHead = p;
		//m_pHead->pNext = m_pHead;
		m_pTail = m_pHead;
		++m_nSCListLen;
		return; 
	}
	else
	{
		p->pNext = m_pHead;
		m_pTail->pNext = p;
		m_pTail = p;
		++m_nSCListLen;
		return;
	}
}
//在指定结点前插入数据，并返回新结点的地址
SCLNode SingleCircleList::InsertAt(SCLNode pos, const int &data)
{
	if(m_pHead == NULL)		// 空
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	if(m_pHead == pos)		// 等于头
	{
		SCLNode p = new SCNode;
		p->data = data;
		p->pNext = m_pHead;
		m_pHead = p;
		m_pTail->pNext = m_pHead;
		++m_nSCListLen;
		return m_pHead;
	}
	SCLNode p;
	p = m_pHead;
	while(p)				// 其他
	{
		if(p->pNext == pos)
		{
			SCLNode q = new SCNode;
			q->data = data;
			q->pNext = p->pNext;
			p->pNext = q;
			++m_nSCListLen;
			return q;
		}
		p = p->pNext;
		if(p == m_pHead)	// 不存在
		{
			return NULL;
		}
	}
	return NULL;
}

SCLNode SingleCircleList::ModifyAt(SCLNode pos, const int &data)
{
	if(m_pHead == NULL)		// 空
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	if(m_pHead == pos)		// 等于头
	{
		m_pHead->data = data;
		return m_pHead;
	}
	SCLNode p;
	p = m_pHead;
	while(p)
	{
		if(p->pNext == pos)
		{
			p->pNext->data = data;
			return p->pNext;
		}
		p = p->pNext;
		if(p == m_pHead)
			return NULL;	// 不存在
	}
	return NULL;
}
//删除指定结点，并返回被删除结点的下一结点的地址
SCLNode SingleCircleList::RemoveAt(SCLNode pos)
{
	if(m_pHead == NULL)		// 空
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	if(m_pHead == pos && m_nSCListLen == 1)		// 等于头,且只有一个
	{
		delete m_pHead;
		m_nSCListLen = 0;
		return NULL;
	}
	SCLNode p;
	p = m_pHead;
	while(p)
	{
		if(p->pNext == pos)
		{
			if(p->pNext == m_pTail)
			{
				p->pNext = m_pHead;
				delete m_pTail;
				--m_nSCListLen;
				return m_pHead;
			}
			else
			{
				p->pNext = pos->pNext;
				delete pos;
				pos = p->pNext;
				--m_nSCListLen;
				return pos;
			}
		}
		p = p->pNext;
		if(p == m_pHead)
			return NULL;	// 不存在
	}
	return NULL;
}

SCLNode SingleCircleList::RemoveAt(UINT nCountBack)
{
	if(m_nSCListLen == 0)		// 空
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	if(m_nSCListLen < nCountBack)
	{
		return NULL;
	}
	if(m_nSCListLen == nCountBack)
	{
		SCLNode p;
		p = m_pHead;
		m_pHead = m_pHead->pNext;
		delete p;
		m_pTail->pNext = m_pHead;
		--m_nSCListLen;
		return m_pHead;
	}
	int n = m_nSCListLen - nCountBack;
	SCLNode p, q;
	p = m_pHead;
	while(n)
	{
		q = p;
		p = p->pNext;
		--n;
	}
	q->pNext = p->pNext;
	delete p;
	q = q->pNext;
	--m_nSCListLen;
	return q;
}
SCLNode SingleCircleList::Find(const int &data)
{
	if(m_nSCListLen == 0)
	{
		std::cout << "This is an empty List!" << std::endl;
		return NULL;
	}
	SCLNode p;
	p = m_pHead;
	while(p)
	{
		if(p->data == data)
		{
			std::cout << "There exists " << data << " number" << std::endl;
			return p;
		}
		p = p->pNext;
		if(p == m_pHead)
		{
			std::cout << "There is not " << data << " number" << std::endl;
			return NULL;	// 不存在
		}
	}
	return NULL;
}

void SingleCircleList::Erase()
{
	if(m_nSCListLen == 0)
		return;
	else if(m_nSCListLen == 1)
	{
		delete m_pHead;
		m_nSCListLen = 0;
		return;
	}
	else if(m_nSCListLen == 2)
	{
		delete m_pHead;
		delete m_pTail;
		m_nSCListLen = 0;
		return;
	}
	else
	{
		SCLNode p, q;
		p = m_pHead;
		q = m_pHead->pNext;
		while(m_pHead)
		{
			delete p;
			p = q;
			q = q->pNext;
			if(q == m_pHead)
				return;
		}
		m_nSCListLen = 0;
	}
}

void SingleCircleList::PrintList() const
{
	if(m_nSCListLen == 0)
	{
		std::cout << "There is not data." << std::endl;
		return;
	}
	else
	{
		SCLNode p = m_pHead;
		while(p)
		{
			std::cout << p->data << std::endl;
			p = p->pNext;
			if(p == m_pHead)
				return;
		}
		return;
	}
}

void SingleCircleList::Reverse()
{
	if(m_nSCListLen == 0)
	{
		std::cout << "There is not data." << std::endl;
		return;
	}
	else if(m_nSCListLen == 1)
	{
		return;
	}
	else if(m_nSCListLen == 2)
	{
		SCLNode p;
		p = m_pHead;
		m_pHead = m_pHead->pNext;
		m_pTail = p;
		return;
	}
	else
	{
		SCLNode p, q, r;
		p = m_pHead;
		q = p->pNext;
		r = q->pNext;
		p->pNext = m_pTail;
		while(p)
		{
			q->pNext = p;
			p = q;
			q = r;
			r = r->pNext;
			if(p == m_pHead)
				break;
		}
		m_pTail = p;
		m_pHead = p->pNext;
	}
}