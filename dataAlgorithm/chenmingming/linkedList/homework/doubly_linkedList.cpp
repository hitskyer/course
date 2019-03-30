//
// Created by mingm on 2019/3/22.
//
#include "doubly_linkedList.h"
#include <iostream>
doubly_linkedList::doubly_linkedList():m_pHead(NULL),m_nListLen(0)
{
    m_pHead = new SNode;
    m_pHead->prev = NULL;
    m_pHead->pNext = NULL;
}

doubly_linkedList::~doubly_linkedList()
{
    Erase();
    delete m_pHead;
}
void doubly_linkedList::Erase()
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
bool doubly_linkedList::IsEmpty() const
{
    return m_pHead->pNext == NULL;
}
UINT doubly_linkedList::GetLength() const
{
    return m_nListLen;
}
ListNode doubly_linkedList::GetHeadNode() const
{
    return m_pHead->pNext;
}
ListNode doubly_linkedList::GetTailNode() const
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
ListNode doubly_linkedList::GetMidNode()   //快慢指针法
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
void doubly_linkedList::AddHead(const int &data)
{
    ListNode newNode = new SNode;
    newNode->data = data;
    newNode->pNext = m_pHead->pNext;
    newNode->prev = m_pHead;
    m_pHead->pNext = newNode;
    m_nListLen++;
}
void doubly_linkedList::AddTail(const int &data)
{
    ListNode newNode = new SNode;
    ListNode pTail = GetTailNode();
    newNode->data = data;
    newNode->pNext = NULL;
    if(pTail)
    {
        pTail->pNext = newNode;
        newNode->prev = pTail;
//      GetTailNode()->pNext = newNode;   //不要在等式左右写GetTailNode()
//      newNode->prev = GetTailNode();    //链表连接后，GetTailNode()获得到的尾指针变了
    }
    else
    {
        m_pHead->pNext = newNode;
        newNode->prev = m_pHead;
    }
    m_nListLen++;
}
bool doubly_linkedList::posInList(ListNode pos)
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
ListNode doubly_linkedList::InsertAt(ListNode pos, const int &data)
{
    if(pos == NULL)
        return NULL;
    else
    {
        ListNode temp = m_pHead->pNext;
        temp->prev = m_pHead;
        while(temp && temp != pos)
        {
            temp = temp->pNext;
        }
        if(temp == NULL)    //指针地址不在链表内
            return NULL;
        else
        {
            ListNode newNode = new SNode;
            newNode->data = data;
            newNode->pNext = pos;
            temp->prev->pNext = newNode;
            m_nListLen++;
            return newNode;
        }
    }
}
ListNode doubly_linkedList::ModifyAt(ListNode pos, const int &data)
{
    if(!posInList(pos))
        return NULL;
    else
    {
        pos->data = data;
        return pos;
    }
}
ListNode doubly_linkedList::RemoveAt(ListNode pos)
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
        if(pos->pNext != NULL)
        {
            pos->pNext->prev = temp;
        }
        delete pos;
        m_nListLen--;
        return temp->pNext;
    }
}
ListNode doubly_linkedList::RemoveAtBack(UINT nCountBack)
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
ListNode doubly_linkedList::Find(const int &data)
{
    ListNode temp = m_pHead->pNext;
    while(temp && temp->data != data)
    {
        temp = temp->pNext;
    }
    return temp;
}
void doubly_linkedList::PrintList() const
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
void doubly_linkedList::Reverse()  //把表头哨兵移至尾节点后，对每个节点，交换prev，next指针
{
    if(m_pHead->pNext && m_pHead->pNext->pNext)
    {
        ListNode pTail = GetTailNode();
        m_pHead->pNext->prev = NULL;
        m_pHead->pNext = NULL;
        m_pHead->prev = pTail;
        pTail->pNext = m_pHead;
        ListNode tempNode = m_pHead;
        while(tempNode != NULL)
        {
            swapPrevNext(tempNode);
            tempNode = tempNode->pNext;
        }
    }
}
void doubly_linkedList::swapPrevNext(ListNode pos)
{
    SNode* temp;
    temp = pos->pNext;
    pos->pNext = pos->prev;
    pos->prev = temp;
}