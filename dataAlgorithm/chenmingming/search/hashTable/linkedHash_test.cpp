/**
 * @description: 
 * @author: michael ming
 * @date: 2019/5/6 17:57
 * @modified by: 
 */
#include "linkedHash.h"
int main()
{
    linkedHash<int> ht2(10);
    for(int i = 15; i < 35; ++i)
    {
        ht2.insert(i);
        ht2.print();
    }
    return 0;
}