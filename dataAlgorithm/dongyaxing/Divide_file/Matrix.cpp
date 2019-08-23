#include<iostream>
#include<stdio.h>
#include<cstdlib>

using namespace std;

// 计算二维矩阵的乘积，时间复杂度O(n^3)
void matrix_product(int **matx1, int **matx2, int **matx3, int len)
{
	int i,j,k;
	for(i = 0; i < len; ++i)		// i 行
	{
		for(j = 0; j < len; ++j)	// j 列
		{
			matx3[i][j] = 0;
			for(k = 0; k < len; ++k)	// k 列
			{
				matx3[i][j] += matx1[i][k] * matx2[k][j];
			}
		}
	}
}

// 打印输出二维数组
void print(int **matx, int len)
{
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < len; ++j)
		{
			cout << matx[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

// 初始化数组
void init(int **matx, int len)
{
	for(int i = 0; i < len; ++i)
        {
                for(int j = 0; j < len; ++j)
                {
                        matx[i][j] = (rand()%30 + 1);
                }
        }
}

// 删除二维矩阵
void Delete(int **matx, int len)
{
	for(int i = 0; i < len; ++i)
        {
                delete [] matx[i];
        }
}

int main()
{
	const int m = 6;
	
	int **matrix1 = new int* [m];
	int **matrix2 = new int* [m];
	int **matrix3 = new int* [m];
	for(int i = 0; i < m; ++i)
	{
		matrix1[i] = new int[m]();
		matrix2[i] = new int[m]();
		matrix3[i] = new int[m]();
	}
	
	init(matrix1, m);
	init(matrix2, m);
	
	cout << "矩阵1：" << endl;
	print(matrix1, m);
	cout << "矩阵2：" << endl;
	print(matrix2, m);
	
	matrix_product(matrix1, matrix2, matrix3, m);
	cout << "矩阵乘积结果： " << endl;
	print(matrix3, m);

	
	Delete(matrix1, m);
	Delete(matrix2, m);
	Delete(matrix3, m);
	return 0;
}
