//循环单链表
// Created by mingm on 2019/3/21.
//
#include "circular_singleList.h"
#include <iostream>
circular_singleList::circular_singleList():m_pHead(NULL),m_nListLen(0)
{
    m_pHead = new SNode;
    m_pHead->pNext = m_pHead;
}

circular_singleList::~circular_singleList()
{
    Erase();
    delete m_pHead;
}
void circular_singleList::Erase()
{
    ListNode temp = m_pHead->pNext, del;
    m_pHead->pNext = NULL;
    while(temp != m_pHead)
    {
        del = temp;
        temp = temp->pNext;
        delete del;
    }
    m_nListLen = 0;
}
bool circular_singleList::IsEmpty() const
{
    return m_pHead->pNext == m_pHead;
}
UINT circular_singleList::GetLength() const
{
    return m_nListLen;
}
ListNode circular_singleList::GetHeadNode() const
{
    if(m_pHead->pNext == m_pHead)
        return NULL;
    else
        return m_pHead->pNext;
}
ListNode circular_singleList::GetTailNode() const
{
    ListNode temp = m_pHead;
    while(temp->pNext != m_pHead)
    {
        temp = temp->pNext;
    }
    if(temp == m_pHead)
        return NULL;
    else
        return temp;
}
ListNode circular_singleList::GetMidNode()   //快慢指针法
{
    ListNode fast = m_pHead->pNext, slow = m_pHead->pNext;
    while(fast != m_pHead)
    {
        if(fast->pNext != m_pHead)
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
//    while(fast != m_pHead && fast->pNext != m_pHead)
//     {
//        fast = fast->pNext->pNext;
//        slow = slow->pNext;
//     }
    return slow;
}
void circular_singleList::AddHead(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    newNode->pNext = m_pHead->pNext;
    m_pHead->pNext = newNode;
    m_nListLen++;
}
void circular_singleList::AddTail(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = NULL;
    if(GetTailNode())
    {
        newNode->pNext = m_pHead;
        GetTailNode()->pNext = newNode;
    }
    else
    {
        m_pHead->pNext = newNode;
        newNode->pNext = m_pHead;
    }
    m_nListLen++;
}
bool circular_singleList::posInList(ListNode pos)
{
    ListNode temp = m_pHead->pNext;
    while(temp != m_pHead && temp != pos)
    {
        temp = temp->pNext;
    }
    if(temp == m_pHead)    //指针地址不在链表内
        return false;
    else
        return true;
}
ListNode circular_singleList::InsertAt(ListNode pos, const int &data)
{
    if(pos == NULL)
        return NULL;
    else
    {
        ListNode temp = m_pHead->pNext;
        ListNode preNode = m_pHead;
        while(temp != m_pHead && temp != pos)
        {
            preNode = temp;
            temp = temp->pNext;
        }
        if(temp == m_pHead)    //指针地址不在链表内
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
ListNode circular_singleList::ModifyAt(ListNode pos, const int &data)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        pos->data = data;
        return pos;
    }
}
ListNode circular_singleList::RemoveAt(ListNode pos)
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
ListNode circular_singleList::RemoveAtBack(UINT nCountBack)
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
        while(fast->pNext != m_pHead)
        {
            fast = fast->pNext;
            slow = slow->pNext;
        }
        fast = RemoveAt(slow);
        return fast;
    }
}
ListNode circular_singleList::Find(const int &data)
{
    ListNode temp = m_pHead->pNext;
    while(temp != m_pHead && temp->data != data)
    {
        temp = temp->pNext;
    }
    return temp;
}
void circular_singleList::PrintList() const
{
    std::cout << "----- print start ----" << std::endl;
    ListNode temp = m_pHead->pNext;
    for(int i = 0; i < m_nListLen && temp != m_pHead; ++i)
    {
        std::cout << "No. " << i+1 << " node is " << temp->data << std::endl;
        temp = temp->pNext;
    }
    std::cout << "----- print end ----" << std::endl;
}
void circular_singleList::Reverse()  //就地反转法
{
    if(m_pHead->pNext && m_pHead->pNext->pNext)
    {
        ListNode preNode, curNode, tempNode;
        preNode = curNode = tempNode = m_pHead->pNext;
        curNode = preNode->pNext;
        preNode->pNext = m_pHead;
        while(curNode->pNext != m_pHead)
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
