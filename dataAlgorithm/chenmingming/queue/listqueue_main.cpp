/**
 * @description:
 * @author: michael ming
 * @date: 2019/4/1 22:49
 * @modified by:
 */
#include "listQueue.h"
#include <iostream>
int main()
{
    ListQueue<int> intqueue;
    int k = 5;
    for(int i = 0; i < k; ++i)
    {
        intqueue.enqueue(i);
    }
    intqueue.print();
    std::cout << "len of queue is " << intqueue.getlength() << std::endl;
    for(int i = 0; i < k-1; ++i)
    {
        intqueue.dequeue();
        std::cout << "after one dequeue: " << std::endl;
        intqueue.print();
    }
    std::cout << "len of queue is " << intqueue.getlength() << std::endl;
    std::cout << "head is " << intqueue.getHead()->data << std::endl;
    std::cout << "tail is " << intqueue.getTail()->data << std::endl;
    return 0;
}

