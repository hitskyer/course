#ifndef _SINGLECIRCLELIST_H
#define _SINGLECIRCLELIST_H
#include<Windows.h>
#include<iostream>

struct SCNode
{
	int data;
	SCNode *pNext;
};
typedef SCNode * SCLNode;
typedef unsigned int UINT;
class SingleCircleList
{
public:
	SingleCircleList(void);
	~SingleCircleList(void);
	bool IsEmpty() const;//判断链表是否为空

	UINT GetLength() const;//获取当前链表的长度

	SCLNode GetHeadNode() const;//获取链表的头结点

	SCLNode GetTailNode() const;//获取链表的尾结点

	SCLNode GetMidNode();//获得链表的中间结点

	void AddHead(const int &data);//在链表的头部插入新的结点

	void AddTail(const int &data);//在链表的尾部插入新的结点

	SCLNode InsertAt(SCLNode pos, const int &data);//在指定结点前插入数据，并返回新结点的地址

	SCLNode ModifyAt(SCLNode pos, const int &data);//修改指定结点的数据，并返回当前节点的地址

	SCLNode RemoveAt(SCLNode pos);//删除指定结点，并返回被删除结点的下一结点的地址

	SCLNode RemoveAt(UINT nCountBack);//删除倒数第n个节点，并返回被删除结点的下一结点的地址

	SCLNode Find(const int &data);//在当前链表中找到和要查找数据相等的第一个结点的地址

	void Erase();//删除链表的所有结点

	//ListNode GetNode(const int &data) const;//获取某一数据在链表中所处的结点地址

	void PrintList() const;//打印链表所有结点的数据
	void Reverse();//反转链表

private:
	SCLNode m_pHead;
	SCLNode m_pTail;
	UINT m_nSCListLen;
};


#endif