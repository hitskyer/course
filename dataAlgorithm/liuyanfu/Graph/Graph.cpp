#include "Graph.h"


int main()
{
	Graph grap(8);
	grap.addEdge(0,1);
	grap.addEdge(0,3);
	grap.addEdge(1,2);
	grap.addEdge(1,4);
	grap.addEdge(2,5);
	grap.addEdge(3,4);
	grap.addEdge(4,5);
	grap.addEdge(4,6);
	grap.addEdge(5,7);
	grap.addEdge(6,7);
	grap.DFS(0,6);
	return 0;
}