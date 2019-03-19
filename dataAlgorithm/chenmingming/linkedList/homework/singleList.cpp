//单向链表（不带头）
// Created by mingm on 2019/3/18.
//
#include "singleList.h"
#include <iostream>

SingleList::SingleList():m_pHead(NULL),m_pTail(NULL),m_nListLen(0){}

SingleList::~SingleList()
{
    Erase();
}
void SingleList::Erase()
{
    if(m_pHead != NULL)
    {
        ListNode temp = m_pHead, del;
        while(temp != NULL)
        {
            del = temp;
            temp = temp->pNext;
            delete del;
        }
        m_pHead = m_pTail = NULL;
        m_nListLen = 0;
    }
}
bool SingleList::IsEmpty() const
{
    return m_pHead == NULL;
}
UINT SingleList::GetLength() const
{
    return m_nListLen;
}
ListNode SingleList::GetHeadNode() const
{
    return m_pHead;
}
ListNode SingleList::GetTailNode() const
{
    return m_pTail;
}
ListNode SingleList::GetMidNode()   //快慢指针法
{
    ListNode fast = m_pHead, slow = m_pHead;
    while(fast)
    {
        if(fast->pNext != NULL)
        {
            fast = fast->pNext->pNext;
        }
        else
        {
            break;
        }
        slow = slow->pNext;
    }
    //简洁写法
//    while(fast && fast->pNext)
//     {
//        fast = fast->pNext->pNext;
//        slow = slow->pNext;
//     }
    return slow;
}
void SingleList::AddHead(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    if(m_pHead == NULL)
    {
        m_pHead = newNode;
        m_pTail = newNode;
    }
    else
    {
        newNode->pNext = m_pHead;
        m_pHead = newNode;
    }
    m_nListLen++;
}
void SingleList::AddTail(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    if(m_pTail == NULL)
    {
        m_pHead = newNode;
        m_pTail = newNode;
    }
    else
    {
        m_pTail->pNext = newNode;
        m_pTail = newNode;
    }
    m_nListLen++;
}
ListNode SingleList::InsertAt(ListNode pos, const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;

}