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
			adj[i] = new vector<int>;		// 每个顶点后面跟着一条链
		}
	}
	void addEdge(int s, int t)
	{
		adj[s-1]->push_back(t);		// 以s为顶点，t接在s后面
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
			cout << i+1 << " 的入度： " ;
			for (int j = 0; j < adj[i]->size(); ++j)
			{
				cout << adj[i]->at(j) << " ";
			}
			std::cout << endl;
		}
	}
};

// 先找一个入度为0的点。打印输出
// 且把此点删除（标记）
// 循环输出所有点
void topoSortByKahn(int v, vector<int>* *adj)
{
	int *inDegree = new int[v]();		// 统计每个顶点的入度,初始化为0
	for (int i = 0;  i < v; ++i)
	{
		for (int j = 0; j < adj[i]->size(); ++j)
		{
			int w = adj[i]->at(j);		// i->w
			if (w != 0)
			{
				inDegree[(w-1)]++;			// w为具体的值，所以当索引使用时，需要-1
			}
		}
	}

	std::list<int> queue;
	for (int i = 0; i < v; ++i)
	{
		if (inDegree[i] == 0)
		{
			queue.push_back(i);		// 记录入度为0的顶点的索引
		}
	}

	while (!queue.empty())		// 入度为0的顶点，非空
	{
		int i = queue.front();	// 取出第一个入度为0索引
		cout << " <- " << i+1 << endl;		// 输出值
		queue.remove(i);	// 删除第一个入度为0的索引
		for (int j = 0; j < adj[i]->size(); ++j)	// 查找i后面的指向i的顶点
		{
			int k = adj[i]->at(j);		// k为值
			inDegree[(k-1)]--;
			if (inDegree[(k-1)] == 0)
			{
				queue.push_back(k-1);		// 压进去的依然是索引
			}
		}
		cout << endl;
	}
}


int main()
{
	// 初始化一个拥有6个顶点的有向图
	const int n = 6;
	Graph G(n);	
	// (num1, num2);表示: num1 <- num2, 
	G.addEdge(1,0);
	G.addEdge(2,1);
	G.addEdge(5,2);
	G.addEdge(3,1);
	G.addEdge(4,2);
	G.addEdge(5,3);
	G.addEdge(6,5);
	G.addEdge(6,4);
	cout << "插入的数据：" << endl;
	G.print();
	cout << "输出topo排序： " << endl;
	topoSortByKahn(G.v, G.adj);
//	system("pause");
	return 0;
}
