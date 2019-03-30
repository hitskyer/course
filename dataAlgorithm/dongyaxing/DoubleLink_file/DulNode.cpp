#include "DulNode.h"
DulList::DulList(void):m_pHead(nullptr), m_pTail(nullptr), m_nDulListLen(0)
{
	m_pHead = m_pTail;
}
DulList::~DulList(void)
{
	Erase();
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
	/*if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
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
	}	*/
	
	DNode fast = m_pHead;
	DNode slow = m_pHead;
	while(fast)
	{
		fast = fast->pNext;
		if(fast != NULL)
		{
			fast = fast->pNext->pNext;
			slow = slow->pNext;
		}
		return slow;
	}
	return NULL;
}
// 在链表的头部插入新的结点
void DulList::AddHead(const int &data)
{
	DNode newNode = new DulNode;
	newNode->data = data;
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	if(m_pHead == NULL)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
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
	if(NULL == m_pHead)
	{
		m_pHead = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
	}
	else
	{
		newNode->pPrev = m_pTail;
		m_pTail->pNext = newNode;
		m_pTail = newNode;
		++m_nDulListLen;
	}
}
// 在指定结点前插入数据，并返回新结点的地址
DNode DulList::InsertAt(DNode pos, const int &data)
{
	DNode p = m_pHead;
	if(NULL == pos)
	{
		return NULL;
	}
	else if(p == pos)
	{
		AddHead(data);
		return m_pHead;
	}
	else
	{
		while(p)
		{
			if(p->pNext == pos)
			{
				DNode newNode = new DulNode;
				newNode->data = data;
				newNode->pNext = NULL;
				newNode->pPrev = NULL;
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
	DNode p;
	p = m_pHead;
	if(pos == NULL || m_pHead == NULL)
	{
		return NULL;
	}
	else
	{
		while(p)
		{
			if(p == pos)
			{
				p->data = data;
				return p;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// 删除指定结点，并返回被删除结点的下一结点的地址
DNode DulList::RemoveAt(DNode pos)
{
	if(pos == NULL || m_pHead == NULL)
	{	
		return NULL;
	}
	else
	{
		DNode p;
		p = m_pHead;
		while(p)
		{
			if(p == pos)
			{
				p->pPrev->pNext = pos->pNext;
				p->pNext->pPrev = pos->pPrev;
				p = p->pNext;
				return p;
				p = nullptr;
				--m_nDulListLen;
				return p;
			}
			p = p->pNext;
		}
	}
	
	return NULL;
}
// 删除倒数第n个节点，并返回被删除结点的下一结点的地址
DNode DulList::RemoveAt(UINT nCountBack)
{
	if(nCountBack > m_nDulListLen || m_pHead == NULL || m_nDulListLen <= 0)
	{	
		return NULL;
	}
	else
	{
		UINT n = m_nDulListLen - nCountBack;
		DNode p, q;
		p = m_pHead;
		q = m_pHead->pNext;
		while(n)
		{
			p = p->pNext;
			q = q->pNext;
			--n;
		}
		q->pPrev = p->pPrev;
		p->pPrev->pNext = q;
		delete p;
		p = nullptr;
		--m_nDulListLen;
		return q;		
	}	
	return NULL;
}
// 在当前链表中找到和要查找数据相等的第一个结点的地址
DNode DulList::Find(const int &data) const
{
	if(m_nDulListLen == 0)
	{	
		return NULL;
	}
	else
	{
		DNode p;
		p = m_pHead;
		while(p)
		{
			if(p->data == data)
				return p;
			p = p->pNext;
		}
	}
	return NULL;
}
// 删除链表的所有结点
void DulList::Erase()
{
	if(m_pHead == NULL || m_pTail == NULL || m_nDulListLen == 0)
	{	
		return;
	}
	else
	{
		DNode p;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			delete m_pHead;
			m_pHead = nullptr;
			m_pHead = p;
		}
		m_nDulListLen = 0;
	}
	return;
}
// 打印链表所有结点的数据
void DulList::PrintList() const
{
	if(m_pHead == NULL)
		return;
	else
	{
		DNode p;
		p = m_pHead;
		int index = 1;
		while(p)
		{
			std::cout <<"第 " << index << " 个结点：" << p->data << std::endl;
			p = p->pNext;
			++index;
		}
		std::cout << "DulList's length is: " << m_nDulListLen << std::endl;
	}
	return;
}
// 反转链表
void DulList::Reverse()
{
	if(m_nDulListLen == 0 || m_nDulListLen == 1)
	{	
		return;
	}
	else if(m_nDulListLen == 2)
	{
		DNode p;
		p = m_pHead;
		m_pHead = m_pTail;
		m_pTail = p;
		return;
	}
	else
	{	
		DNode p = NULL;
		DNode q = NULL;
		DNode r = m_pHead;
		while(m_pHead)
		{
			p = m_pHead->pNext;
			m_pHead->pNext = q;
			m_pHead->pPrev = p;
			q = m_pHead;
			if(NULL == p)		// 如果不加此语句，则最后都是NULL，无数据
				break;
			m_pHead = p;
		}
		m_pTail = r;
		return;
	}
}