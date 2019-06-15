/**
 * @description: 基于邻接矩阵的无向图
 * @author: michael ming
 * @date: 2019/6/11 21:50
 * @modified by: 
 */
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define MaxNum 20   //最大顶点数
#define MaxValue 65535  //最大值(标记矩阵空位)
struct CloseEdge    //最短的边
{
    int startV;
    int endV;
    int minWeight;  //最小的权值
    bool operator < (const CloseEdge &s) const
    {//符号重载
        return minWeight < s.minWeight;
    }
};
class arrGraph  //邻接矩阵图
{
public:
    char vertex[MaxNum];    //顶点信息
    int GType;              //图的类型（0无向图，1有向图）
    int v;                  //顶点个数
    int e;                  //边数量
    int ew[MaxNum][MaxNum]; //边的权重（邻接矩阵）
    int visited[MaxNum];    //访问标志
    CloseEdge close_edge[MaxNum];   //存储最小生成树

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
    int findPos(char ch)
    {
        int i;
        for(i = 0; i < v && ch != vertex[i]; ++i);//找到ch的位置i
        return i;
    }
    void bfs(char s)//从字符s开始广度遍历
    {
        int i, k;
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        i = findPos(s);
        if(i >= v)
            return;
        visited[i] = 1;
        queue<char> q;
        q.push(s);
        cout << "从 " << s << " 开始广度优先遍历结果：" << endl;
        while(!q.empty())
        {
            char w = q.front();
            cout << w << " ";
            q.pop();
            k = findPos(w);
            for(i = 0; i < v; ++i)
            {
                if(ew[k][i] != MaxValue && !visited[i])
                {
                    visited[i] = 1;
                    q.push(vertex[i]);
                }
            }
        }
        cout << endl;
    }
    void bfs(char s, char t)//从字符s开始广度优先搜索t
    {
        if(s == t)
            return;
        int i, k;
        k = findPos(s);
        if(k >= v)
            return;//s不存在
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        visited[k] = 1;//访问s，存入队列
        queue<char> q;
        q.push(s);
        char *prev = new char [v];//记录搜索的路径
        for(i = 0; i < v; ++i)
            prev[i] = '*';
        cout << "从 " << s << " 开始广度优先搜索 " << t << " 路径：" << endl;
        while(!q.empty())
        {
            char w = q.front();
            q.pop();
            k = findPos(w);
            for(i = 0; i < v; ++i)
            {
                if(ew[k][i] != MaxValue && !visited[i])
                {
                    prev[i] = vertex[k];    //从k处找到了i位置，记录下来
                    if(vertex[i] == t)
                    {
                        printPath(prev, s, t, i);//递归打印路径
                        cout << t << endl;
                        delete [] prev;
                        return;
                    }
                    visited[i] = 1;
                    q.push(vertex[i]);
                }
            }
        }
        delete [] prev;
        cout << endl;
    }
    void printPath(char *prev, char s, char t, int i)
    {
        int k = findPos(prev[i]);
        if(prev[k] != '*' && t != s)
        {
            printPath(prev, s, prev[k], k);//递归打印路径
        }
        cout << prev[i] << " ";
    }

