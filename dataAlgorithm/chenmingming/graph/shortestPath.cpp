/**
 * @description: 最短路径，有向有权图
 * @author: michael ming
 * @date: 2019/7/31 23:46
 * @modified by: 
 */
#include "PriorityQueue.h"
#include <limits.h>
Graph::Graph(int vn, int en)
{
    v = vn;
    e = en;
    adj = new list<G_Node *>[v];
    pEdge = new Edge[e]();
    pGNode = new G_Node[v]();
    path = new int [v];
    for(int i = 0; i < v; ++i)
    {
        pGNode[i].id = i;
        pGNode[i].dist = INT_MAX;
    }
    cout << "请输入起点序号，终点序号，其间距离" << endl;
    for(int i = 0; i < e; ++i)
    {
        cin >> pEdge[i].sid >> pEdge[i].tid >> pEdge[i].w;
    }
}

Graph::~Graph()
{
    delete[] path;
    delete[] pGNode;
    delete[] pEdge;
    delete[] adj;
}

Edge* Graph::findEdge(int s, int t)
{
    for(int i = 0; i < e; ++i)
    {
        if(s == pEdge[i].sid && t == pEdge[i].tid)
            return &pEdge[i];
    }
    return NULL;
}
void Graph::dijkstra(int s, int t)
{
    bool *inqueue = new bool[v];
    PriorityQueue *pqueue;//前向声明后，不能定义对象，只能指针或引用，编译到这不知道其实现
    pGNode[s].dist = 0;
    pqueue->add(pGNode[s]);
    inqueue[s] = true;
    G_Node minDnode;
    while(!pqueue->isEmpty())
    {
        minDnode = pqueue->poll();
        if(minDnode.id == t)
            break;
        for(auto it = adj[minDnode.id].begin(); it != adj[minDnode.id].end(); ++it)
        {
            Edge *e = findEdge(minDnode.id, (*it)->id);
            G_Node nextNode = pGNode[e->tid];
            if(minDnode.dist + e->w < nextNode.dist)
            {
                nextNode.dist = minDnode.dist + e->w;
                path[nextNode.id] = minDnode.id;
                if(inqueue[nextNode.id] == true)
                {
                    pqueue->update(nextNode);
                }
                else
                {
                    inqueue[nextNode.id] = true;
                    pqueue->add(nextNode);
                }
            }
        }
    }
    //打印输出
    cout << s;
    pathPrint(s,t,path);
}
void Graph::pathPrint(int s, int term, int *path)
{
    if(s == term)
        return;
    pathPrint(s,path[term],path);
    cout << "->" << term;
}