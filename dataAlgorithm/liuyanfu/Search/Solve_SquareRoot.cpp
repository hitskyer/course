/*
* Copyright: (c) 2019
*
* 文件名称:  Solve_SquareRoot.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/18  14:48
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

double SolveSqroot(int n)
{
	double precision = 0.000001;
	double square = 0.0;
	double mid = 0;
	double low = 0.0;
	double high = n;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		square = mid * mid;
		if(abs(square - n) <= precision)
			return mid;
		else if(abs(square - n) > precision && square > n)
			high = mid;
		else
			low = mid;
	}
}

int main()
{
	int InputNum = 0;
	while(scanf_s("%d", &InputNum) && InputNum)
	{
		printf("%d%s%.6lf\n", InputNum, "的平方根为：", SolveSqroot(InputNum));
	}
	return 0;
}