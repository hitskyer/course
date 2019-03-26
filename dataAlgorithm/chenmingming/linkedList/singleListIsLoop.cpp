//
// Created by mingm on 2019/3/24.
//检查单链表中是否存在环，求环的长度，链表长度，及环的入口
#include <iostream>
#include <time.h>
#include <cstdlib>
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
        size_t n = rand()%(intList.GetLength());    //0-链表减1的随机数
        ListNode randNode = intList.GetHeadNode();
        for(size_t i = 0; i != n; ++i)
        {
            randNode = randNode->pNext;     //链表的一个随机节点
        }
        ListNode originTail = intList.GetTailNode();
        originTail->pNext = randNode;    //尾节点接入链表中的随机位置形成环
        intList.hasLoop();  //调用环检测函数
        originTail->pNext = NULL;   //断开环，让链表能够按照单链表析构函数析构!!!
        std::cout << "getListLength（） is " << intList.GetLength() << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
    return 0;
}
