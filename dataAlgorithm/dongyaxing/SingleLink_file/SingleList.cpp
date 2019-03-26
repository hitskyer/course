#include "SingleList.h"
SingleList::SingleList(void):m_pHead(nullptr), m_pTail(nullptr), m_nListLen(0)
{
	//m_nListLen = 0;
	//m_pHead = m_pTail = nullptr;
}

SingleList::~SingleList(void)
{
	Erase();
}
//判断链表是否为空
bool SingleList::IsEmpty() const
{
	return m_nListLen == 0;	
}
//获取当前链表的长度
UINT SingleList::GetLength() const
{
	return m_nListLen;
}
//获取链表的头结点
ListNode SingleList::GetHeadNode() const
{
	return m_pHead;
}
//获取链表的尾结点
ListNode SingleList::GetTailNode() const
{
	return m_pTail;
}
//获得链表的中间结点，偶数时，返回第一个结点
ListNode SingleList::GetMidNode() const
{
	// 基数偶数判断，找中点
	//int mid = 0;
	//ListNode midNode;
	//if(0 == m_nListLen)
	//{
	//	return NULL;
	//}
	//else if(1 == m_nListLen % 2)
	//{
	//	midNode = m_pHead;
	//	mid = m_nListLen / 2;
	//	while(mid)
	//	{
	//		midNode = midNode->pNext;
	//		--mid;
	//	}
	//	return midNode;		// 基数返回中间结点，偶数返回中间的两个
	//}
	//else
	//{
	//	midNode = m_pHead;
	//	mid = m_nListLen/2-1;
	//	while(mid)
	//	{
	//		midNode = midNode->pNext;
	//		--mid;
	//	}
	//	return midNode;	
	//}
	//return NULL;
	ListNode fast = m_pHead;
	ListNode slow = m_pHead;
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
//在链表的头部插入新的结点
void SingleList::AddHead(const int &data)
{
	ListNode newNode = new SNode;
	newNode->data = data;
	newNode->pNext = m_pHead;
	m_pHead = newNode;
	++m_nListLen;
}
//在链表的尾部插入新的结点
void SingleList::AddTail(const int &data)
{
	ListNode newNode = new SNode;
	newNode->data = data;
	newNode->pNext = NULL;
	if(NULL == m_pTail)
	{
		m_pHead = newNode;
	}
	else
	{
		m_pTail->pNext = newNode;
		m_pTail = newNode;
		++m_nListLen;
	}
}
//在指定结点前插入数据，并返回新结点的地址
ListNode SingleList::InsertAt(ListNode pos, const int &data)
{
	ListNode p = m_pHead;
	if(NULL == pos)
	{
		return NULL;
	}
	else if(pos == p)
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
				ListNode newNode = new SNode;
				newNode->data = data;
				newNode->pNext = p->pNext;
				p->pNext = newNode;
				++m_nListLen;
				return newNode;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
// 修改返回类型，单进单出2019/3/26
bool SingleList::InsertAt_2(ListNode pos, const int &data)
{
	bool flag;
	if(NULL == pos)
	{
		flag = false;		// 没有数据插入
	}
	else
	{
		if(pos == m_pHead)
		{
			AddHead(data);
			flag = true;
		}
		else
		{
			ListNode p;
			p = m_pHead;
			while(p)
			{
				if(p->pNext == pos)
				{
					ListNode newNode = new SNode;
					newNode->data = data;
					newNode->pNext = p->pNext;
					p->pNext = newNode;
					flag = true;
					break;
				}
				p = p->pNext;
			}
			flag = false;
		}
	}
	return flag;
}

//修改指定结点的数据，并返回当前节点的地址
ListNode SingleList::ModifyAt(ListNode pos, const int &data)
{
	ListNode p;
	p = m_pHead;
	if(m_pHead == NULL)
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
			if(p == NULL)
				return NULL;		// 此链表中，没有这个结点
		}
	}
	return NULL;
}
//修改指定结点的数据，
bool SingleList::ModifyAt_2(ListNode pos, const int &data)
{
	bool flag = false;
	if(NULL == m_pHead)
	{
		flag = false;
	}
	else
	{
		ListNode p;
		p = m_pHead;
		while(p)
		{
			if(p == pos)
			{
				p->data = data;
				flag = true;
				break;
			}
			p = p->pNext;
		}
	}
	return flag;
}

