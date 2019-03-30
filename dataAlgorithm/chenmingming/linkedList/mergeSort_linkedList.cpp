//归并排序
// Created by mingm on 2019/3/23.
//
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "./homework/singleList.cpp"
using namespace std;

ListNode GetMidNode(ListNode s)   //快慢指针法,获取中间节点
{
    ListNode fast, slow;
    fast = s->pNext;//让快指针早点到达末位，慢指针指向中点或者(偶数个长度时)中点前一个位置
    slow = s;
    while(fast && fast->pNext)
     {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
     }
    return slow;
}
ListNode mergeList(ListNode L, ListNode R)  //归并函数
{
    if(L == NULL)   //如果一边为空，则返回另一边的头结点
        return R;
    if(R == NULL)
        return L;
    ListNode tempL = L, tempR = R;  //把左右表头存储起来
    ListNode temp = new SNode, emptyHead = temp; //利用一个空表头哨兵temp
    while(tempL && tempR)       //左右链表均不为空的话，进行数据比较
    {
        if(tempL->data < tempR->data)
        {
            temp->pNext = tempL;
            temp = temp->pNext;
            tempL = tempL->pNext;
        }
        else
        {
            temp->pNext = tempR;
            temp = temp->pNext;
            tempR = tempR->pNext;
        }
    }
    if(tempL)                   //如果左边还有剩余的节点，把其接入链表末尾
        temp->pNext = tempL;
    if(tempR)                   //如果右边还有剩余的节点，把其接入链表末尾
        temp->pNext = tempR;
    temp = emptyHead->pNext;     //实际链表数据节点表头
    delete emptyHead;           //释放new出来的哨兵
    emptyHead = NULL;
    return temp;                //返回链表数据头结点
}
ListNode divList(ListNode Lhead)
{
    if(Lhead == NULL || Lhead->pNext == NULL)   //链表长度为0或者1，不用排序
        return Lhead;
    ListNode Mid = GetMidNode(Lhead);   //获取链表中间节点(如果长度为2，则Mid是第一个节点)
    ListNode Rhead = Mid->pNext;    //右边链表表头地址
    Mid->pNext = NULL;              //断开左右链表
    ListNode L = divList(Lhead);    //继续对左右两条链表进行划分
    ListNode R = divList(Rhead);
    return mergeList(L,R);          //返回merge后的链表的表头
}
ListNode mergeSort(ListNode head)   //归并排序入口，将头结点地址传入
{
    if(head == NULL || head->pNext == NULL) //链表长度为0或者1，不用排序
        return head;
    else
        divList(head);  //长度大于1，则对其进行划分将链表切片
}

int main()
{
    srand((unsigned)time(NULL));    //用时间随机数种子
    size_t len = 10;       //测试链表最大长度
    for(size_t j = 0; j < len; ++j)
    {
        SingleList intList;
        for(size_t i = 0; i < j; ++i)
        {
            intList.AddTail(rand()%100);    //添加随机数到链表
        }
        cout << "before merge sort: " << endl;
        intList.PrintList();    //排序前链表打印
        intList.SetHeadNode(mergeSort(intList.GetHeadNode()));  //把排序后的链表的头结点设置成链表的头结点
        cout << "after merge sort: " << endl;
        intList.PrintList();    //排序后链表打印
    }
    return 0;
}