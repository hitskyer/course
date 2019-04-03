/**
 * @description: 顺序队列实现文件
 * @author: michael ming
 * @date: 2019/4/2 21:26
 * @modified by:
 */
#include <iostream>
using namespace std;
template <class T>
arrQueue<T>::arrQueue(const int capa):m_pHead(0),m_pTail(-1),m_QueueLen(0),m_capacity(capa)
{
    arrQ = new T[m_capacity];
}
template <class T>
arrQueue<T>::~arrQueue()
{
    erase();
    delete [] arrQ;
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
template <class T>
bool arrQueue<T>::dequeue()
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
UINT arrQueue<T>::getlength() const
{
    return m_QueueLen;
}
template <class T>
const T& arrQueue<T>::getHead() const
{
    return arrQ[m_pHead];
}
template <class T>
const T& arrQueue<T>::getTail() const
{
    return arrQ[m_pTail];
}
template <class T>
void arrQueue<T>::print() const
{
    if(empty())
        cout << "empty queue!" << endl;
    cout << "arrQueue from head to tail as follow:" << endl;
    int j = m_pHead;
    for(UINT i = 0; i < m_QueueLen; )
    {
        cout << "No." << ++i << " elem is " << arrQ[j++] << endl;
    }
    cout << "--------------print end----------------" << endl;
}