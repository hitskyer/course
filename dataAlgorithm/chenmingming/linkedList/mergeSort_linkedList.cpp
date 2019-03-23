//
// Created by mingm on 2019/3/23.
//
#include <iostream>
#include <time.h>
#include "./homework/singleList.cpp"
using namespace std;

ListNode GetMidNode(ListNode s)   //快慢指针法,获取中间节点
{
    ListNode fast, slow;
    fast = s->pNext;//让快指针早点到达末位，慢指针指向中点前一个位置
    slow = s;
    while(fast && fast->pNext)
     {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
     }
    return slow;
}
ListNode mergeList(ListNode L, ListNode R)
{
    if(L == NULL)
        return R;
    if(R == NULL)
        return L;
    ListNode tempL = L, tempR = R;
    ListNode temp = new SNode, trueHead;
    while(tempL && tempR)
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
    if(tempL)
        temp->pNext = tempL;
    if(tempR)
        temp->pNext = tempR;
    trueHead = temp->pNext;
    delete temp;
    temp = NULL;
    return trueHead;
}
ListNode divList(ListNode Lhead)
{
    if(Lhead == NULL || Lhead->pNext == NULL)
        return Lhead;
    ListNode Mid = GetMidNode(Lhead);
    ListNode Rhead = Mid->pNext;
    Mid->pNext = NULL;
    ListNode L = divList(Lhead);
    ListNode R = NULL;
    if(Rhead)
    {
        R = divList(Rhead);
    }
    return mergeList(L,R);
}
ListNode mergeSort(ListNode head)
{
    if(head == NULL || head->pNext == NULL)
        return head;
    else
        divList(head);
}

int main()
{
    srand((unsigned)time(NULL));
    size_t len = 10;
    for(size_t j = 2; j < len; ++j)
    {
        SingleList intList;
        for(size_t i = 0; i < j; ++i)
        {
            intList.AddTail(rand()%100);
        }
        cout << "before merge sort: " << endl;
        intList.PrintList();
        mergeSort(intList.GetHeadNode());
        cout << "after merge sort: " << endl;
        intList.PrintList();
    }
    return 0;
}