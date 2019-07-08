#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int VertexType;		// 顶点类型
typedef int EdgeType;			// 边上的权值的类型
#define MAXVEX 20				// 顶点数
#define INFINITY 65535			// 无穷大数
/*
* 邻接矩阵图
*/
typedef struct MGraph
{
	VertexType vexs[MAXVEX];			// 顶点表
	EdgeType arc[MAXVEX][MAXVEX];		// 邻接矩阵，边
	int numVertexs, numEdges;			// 途中当前的顶点数和边数
}MGraph;


/****************************************************************
* @brief : 		构造一个图，建立无向网图的邻接矩阵表示
* @author : 	dyx
* @date : 		2019/7/3 15:12
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	cout << "please input vexs and edges: " << endl;// 输入顶点数和边数
	cin >> G->numVertexs;
	cin >> G->numEdges;			// 边 = 顶点数^2
	cout << "please input vexs num: " << endl;
	for (i = 0; i < G->numVertexs; ++i)		// 读入顶点信息，建立顶点表
	{
		cin >> G->vexs[i];
	}
	for (i = 0; i < G->numVertexs; ++i)		// 邻接矩阵初始化
	{
		for (j = 0; j < G->numVertexs; ++j)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < G->numEdges; ++k)		// 读入numEdges条边。
	{
		cout << "please input the i,j of <vi, vj> , and w(begin at 0):" << endl;
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];		// 无向图，对称
	}
}


/****************************************************************
* @brief : 		打印输出图邻接矩阵
* @author : 	dyx
* @date : 		2019/7/3 15:23
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void print(MGraph *G)
{
	cout << "Vertex : " << G->numVertexs << endl;
	for (int i = 0; i < G->numVertexs; ++i)
	{
		cout << G->vexs[i] << " ";
	}
	cout << endl;
	cout << "Edges : " << G->numEdges << endl;
	for (int i = 0; i < G->numVertexs; ++i)
	{
		for (int j = 0; j < G->numVertexs; ++j)
		{
			cout << G->arc[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/* 边的结构体 */
typedef struct Edge
{
	int begin;
	int end;
	int weight;
}Edge;


/****************************************************************
* @brief : 		按照权重排序，由小到大
* @author : 	dyx
* @date : 		2019/7/8 15:09
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void sortByWeight(Edge * edges, int len)
{
	int preIndex;
	Edge current;
	for (int i = 1; i < len; ++i)
	{
		preIndex = i -1;
		current = edges[i];
		while(preIndex >= 0 && edges[preIndex].weight > current.weight)
		{
			edges[preIndex + 1] = edges[preIndex];
			--preIndex;
		}
		edges[preIndex + 1] = current;
	}
}

//bool comp(Edge &a, Edge &b)
//{
//	return a.weight > b.weight ? true:false;
//}

/****************************************************************
* @brief : 		查找连线顶点的尾部下标
* @author : 	dyx
* @date : 		2019/7/8 15:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int Find(int *parent, int f)
{
	while(parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/****************************************************************
* @brief : 		Kruskal--最小生成树
* @author : 	dyx
* @date : 		2019/7/8 15:20
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAXVEX];		// 定义边集数组
	int parent[MAXVEX];		// 定义一数组用来判断边与边是否形成环路
	// 将邻接矩阵G转化为边集数组 edges
	int k = 0;
	for (i = 1; i < G.numVertexs; ++i)
	{
		for (int j = 0; j < i; ++j, ++k)
		{ 
			edges[k].begin = G.vexs[i];
			edges[k].end = G.vexs[j];
			edges[k].weight = G.arc[i][j];
		}
	}
	// 并按权由小到大排序
	sortByWeight(edges, G.numVertexs * (G.numVertexs - 1) / 2);
	for (i = 0; i < G.numVertexs; ++i)
	{
		parent[i] = 0;		// 初始化数组值为0
	}
	for (i = 0; i < G.numVertexs; ++i)		// 循环每一条边
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)		//	加入n与m不等，说明此边没有与现有生成树形成环路
		{
			parent[n] = m;	// 将此边的结尾顶点放入下标为起点的parent中，表示此顶点已经在生成树集合中
			cout << "(" << edges[i].begin << ", " << edges[i].end << ")" << " " << edges[i].weight << endl;
		}
	}
}

/*
输入：
6 10
0 1 2 3 4 5 
1 0 6
2 0 1
2 1 5
3 0 5
3 2 5
4 1 3
4 2 6
5 2 4
5 3 2
5 4 6
输入：
(2, 0) 1
(5, 3) 2
(4, 1) 3
(5, 2) 4
(2, 1) 5
(3, 0) 5 //最后一条有问题
*/
int main()
{
	// 邻接矩阵图
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);
	MiniSpanTree_Kruskal(*G);	// 解引用

//	system("pause");
	return 0;
}
