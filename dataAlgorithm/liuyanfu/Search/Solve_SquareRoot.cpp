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
/*
（1）对于小于1的数，它的平方根是大于被开方的数比如0.04的平方根是0.2。因此如果n < 1,则其平方根的范围是(n,1)
（2）对于大于1的数，它的平方根是恒小于被开方数的，比如4的平方根是2。因此如果n >= 1，则其平方根的范围是[1,n)
*/
double SolveSqroot(double n)
{
	double precision = 0.0000001;
	double square = 0.0;
	double mid = 0;
	double low = 0.0;
	double high = 0.0;
	if(n < 1)
	{
		low = n;
		high = 1;
	}
	else
	{
		low = 1;
		high = n;
	}
	while(high - low >= precision)
	{
		mid = low + (high - low)/2;
		if(mid * mid == n)
			return mid;
		else if(mid * mid < n)
			low = mid;
		else
			high = mid;
	}
	return low;
}

int main()
{
	double InputNum = 0;
	while(scanf_s("%lf", &InputNum) && InputNum)
	{
		printf("%lf%s%lf\n", InputNum, "的平方根为：", SolveSqroot(InputNum));
	}
	return 0;
}