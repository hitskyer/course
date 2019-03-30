//
// Created by mingm on 2019/3/26.
//
#include "stack.h"
#include <iostream>
using namespace std;
template <class T> Stack<T>::Stack():m_pTop(NULL),m_pBot(NULL),m_nStackLen(0){}
template <class T> Stack<T>::~Stack() {   Clear();    }
template <class T> bool Stack<T>::Empty() const
{
    return m_nStackLen == 0;
}
template <class T> void Stack<T>::Clear()
{
    while(m_pTop != NULL)
    {
        Pop();
    }
}
template <class T> void Stack<T>::Push(T &data)
{
    StackNode<T> newNode = new SNode<T>;
    newNode->data = data;
    newNode->pNext = NULL;
    if(m_pTop == NULL)
    {
        m_pTop = m_pBot = newNode;
    }
    else
    {
        newNode->pNext = m_pTop;
        m_pTop = newNode;
    }
    m_nStackLen++;
}
template <class T> void Stack<T>::Pop()
{
    if(m_pTop != NULL)
    {
        StackNode<T> temp = m_pTop->pNext;
        delete m_pTop;
        m_pTop = temp;
        m_nStackLen--;
        if(m_pTop == NULL)
            m_pBot = NULL;
    }

}
template <class T> StackNode<T> Stack<T>::GetTop() const
{
    return m_pTop;
}
template <class T> StackNode<T> Stack<T>::GetBot() const
{
    return m_pBot;
}
template <class T> UINT Stack<T>::GetLength() const
{
    return m_nStackLen;
}
template <class T> void Stack<T>::print()
{
    cout << "----stack top----" << endl;
    StackNode<T> temp = m_pTop;
    size_t i = 0;
    while(temp != NULL)
    {
        cout << "No." << ++i << " elem " << temp->data << endl;
        temp = temp->pNext;
    }
    cout << "----stack bottom----" << endl;
}