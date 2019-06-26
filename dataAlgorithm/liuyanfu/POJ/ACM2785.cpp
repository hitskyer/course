/*
* Copyright: (c) 2019
*
* 文件名称:  ACM2785.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/16  8:00
*/
#include <stdio.h>
#include <algorithm>
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int sum1[16000001];
int sum2[16000001];
int ans ,r;
void find(int value)
{
	int low = 0, high = r - 1;
	int mid = 0;
	while(low < high)//保证找到第一个与传入值相等的位置
	{
		mid = low + (high - low) / 2;
		if(sum1[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	while(sum1[low] == value && low < r)
	{
		ans++;
		low++;
	}
}
int main()
{
	int row;
	while(~scanf("%d", &row))
	{
		for(int i = 0; i < row; ++i)//n
		{
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		r = 0;
		for(int i = 0; i < row; ++i)//n^2
		{
			for(int j = 0; j < row; ++j)
			{
				sum1[r++] = A[i] + B[j];
				sum2[r - 1] = C[i] + D[j];
			}
		}
		ans = 0;
		std::sort(sum1, sum1 + r);//nlogn
		for(int i = 0; i < r; ++i)//n * nlogn
		{
			find(-sum2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}