//
// Created by mingm on 2019/3/24.
//检查单链表中是否存在环，求环的长度，链表长度，及环的入口
#include <iostream>
#include <time.h>
#include "./homework/singleList.cpp"
using namespace std;
int main()
{
    srand((unsigned)time(NULL));    //用时间随机数种子
    size_t len = 10;       //测试链表最大长度
    for(size_t j = 1; j < len; ++j)
    {
        SingleList intList;
        for(size_t i = 0; i < j; ++i)
        {
            intList.AddTail(rand()%100);    //添加随机数到链表
        }
        cout << "no loop list: " << endl;
        intList.PrintList();    //排序前链表打印
        size_t n = rand()%(intList.GetLength());
        ListNode randNode = intList.GetHeadNode();
        for(size_t i = 0; i != n; ++i)
        {
            randNode = randNode->pNext;
        }
        intList.GetTailNode()->pNext = randNode;
        intList.hasLoop();
    }
    return 0;
}
