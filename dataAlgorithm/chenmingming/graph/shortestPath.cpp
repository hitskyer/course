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
    bool operator<(const G_Node &a, const G_Node &b)
    {
        return a.dist > b.dist;
    }
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
class PriorityQueue;
class Graph //图类
{
    int v;  //顶点个数
    int e;  //边个数
    list<G_Node *> *adj;  //邻接表
    Edge *pEdge;//节点
    G_Node *pGNode;//节点
    friend class PriorityQueue;
public:
    Graph(int vn, int en)
    {
        v = vn;
        e = en;
        adj = new list<G_Node *>[v];
        pEdge = new Edge[e]();
        pGNode = new G_Node[v]();
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

    ~Graph()
    {
        delete[] pGNode;
        delete[] pEdge;
        delete[] adj;
    }

    Edge findEdge(int s, int t)
    {
        for(int i = 0; i < e; ++i)
        {
            if(s == pEdge[i].sid && t == pEdge[i].tid)
                return pEdge[i];
        }
    }
    void dijkstra(int s, int t)
    {
        int *path = new int [v];
        bool *inqueue = new bool[v];
        PriorityQueue pqueue;
        pGNode[s].dist = 0;
        pqueue.push(pGNode[s]);
        inqueue[s] = true;
        G_Node minDnode;
        while(!pqueue.empty())
        {
            minDnode = pqueue.top();
            pqueue.pop();
            if(minDnode.id == t)
                break;
            for(auto it = adj[minDnode.id].begin(); it != adj[minDnode.id].end(); ++it)
            {
                Edge e = findEdge(minDnode.id, (*it)->id);
                G_Node nextNode = pGNode[e.tid];
                if(minDnode.dist + e.w < nextNode.dist)
                {
                    nextNode.dist = minDnode.dist + e.w;
                    path[nextNode.id] = minDnode.id;
                    if(inqueue[nextNode.id] == true)
                    {
//                        pqueue.
                    }
                }
            }
        }
    }
};
class PriorityQueue //优先队列
{
    Graph *grp;
    G_Node *node;
    int count;//堆内元素个数
    int n;  //堆内有效元素个数上限
public:
    PriorityQueue(Graph *g)//根据 dist 构建小顶堆
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
    ~PriorityQueue()
    {
        delete [] node;
    }
    G_Node poll()//获取堆顶元素，并删除
    {
        if(count < 1)
            return NULL;
        G_Node temp = node[1];//堆顶元素
        node[1] = node[count--];//堆顶删除，变成最后一个元素，计数-1
        heapify(node,count,1);
        return temp;
    }
    void heapify(G_Node *arr, int N, int i)
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
    void add(G_Node vertex)
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
    void update(G_Node vertex)//更新节点的dist
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
    bool isEmpty()
    {
        if(count < 1)
            return true;
        return false;
    }
};