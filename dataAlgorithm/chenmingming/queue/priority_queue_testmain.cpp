/**
 * @description: 
 * @author: michael ming
 * @date: 2019/4/3 21:35
 * @modified by: 
 */
#include "priority_queue.cpp"
#include <functional>
#include <time.h>
#include <random>

int& compfunction(int &a, int &b)
{
    return a < b ? b : a;
}
int (*p)(int &, int &) = compfunction(int&, int&);
int main()
{
    srand((unsigned)time(NULL));
    priority_queue<int,p> intqueue(5);
    for(int i = 0; i < 6; ++i)
    {
        intqueue.enqueue(rand()%20);
    }
    intqueue.print();
    for(int i = 0; i < 6; ++i)
    {
        intqueue.dequeue();
        intqueue.print();
    }
    return 0;
}