    void dfs_r(char s)//从字符s开始递归深度优先遍历
    {
        int i, j;
        i = findPos(s);
        if(i >= v)
            return;
        j = i;//j存储了开始字符s的位置
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        cout << "从 " << s << " 开始深度优先遍历结果（递归）：" << endl;
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

    void dfs_r(char s, char t)//从字符 s 开始递归深度优先搜索 t
    {
        cout << "从 " << s << " 开始深度优先搜索 " << t << " 路径（递归）：" << endl;
        bool found = false;
        int i, j;
        char *prev = new char [v];//记录搜索的路径
        for(i = 0; i < v; ++i)
            prev[i] = '*';
        i = findPos(s);
        j = i;//j存储了开始字符s的位置
        if(i >= v)
            return;
        if(s == t)
            return;
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        for(i = 0; i < v; ++i,++j)
        {
            if(j == v)
                j = 0;
            if(!visited[j])//没有访问
                dfs_recu(j, prev, found, s, t);
        }
        i = findPos(t);
        printPath(prev, s, t, i);//递归打印路径
        cout << t << endl;
        delete [] prev;
    }
    void dfs_recu(int k, char *prev, bool &found, char s, char t)
    {
        if(found == true)//如果已经找到了，for循环剩余的不执行（优化）
            return;
        visited[k] = 1;
        if(s == t)
        {
            found = true;
            return;
        }
        for(int i = 0; i < v; ++i)
        {
            if(ew[k][i] != MaxValue && !visited[i])
            {
                prev[i] = vertex[k];    //从k处找到了i位置，记录下来
                dfs_recu(i, prev, found, vertex[k], t);
            }
        }
    }

    void dfs(char s)//从字符s开始深度优先遍历（非递归）
    {
        int i, k;
        i = findPos(s);
        if(i >= v)
            return;
        k = i;//k存储了开始字符s的位置
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        cout << "从 " << s << " 开始深度优先遍历结果（非递归）：" << endl;
        stack<char> q;
        q.push(s);
        visited[k] = 1;
        while(!q.empty())
        {
            char w = q.top();
            q.pop();
            k = findPos(w);
            if(visited[k])//访问过了
            {
                cout << w << " ";
                for(i = 0; i < v; ++i)
                {
                    if(ew[k][i] != MaxValue && !visited[i])
                    {
                        visited[i] = 1;
                        q.push(vertex[i]);
                    }
                }
            }
        }
        cout << endl;
    }

    void dfs(char s, char t)//从字符s开始深度优先搜索t（非递归）
    {
        cout << "从 " << s << " 开始深度优先搜索 " << t << " 路径（非递归）：" << endl;
        if(s == t)
            return;
        int i, k;
        i = findPos(s);
        k = i;//k存储了开始字符s的位置
        if(i >= v)
            return;
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        char *prev = new char [v];//记录搜索的路径
        for(i = 0; i < v; ++i)
            prev[i] = '*';
        stack<char> q;
        q.push(s);
        visited[k] = 1;
        while(!q.empty())
        {
            char w = q.top();
            q.pop();
            k = findPos(w);
            if(visited[k])//访问过了
            {
                for(i = 0; i < v; ++i)
                {
                    if(ew[k][i] != MaxValue && !visited[i])
                    {
                        prev[i] = vertex[k];    //从k处找到了i位置，记录下来
                        if(vertex[i] == t)
                        {
                            printPath(prev, s, t, i);//递归打印路径
                            cout << t << endl;
                            delete [] prev;
                            return;
                        }
                        visited[i] = 1;
                        q.push(vertex[i]);
                    }
                }
            }
        }
        delete [] prev;
        cout << endl;
    }

    //----------prim最小生成树---------------
    void MiniSpanTree_Prim(char ch)
    {
        int s = findPos(ch);
        if(s >= v)
            return;
        cout << "从 " << ch << " 开始的Prim最小生成树：" << endl;
        int i, j, k, x, w, minid, sum = 0;
        for(i = 0; i < v; ++i)
            visited[i] = 0;//访问标志置0
        visited[s] = 1;
        vector<int> q;
        vector<int>::iterator it;
        q.push_back(s);
        for(i = 0; i < v-1; ++i)
        {
            for(it = q.begin(),x = 0; it != q.end(); ++it,++x)
            {
                w = MaxValue;
                for(j = 0; j < v; ++j)
                {
                    if (!visited[j] && ew[*it][j] < w)
                    {
                        w = ew[*it][j];
                        minid = j;//记录较小的权的序号为k
                    }
                }
                close_edge[x].minWeight = w;
                close_edge[x].startV = *it;
                close_edge[x].endV = minid;
            }
            sort(close_edge,close_edge+x);
            visited[close_edge[0].endV] = 1;
            cout << vertex[close_edge[0].startV] << "-" << vertex[close_edge[0].endV] << " 权值 " << close_edge[0].minWeight << endl;
            sum += close_edge[0].minWeight;
            q.push_back(close_edge[0].endV);
        }
        cout << "最小生成树权重总和为：" << sum << endl;
//        for(i = 0; i < v; ++i)  //初始化数组
//        {
//            if(i != s)
//            {
//                close_edge[i].adjVertex = s;
//                close_edge[i].minWeight = ew[s][i];//每个顶点的权值初始为起始点s到该点的权
//            }
//        }
//        close_edge[s].adjVertex = s;
//        close_edge[s].minWeight = MaxValue;//到自身的权不存在，置为MaxValue标记
//        for(i = 0; i < v; ++i)
//        {
//            if (s == i)
//                continue;//除了起点外，其余的点
//            w = MaxWeightValue;
//            for (j = 0; j < v; ++j)
//            {
//                if (close_edge[j].minWeight != MaxValue && close_edge[j].minWeight < w)
//                {
//                    w = close_edge[j].minWeight;
//                    minid = j;//记录较小的权的序号为k
//                }
//            }
//            cout << vertex[close_edge[minid].adjVertex] << "-" << vertex[minid] << " 权值 " << w << endl;
//            sum += w;
//            close_edge[minid].minWeight = MaxValue;//第
//            for (j = 0; j < v; ++j)
//            {
//                if (ew[minid][j] < close_edge[j].minWeight)
//                {
//                    close_edge[j].adjVertex = minid;
//                    close_edge[j].minWeight = ew[minid][j];
//                }
//            }
//        }
//        for(i = 0; i < v; ++i)
//            if(i != s)
//            {
//                cout << i << " -> " << close_edge[i].adjVertex << ","
//                        << ew[i][close_edge[i].adjVertex] << endl;
//            }
    }
};


int main()
{
//-------------------------------------------------
//    A — B — C
//    |    |    |
//    D — E — F
//         |    |
//         G — H
//请输入A B C D E F G H  A B 1 B C 1 A D 1 B E 1 C F 1 D E 1 E F 1 E G 1 F H 1 G H 1
//-------------------------------------------------
//    arrGraph ag(8,10);    //8个顶点，10条边，默认生成无向图
//    ag.creatGraph();
//    cout << "打印图的邻接矩阵：" << endl;
//    ag.printArrOfGraph();
//    ag.bfs('B');
//    ag.bfs('A','G');
//    ag.dfs_r('E');
//    ag.dfs_r('A','H');
//    ag.dfs('E');//非递归版本dfs貌似路径不太合理,
//                // 如 B E G H F D C A && E G H F C D A B
//                //可能非递归版的dfs就不叫dfs了，我瞎说的
//    ag.dfs('A','H');
//------------以下测试Prim最小生成树------------------
//    A -40- B -50- C
//  30|  \10 5|    20|
//    D -35- E -45- F
//  10|    55|    10|
//    I -15- G -25- H
//请输入以下数据生成上面的图
//A B C D E F G H I  A B 40 B C 50 A D 30 B E 5 C F 20 D E 35 E F 45 E G 55 F H 10 G H 25 A E 10 D I 10 I G 15
    arrGraph bg(9,13);    //9个顶点，13条边，默认生成无向图
    bg.creatGraph();
    bg.printArrOfGraph();
    bg.MiniSpanTree_Prim('A');
    bg.MiniSpanTree_Prim('I');//从任一点出发，最小花费都一样
    return 0;
}