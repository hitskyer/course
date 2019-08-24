#include<iostream>
using namespace std;

static int *result = new int[8]();
static int count = 0;
// 用一位数组实现棋盘，数组下标表示行，数组值表示该列有值。
// 判断row行，column列放置是否合适
bool isOk(int row, int column)
{
	int leftup = column - 1;		// 左上角
	int rightup = column + 1;		// 右上角
	for(int i = row - 1; i >= 0; --i)	// 逐行往上考察每一行
	{
		if(result[i] == column)		// 第i行的column列有棋子吗？
			return false;
		if(leftup >= 0)			// 考察左上对角线：第i行的column列有棋子吗？
		{
			if(result[i] == leftup)
				return false;
		}
		if(rightup < 8)			// 考察右上角对角线：第i行rightup列有棋子吗？
		{
			if(result[i] == rightup)
				return false;
		}
		--leftup;
		++rightup;
	}
	return true;
}

// 打印出一个二维矩阵
void printQueens(int *result)
{
	for(int row = 0; row < 8; ++row)
	{
		for(int column = 0; column < 8; ++column)
		{
			if(result[row] == column)
				cout << "Q ";
			else
				cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
}

// 回溯查找位置
void cal8queens(int row)
{
	if(row == 8)
	{
		printQueens(result);
		++count;
		return;
	}
	for(int column = 0; column < 8; ++column)
	{
		if(isOk(row, column))	// 满足要求，放置
		{
			result[row] = column;	// row行，放到column列
			cal8queens(row+1);	// 考察下一行
		}
	}
}


int main()
{
	cal8queens(0);
	delete [] result;
	cout << "共有 " << count << " 中放法！" << endl;
	return 0;
}
