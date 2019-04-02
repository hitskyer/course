/**
 * @description: 顺序队列实现文件
 * @author: michael ming
 * @date: 2019/4/2 21:26
 * @modified by:
 */
#include "arrqueue.h"
template <class T>
arrQueue<T>::arrQueue(const int capa):m_pHead(0),m_pTail(-1),m_QueueLen(0),m_capacity(capa)
{
    arrQueue = new T[m_capacity];
}
template <class T>
arrQueue<T>::~arrQueue()
{
    erase();
    delete [] arrQueue;
}
template <class T>
inline void arrQueue<T>::erase()
{
    m_QueueLen = 0;
    m_pHead = 0;
    m_pTail = -1;
}
template <class T>
bool arrQueue<T>::empty() const
{
    return m_QueueLen == 0;
}
template <class T>
bool arrQueue<T>::full() const
{
    return m_QueueLen == m_capacity;
}
template <class T>
bool arrQueue<T>::enqueue(const T &data)
{
    if(full())
        return false;
    else
    {
        arrQueue[m_pTail++] = data;
        m_QueueLen++;
        return true;
    }
}
template <class T>
bool arrQueue<T>::dequeue()
{
    if(empty())
        return false;
    else
    {
        arrQueue[m_pHead]
    }
}
