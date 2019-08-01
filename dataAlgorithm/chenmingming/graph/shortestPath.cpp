/**
 * @description: 最短路径，有向有权图
 * @author: michael ming
 * @date: 2019/7/31 23:46
 * @modified by: 
 */
#include <list>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class G_Node    //节点类
{
public:
    int id;//节点id
    int dist;//从起始顶点到这个顶点的距离
    G_Node(int idx = 0, int d = INT_MAX):id(idx),dist(d){};
};
class Edge  //边
{
    int sid;    //起点id
    int tid;    //终点id
    int w;      //权重，路长度
    Edge(int s, int t, int dist)
    {
        sid = s;
        tid = t;
        w = dist;
    }
};
class Graph //图类
{
    int v;  //顶点个数
    list<G_Node *> *adj;  //邻接表
    G_Node *pGNode;//节点
public:
    Graph(int vn)
    {
        v = vn;
        adj = new list<G_Node *>[v];
        pGNode = new G_Node[v]();
        for (int i = 0; i < v; ++i)
            pGNode[i].id = i;
    }

    ~Graph()
    {
        delete[] pGNode;
        delete[] adj;
    }

    void addEdge(int s, int t)
    {
        if(s == t)
            return;
        adj[s].push_back(&pGNode[t]);//s->t,邻接表
    }
};