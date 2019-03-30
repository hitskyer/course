//
// Created by mingm on 2019/3/27.
//
#include "arrStack.h"
#include <iostream>
using namespace std;
template <class T> arrStack<T>::arrStack(int capacity):m_pTop(-1),m_nStackLen(capacity)
{
    arr = new T[capacity];
}
template <class T> arrStack<T>::~arrStack()
{
    Clear();
    delete [] arr;
    arr = NULL;
}
template <class T> bool arrStack<T>::Empty() const
{
    return m_pTop == -1;
}
template <class T> bool arrStack<T>::IsFull() const
{
    return m_pTop == m_nStackLen - 1;
}
template <class T> void arrStack<T>::Clear()
{
    m_pTop = -1;
}
template <class T> void arrStack<T>::Push(T &data)
{
    if(IsFull())
    {
//        cout << "overflow !" << endl;
        Expand();
    }
    arr[++m_pTop] = data;
}
template <class T> void arrStack<T>::Expand()
{
    m_nStackLen = 2 * m_nStackLen;
    T* temparr = new T[m_nStackLen];
    for(int i = 0; i <= m_pTop; ++i)
    {
        temparr[i] = arr[i];
    }
    T* temp = arr;
    arr = temparr;
    temparr = temp;
    delete [] temparr;
    temparr = NULL;
}
template <class T> void arrStack<T>::Pop()
{
    if(!Empty())
        --m_pTop;
}
template <class T> T& arrStack<T>::GetTop() const
{
    if(!Empty())
        return arr[m_pTop];
    throw "no elem!";   //抛出异常
}
template <class T> UINT arrStack<T>::GetLength() const
{
    return m_nStackLen;
}
template <class T> void arrStack<T>::print()
{
    cout << "----arrstack top----" << endl;
    int i = m_pTop, j = m_pTop;
    while(m_pTop != -1 && j >= 0)
    {
        cout << "No." << i-- << " elem " << arr[j--] << endl;
    }
    cout << "----arrstack bottom----" << endl;
}