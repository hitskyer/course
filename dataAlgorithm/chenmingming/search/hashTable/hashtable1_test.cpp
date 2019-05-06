/**
 * @description: 
 * @author: michael ming
 * @date: 2019/5/6 10:42
 * @modified by: 
 */
#include "hashtable1.cpp"
#include <iostream>
int main()
{
    hashtable1<int> ht1(10);
    ht1.print();
    for(int i = 15; i < 18; ++i)
    {
        ht1.insert(i);
        ht1.print();
    }
    for(int i = 25; i < 29; ++i)
    {
        ht1.insert(i);
        ht1.print();
    }
    for(int i = 27; i < 29; ++i)
    {
        ht1.delete_elem(i);
        ht1.print();
    }
    for(int i = 100; i < 103; ++i)
    {
        ht1.insert(i);
        ht1.print();
    }
    for(int i = 200; i < 203; ++i)
    {
        ht1.insert(i);
        ht1.print();
    }
    if(ht1.isInTable(109) >= 0)
        std::cout << ht1.getValue(ht1.isInTable(109));
    return 0;
}