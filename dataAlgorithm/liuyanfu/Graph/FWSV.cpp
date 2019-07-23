#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <queue>
using namespace std;

#define MAXVERTEX 16

typedef struct  
{
	int farmer;
	int wolf;
	int sheep;
	int vegetable;
}VertexType;

typedef struct  
{
	VertexType vertexs[MAXVERTEX]; /*顶点表表示点集*/
	int edges[MAXVERTEX][MAXVERTEX];
	int vertexNum, edgeNum;
}MGraph;


bool visited[MAXVERTEX];
int path[MAXVERTEX];

int Locate(MGraph *G, int F, int W, int S, int V)
{
	for(int i = 0; i < MAXVERTEX; ++i)
	{
		if(G->vertexs[i].farmer == F && G->vertexs[i].wolf == W 
			&& G->vertexs[i].sheep == S && G->vertexs[i].vegetable == V)
			return i;
	}
	return -1;//证明没有找到指定的顶点
}

//判断当前顶点是否为安全顶点
bool Is_safe(int F, int W, int S, int V)
{
	if(F != S && (W == S || S == V))
		return false;
	else
		return true;
}

//判断当前顶点的状态能不能转变成下一个顶点的状态，目的保证每次人只能带着一个东西过河
bool Is_connected(MGraph* G, int i, int j)
{
	int k = 0;
	if(G->vertexs[i].wolf != G->vertexs[j].wolf)
		k++;
	if(G->vertexs[i].sheep != G->vertexs[j].sheep)
		k++;
	if(G->vertexs[i].vegetable != G->vertexs[j].vegetable)
		k++;
	if(G->vertexs[i].farmer != G->vertexs[j].farmer && k <= 1)
		return true;
	else
		return false;
}


void CreateGraph(MGraph *G)
{
	int i,j,F,W,S,V;
	i = 0;
	for(F = 0; F <= 1; ++F)
		for(W = 0; W <= 1; ++W)
			for(S = 0; S <= 1; ++S)
				for(V = 0; V <= 1; ++V)
					if(Is_safe(F,W,S,V))
					{
						G->vertexs[i].farmer = F;
						G->vertexs[i].wolf = W;
						G->vertexs[i].sheep = S;
						G->vertexs[i].vegetable = V;
						++i;
					}
	G->vertexNum = i;
	for(i = 0; i < G->vertexNum; ++i)
		for(j = 0; j < G->vertexNum; ++j)
			if(Is_connected(G, i, j))
				G->edges[i][j] = G->edges[j][i] = 1;
			else
				G->edges[i][j] = G->edges[j][i] = 0;
}


void DFS(MGraph *G, int s, int t)
{
	visited[s] = true;
	for(int j = 0; j < G->vertexNum; ++j)
	{
		if(!visited[j] && G->edges[s][j] == 1)
		{
			path[s] = j;
			DFS(G, j, t);
		}
	}
}


void BFS(MGraph *G, int s, int t)
{
	visited[s] = true;
	std::queue<int> que;
	que.push(s);
	while(!que.empty())
	{
		int temp = que.front();
		que.pop();
		for(int j = 0; j < G->vertexNum; ++j)
		{
			if(!visited[j] && G->edges[temp][j] == 1)
			{
				visited[j] = true;
				que.push(j);
				path[temp] = j;
			}
		}
	}
}

void Print_Path(MGraph* G, int s, int t)
{
	int k = s;
	cout << "显示右岸已经过河的物体（农夫、狼、羊、蔬菜）" << endl;
	while(k != t)
	{
		cout << G->vertexs[k].farmer << G->vertexs[k].wolf << G->vertexs[k].sheep 
			<< G->vertexs[k].vegetable << endl;
		k = path[k];
	}
	cout << G->vertexs[k].farmer << G->vertexs[k].wolf << G->vertexs[k].sheep 
		<< G->vertexs[k].vegetable << endl;
}

//输出从起点到终点的简单可视图
void Print_Graph(MGraph* G, int s, int t)
{
	int k = s;
	while(k != t)
	{
		Sleep(1500);
		cout << "左岸 ||			|| 右岸" << endl;
		cout << "-----++-----------------++-----" << endl;
		if(G->vertexs[k].farmer == 0)
			cout << "农夫 ||		    || " << endl;
		else
			cout << "     ||			|| 农夫" << endl;  
		if(G->vertexs[k].wolf == 0)
			cout << "狼   ||	    河	     || " << endl;
		else
			cout << "     ||        河       || 狼" << endl;
		if(G->vertexs[k].sheep == 0)
			cout << "羊   ||        	     || " << endl;
		else
			cout << "     ||                 || 羊" << endl;
		if(G->vertexs[k].vegetable == 0)
			cout << "蔬菜 ||	 	         || " << endl;
		else
			cout << "     ||                 || 蔬菜" << endl;
		k = path[k];
	}

	Sleep(1500);
	cout << "左岸 ||			|| 右岸" << endl;
	cout << "-----++-----------------++-----" << endl;
	cout << "     ||			|| 农夫" << endl; 
	cout << "     ||        河       || 狼" << endl;
	cout << "     ||                 || 羊" << endl;
	cout << "     ||                 || 蔬菜" << endl;
	cout << "农夫的物品已安全过河..." << endl; 
}


int main()
{
	int i,j;
	MGraph graph;
	CreateGraph(&graph);
	for(i = 0; i < graph.vertexNum; ++i)
		visited[i] = false;
	i = Locate(&graph, 0, 0, 0, 0);
	j = Locate(&graph, 1, 1, 1, 1);
	//DFS(&graph, i, j);
	BFS(&graph, i, j);
	if(visited[j])
	{
		Print_Path(&graph, i, j);
		cout << "1.5秒后打印路径..." << endl;
		Print_Graph(&graph, i, j);
	}
	return 0;
}