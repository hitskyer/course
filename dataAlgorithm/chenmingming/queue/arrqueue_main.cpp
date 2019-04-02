/**
 * @description:
 * @author: mingm
 * @date: 2019/4/1 22:44
 * @param:
 * @return:
 */
#include <iostream>
#include "arrqueue.h"
int main()
{
    arrQueue<int> intqueue(7);
    for(UINT i = 0; i < 8; ++i)
    {
        intqueue.enqueue(i);
        intqueue.print();
    }
    for(UINT i = 0; i < 5; ++i)
    {
        intqueue.dequeue();
        intqueue.print();
    }
    intqueue.enqueue(100);
    intqueue.print();
    cout << "the length of queue is " << intqueue.getlength() << endl;
    cout << "head is " << intqueue.getHead() << ", tail is " << intqueue.getTail() << endl;
    return 0;
}