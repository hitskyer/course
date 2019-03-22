//带头单链表
// Created by mingm on 2019/3/21.
//
#include "singleList_withHead.h"
#include <iostream>
singleList_withHead::singleList_withHead():m_pHead(NULL),m_nListLen(0)
{
    m_pHead = new SNode;
    m_pHead->pNext = NULL;
}

singleList_withHead::~singleList_withHead()
{
    Erase();
    delete m_pHead;
}
void singleList_withHead::Erase()
{
    ListNode temp = m_pHead->pNext, del;
    while(temp != NULL)
    {
        del = temp;
        temp = temp->pNext;
        delete del;
    }
    m_nListLen = 0;
}
bool singleList_withHead::IsEmpty() const
{
    return m_pHead->pNext == NULL;
}
UINT singleList_withHead::GetLength() const
{
    return m_nListLen;
}
ListNode singleList_withHead::GetHeadNode() const
{
    return m_pHead->pNext;
}
ListNode singleList_withHead::GetTailNode() const
{
    ListNode temp = m_pHead;
    while(temp->pNext != NULL)
    {
        temp = temp->pNext;
    }
    if(temp == m_pHead)
        return NULL;
    else
        return temp;
}
ListNode singleList_withHead::GetMidNode()   //快慢指针法
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
void singleList_withHead::AddHead(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    newNode->pNext = m_pHead->pNext;
    m_pHead->pNext = newNode;
    m_nListLen++;
}
void singleList_withHead::AddTail(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    if(GetTailNode())
        GetTailNode()->pNext = newNode;
    else
        m_pHead->pNext = newNode;
    m_nListLen++;
}
bool singleList_withHead::posInList(ListNode pos)
{
    ListNode temp = m_pHead->pNext;
    while(temp && temp != pos)
    {
        temp = temp->pNext;
    }
    if(temp == NULL)    //指针地址不在链表内
        return false;
    else
        return true;
}
ListNode singleList_withHead::InsertAt(ListNode pos, const int &data)
{
    if(pos == NULL)
        return NULL;
    else
    {
        ListNode temp = m_pHead->pNext;
        ListNode preNode = m_pHead;
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
ListNode singleList_withHead::ModifyAt(ListNode pos, const int &data)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        pos->data = data;
        return pos;
    }
}
ListNode singleList_withHead::RemoveAt(ListNode pos)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        ListNode temp = m_pHead;
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
ListNode singleList_withHead::RemoveAtBack(UINT nCountBack)
//先让快指针先走n-1步，然后快慢指针一起动，快指针到达尾部，慢指针指向倒数第n个
{
    if(nCountBack == 0 || nCountBack > m_nListLen)
        return NULL;
    else
    {
        ListNode fast = m_pHead->pNext;
        ListNode slow = m_pHead->pNext;
        for(int i = 0; i < nCountBack-1 && fast; ++i)
        {
            fast = fast->pNext;
        }
        while(fast->pNext)
        {
            fast = fast->pNext;
            slow = slow->pNext;
        }
        fast = RemoveAt(slow);
        return fast;
    }
}
ListNode singleList_withHead::Find(const int &data)
{
    ListNode temp = m_pHead->pNext;
    while(temp && temp->data != data)
    {
        temp = temp->pNext;
    }
    return temp;
}
void singleList_withHead::PrintList() const
{
    std::cout << "----- print start ----" << std::endl;
    ListNode temp = m_pHead->pNext;
    for(int i = 0; i < m_nListLen && temp; ++i)
    {
        std::cout << "No. " << i+1 << " node is " << temp->data << std::endl;
        temp = temp->pNext;
    }
    std::cout << "----- print end ----" << std::endl;
}
void singleList_withHead::Reverse()  //就地反转法
{
    if(m_pHead->pNext && m_pHead->pNext->pNext)
    {
        ListNode preNode, curNode, tempNode;
        preNode = curNode = tempNode = m_pHead->pNext;
        curNode = preNode->pNext;
        preNode->pNext = NULL;
        while(curNode->pNext)
        {
            tempNode = curNode;
            curNode = curNode->pNext;
            tempNode->pNext = preNode;
            preNode = tempNode;
        }
        curNode->pNext = preNode;
        m_pHead->pNext = curNode;
    }
}