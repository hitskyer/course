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
    char info;//节点存储信息
    int dist;//从起始顶点到这个顶点的距离
    G_Node(char ch, int d):info(ch),dist(d){};
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
    list<G_Node *> *reverseadj;  //逆邻接表
    G_Node *pGNode;//节点
public:
    Graph(int vn) {
        v = vn;
        adj = new list<G_Node *>[v];
        reverseadj = new list<G_Node *>[v];
        pGNode = new G_Node[v];
        cout << "请顺序输入节点的信息：" << endl;
        char ch;
        for (int i = 0; i < v; ++i)
            cin >> pGNode[i].info;
    }

    ~Graph() {
        delete[] pGNode;
        delete[] reverseadj;
        delete[] adj;
    }

    int findIdx(char ch) {
        for (int i = 0; i < v; ++i) {
            if (pGNode[i].info == ch)
                return i;
        }
        return -1;
    }

    void addEdge(char s, char t)//s先于t,边s->t
    {
        int i = findIdx(s), j = findIdx(t);
        if (i != -1 && j != -1) {
            adj[i].push_back(&pGNode[j]);//s->t，邻接表
            pGNode[j].indegree++;
            reverseadj[j].push_back(&pGNode[i]);//逆邻接表
        }
    }
};