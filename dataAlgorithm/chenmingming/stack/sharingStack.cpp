//共享顺序栈
// Created by mingm on 2019/3/28.
//
#include "sharingStack.h"
//#include <assert.h>
#include <iostream>
template <class T>
sharingStack<T>::sharingStack(int size):capacity(size)
{
    top[0] = -1;
    bot[0] = -1;
    top[1] = size;
    bot[1] = size;
    arr = new T [size];
}
template <class T>
void sharingStack<T>::push(const T &data, int stackIndex)
{
//    assert(!full());    //如果栈满了（条件为false），程序终止
    if(full())
        throw("stack is full !");
    if(stackIndex == 0)
        arr[++top[0]] = data;
    else
        arr[--top[1]] = data;
}
template <class T>
int sharingStack<T>::pop(int stackIndex)
{
    if(empty(stackIndex))
        return 0;
    if(stackIndex == 0)
        top[0]--;
    else
        top[1]++;
    return 1;
}
template <class T>
T* sharingStack<T>::getTop(int stackIndex)
{
    if(empty(stackIndex))
        return NULL;
    return &arr[top[stackIndex]];
}
template <class T>
void sharingStack<T>::clear(int stackIndex)
{
    if(stackIndex == 0)
        top[0] = bot[0] = -1;
    else
        top[1] = bot[1] = capacity;
}
template <class T>
void sharingStack<T>::printOneSide(int stackIndex) const
{
    if(empty(stackIndex))
    {
        std::cout << "----Stack " << stackIndex << " is empty---- " << std::endl;
        return;
    }
    else
    {
        if(stackIndex == 0)
        {
            std::cout << "----Stack " << stackIndex << " bottom---- " << top[stackIndex]+1 << " elem(s)" << std::endl;
            for(int i = bot[0]+1; i<= top[0]; ++i)
            {
                std::cout << arr[i] << std::endl;
            }
            std::cout << "----Stack " << stackIndex << " top---- " << top[stackIndex]+1 << " elem(s)" << std::endl;
        }
        else
        {
            std::cout << "----Stack " << stackIndex << " top---- " << bot[stackIndex]-top[stackIndex] << " elem(s)" << std::endl;
            for(int i = top[1]; i< bot[1]; ++i)
            {
                std::cout << arr[i] << std::endl;
            }
            std::cout << "----Stack " << stackIndex << " bottom---- " << bot[stackIndex]-top[stackIndex] << " elem(s)" << std::endl;
        }
    }
}
template <class T>
void sharingStack<T>::printAll() const
{
    std::cout << "****capacity of doubleStack is " << capacity << " *****" << std::endl;
    printOneSide(0);
    printOneSide(1);
    std::cout << "*******************************************" << std::endl;
}