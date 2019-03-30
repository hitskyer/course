//共享顺序栈
// Created by mingm on 2019/3/28.
//
#ifndef STACK_SHARINGSTACK_H
#define STACK_SHARINGSTACK_H

#include <iostream>
template <class T> class sharingStack
{
private:
    int top[2], bot[2]; //双栈的栈顶指针和栈底指针
    T* arr;     //栈数组
    int capacity;   //栈容量
public:
    sharingStack(int size = 10);    //初始化，总容量默认10
    ~sharingStack()
    {
        delete [] arr;
        arr = NULL;
    }
    void push(const T& data, int stackIndex);    //将数据压入index号栈内
    int pop(int stackIndex);        //将index号栈顶元素弹出
    T* getTop(int stackIndex);      //返回index号栈顶元素
    bool empty(int stackIndex) const    //判断是否为空
    {
        return top[stackIndex] == bot[stackIndex];
    }
    bool full() const   //判断栈是否满
    {
        return top[0]+1 == top[1];
    }
    void clear(int stackIndex);     //清空index号栈
    void printOneSide(int stackIndex) const;    //打印一侧栈
    void printAll() const;                      //打印所有
};

#endif //STACK_SHARINGSTACK_H