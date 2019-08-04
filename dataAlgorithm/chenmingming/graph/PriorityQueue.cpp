/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/5 1:21
 * @modified by: 
 */
#include "PriorityQueue.h"
PriorityQueue::PriorityQueue(Graph *g)//根据 dist 构建小顶堆
{
    grp = g;
    n = grp->v;
    count = 0;
    node = new G_Node [n+1];//堆从下标1开始到n
    for(int i = 1; i <= n; ++i)
    {
        node[i] = grp->pGNode[i-1];
    }
}
PriorityQueue::~PriorityQueue()
{
    delete [] node;
}
G_Node PriorityQueue::poll()//获取堆顶元素，并删除
{
    if(count < 1)
        return NULL;
    G_Node temp = node[1];//堆顶元素
    node[1] = node[count--];//堆顶删除，变成最后一个元素，计数-1
    heapify(node,count,1);
    return temp;
}
void PriorityQueue::heapify(G_Node *arr, int N, int i)
{
    if(N < 1)
        return;
    int min = i;
    G_Node tempNode;
    while(1)
    {
        if(2*i <= N && arr[2*i].dist < arr[min].dist)
            min = 2*i;
        if(2*i+1 <= N && arr[2*i+1].dist < arr[min].dist)
            min=2*i+1;
        //上面2个if找最小的元素下标
        if(min == i)
            return;
        tempNode = arr[min];
        arr[min] = arr[i];
        arr[i] = tempNode;
        i = min;
    }
}
void PriorityQueue::add(G_Node vertex)
{
    if(count >= n)
        return;
    node[++count] = vertex;
    int i = count;
    G_Node tempNode;
    while(i/2 > 0 && node[i/2].dist > node[i].dist)
    {
        tempNode = node[i/2];
        node[i/2] = node[i];
        node[i] = tempNode;
        i = i/2;
    }
}
void PriorityQueue::update(G_Node vertex)//更新节点的dist
{
    int i = 1;
    for( ; i <= n; ++i)
    {
        if(node[i].id == vertex.id)
            break;
    }
    node[i].dist = vertex.dist;//节点的距离只会加（图中无负权）
    heapify(node,count,i);
}
bool PriorityQueue::isEmpty()
{
    if(count < 1)
        return true;
    return false;
}