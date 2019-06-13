/**
 * @description: 农夫过河问题（羊，白菜，狼），一次最多带一个东西过河，
 *                  农夫不在的情况下羊会吃白菜，狼会吃羊，如何平安过河
 * @author: michael ming
 * @date: 2019/6/13 20:06
 * @modified by: 
 */
#include <iostream>
#include <queue>
#include <memory.h>

#define MaxVertexNum 10 //最多10种情况（顶点）
using namespace std;
struct vertexType
{
    int farmer;
    int wolf;
    int sheep;
    int vegetable;
};
class MGraph_Farmer //邻接矩阵图类
{
public:
    vertexType vertex[MaxVertexNum];    //顶点表
    int edges[MaxVertexNum][MaxVertexNum];//边的邻接矩阵
    int vN, eN;   //顶点和边的数量
    int visited[MaxVertexNum];  //访问标志
    int prev[MaxVertexNum];     //存储搜索路径

    MGraph_Farmer():vN(0),eN(0)
    {
        memset(visited,0, sizeof(int)*MaxVertexNum);
    }
    void clearPrev()
    {
        for(int i = 0; i < MaxVertexNum; ++i)
            prev[i] = -1;
    }
    int findPos(int F, int W, int S, int V)//查找顶点在图中的位置
    {
        for(int i = 0; i < vN; ++i)
            if(vertex[i].farmer == F && vertex[i].wolf == W &&
                vertex[i].sheep == S && vertex[i].vegetable == V)
                return i;
        return -1;
    }
    int is_safe(int F, int W, int S, int V)//判断是否安全
    {
        if(F != S && (W == S || S == V))//人和羊不在一起时，狼羊或者羊菜在一起，不安全
            return 0;
        return 1;
    }
    int is_connected(int i, int j)//判断状态之间是否可以转换
    {
        int k = 0;
        if(vertex[i].wolf != vertex[j].wolf)
            k++;
        if(vertex[i].sheep != vertex[j].sheep)
            k++;
        if(vertex[i].vegetable != vertex[j].vegetable)
            k++;
        if(vertex[i].farmer != vertex[j].farmer && k <= 1)//农夫每次需要过河，只能带一件东西
            return 1;
        return 0;
    }
    void creatGraph()//建立图的存储矩阵
    {
        int i = 0, j, F, W, S, V;
        for(F = 0; F <= 1; F++)//生成所有安全状态的顶点
            for(W = 0; W <= 1; W++)
                for(S = 0; S <= 1; S++)
                    for(V = 0; V <= 1; V++)
                        if(is_safe(F, W, S, V))
                        {
                            vertex[i].farmer = F;
                            vertex[i].wolf = W;
                            vertex[i].sheep = S;
                            vertex[i].vegetable = V;
                            i++;
                        }
        vN = i;//安全顶点个数
        for(i = 0; i < vN; ++i)
            for(j = 0; j < vN; ++j)
                if(is_connected(i,j))//i,j两种状态可以转换，他们的边置1，否则置0
                {
                    edges[i][j] = edges[j][i] = 1;//无向图
                    eN++;
                }
                else
                    edges[i][j] = edges[j][i] = 0;//无向图
        eN /= 2;
    }
    void dfs(int s, int t)
    {
        memset(visited,0, sizeof(int)*MaxVertexNum);
        clearPrev();
        dfs_path(s, t);
        if(visited[t])
            printPath(s,t,t);
    }
    void dfs_path(int s, int t)//dfs搜索s到t的路径
    {
        int j;
        visited[s] = true;
        for(j = 0; j < vN; ++j)
            if(edges[s][j] == 1 && !visited[j] && !visited[t])
            {
                prev[j] = s;//记录路径
                dfs_path(j, t);
            }
    }

    void printPath(int s, int t, int k)
    {
        if(k != s)
        {
            printPath(s,t,prev[k]);
        }
        cout << endl;
        cout << "(" << vertex[k].farmer << vertex[k].wolf
             << vertex[k].sheep << vertex[k].vegetable << ")";
    }
    void bfs(int s, int t)//bfs搜索s到t的路径
    {
        memset(visited,0, sizeof(int)*MaxVertexNum);
        clearPrev();
        queue<int> q;
        q.push(s);
        visited[s] = true;
        int j, w;
        while(!q.empty())
        {
            int w = q.front();
            q.pop();
            for(j = 0; j < vN; ++j)
            {
                if(edges[w][j] == 1 && !visited[j])
                {
                    prev[j] = w;
                    if(j == t)
                    {
                        printPath(s,t,j);
                        return;
                    }
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
};

int main()
{
    int s, t;
    MGraph_Farmer farmerCrossRiver;
    farmerCrossRiver.creatGraph();
    s = farmerCrossRiver.findPos(0,0,0,0);
    t = farmerCrossRiver.findPos(1,1,1,1);
    cout << "dfs搜索:";
    farmerCrossRiver.dfs(s,t);
    cout << endl << "bfs搜索:";
    farmerCrossRiver.bfs(s,t);
    return 0;
}