/**
 * @description: 拉链法散列表 测试
 * @author: michael ming
 * @date: 2019/5/6 17:57
 * @modified by: 
 */
#include "linkedHash.h"
int main()
{
    linkedHash<int> ht2(10);
    for(int i = 15; i < 37; ++i)
    {
        ht2.insert(i);
        ht2.print();
    }
    ht2.delete_elem(15);
    ht2.print();
    ht2.delete_elem(18);
    ht2.print();
    ht2.delete_elem(28);
    ht2.print();
    ht2.insert(88);
    ht2.print();
    ht2.delete_elem(100);
    ht2.print();
    return 0;
}