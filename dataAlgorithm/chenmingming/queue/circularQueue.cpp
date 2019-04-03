/**
 * @description: 实现方法1：用长度==容量判断；
 *                       2：用（tail+1）%capacity = head 则队列满了（少用一个数组空间）
 * @author: michael ming
 * @date: 2019/4/2 22:43
 * @modified by: 
 */
#include "circularQueue.h"
#include <iostream>
using namespace std;
template <class T>
circularQueue<T>::circularQueue(const int capa):m_pHead(0),m_pTail(-1),m_QueueLen(0),m_capacity(capa)
{
    arrQ = new T[m_capacity];
}
template <class T>
circularQueue<T>::~circularQueue()
{
    erase();
    delete [] arrQ;
}
template <class T>
inline void circularQueue<T>::erase()
{
    m_QueueLen = 0;
    m_pHead = 0;
    m_pTail = -1;
}
template <class T>
bool circularQueue<T>::empty() const
{
    return m_QueueLen == 0;
}
template <class T>
bool circularQueue<T>::full() const
{
    return m_QueueLen == m_capacity;    //方法1
}
template <class T>
bool circularQueue<T>::enqueue(const T &data)
{
    if(full())
        return false;
    else
    {
        if(empty())
        {
            m_pHead = m_pTail = 0;
            arrQ[0] = data;
            m_QueueLen++;
        }
        else if(m_pTail < m_capacity-1)
        {
            arrQ[++m_pTail] = data;
            m_QueueLen++;
        }
        else    //队列没满，但是队尾到达数组末尾了，让tail变成-1
        {
            if(m_pTail + 1 == m_capacity)
                m_pTail = -1;
            arrQ[++m_pTail] = data;
            m_QueueLen++;
        }
        return true;
    }
}
template <class T>
bool circularQueue<T>::dequeue()
{
    if(empty())
        return false;
    else
    {
        m_pHead++;
        m_QueueLen--;
        if(m_QueueLen == 0)
        {
            m_pHead = 0;
            m_pTail = -1;
        }
        return true;
    }
}
template <class T>
UINT circularQueue<T>::getlength() const
{
    return m_QueueLen;
}
template <class T>
const T& circularQueue<T>::getHead() const
{
    return arrQ[m_pHead];
}
template <class T>
const T& circularQueue<T>::getTail() const
{
    return arrQ[m_pTail];
}
template <class T>
void circularQueue<T>::print() const
{
    if(empty())
        cout << "empty queue!" << endl;
    cout << "circularQueue from head to tail as follow:" << endl;
    int j = m_pHead;
    for(UINT i = 0; i < m_QueueLen; )
    {
        if(j == m_capacity)     //打印时注意下标循环跳转
            j = 0;
        cout << "No." << ++i << " elem is " << arrQ[j++] << endl;
    }
    cout << "--------------print end----------------" << endl;
}