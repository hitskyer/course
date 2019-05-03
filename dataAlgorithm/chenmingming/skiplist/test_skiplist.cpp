/**
 * @description: 测试跳表
 * @author: michael ming
 * @date: 2019/4/23 0:07
 * @modified by: 
 */
#include "skiplist.h"
int main()
{
    skiplist<int> intSList;
    for(int i = 0; i < 10; ++i)
    {
        intSList.insert(i);
    }
    intSList.printSkipList();
}