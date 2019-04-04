/**
 * @description: 优先级队列，出队按照一定的优先级
 * @author: michael ming
 * @date: 2019/4/3 21:20
 * @modified by: 
 */

#include "priority_queue.h"
#include <iostream>
using namespace std;
template <class T, int *compf >
priority_queue<T, compf>::priority_queue(const int capa):m_pHead(0),m_pTail(-1),m_QueueLen(0),m_capacity(capa)
{
    arrQ = new T[m_capacity];
}
template <class T, int *compf >
priority_queue<T, compf>::~priority_queue()
{
    erase();
    delete [] arrQ;
}
template <class T, int *compf >
inline void priority_queue<T, compf>::erase()
{
    m_QueueLen = 0;
    m_pHead = 0;
    m_pTail = -1;
}
template <class T, int *compf >
bool priority_queue<T, compf>::empty() const
{
    return m_QueueLen == 0;
}
template <class T, int *compf >
bool priority_queue<T, compf>::full() const
{
    return m_QueueLen == m_capacity;
}
template <class T, int *compf >
bool priority_queue<T, compf>::enqueue(const T &data)
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
        else    //队列没满，但是队尾到达数组末尾了，数据整体移至数组头部
        {
            for(UINT i = 0; i < m_QueueLen; ++i)
            {
                arrQ[i] = arrQ[m_pHead++];
            }
            m_pHead = 0;
            arrQ[m_QueueLen++] = data;
            m_pTail = m_QueueLen - 1;
        }
        return true;
    }
}
template <class T, int *compf >
bool priority_queue<T, compf>::dequeue()
{
    if(empty())
        return false;
    else
    {
        size_t index = m_pHead;
        T prio_elem = arrQ[m_pHead];
        for(int i = 1; i < m_QueueLen; ++i)
        {
            index++;
            prio_elem = (*compf)(arrQ[index], prio_elem);
        }
        swap(arrQ[m_pHead],prio_elem);
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
template <class T, int *compf >
UINT priority_queue<T, compf>::getlength() const
{
    return m_QueueLen;
}
template <class T, int *compf >
const T& priority_queue<T, compf>::getHead() const
{
    return arrQ[m_pHead];
}
template <class T, int *compf >
const T& priority_queue<T, compf>::getTail() const
{
    return arrQ[m_pTail];
}
template <class T, int *compf >
void priority_queue<T, compf>::print() const
{
    if(empty())
        cout << "empty queue!" << endl;
    cout << "priority_queue from head to tail as follow:" << endl;
    int j = m_pHead;
    for(UINT i = 0; i < m_QueueLen; )
    {
        cout << "No." << ++i << " elem is " << arrQ[j++] << endl;
    }
    cout << "--------------print end----------------" << endl;
}