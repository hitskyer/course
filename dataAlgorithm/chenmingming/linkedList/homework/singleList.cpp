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
    ListNode temp = m_pHead;
    while(temp != NULL)
    {
        temp = temp->pNext;
    }
    return temp;
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
    if(m_pHead == NULL)
    {
        m_pHead = newNode;
    }
    else
    {
        GetTailNode()->pNext = newNode;
    }
    m_nListLen++;
}
bool SingleList::posInList(ListNode pos)
{
    if(m_pHead == NULL)
        return false;
    else
    {
        ListNode temp = m_pHead;
        while(temp && temp != pos)
        {
            temp = temp->pNext;
        }
        if(temp == NULL)    //指针地址不在链表内
            return false;
        else
            return true;
    }
}
ListNode SingleList::InsertAt(ListNode pos, const int &data)
{
    if(pos == NULL)
        return NULL;
    else if(pos == m_pHead)
    {
        AddHead(data);
        return m_pHead;
    }
    else
    {
        ListNode temp = m_pHead;
        ListNode preNode = NULL;
        while(temp && temp != pos)
        {
            preNode = temp;
            temp = temp->pNext;
        }
        if(temp == NULL)    //指针地址不在链表内
            return NULL;
        else
        {
            ListNode newNode = new SNode;
            newNode->data = data;
            newNode->pNext = NULL;
            newNode->pNext = pos;
            preNode->pNext = newNode;
            m_nListLen++;
            return newNode;
        }
    }
}
ListNode SingleList::ModifyAt(ListNode pos, const int &data)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        pos->data = data;
        return pos;
    }
}
ListNode SingleList::RemoveAt(ListNode pos)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        ListNode temp = m_pHead;
        if(pos == m_pHead)
        {
            temp = pos->pNext;
            delete pos;
            m_nListLen--;
            m_pHead = temp;
            return temp;
        }
        else
        {
            while(temp->pNext != pos)
            {
                temp = temp->pNext;
            }
            temp->pNext = pos->pNext;
            delete pos;
            m_nListLen--;
            return temp->pNext;
        }
    }
}
ListNode SingleList::RemoveAtBack(UINT nCountBack)
{

}