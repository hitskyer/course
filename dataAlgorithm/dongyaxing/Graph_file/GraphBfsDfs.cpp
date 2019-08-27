/*
* 广度优先搜索：
	每个顶点都要进出一遍队列，每个边也都会被访问一次，所以
	时间复杂度O(V+E)
	主要消耗内存的是visited、prev数组、queue队列，所以
	空间复杂度O(V)

* 深度优先搜索：
	每条边最多会被访问两次，一次遍历，一次回退，所以
	时间复杂度O(E)，E表示边的个数
	主要消耗内存的是visited、prev数组和递归调用栈，
	visited、prev数组的大小跟顶点个数V有关，递归深度不会超过顶点个数V，所以
	空间复杂度O(V)
*/
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
	typedef std::vector<int>* pVector;	// 存储该点的其他油连接的点
public:
	// 构造函数
	Graph(int nCount)
	{
		count = nCount;
		adj = new pVector[count];
		for (int i = 0; i < count; ++i)
		{
			adj[i] = new std::vector<int>();
		}
	}
	// 析构函数
	~Graph()
	{
		for (int i = 0; i < count; ++i)
		{
			delete adj[i];
			adj[i] = NULL;
		}
		delete []adj;
		adj = NULL;
	}

	// 广度优先搜索
	void BFS(int start, int end)
	{
		if(start == end)
			return;
		bool *visited = new bool[count];		// false - 未访问过；true - 访问过
		memset(visited, 0, sizeof(bool)*count);
		visited[start] = true;
		std::queue<int> que;
		que.push(start);
		int *prev = new int[count];			// 记录前驱结点
		for (int i = 0; i < count; ++i)
		{
			prev[i] = -1;
		}
		while(!que.empty())
		{
			int w = que.front();
			que.pop();
			for (int i = 0; i < adj[w]->size(); ++i)
			{
				int q = adj[w]->at(i);
				if (!visited[q])
				{
					prev[q] = w;
					if (q == end)
					{
						print(prev, start, end);
						return;
					}
					visited[q] = true;
					que.push(q);
				}
			}
		}
		delete []visited;
		delete []prev;
	}

	// 深度优先搜索
	void DFS(int start, int end)
	{
		found = false;
		bool *visited = new bool[count];
		memset(visited, 0, sizeof(bool)*count);
		int *prev = new int[count];
		for (int i = 0; i < count; ++i)
		{
			prev[i] = -1;
		}
		recurDfs(start, end, visited, prev);
		print(prev, start, end);
	}

	// 增加边（无向图）
	void addEdge(int start, int end)
	{
		adj[start]->push_back(end);
		adj[end]->push_back(start);
	}

	// 打印输出图
	void printGraph()
	{
		for (int i = 0; i < count; ++i)
		{
			cout << i << "->";
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

private:
	int count;		// 图的顶点
	pVector* adj;	// 图的边链表
	bool found;
	// 递归打印
	void print(int *arr, int start, int end)
	{
		if (arr[end] != -1 && end != start)
		{
			print(arr, start, arr[end]);
		}
		if (arr[end] != -1)
		{
			std::cout << arr[end] << "->";
		}
	}

	// DFS搜索
	void recurDfs(int w, int target, bool *visited, int *prev)
	{
		if (found == true)
		{
			return;
		}
		visited[w] = true;
		if(w == target)
		{
			found = true;
			return;
		}
		for (int i = 0; i < adj[w]->size(); ++i)
		{
			int q = adj[w]->at(i);
			if (!visited[q])
			{
				prev[q] = w;
				recurDfs(q, target, visited, prev);
			}
		}
	}
};

int main()
{
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,5);
	g.addEdge(3,4); 
	g.addEdge(4,5);
	g.addEdge(4,6);
	g.addEdge(5,7);
	g.addEdge(6,7);
	g.printGraph();		// 查看图建立的是否正确
	cout << "查找从0到6的路径，并输出。" << endl;
	cout << "深度优先搜索：" << endl;
	g.DFS(0,6);			// 查找从0到6的路径，并输出
	cout << endl;
	cout << "广度优先搜索：" << endl;
	g.BFS(0,6);
	cout << endl;
//	system("pause");
	return 0;
}
