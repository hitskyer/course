/**
 * @description: 拓扑排序，有向无环图
 * @author: michael ming
 * @date: 2019/7/29 0:36
 * @modified by: 
 */
#include <list>
using namespace std;
class Graph
{
    int v;//顶点个数
    list<int> *adj;//邻接表
public:
    Graph(int vn)
    {
        v = vn;
        adj = new list<int> [v];
    }
    ~Graph()
    {
        delete [] adj;
    }
    void addEdge(int s, int t)//s先于t,边s->t
    {
        adj[s].push_back(t);
    }
    void topoSortByKahn()
    {
        int *indegree = new int[v];//统计每个顶点的入度
        int i, j, w;
        for(i = 0; i < v; ++i)
        {
            for(j = 0; j < adj[i].size(); ++j)
            {
                w = adj[i].f
            }
        }
    }
};