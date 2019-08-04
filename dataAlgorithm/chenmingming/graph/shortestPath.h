/**
 * @description: 最短路径，有向有权图
 * @author: michael ming
 * @date: 2019/7/31 23:46
 * @modified by: 
 */
#include <list>
#include <iostream>
#include <queue>
using namespace std;
class G_Node    //节点类
{
public:
    int id;//节点id
    int dist;//从起始顶点到这个顶点的距离
    G_Node(int idx = 0, int d = INT_MAX):id(idx),dist(d){};
    void operator=(const G_Node &b)
    {
        id = b.id;
        dist = b.dist;
    }
};
class Edge  //边
{
public:
    int sid;    //起点id
    int tid;    //终点id
    int w;      //权重，路长度
    Edge(int s = 0, int t = 0, int dist = 0)
    {
        sid = s;
        tid = t;
        w = dist;
    }
};
class Graph //图类
{
    int v;  //顶点个数
    int e;  //边个数
    list<G_Node *> *adj;  //邻接表
    Edge *pEdge;//节点
    G_Node *pGNode;//节点
    int *path;
    friend class PriorityQueue;
public:
    Graph(int vn, int en)
    {
        
    }

    ~Graph()
    {
        
    }

    Edge findEdge(int s, int t)
    {
        
    }
    void dijkstra(int s, int t)
    {
        
    }
    void pathPrint(int s, int term, int *path)
    {
        
    }
};
