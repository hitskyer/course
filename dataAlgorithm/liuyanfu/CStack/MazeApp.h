#include <iostream>
#include "AStack.cpp"
#define		MAZE_NOENTERPORT_ERR	0x90000001
#define		MAZE_NOEXPORT_ERR		0x90000002

struct Pos
{
	int row;
	int col;
};

//int Maze[M][N];

bool CheckAccess(int maze[][6], int m, Pos &);
void GetMazePath(int maze[][6], int m, AStack<Pos> *stack);
bool  FindMazeEport(int maze[][6], int m, Pos *EnterPort);
void GetShortPath(int maze[][6], int m, AStack<Pos> *stack);
void PrintMazePath(AStack<Pos> &stack);