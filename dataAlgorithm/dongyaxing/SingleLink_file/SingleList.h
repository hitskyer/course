/**
* 摘要：	单链表，无哨兵，有头结点、尾结点。
* 修改：	添加部分函数返回类型为bool；将部分函数整理简洁；
*			部分函数添加const，避免被修改；单进单出；注释，避免二义性
* 修改日期：2019/3/26
*/

#ifndef _SINGLELIST_H
#define _SINGLELIST_H
#include<Windows.h>
#include<iostream>

struct SNode		//结点的基本数据类型
{
	int data;
	SNode* pNext;
};

typedef unsigned int UINT;
typedef SNode* ListNode;		// 表示一个结点

class SingleList
{

public:
 	SingleList(void);
 	~SingleList(void);

	bool IsEmpty() const;//判断链表是否为空

	UINT GetLength() const;//获取当前链表的长度

	ListNode GetHeadNode() const;//获取链表的头结点

	ListNode GetTailNode() const;//获取链表的尾结点

	ListNode GetMidNode() const;//获得链表的中间结点，偶数返回第一个结点

	void AddHead(const int &data);//在链表的头部插入新的结点

	void AddTail(const int &data);//在链表的尾部插入新的结点

	ListNode InsertAt(ListNode pos, const int &data);	//在指定结点前插入数据，并返回新结点的地址
	bool InsertAt_2(ListNode pos, const int &data);		//在指定结点前插入数据，并返回bool类型，成功返回ture

	ListNode ModifyAt(ListNode pos, const int &data);	//修改指定结点的数据，并返回当前节点的地址
	bool ModifyAt_2(ListNode pos, const int &data);		//修改指定结点的数据，并返回bool类型，成功返回ture

	ListNode RemoveAt(ListNode pos);		//删除指定结点，并返回被删除结点的下一结点的地址
	bool RemoveAt_2(ListNode pos);			//删除指定结点，并返回bool类型，成功返回ture

	ListNode RemoveAt(UINT nCountBack);		//删除倒数第n个节点，并返回被删除结点的下一结点的地址
	bool RemoveAt_2(UINT nCountBack);		//删除倒数第n个节点，并返回bool类型，成功返回ture

	ListNode Find(const int &data) const;			//在当前链表中找到和要查找数据相等的第一个结点的地址

	void Erase();							//删除链表的所有结点

	void PrintList() const;					//打印链表所有结点的数据

	void Reverse();							//反转链表
	
private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_nListLen;
};


#endif

