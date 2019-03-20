//
// Created by mingm on 2019/3/18.
//
#ifndef _SINGLELIST_H
#define _SINGLELIST_H

struct SNode		//结点的基本数据类型
{
    int data;
    SNode* pNext;
};

typedef unsigned int UINT;
typedef SNode* ListNode;

class SingleList
{

public:
    SingleList(void);
    ~SingleList(void);

    bool IsEmpty() const;//判断链表是否为空

    UINT GetLength() const;//获取当前链表的长度

    ListNode GetHeadNode() const;//获取链表的头结点

    ListNode GetTailNode() const;//获取链表的尾结点

    ListNode GetMidNode();//获得链表的中间结点

    void AddHead(const int &data);//在链表的头部插入新的结点

    void AddTail(const int &data);//在链表的尾部插入新的结点

    bool posInList(ListNode pos);//检查节点指针是否在链表中

    ListNode InsertAt(ListNode pos, const int &data);//在指定结点前插入数据，并返回新结点的地址

    ListNode ModifyAt(ListNode pos, const int &data);//修改指定结点的数据，并返回当前节点的地址

    ListNode RemoveAt(ListNode pos);//删除指定结点，并返回被删除结点的下一结点的地址

    ListNode RemoveAtBack(UINT nCountBack);//删除倒数第n个节点，并返回被删除结点的下一结点的地址

    ListNode Find(const int &data);//在当前链表中找到和要查找数据相等的第一个结点的地址

    void Erase();//删除链表的所有结点

    void PrintList() const;//打印链表所有结点的数据

    void Reverse();//反转链表

private:
    ListNode m_pHead;   //头结点
    UINT m_nListLen;    //链表数据长度
};

#endif