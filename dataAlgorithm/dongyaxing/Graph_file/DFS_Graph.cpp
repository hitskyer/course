/*
* 拓扑排序——DFS
*/
#include <iostream>
#include<vector>
#include<list>
using namespace std;

// 图结构
class Graph
{
public:
	int v;					// 顶点个数
	typedef vector<int>* node;
	node *adj;		// 邻接表
	Graph(int data):v(data)
	{
		adj = new node[v];
		for (int i = 0; i < v; ++i)
		{
			adj[i] = new vector<int>();		// 每个顶点后面跟着一条链
		}
	}
	void addEdge(int s, int t)
	{
		adj[s]->push_back(t);		// s->t, 逆邻接表的话，输入的时候，注意顺序，顶点从0开始
	}
	~Graph()
	{
		for (int i = 0; i < v; ++i)
		{
			delete adj[i];
		}
		delete []adj;
	}

	void print()
	{
		for (int i = 0; i < v; ++i)
		{
			cout << i << " 的入度： " ;
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			std::cout << endl;
		}
	}

	void topoSortByDFS();
	void dfs(int v, vector<int> **adj, bool *visited);
};

void Graph::topoSortByDFS()
{
	bool *visited;
	visited = new bool[6]();		// 只有6个顶点
	for (int i = 0; i < v; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(i, adj, visited);
		}
	}
}

/****************************************************************
* @brief : 		dfs深度优先搜索
* @author : 	dyx
* @date : 		2019/8/28 10:34
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void Graph::dfs(int v, vector<int> **adj, bool *visited)
{
	for (int i = 0; i < adj[v]->size(); ++i)
	{
		int w = adj[v]->at(i);
		if (visited[w] == true)
		{
			continue;
		}
		visited[w] = true;
		dfs(w, adj, visited);
	}
	cout << " -> " << v ;
}

int main()
{
	// 初始化一个拥有6个顶点的有向图
	const int n = 6;
	Graph G(n);	
	// (num1, num2);表示: num1 <- num2,2先于1执行
	G.addEdge(1,0);
	G.addEdge(2,0);
	G.addEdge(4,1);
	G.addEdge(3,1);
	G.addEdge(4,2);
	G.addEdge(5,3);
	G.addEdge(5,4);

	cout << "插入的数据：" << endl;
	G.print();
	cout << "输出topoDFS排序： " << endl;
	G.topoSortByDFS();
//	system("pause");
	return 0;
}
