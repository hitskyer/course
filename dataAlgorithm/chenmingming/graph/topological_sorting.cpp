/**
 * @description: 拓扑排序，有向无环图
 * @author: michael ming
 * @date: 2019/7/29 0:36
 * @modified by: 
 */
#include <list>
#include <iostream>
#include <queue>

using namespace std;
class G_Node    //节点类
{
public:
    char info;//节点存储信息
    int indegree;//节点入度
    G_Node(char ch = '/'):info(ch),indegree(0){};
};
class Graph //图类
{
    int v;  //顶点个数
    list<G_Node> *adj;  //邻接表
    G_Node *pGNode;//节点
public:
    Graph(int vn)
    {
        v = vn;
        adj = new list<G_Node> [v];
        pGNode = new G_Node [v];
        cout << "请顺序输入节点的信息：" << endl;
        char ch;
        for(int i = 0; i < v; ++i)
            cin >> pGNode[i].info;
    }
    ~Graph()
    {
        delete [] adj;
    }
    int findIdx(char ch)
    {
        for(int i = 0; i < v; ++i)
        {
            if(pGNode[i].info == ch)
                return i;
        }
        return INT_MIN;
    }
    void addEdge(char s, char t)//s先于t,边s->t
    {
        int i = findIdx(s), j = findIdx(t);
        if(i != INT_MIN && j != INT_MIN)
        {
            adj[i].push_back(G_Node(t));
            pGNode[j].indegree++;
        }
    }
    void topoSortByKahn()
    {
        int i, j;
        queue<G_Node> nodeQueue;
        G_Node frontNode;
        for(i = 0; i < v; ++i)
        {
            if(pGNode[i].indegree == 0)
                nodeQueue.push(pGNode[i]);
        }
        while(!nodeQueue.empty())
        {
            frontNode = nodeQueue.front();
            nodeQueue.pop();
            cout <<
        }
    }
};