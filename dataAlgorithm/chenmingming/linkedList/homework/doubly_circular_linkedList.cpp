//双向循环链表
// Created by mingm on 2019/3/23.
//
#include "doubly_circular_linkedList.h"
#include <iostream>
doubly_circular_linkedList::doubly_circular_linkedList():m_pHead(NULL),m_nListLen(0)
{
    m_pHead = new SNode;
    m_pHead->prev = m_pHead;
    m_pHead->pNext = m_pHead;
}
doubly_circular_linkedList::~doubly_circular_linkedList()
{
    Erase();
    delete m_pHead;
}
void doubly_circular_linkedList::Erase()
{
    ListNode temp = m_pHead->pNext, del;
    while(temp != m_pHead)
    {
        del = temp;
        temp = temp->pNext;
        delete del;
    }
    m_nListLen = 0;
}
bool doubly_circular_linkedList::IsEmpty() const
{
    return m_pHead->pNext == m_pHead;
}
UINT doubly_circular_linkedList::GetLength() const
{
    return m_nListLen;
}
ListNode doubly_circular_linkedList::GetHeadNode() const
{
    if(m_pHead->pNext != m_pHead)
        return m_pHead->pNext;
    else
        return NULL;
}
ListNode doubly_circular_linkedList::GetTailNode() const    //表头哨兵前一个就是尾节点,O(1)
{
    if(m_pHead->pNext == m_pHead)
        return NULL;
    else
        return m_pHead->prev;
}
ListNode doubly_circular_linkedList::GetMidNode()   //快慢指针法
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
void doubly_circular_linkedList::AddHead(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = m_pHead->pNext;
    m_pHead->pNext->prev = newNode;
    newNode->prev = m_pHead;
    m_pHead->pNext = newNode;
    m_nListLen++;
}
void doubly_circular_linkedList::AddTail(const int &data)
{
    ListNode newNode = new SNode;
    ListNode pTail = GetTailNode();
    newNode->data = data;
    newNode->pNext = NULL;
    if(pTail)
    {
        pTail->pNext = newNode;
        newNode->prev = pTail;
        newNode->pNext = m_pHead;
        m_pHead->prev = newNode;
    }
    else
    {
        m_pHead->pNext = newNode;
        m_pHead->prev = newNode;
        newNode->prev = m_pHead;
        newNode->pNext = m_pHead;
    }
    m_nListLen++;
}
bool doubly_circular_linkedList::posInList(ListNode pos)
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
ListNode doubly_circular_linkedList::InsertAt(ListNode pos, const int &data)
{
    if(pos == NULL)
        return NULL;
    else
    {
        ListNode temp = m_pHead->pNext;
        temp->prev = m_pHead;
        while(temp != m_pHead && temp != pos)
        {
            temp = temp->pNext;
        }
        if(temp == m_pHead)    //指针地址不在链表内
            return NULL;
        else
        {
            ListNode newNode = new SNode;
            newNode->data = data;
            newNode->pNext = pos;
            pos->prev->pNext = newNode;
            newNode->prev = pos->prev;
            pos->prev = newNode;
            m_nListLen++;
            return newNode;
        }
    }
}
ListNode doubly_circular_linkedList::ModifyAt(ListNode pos, const int &data)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        pos->data = data;
        return pos;
    }
}
ListNode doubly_circular_linkedList::RemoveAt(ListNode pos)
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
//        if(pos->pNext != m_pHead)
//        {
            pos->pNext->prev = temp;
//        }
        delete pos;
        m_nListLen--;
        return temp->pNext;
    }
}
ListNode doubly_circular_linkedList::RemoveAtBack(UINT nCountBack)
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
ListNode doubly_circular_linkedList::Find(const int &data)
{
    ListNode temp = m_pHead->pNext;
    while(temp != m_pHead && temp->data != data)
    {
        temp = temp->pNext;
    }
    return temp;
}
void doubly_circular_linkedList::PrintList() const
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
void doubly_circular_linkedList::Reverse()  //对每个节点，交换prev，next指针
{
    ListNode tempNode = m_pHead;
    while(tempNode->pNext != m_pHead)
    {
        swapPrevNext(tempNode);
        tempNode = tempNode->pNext;
    }
    swapPrevNext(tempNode);
}
void doubly_circular_linkedList::swapPrevNext(ListNode pos)
{
    SNode* temp;
    temp = pos->pNext;
    pos->pNext = pos->prev;
    pos->prev = temp;
}