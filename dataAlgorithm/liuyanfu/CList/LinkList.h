#ifndef _LINKLIST_H
#define _LINKLIST_H


typedef struct SNode 
{
	int data;
	SNode *pNext;
}* ListNode;

typedef unsigned int UINT;

class LinkList
{
public:
	LinkList(void);
	~LinkList(void);

	bool Empty() const
	{
		return m_ListLen == 0;
	}

	UINT GetLength() const
	{
		return m_ListLen;
	}

	ListNode GetHeadNode() const
	{
		return m_pHead->pNext;
	}

	ListNode GetTailNode() const
	{
		return m_ListLen == 0 ? nullptr : m_pTail;
	}

	ListNode GetMidNode();

	void AddHead(const int &data);//在链表的头部插入新的结点
	void AddTail(const int &data);//在链表的尾部插入新的结点

	bool InsertAt(ListNode pos, const int &data);//在指定结点前插入数据，并返回新结点的地址
	bool ModifyAt(ListNode pos, const int &data);//修改指定结点的数据，并返回当前节点的地址
	bool RemoveAt(ListNode pos);//删除指定结点，并返回被删除结点的下一结点的地址
	//bool RemoveAt(UINT nCountBack);//删除倒数第n个节点，并返回被删除结点的下一结点的地址

	ListNode Find(const int &data);//在当前链表中找到和要查找数据相等的第一个结点的地址
	ListNode GetNode(const int &data) const;//获取某一数据在链表中所处的结点地址
	void Erase();//删除链表的所有结点

	void PrintList() const;//打印链表所有结点的数据
	//void Reverse();//反转链表

	void SetLoopPortPos(const UINT &pos) //当pos = 0时代表该链表没有环的入口，即为普通的单链表
	{
		m_LoopPortPos = pos;
	}
private:
	void SetLoopPort();
	ListNode FindByPos(UINT nNum);

	UINT m_ListLen;
	UINT m_LoopPortPos;
	ListNode m_pHead;
	ListNode m_pTail;
	ListNode m_pLoopPort;
};

#endif