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
    list<G_Node*> *adj;  //邻接表
    G_Node *pGNode;//节点
public:
    Graph(int vn)
    {
        v = vn;
        adj = new list<G_Node*> [v];
        pGNode = new G_Node [v];
        cout << "请顺序输入节点的信息：" << endl;
        char ch;
        for(int i = 0; i < v; ++i)
            cin >> pGNode[i].info;
    }
    ~Graph()
    {
        delete [] pGNode;
        delete [] adj;
    }
    int findIdx(char ch)
    {
        for(int i = 0; i < v; ++i)
        {
            if(pGNode[i].info == ch)
                return i;
        }
        return -1;
    }
    void addEdge(char s, char t)//s先于t,边s->t
    {
        int i = findIdx(s), j = findIdx(t);
        if(i != -1 && j != -1)
        {
            adj[i].push_back(&pGNode[j]);
            pGNode[j].indegree++;
        }
    }
    void topoSortByKahn()
    {
        int i, j, k;
        queue<G_Node*> nodeQueue;
        //坑，要存指针在里面，后面才能修改入度，否则修改的是副本
        G_Node *frontNode;
        list<G_Node*>::iterator it;
        for(i = 0; i < v; ++i)
        {
            if(pGNode[i].indegree == 0)
                nodeQueue.push(&pGNode[i]);//找到所有入度为0的入队
        }
        while(!nodeQueue.empty())
        {
            frontNode = nodeQueue.front();
            i = findIdx(frontNode->info);
            nodeQueue.pop();
            cout << frontNode->info << "->";//输出入度为0的，出队
            for(it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                (*it)->indegree--;//该节点后面跟着的所有节点入度-1
                if((*it)->indegree == 0)//入度如果等于0
                    nodeQueue.push(*it);//入队，一会可以打印了
            }
        }
    }
};
int main()
{
    Graph grp(6);
    grp.addEdge('a','b');
    grp.addEdge('b','e');
    grp.addEdge('b','d');
    grp.addEdge('d','c');
    grp.addEdge('d','f');
    grp.topoSortByKahn();
    return 0;
}