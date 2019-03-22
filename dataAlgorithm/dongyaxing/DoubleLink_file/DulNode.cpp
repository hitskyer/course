#include "DulNode.h"
DulList::DulList(void)
{
	m_pHead = m_pTail = NULL;
	m_nDulListLen = 0;
}
DulList::~DulList(void)
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;

	DNode p;
	while(m_pHead)
	{
		p = m_pHead->pNext;
		delete m_pHead;
		m_pHead = p;
	}
	m_nDulListLen = 0;
	return;
}
// 判断是否为空
bool DulList::IsEmpty() const
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return true;
	else
		return false;
}
// 获取当前链表的长度
UINT DulList::GetLength() const
{
	return m_nDulListLen;
}
// 获取链表的头结点
DNode DulList::GetHeadNode() const
{
	return m_pHead;
}
// 获得链表的尾结点
DNode DulList::GetTailNode() const
{
	return m_pTail;
}
// 获得链表的中间结点
DNode DulList::GetMidNode() const
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	int mid = m_nDulListLen / 2;
	int remainder = m_nDulListLen % 2;
	DNode temp;
	temp = m_pHead;
	if(remainder == 1)
	{
		while(mid)
		{
			temp = temp->pNext;
			--mid;
		}
		return temp;
	}
	else
	{
		--mid;
		while(mid)
		{
			temp = temp->pNext;
			--mid;
		}
		return temp;
	}	
}
// 在链表的头部插入新的结点
void DulList::AddHead(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
	}
	else
	{
		newNode->pNext = m_pHead;
		m_pHead->pPrev = newNode;
		m_pHead = newNode;
		++m_nDulListLen;
		return;
	}
}
// 在链表的尾部插入新的结点
void DulList::AddTail(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
	}
	else
	{
		m_pTail->pNext = newNode;
		newNode->pPrev = m_pTail;
		m_pTail = newNode;
		++m_nDulListLen;
		return;
	}
}
// 在指定结点前插入数据，并返回新结点的地址
DNode DulList::InsertAt(DNode pos, const int &data)
{
	if(pos == NULL)
		return NULL;
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	DNode p;
	p = m_pHead;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		m_pTail = newNode;
		m_pHead = newNode;
		++m_nDulListLen;
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
				newNode->pNext = p->pNext;
				newNode->pPrev = p;
				pos->pPrev = newNode;
				p->pNext = newNode;
				++m_nDulListLen;
				return newNode;
			}
			p = p->pNext;
		}	
	}
	return NULL;
}
// 修改指定结点的数据，并返回当前节点的地址
DNode DulList::ModifyAt(DNode pos, const int &data)
{
	if(pos == NULL)
		return NULL;
	DNode p;
	p = m_pHead;
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
				pos->data = data;
				return pos;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// 删除指定结点，并返回被删除结点的下一结点的地址
DNode DulList::RemoveAt(DNode pos)
{
	if(pos == NULL)
		return NULL;
	if(m_pHead == NULL ||m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	if(m_pHead == m_pTail && m_pHead != NULL)
	{
		if(pos == m_pTail)
		{
			m_pHead = NULL;
			m_pTail = NULL;
			return NULL;
		}
		else
		{
			return NULL;
		}
	}
	DNode p;
	p = m_pHead;
	while(p)
	{
		if(p->pNext == pos)
		{
			p->pNext = pos->pNext;
			pos->pPrev->pPrev = p;
			p = p->pNext;
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
// 删除倒数第n个节点，并返回被删除结点的下一结点的地址
DNode DulList::RemoveAt(UINT nCountBack)
{
	if(nCountBack > m_nDulListLen )
		return NULL;
	if(m_pHead == NULL ||m_pTail == NULL || m_nDulListLen == 0)
		return NULL;
	if(m_pHead == m_pTail && m_pHead != NULL)
	{
		m_pHead = NULL;
		m_pTail = NULL;
		--m_nDulListLen;
		return NULL;
	}
	UINT n = m_nDulListLen - nCountBack;
	DNode p;
	p = m_pHead;
	DNode q;
	if(n == 0)
	{
		p = p->pNext;
		p->pPrev = NULL;
		delete m_pHead;
		m_pHead = p;
		return m_pHead;
	}
	else
	{
		while(n)
		{
			p = p->pNext;
			--n;
		}
		q = p;
		p->pNext->pPrev = q->pPrev;
		p->pPrev->pNext = q->pNext;
		--m_nDulListLen;
		q = q->pNext;
		delete p;
		return q;		
	}
	return NULL;
}
// 在当前链表中找到和要查找数据相等的第一个结点的地址
DNode DulList::Find(const int &data)
{
	if(m_nDulListLen == 0)
		return NULL;
	
	DNode p;
	p = m_pHead;
	while(p)
	{
		if(p->data == data)
			return p;
		p = p->pNext;
	}
	return NULL;
}
// 删除链表的所有结点
void DulList::Erase()
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;

	DNode p;
	while(m_pHead)
	{
		p = m_pHead->pNext;
		delete m_pHead;
		m_pHead = p;
	}
	m_nDulListLen = 0;
	return;
}
// 打印链表所有结点的数据
void DulList::PrintList() const
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
		return;
	DNode p;
	p = m_pHead;
	while(p)
	{
		std::cout << p->data << std::endl;
		p = p->pNext;
	}
	std::cout << "DulList's length is " << m_nDulListLen << std::endl;
	return;
}
// 反转链表
void DulList::Reverse()
{
	if(m_nDulListLen == 0)
		return;
	if(m_nDulListLen == 1)
		return;
	if(m_nDulListLen == 2)
	{
		DNode p;
		p = m_pHead;
		m_pHead = m_pTail;
		m_pTail = p;
		return;
	}
	else
	{	
		DNode q = NULL;
		DNode p = NULL;
		DNode r = m_pHead;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			
			m_pHead->pNext = q;
			m_pHead->pPrev = p;
			q = m_pHead;
			if(p == NULL)		// 如果不加此语句，则最后都是NULL，无数据
				break;
			m_pHead = p;
		}
		m_pTail = r;
		return;
	}
}