//删除指定结点，并返回被删除结点的下一结点的地址
ListNode SingleList::RemoveAt(ListNode pos)
{
	if(m_pHead == NULL)
		return NULL;
	else if(m_pHead == pos)
	{
		ListNode p;
		p = m_pHead;
		m_pHead = m_pHead->pNext;
		delete p;
		p = nullptr;
		--m_nListLen;
		return m_pHead;
	}
	else 
	{
		ListNode p, q;
		p = m_pHead;
		q = p->pNext;
		while(p)
		{
			if(q == pos)
			{
				p->pNext = q->pNext;
				delete q;
				q = nullptr;
				--m_nListLen;
				return q;
			}
			p = p->pNext;
		}
	}
	return NULL;
}

bool SingleList::RemoveAt_2(ListNode pos)
{
	bool flag = false;
	if(m_pHead == NULL)
	{
		flag = false;
	}
	else 
	{
		ListNode p, q;
		p = m_pHead;
		q = p->pNext;
		while(p)
		{
			if(p == pos)
			{
				delete p;
				p = nullptr;
				--m_nListLen;
				m_pHead = q;
				flag = true;
				break;
			}
			p = p->pNext;
			q = q->pNext;
		}
	}
	return flag;
}
//删除倒数第n个节点，并返回被删除结点的下一结点的地址
ListNode SingleList::RemoveAt(UINT nCountBack)
{
	UINT n = 0, m = 0;
	ListNode p, q;
	p = m_pHead;
	q = p->pNext;
	if(m_nListLen < nCountBack || nCountBack <= 0 || m_nListLen == 0)
	{
		return NULL;
	}
	else if(m_nListLen == nCountBack)
	{
		m_pHead = m_pHead->pNext;
		delete p;
		p = nullptr;
		--m_nListLen;
		return m_pHead;
	}
	else
	{
		n = m_nListLen - nCountBack - 1;
		while(n)
		{
			--n;
			p = p->pNext;
			q = p->pNext;
		}
		p->pNext = q->pNext;
		delete q;
		q = nullptr;
		--m_nListLen;
		p = p->pNext;
		return p;
	}
	return NULL;
}

bool SingleList::RemoveAt_2(UINT nCountBack)
{
	bool flag;
	if(m_nListLen < nCountBack || nCountBack <= 0 || m_nListLen == 0)
	{
		flag = false;
	}
	else
	{
		UINT n = 0, m = 0;
		n = m_nListLen - nCountBack;
		ListNode p, q;
		p = m_pHead;
		q = p->pNext;
		while(n)
		{
			p = p->pNext;
			q = p->pNext;
			--n;
		}
		delete p;
		p = nullptr;
		--m_nListLen;
		q = m_pHead;
		flag = true;
	}
	return flag;
}
//在当前链表中找到和要查找数据相等的第一个结点的地址
ListNode SingleList::Find(const int &data) const
{
	ListNode p;
	p = m_pHead;
	if(p == NULL)
		return NULL;
	else
	{
		while(p)
		{
			if(p->data == data)
			{
				return  p;
			}
			p = p->pNext;
		}
		return NULL;
	}
	return NULL;
}
//删除链表的所有结点
void SingleList::Erase()
{
	ListNode p;
	p = m_pHead;
	while(m_pHead)
	{
		p = p->pNext;
		free(m_pHead);
		m_pHead = p;
	}
	m_nListLen = 0;
}

//打印链表所有结点的数据
void SingleList::PrintList() const
{
	ListNode p;
	p = m_pHead;
	if(m_nListLen == 0)
		std::cout << "Empty List!" << std::endl;
	else
	{
		while(p)
		{
			std::cout << p->data << ", " << std::endl;
			p = p->pNext;
		}
		std::cout << "ListLen is " << m_nListLen << "! print over!" << std::endl;
		return;
	}
}
//反转链表
void SingleList::Reverse()
{
	if(m_pHead == NULL || m_pHead->pNext ==NULL)
		return;
	ListNode m, n, r, tail;
	m = m_pHead;			// 用于记录当前结点
	n = m_pHead->pNext;		// 用于记录下一个结点
	m_pHead->pNext = NULL;	// 头做尾，next = null
	tail = m_pHead;			// 保留头，做尾
	while(n)
	{
		r = n->pNext;
		n->pNext = m;
		m = n;
		n = r;
	}
	m_pHead = m;
	m_pTail = tail;
	return;
}
