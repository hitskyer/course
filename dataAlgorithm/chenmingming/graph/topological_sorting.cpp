/**
 * @description: 拓扑排序，有向无环图
 * @author: michael ming
 * @date: 2019/7/29 0:36
 * @modified by: 
 */
#include <list>
#include <iostream>

using namespace std;
class G_Node
{
public:
    char info;
    int indegree;
    G_Node(char ch = '/'):info(ch),indegree(0){};
};
class Graph
{
    int v;//顶点个数
    list<G_Node> *adj;//邻接表
public:
    Graph(int vn)
    {
        v = vn;
        adj = new list<G_Node> [v];
        auto *pGNode = new G_Node [v];
        cout << "请顺序输入节点的信息：" << endl;
        char ch;
        for(int i = 0; i < v; ++i)
        {
            cin >> pGNode[i].info;
        }
    }
    ~Graph()
    {
        delete [] adj;
    }
    void addEdge(char s, char t)//s先于t,边s->t
    {
        adj[s].push_back(t);
    }
    void topoSortByKahn()
    {
        int *indegree = new int[v];//统计每个顶点的入度
        int i, w;
        list<int>::iterator it;
        for(i = 0; i < v; ++i)
        {
            for(it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                indegree[*]
            }
        }
    }
};