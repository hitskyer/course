#ifndef _GRAPH_MATRIX_H
#define _GRAPH_MATRIX_H

#include <vector>
#include <stack>
#include <queue>

class Graph_Matrix
{
	typedef std::vector<int>* pVector;
public:
	Graph_Matrix(int nCount)
	{
		count = nCount;
		visited.assign(count, false);
		adj = new pVector[count];
		for(int i = 0; i < count; ++i)
		{
			adj[i] = new std::vector<int>(count, 0);
		}
	}

	~Graph_Matrix(void)
	{
		delete adj;
	}
	
	void BFS(int start);
	void DFS(int start);
	void DFS_Nr(int start);
	void addEdge(int row, int col);
private:
	int count;
	pVector* adj;
	std::vector<bool> visited;
};

#endif //_GRAPH_MATRIX_H
