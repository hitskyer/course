#include "MazeApp.h"

using namespace std;

bool CheckAccess(int maze[][6], int m, Pos &next)
{
	int n = 6;
	//int m = sizeof(maze) / sizeof(maze[0]);
	//int n = sizeof(maze[0]) / sizeof(maze[0][0]);
	if(next.row >= 0 && next.col >= 0 &&
		next.row <= m - 1 && next.col <= n - 1)
	{
		if(maze[next.row][next.col] == 1)
			return true;
	}
	return false;
}


void GetMazePath(int maze[][6], int m, AStack<Pos> *ms)
{
	int n = 6;
	//int m = sizeof(maze) / sizeof(maze[0]);
	//int n = sizeof(maze[0]) / sizeof(maze[0][0]);
	Pos EnterPort;
	int nTimes = 0;
	bool isfind;
	while(ms->GetLength() == 0)
	{
		++nTimes;
		isfind = FindMazeEport(maze, m, &EnterPort);
		if(!isfind && nTimes == 1)
			throw(MAZE_NOENTERPORT_ERR);
		else if(!isfind && nTimes != 1)
			throw(MAZE_NOEXPORT_ERR);
		else
		{
			ms->Push(EnterPort); //将入口坐标压栈
			Pos cur = EnterPort;
			Pos next = cur;
			while(true)//保证入口坐标能正常进入循环
			{
				//up
				next.row = cur.row - 1;
				next.col = cur.col;
				if(CheckAccess(maze, m, next))
				{
					maze[next.row][next.col] = 2;
					ms->Push(next);
					cur = next;
					continue;
				}

				//down
				next.row = cur.row + 1;
				next.col = cur.col;
				if(CheckAccess(maze, m, next))
				{
					maze[next.row][next.col] = 2;
					ms->Push(next);
					cur = next;
					continue;
				}

				//left
				next.col = cur.col - 1;
				next.row = cur.row;
				if(CheckAccess(maze, m, next))
				{
					maze[next.row][next.col] = 2;
					ms->Push(next);
					cur = next;
					continue;
				}

				//right
				next.col = cur.col + 1;
				next.row = cur.row;
				if(CheckAccess(maze, m, next))
				{
					maze[next.row][next.col] = 2;
					ms->Push(next);
					cur = next;
					continue;
				}

				//如果找不到出路，就回退一步继续找
				if(next.row < m -1 && next.col < n - 1 &&
					next.row > 0 && next.col > 0)
				{
					ms->Pop();
					cur = *(ms->GetTop());
					continue;

				}
				else
					break;
			}
		}
		//如果回退到入口，将栈清空
		if(ms->GetLength() == 1)
		{
			ms->Pop();
		}
	}
}


bool FindMazeEport(int maze[][6], int m, Pos *EnterPort)
{
	int n = 6;
	//int m = sizeof(maze) / sizeof(maze[0]);
	//int n = sizeof(maze[0]) / sizeof(maze[0][0]);
	for(int i = 0; i< m; ++i)
	{
		if(i == 0 || i == m - 1)
		{
			for(int j = 0; j < n; ++j)
			{
				if(maze[i][j] == 1)
				{
					EnterPort->row = i;
					EnterPort->col = j;
					maze[i][j] = 2;
					return true;
				}
			}
		}
		else
		{
			for(int j = 0; j < n; j += n-1)
			{
				if(maze[i][j] == 1)
				{
					EnterPort->row = i;
					EnterPort->col = j;
					maze[i][j] = 2;
					return true;
				}
			}
		}
	}
	return false;
}


void GetShortPath(int maze[][6], int m, AStack<Pos> *stack)
{

}


void PrintMazePath(AStack<Pos> &stack)
{
	if(stack.Empty())
		std::cout << "No find export frow current maze!" << std::cout << endl;
	else
	{
		std::cout << "I find way to get away from current maze, follow me" << endl;
		while(true)
		{
			std::cout << "(" << stack.GetTop()->row + 1
				<< "," << stack.GetTop()->col + 1<<")";
			stack.Pop();
			if(!stack.GetLength())
				break;
			std::cout << " -> ";
		}
	}
}