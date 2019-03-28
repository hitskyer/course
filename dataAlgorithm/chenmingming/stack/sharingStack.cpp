//共享顺序栈
// Created by mingm on 2019/3/28.
//
#include "sharingStack.h"
#include <assert.h>
template <class T>
sharingStack<T>::sharingStack(int size):capacity(size),top[0](-1), bot[0](-1),top[1](size),bot[1](size)
{
    arr = new T [size];
}
template <class T>
void sharingStack<T>::push(const T &data, int stackIndex)
{
    assert(!full());    //如果栈满了（条件为false），程序终止
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