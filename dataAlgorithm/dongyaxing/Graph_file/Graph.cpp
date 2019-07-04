#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType;		// 顶点类型
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
	cout << "Vertexs : " << G->numVertexs << endl;
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


/************************************************************************/
/*链邻接矩阵
/************************************************************************/
// 边
typedef struct EdgeNode
{
	int adjvex;				// 邻接点域，存储该顶点对应的下标
	EdgeType weight;		// 用于存储权值，可以不需要，不需要就默认为1，也可以删掉
	struct EdgeNode *next;	// 链域，指向下一个邻接点
	EdgeNode()
	{
		adjvex = -1;
		weight = 1;
		next = NULL;
	}
}EdgeNode;

// 顶点
typedef struct VertexNode
{
	VertexType data;			// 顶点域，存储顶点信息
	EdgeNode *firstedge;		// 边的表头指针
}VertexNode, AdgList[MAXVEX];

// 图链
typedef struct GraphAdjList
{
	AdgList adjList;
	int numVertexes, numEdges;		// 图中当前顶点数和边数
}GraphAdjList;


/****************************************************************
* @brief : 		创建链表邻接图
* @author : 	dyx
* @date : 		2019/7/4 11:15
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	cout << "please input vexs and edges: "<< endl;
	cin >> G->numVertexes;
	cin >> G->numEdges;
	cout << "please input vexs num: " << endl;
	for (i = 0; i < G->numVertexes; ++i)		// 读入顶点信息
	{
		cin >> G->adjList[i].data;				// 输入顶点信息
		G->adjList[i].firstedge = NULL;			// 将边置为空表
	}
	for (k = 0; k < G->numEdges; ++k)
	{
		cout << "please <vi,vj> weights(begin at 0 index) : "<< endl;
		cin >> i;
		cin >> j;
		
		e = (EdgeNode *)malloc(sizeof(EdgeNode));	// 向内存申请空间，生成边表结点
		e->adjvex = j;								// 邻接序号为j
		e->next = G->adjList[i].firstedge;			// 将e指针指向当前顶点指向的结点
		G->adjList[i].firstedge = e;				// 将当前顶点的指针指向e

		e = (EdgeNode *)malloc(sizeof(EdgeNode));	// 向内存申请空间，生成边表结点
		e->adjvex = i;								// 邻接序号为i
		e->next = G->adjList[j].firstedge;			// 将e指针指向当前顶点指向的结点
		G->adjList[j].firstedge = e;				// 将当前顶点的指针指向e
	}
}

/****************************************************************
* @brief : 		需要打印入度链表和出度链表
* @author : 	dyx
* @date : 		2019/7/4 11:16
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void PrintListGraph(GraphAdjList *G)
{
	cout << "vertexe nums: " << G->numVertexes << endl;
	for (int i = 0; i < G->numVertexes; ++i)
	{
		cout << G->adjList[i].data << endl;
	}
	cout << "edges nums: " << G->numEdges << endl;
	for (int i = 0; i < G->numEdges; ++i)
	{
		cout << G->adjList[i].data;
		cout << "uncomplete..."<< endl;
	}
}

int main()
{
	// 邻接矩阵图
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);

	//链图
	GraphAdjList *grlst = new GraphAdjList();
	CreateALGraph(grlst);
	//PrintListGraph(grlst);
	//system("pause");
	return 0;
}
