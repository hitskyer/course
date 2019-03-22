#include "SingleList.h"
SingleList::SingleList(void)
{
	m_nListLen = 0;
	m_pHead = m_pTail = nullptr;
	
}

SingleList::~SingleList(void)
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
//�ж������Ƿ�Ϊ��
bool SingleList::IsEmpty() const
{
	if(m_nListLen == 0 && m_pHead == NULL && m_pTail == NULL)
		return true;
	return false;	
}
//��ȡ��ǰ�����ĳ���
UINT SingleList::GetLength() const
{
	return m_nListLen;
}
//��ȡ������ͷ���
ListNode SingleList::GetHeadNode() const
{
	return m_pHead;
}
//��ȡ������β���
ListNode SingleList::GetTailNode() const
{
	return m_pTail;
}
//����������м���
ListNode SingleList::GetMidNode()
{
	int mid = 0;
	ListNode midNode;
	if(0 == m_nListLen)
		return NULL;
	else if(1 == m_nListLen%2)
	{
		midNode = m_pHead;
		mid = m_nListLen / 2;
		while(mid)
		{
			midNode = midNode->pNext;
			--mid;
		}
		return midNode;		// ���������м��㣬ż�������м������
	}
	else
	{
		midNode = m_pHead;
		mid = m_nListLen/2-1;
		while(mid)
		{
			midNode = midNode->pNext;
			--mid;
		}
		return midNode;	
	}
	return NULL;
}
//��������ͷ�������µĽ��
void SingleList::AddHead(const int &data)
{
	ListNode newNode = new SNode;
	newNode->data = data;
	if(NULL == m_pHead)
	{
		newNode->pNext = NULL;
		m_pTail = newNode;
	}
	else
	{
		newNode->pNext = m_pHead;
	}
	m_pHead = newNode;
	++m_nListLen;
}
//��������β�������µĽ��
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
	}
	m_pTail = newNode;
	++m_nListLen;
}
//��ָ�����ǰ�������ݣ��������½��ĵ�ַ
ListNode SingleList::InsertAt(ListNode pos, const int &data)
{
	if(NULL == pos)
		return NULL;
	ListNode p = m_pHead;
	if(pos == p)
	{
		AddHead(data);
		return m_pHead;
	}

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
	return NULL;
}
//�޸�ָ���������ݣ������ص�ǰ�ڵ�ĵ�ַ
ListNode SingleList::ModifyAt(ListNode pos, const int &data)
{
	if(m_pHead == NULL)
		return NULL;

	ListNode p;
	p = m_pHead;
	while(p)
	{
		if(p == pos)
		{
			p->data = data;
			return pos;
		}
		p = p->pNext;
		if(p == NULL)
			return ERROR;		// �������У�û��������
	}
	return NULL;
}
//ɾ��ָ����㣬�����ر�ɾ��������һ���ĵ�ַ
ListNode SingleList::RemoveAt(ListNode pos)
{
	if(m_pHead == NULL)
		return NULL;

	ListNode p, q;
	p = m_pHead;
	if(m_pHead == pos)
	{
		p = p->pNext;
		delete m_pHead;
		--m_nListLen;
		m_pHead = p;
		return m_pHead;
	}
	while(p)
	{
		if(p->pNext == pos)
		{
			if(pos->pNext == NULL)
			{
				m_pTail = p;
				delete pos;
				--m_nListLen;
				return m_pTail;
			}
			else
			{
				q = pos;
				p->pNext = q->pNext;
				delete pos;
				--m_nListLen;
				pos = p->pNext;
				return pos;
			}
		}
		p = p->pNext;
	}
	return NULL;
}
//ɾ��������n���ڵ㣬�����ر�ɾ��������һ���ĵ�ַ
ListNode SingleList::RemoveAt(UINT nCountBack)
{
	UINT n = 0, m = 0;
	ListNode p, q;
	p = m_pHead;
	if(m_nListLen <= nCountBack || nCountBack <= 0)
		return NULL;
	else
	{
		n = m_nListLen - nCountBack;
		for(size_t i = 0; i < (n - 1); ++i)
		{
			p = p->pNext;
		}
		q = p->pNext->pNext;
		delete p->pNext;
		p->pNext = q;
		--m_nListLen;
	}
	return NULL;
}
//�ڵ�ǰ�������ҵ���Ҫ����������ȵĵ�һ�����ĵ�ַ
ListNode SingleList::Find(const int &data)
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
//ɾ�����������н��
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

//��ȡĳһ�����������������Ľ���ַ
//ListNode SingleList::GetNode(const int &data) const
//{}

//��ӡ�������н�������
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
	}
}
//��ת����
void SingleList::Reverse()
{
	if(m_pHead == NULL || m_pHead->pNext ==NULL)
		return;
	ListNode m, n, r, tail;
	m = m_pHead;			// ���ڼ�¼��ǰ���
	n = m_pHead->pNext;		// ���ڼ�¼��һ�����
	m_pHead->pNext = NULL;	// ͷ��β��next = null
	tail = m_pHead;			// ����ͷ����β
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