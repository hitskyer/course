/**
 * @description: 基于邻接矩阵的无向图
 * @author: michael ming
 * @date: 2019/6/11 21:50
 * @modified by: 
 */
#include <iostream>
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
    arrGraph(int vertexNum, int edgeNum, int gt = 0)
    {
        v = vertexNum;
        e = edgeNum;
        GType = gt;
        clearGraph();
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

    void printArrOfGraph()
    {
        int i, j;
        for(j = 0; j < v; ++j)
            cout << "\t" << vertex[j];//第1行顶点信息
        cout << endl;
        for(i = 0; i < v; ++i)
        {
            cout << vertex[i];
            for(j = 0; j < v; ++j)
            {
                if(ew[i][j] == MaxValue)
                    cout << "\t∞";
                else
                    cout << "\t" << ew[i][j];
            }
            cout << endl;
        }
    }

    void dfs_r(char s)
    {
        int i, j;
        for(i = 0; i < v && s != vertex[i]; ++i);
        if(i >= v)
            return;
        j = i;//j存储了开始字符s的位置
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        cout << "从" << s << "开始深度优先搜索结果：" << endl;
        for(i = 0; i < v; ++i,++j)
        {
            if(j == v)
                j = 0;
            if(!visited[j])//没有访问
                dfs_recu(j);
        }
        cout << endl;
    }
    void dfs_recu(int k)
    {
        visited[k] = 1;
        cout << vertex[k] << " ";
        for(int i = 0; i < v; ++i)
        {
            if(ew[k][i] != MaxValue && !visited[i])
                dfs_recu(i);
        }
    }
};

int main()
{
    arrGraph ag(8,10);    //8个顶点，10条边，默认生成无向图
    ag.creatGraph();
//    A — B — C
//    |    |    |
//    D — E — F
//         |    |
//         G — H
//请输入A B C D E F G H  A B 1 B C 1 A D 1 B E 1 C F 1 D E 1 E F 1 E G 1 F H 1 G H 1
    cout << "打印图的邻接矩阵：" << endl;
    ag.printArrOfGraph();
    ag.dfs_r('B');
}