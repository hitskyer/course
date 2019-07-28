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
};
