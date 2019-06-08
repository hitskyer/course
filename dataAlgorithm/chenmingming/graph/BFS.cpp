/**
 * @description: BFS
 * @author: michael ming
 * @date: 2019/6/4 23:05
 * @modified by: 
 */
#include <list>
#include <queue>
#include <iostream>
#include <memory.h>
using namespace std;
class graph
{
    int v;//顶点个数
    list<int> *adj;//邻接表
public:
    graph(int numofvertex)
    {
        v = numofvertex;
        adj = new list<int> [v];
    }
    ~graph()
    {
        delete [] adj;
    }
    void insertEdge(int s, int t)   //无向图，一次存两边
    {
        s--;t--;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    void print()
    {
        for(int i = 0; i < v; ++i)
        {
            cout << "邻接表，节点 " << i << " is \n";
            for(auto it = adj[i].begin(); it != adj[i].end();++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    void bfs(int s)//从s开始遍历全部
    {
        bool *visited = new bool [v];
        memset(visited,false, sizeof(bool)*(v));
        visited[s] = true;//visited存储已经访问的节点，避免重复访问
        list<int> q;//
        q.push_back(s);
        list<int>::iterator it;
        cout << "从" << s << "开始广度搜索的结果是:" << endl;
        while(!q.empty())
        {
            int w = q.front();
            cout << w << " ";
            q.pop_front();
            for(it = adj[w].begin(); it != adj[w].end();++it)
            {
                if(visited[*it]==false)
                {
                    visited[*it] = true;
                    q.push_back(*it);
                }
            }
        }
    }
};

int main()
{
    graph gp(8);
    gp.insertEdge(1,2);
    gp.insertEdge(2,3);
    gp.insertEdge(1,4);
    gp.insertEdge(2,5);
    gp.insertEdge(3,6);
    gp.insertEdge(4,5);
    gp.insertEdge(5,6);
    gp.insertEdge(5,7);
    gp.insertEdge(6,8);
    gp.insertEdge(7,8);
    gp.print();
    gp.bfs(7);
    return 0;
}