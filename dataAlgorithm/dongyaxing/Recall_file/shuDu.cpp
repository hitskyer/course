// 此方法是错误的。没有回溯，就是暴利求解。结果也不对。
#include<iostream>
using namespace std;


static bool sign = false;
static int **sudoku = new int*[9];
void init()
{
	for(int i = 0; i < 9; ++i)
	{
		sudoku[i] = new int[9]();
	}
}

// 判断填在空白位置的数字，在行、列上是否符合要求
bool Judge1(int x, int y, int n)	// 行列，放置n
{
	int i;
	for(i = 0; i < 9; ++i)
	{
		// 判断 列, 否存在此数
		if(sudoku[i][y] == n && i != x)
		{
			return false;
		}
		// 判断 行 ，存在此数
		if(sudoku[x][i] == n && i != y)
		{
			return false;
		}
	}
	return true;
}

// 判断填在空白位置的数字在九宫格之内是否符合要求
bool Judge2(int x, int y, int n)
{
	int xx, yy, i, j;
	xx = x/3;	// 第几行的块 0 1 2
	yy = y/3;	// 第几列的块 0 1 2
	for(i == xx*3; i < xx*3+3; ++i)		// 块内3个行的循环
	{
		for(j = yy*3; j < yy*3+3; ++j)	// 块内3个列的循环
		{
			if(sudoku[i][j] == n)	// 找到此数
			{
				if(i == x && j == y)	// 找到的是n本身
					continue;
				else
					return false;
			}
		}
	}
	return true;
}

// 填充空白数组
bool Fill(int m)
{
	int n, x, y;
	x = m/9;	// 行
	y = m%9;	// 列
	if(m > 80)
	{	
		sign = true;	// 由于程序扫描二维实际是扫描一维，所以会有81。81出局。
		return true;	// 感觉应该是false，而不是true
	}
	if(sudoku[x][y] == 0)
	{
		for(n = 1; n <= 9; ++n)		// n 是要暴利填充的数据
		{
			sudoku[x][y] = n;	// 填充数字
			if(Judge1(x, y, n)&&Judge2(x, y, n))	// 判断此数字是否合理
			{	
			//	sudoku[x][y] = n;       // 填充数字
				if(Fill(m))		// 继续在放下一个位置，递归，最终再依次返回true
					return true;
			}
			sudoku[x][y] = 0;	// 不符合，则重置为0，然后继续判断
		}
	}
	else
		return Fill(m+1);	// 上一个位置已经有值，则填充下一个位置，一行一行的扫描
	return false;
}

void print(int **sudoku)
{
	int i, j;
	for(i = 0; i < 9; ++i)
	{
		for(j = 0; j < 9; ++j)
		{
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Delete()
{
	for(int i = 0; i < 9; ++i)
	{
		delete[]sudoku[i];
		sudoku[i] = NULL;
	}
}

int main()
{
	init();	// 为数独数组开辟空间
	int i, j, k;
	cout << "输入原始数独数据，空白用0代替" << endl;
	for(i = 0; i < 9; ++i)
	{
		for(j = 0; j < 9; ++j)
			cin >> sudoku[i][j];
	}
	//print(sudoku);
	//开始数独函数
	cout << "////////**************///////////" << endl << endl;
	if(Fill(0))	// 从第一个位置开始填充
	{
		for(i = 0; i < 9; ++i)
		{
			for(j = 0; j < 9; ++j)
			{
				cout << sudoku[i][j] << " ";
				if(!((j + 1)%3)) 
				{
					cout << "|";		// 每3个数，打一条线
				}
			}
			cout << endl;
			if(!((i + 1)%3))
			{
				for(k = 0; k < 12; ++k)
                                        cout << "__";
                                cout << endl;
			}
		}
	}
	else
		cout << "该数独无解，请检查输入是否正确！" << endl;
	Delete();
	return 0;
}

/*
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0 
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0 
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

0 0 0 0 0 1 2 0 0 
0 6 0 0 5 0 0 0 7
0 0 0 3 0 0 0 0 4
0 0 0 4 0 0 0 3 0
0 0 0 0 0 2 1 0 0 
0 0 8 0 7 0 0 0 6
0 9 2 0 0 0 0 0 0
7 8 0 0 0 0 0 0 5
6 0 5 0 9 0 0 0 0
 
*/
