#include "Graph_Matrix.h"
#include <iostream>

void Graph_Matrix::BFS(int start)
{
	visited[start] = true;
	std::cout << "start position " << start << std::endl;
	std::queue<int> que;
	que.push(start);
	while(!que.empty())
	{
		int q = que.front();
		que.pop();
		for(int i = 0; i < count; ++i)
		{
			if(!visited[i] && adj[q]->at(i) == 1)
			{
				std::cout << "visit: " << i << std::endl;
				visited[i] = true;
				que.push(i);
			}
		}
	}
}


void Graph_Matrix::DFS(int start)
{
	visited[start] = true;
	std::cout << "visit: " << start << std::endl;
	for(int i = 0; i < count; ++i)
	{
		if(!visited[i] && adj[start]->at(i) == 1)
			DFS(i);
	}
}


void Graph_Matrix::addEdge(int row, int col)
{
	adj[row]->at(col) = 1;
	adj[col]->at(row) = 1;
}


void Graph_Matrix::DFS_Nr(int start)
{
	visited[start] = true;
	std::cout << "visit: " << start << std::endl;
	std::stack<int> st;
	st.push(start);
	bool is_push;
	while(!st.empty())
	{
		is_push = false;
		int top = st.top();
		for(int i = 0; i < count; ++i)
		{
			if(!visited[i] && adj[top]->at(i) ==1)
			{
				visited[i] = true;
				std::cout << "visit: " << i << std::endl;
				st.push(i);
				is_push = true;
				break;
			}
		}
		if(!is_push)
			st.pop();
	}
}