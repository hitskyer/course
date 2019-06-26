/**
 * @description: 利用图的BFS广度搜索查找二度好友
 * @author: michael ming
 * @date: 2019/6/13 0:32
 * @modified by: 
 */
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
#define MaxNum 20   //最大顶点数
#define MaxValue 65535  //最大值(标记矩阵空位)
class arrGraph  //邻接矩阵图
{
public:
    char vertex[MaxNum];    //顶点信息
    int GType;              //图的类型（0无向图，1有向图）
    int v;                  //顶点个数
    int e;                  //边数量
    int ew[MaxNum][MaxNum]; //边的权重
    int visited[MaxNum];    //访问标志
    int distance[MaxNum];   //距离（几度好友）
    arrGraph(int vertexNum, int edgeNum, int gt = 0)
    {
        v = vertexNum;
        e = edgeNum;
        GType = gt;
        clearGraph();
        memset(distance,0,sizeof(int)*v);
    }
    void creatGraph()
    {
        int i, j, k;//循环用计数器
        int weight;//权重
        char startV, endV;//边的起始终止点
        cout << "输入图中各顶点的信息：" << endl;
        for(i = 0; i < v; ++i)
        {
            cout << "第" << i+1 << "个顶点：";
            cin >> vertex[i];
        }
        cout << "输入各边的起点，终点，权值：" << endl;
        for(k = 0; k < e; ++k)
        {
            cout << "第" << k+1 << "条边：";
            cin >> startV >> endV >> weight;
            for(i = 0; startV != vertex[i]; ++i);   //查找起点
            for(j = 0; endV != vertex[j]; ++j);     //终点
            ew[i][j] = weight;                      //权值，一条边 i->j
            if(GType == 0)
                ew[j][i] = weight;  //无向图，对称位置一样的权
        }
    }

    void clearGraph()
    {
        int i, j;
        for(i = 0; i < v; ++i)
            for(j = 0; j < v; ++j)
                ew[i][j] = MaxValue;    //清空矩阵（每个值置为MaxValue）
    }

    int findPos(char ch)
    {
        int i;
        for(i = 0; i < v && ch != vertex[i]; ++i);//找到ch的位置i
        return i;
    }
    void find_friend_bfs(char s, size_t d)//从s开始广度遍历搜索 d 度好友
    {
        memset(distance,0,sizeof(int)*v);
        int i, k;
        size_t dist = 1;//好友距离（度）
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        i = findPos(s);
        if(i >= v)
            return;
        visited[i] = 1;
        queue<char> q;
        q.push(s);
        while(!q.empty())
        {

            char w = q.front();
            q.pop();
            k = findPos(w);
            for(i = 0; i < v; ++i)
            {
                if(ew[k][i] != MaxValue && !visited[i])
                {
                    visited[i] = 1;
                    q.push(vertex[i]);
                    distance[i] = distance[k]+1;
                    //每个未访问点的距离是前一个访问点距离+1
                }
            }
        }
        cout << s << "的" << d << "度好友如下：" << endl;
        for(i = 0; i < v; ++i)  //输出d度好友
        {
            if(distance[i] == d)
                cout << vertex[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    arrGraph ag(10,14);    //10个顶点，14条边，默认生成无向图
    ag.creatGraph();
    //输入ABCDEFGHIJ  AB1BE1EG1AG1AC1BD1EF1GH1GJ1CD1DF1FH1DI1FJ1
    cout << endl;
    ag.find_friend_bfs('A',1);  //查找A的1度好友
    ag.find_friend_bfs('A',2);  //查找A的2度好友
    ag.find_friend_bfs('A',3);  //查找A的3度好友
    ag.find_friend_bfs('A',4);  //查找A的4度好友
    ag.find_friend_bfs('I',2);  //查找I的2度好友
    return 0;
}