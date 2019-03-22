#ifndef _DULNODE_H
#define _DULNODE_H
#include<Windows.h>
#include<iostream>

struct DulNode
{
	int data;
	DulNode *pNext;
	DulNode *pPrev;
};
typedef unsigned int UINT;
typedef DulNode* DNode;		// 表示一个结点


class DulList
{
private:
	DNode m_pHead;
	DNode m_pTail;
	UINT m_nDulListLen;
public:
	DulList(void);
	~DulList(void);

	bool IsEmpty() const;	// 判断是否为空

	UINT GetLength() const;	// 获取当前链表的长度

	DNode GetHeadNode() const;	// 获取链表的头结点

	DNode GetTailNode() const;	// 获得链表的尾结点 

	DNode GetMidNode() const;		// 获得链表的中间结点

	void AddHead(const int &data);	// 在链表的头部插入新的结点

	void AddTail(const int &data);	// 在链表的尾部插入新的结点

	DNode InsertAt(DNode pos, const int &data);	// 在指定结点前插入数据，并返回新结点的地址

	DNode ModifyAt(DNode pos, const int &data);	// 修改指定结点的数据，并返回当前节点的地址

	DNode RemoveAt(DNode pos);					// 删除指定结点，并返回被删除结点的下一结点的地址

	DNode RemoveAt(UINT nCountBack);				// 删除倒数第n个节点，并返回被删除结点的下一结点的地址

	DNode Find(const int &data);	// 在当前链表中找到和要查找数据相等的第一个结点的地址

	void Erase();					// 删除链表的所有结点

	void PrintList() const;			// 打印链表所有结点的数据

	void Reverse();					// 反转链表
};

#endif
