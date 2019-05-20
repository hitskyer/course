/*
* Copyright: (c) 2019
*
* 文件名称:  ACM2785_2.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/17  10:24
*/
#include <stdio.h>
#include <algorithm>
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int sum1[16000001];
int sum2[16000001];


//lower_bound(begin,end,num)找到第一个大于或者等于num的数字，找到后返回该数字的地址，不存在返回end
//upper_bound(begin,end,num)找到第一个大于num的数字，找到返回该数字的地址，不存在则返回end
//lower_bound和upper_bound都是利用二分查找的方法在一个排好的数组进行查找
int main()
{
	int row;
	while(~scanf("%d", &row))
	{
		for(int i = 0; i < row; ++i)//n
		{
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		int r = 0;
		for(int i = 0; i < row; ++i)//n^2
		{
			for(int j = 0; j < row; ++j)
			{
				sum1[r++] = A[i] + B[j];
				sum2[r - 1] = C[i] + D[j];
			}
		}
		int ans = 0;
		std::sort(sum1, sum1 + r);//nlogn
		for(int i = 0; i < r; ++i)//n * nlogn
		{
			ans += std::upper_bound(sum1, sum1 + r, -sum2[i]) - std::lower_bound(sum1, sum1 + r, -sum2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}