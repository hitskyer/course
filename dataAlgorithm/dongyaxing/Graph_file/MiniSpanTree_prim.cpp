#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType;		// 顶点类型
typedef int EdgeType;			// 边上的权值的类型
#define MAXVEX 9				// 顶点数
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

void MiniSpanTree_prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		// 保存顶点下标
	int lowcost[MAXVEX];	// 保存相关顶点之间的权值
	lowcost[0] = 0;			// 初始化第一个权值为0，即v0假如生成树，lowcost的值为0，说明此下标的顶点已经加入生成树
	adjvex[0] = 0;			// 初始化第一个顶点下标为0
	for (i = 1; i < G.numVertexs; ++i)		// 循环除下标为0外的全部顶点
	{
		lowcost[i] = G.arc[0][i];			// 将V0顶点与之有变的权值存入数组
		adjvex[i] = 0;						// 初始化都为v0的下标
	}
	for (i = 1; i < G.numVertexs; ++i)
	{
		min = INFINITY;		// 初始化最小权值为∞
		j = 1;
		k = 0;
		while (j < G.numVertexs)	// 循环全部顶点
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				// 如果权值不为0，且权值小于min
				min = lowcost[j];		// 则让当前权值成为最小值
				k  = j;					// 将当前最小值的下标存入k
			}
			++j;
		}
		cout << "打印当前顶点边中权值最小边：" << adjvex[k] << " - " << k << endl;
		lowcost[k] = 0;		// 将当前顶点的权值设置为0， 表示此顶点已经完成任务
		for (j = 1; j < G.numVertexs; ++j)
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				// 若下标为k顶点各边权值小于此前这些顶点，未被加入生成树权值
				lowcost[j] = G.arc[k][j];	// 将较小权值存入lowcose
				adjvex[j] = k;				// 将下标为k的顶点存入adjvex
			}
		}
	}
}

int main()
{
	// 邻接矩阵图
	MGraph *G = new MGraph();
	CreateMGraph(G);
	print(G);
	MiniSpanTree_prim(*G);	// 解引用
	
//	system("pause");
	return 0;
}
