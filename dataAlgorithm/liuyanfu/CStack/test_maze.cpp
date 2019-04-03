#include <iostream>
#include "MazeApp.h"


using namespace std;


int Maze[6][6] = {{0,0,0,0,0,0},
				  {0,0,1,0,0,0},
				  {0,0,1,0,0,0},
				  {0,0,1,1,1,0},
				  {0,0,1,0,1,1},
				  {0,0,1,0,0,0}};

int main()
{
	AStack<Pos> pstk;
	GetMazePath(Maze, 6, &pstk);
	PrintMazePath(pstk);
	return 0;
}