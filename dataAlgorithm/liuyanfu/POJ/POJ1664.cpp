/*
* Copyright: (c) 2019
*
* 文件名称:  POJ1664.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/15  20:40
*/



//其中苹果的个数n，盘子的个数m
//分为以下几种情况
//（1）当只有1个苹果或者只有1个盘子时或者没有苹果时只有一种方法
//（2）当n < m 时实际上就变成了n个苹果放在n个盘子中的问题，即f(n,n)
//（3）当n == m 时分为两种方法，第一至少有一个盘子为空的放法f(n,m-1)，第二种一个盘子放一个
//（4）当n > m 时分为两种放法，第一种至少有一个盘子为空的放法，第二种一个盘子放一个剩下的n-m个放在m个盘子中f(n-m,m)
#include <iostream>

using namespace std;
int f(int M,int N)

{
	if(M == 1 || N == 1 || M == 0)
		return 1;
	if(M < N)
		return f(M, M);
	else
		return f(M, N-1) + f(M-N,N);
}

int main()

{
	int Num,M,N;
	cin >> Num;
	while(Num--)
	{
		cin >> M >> N;
		cout << f(M, N) << endl;
	}
	return 0;
}
