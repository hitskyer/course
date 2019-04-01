/**
 * @description: 链式队列实现文件
 * @author: michael ming
 * @date: 2019/4/1 22:47
 * @modified by:
 */
//#include "listQueue.h"
#include <iostream>
using namespace std;
template <class T>
ListQueue<T>::ListQueue():m_pHead(NULL),m_pTail(NULL),m_QueueLen(0){}
template <class T>
ListQueue<T>::~ListQueue()
{
    erase();
}
template <class T>
inline void ListQueue<T>::erase()
{
    SNode<T>* temp;
    while(m_pHead != NULL)
    {
        temp = m_pHead->pNext;
        delete m_pHead;
        m_pHead = temp;
    }
    m_pTail = NULL;
    m_QueueLen = 0;
}
template <class T>
bool ListQueue<T>::empty() const
{
    return m_pHead == NULL;
}
template <class T>
UINT ListQueue<T>::getlength() const
{
    return m_QueueLen;
}
template <class T>
bool ListQueue<T>::enqueue(const T &data)
{
    SNode<T>* newNode = new SNode<T>;
    newNode->data = data;
    newNode->pNext = NULL;
    if(m_pTail == NULL)
        m_pHead = m_pTail = newNode;
    else
    {
        m_pTail->pNext = newNode;
        m_pTail = newNode;
    }
    m_QueueLen++;
    return true;
}
template <class T>
bool ListQueue<T>::dequeue()
{
    if(m_pHead != NULL)
    {
        SNode<T>* temp = m_pHead;
        m_pHead = m_pHead->pNext;
        if(m_pHead == NULL)
            m_pTail == NULL;
        delete temp;
        m_QueueLen--;
        return true;
    }
    return false;
}
template <class T>
void ListQueue<T>::print() const
{
    cout << "-------------------------------------------" << endl;
    cout << "List Queue from head to tail as follow: " << endl;
    SNode<T>* temp = m_pHead;   int i = 0;
    while(temp != NULL)
    {
        cout << "No." << ++i << " elem is " << temp->data << endl;
        temp = temp->pNext;
    }
}
template <class T>
SNode<T>* ListQueue<T>::getHead()
{
    return m_pHead;
}
template <class T>
SNode<T>* ListQueue<T>::getTail()
{
    return m_pTail;
}