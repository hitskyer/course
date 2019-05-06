/*
* Copyright: (c) 2019
*
* 文件名称:  UpStair.cpp	
* 文件标识：
* 摘	要： 走台阶问题
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/23  9:45
*/

#include <iostream>
#include <windows.h>
using namespace std;

/*
问题描述：假设有n个台阶，每跨一步只能向上1个或者2个台阶。求出上这n个台阶有多少种走法
思路：
（1）采用递归的方式进行求解f(n)，因为一步可以上1个或者2个台阶，
	 所以当先上1个时则剩下n-1个台阶，先上2个时则剩下n-2个台阶，因此f(n) = f(n - 1) + f(n - 2)(n > 2)
*/

/*
* @brief	利用递归解决该问题
*
* @method:    SolveStep
* @access:    public 
* @param:     size_t nStair
* @Return:    size_t
* @author:    RF_LYF
* @since:   2019/4/23  9:57 
*/
//该方法，当台阶的个数超过一定值得时候，求解速度很慢
DWORD SolveStep(size_t nStair)
{
	if(nStair <= 0)
		return 0;
	else if(nStair < 3 && nStair > 0)
		return nStair;
	else
		return SolveStep(nStair - 1) + SolveStep(nStair -2);
}


/**
* @brief	由于上一种方法中，好多结果被重复计算了很多遍，所以很影响执行效率，
*			比如f(5) = f(4) + f(3);而f(4) = f(3) + f(2); f(3) = f(2) + f(1);这其中f(4)和f(3)都要被计算2次
*			因此本函数采用自顶向下的动态规划方式进行求解
*
* @method:    SolveStepOpti
* @access:    public 
* @param:     size_t nStair
* @param:     int * Counter
* @Return:    ULONG
* @author:    RF_LYF
* @since:   2019/4/23  10:33 
*/
DWORD SolveStepOpti(size_t nStair, int *Counter)
{
	if(0 !=Counter[nStair])
		return Counter[nStair];
	if(nStair <= 0)
		return 0;
	else if(nStair > 0 && nStair < 3)
	{
		return Counter[nStair] = nStair;
	}
	else
	{
		Counter[nStair] = SolveStepOpti(nStair - 1, Counter) + SolveStepOpti(nStair - 2, Counter);
		return Counter[nStair];
	}
}


/**
* @brief	利用循环求解问题，自底向上的动态规划求解问题
*
* @method:    SolveStepOpti2
* @access:    public 
* @param:     size_t nStair
* @Return:    DWORD
* @author:    RF_LYF
* @since:   2019/4/23  10:52 
*/
DWORD SolveStepOpti2(size_t nStair)
{
	if(nStair <= 0)
		return 0;
	else
	{
		DWORD step = 0;
		DWORD fstep = 1;
		DWORD ffstep = 0;
		for(size_t i = 1; i <= nStair; ++i)
		{
			step = fstep + ffstep;
			ffstep = fstep;
			fstep = step;
		}
		return step;
	}
}

/*
走台阶问题的变形问题，还是n个台阶，同样每次跨步可以上1个台阶或者2个台阶，现在指定第一次跨步时跨的是左脚，
那么当走完第n个台阶正好跨的是左脚的走法有多少种？
问题分析：该问题实际上求的是，当走n个台阶用奇数次走完，有多少种走法
*/


/**
* @brief	 递归法实现
*
* @method:    SolveStepOddEven
* @access:    public 
* @param:     int nStair
* @param:     size_t nStep(用来记录步数)
* @param:     DWORD& nCountOdd(用来记录奇数次走法的数目)
* @param:     DWORD& nCountEven(用来记录偶数次走法的数目)
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/23  11:28 
*/
void SolveStepOddEven(int nStair, size_t nStep, DWORD& nCountOdd, DWORD& nCountEven)
{
	
	if(nStair < 0)
		return;
	else if(nStair == 0)
	{
		if(nStep % 2 == 1)
			++nCountOdd;
		else
			++nCountEven;
		return;
	}
	else
	{
		++nStep;
		SolveStepOddEven(nStair - 1, nStep, nCountOdd, nCountEven);
		SolveStepOddEven(nStair - 2, nStep, nCountOdd, nCountEven);
	}
}


/**
* @brief	动态规划 + 循环方法
*
* @method:    SolveStepOddOpti
* @access:    public 
* @param:     int nStair
* @param:     DWORD& nCountOdd(用来记录奇数次走法的数目)
* @param:     DWORD& nCountEven(用来记录偶数次走法的数目)
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/23  14:05 
*/
void SolveStepOddEvenOpti(int nStair, DWORD& nCountOdd, DWORD& nCountEven)
{
	if(nStair <= 0)
		return;
	else if(nStair == 1)
	{
		nCountOdd = 1;
		nCountEven = 1;
	}
	else
	{
		DWORD *pFOdd = new DWORD[nStair + 1];
		DWORD *pFEven = new DWORD[nStair + 1];
		pFOdd[0] = 0,pFOdd[1] = 1;
		pFEven[0] = 1,pFEven[1] = 0;
		for(int i = 2; i <= nStair; ++i)
		{
			pFOdd[i] = pFEven[i - 1] + pFEven[i - 2];
			pFEven[i] = pFOdd[i - 1] + pFOdd[i - 2];
		}
		nCountOdd = pFOdd[nStair];
		nCountEven = pFEven[nStair];
		delete []pFOdd;
		delete []pFEven;
	}
}


/*
台阶问题升级，一个台阶总共有n级，如果每次可以跳1阶，2阶……n阶，求总共有多少种跳法？
问题分析：
（1）当有1个台阶时f(1) = 1
（2）当有2个台阶时f(2) 分为2种方式，第一种跳1阶剩下f(1)种跳法，第二种跳2阶只有1种跳法，因此
		f(2) = f(2 - 1) + f(2 -2) = f(1) + 1
（3）当有3个台阶时f(3) 分为3种方式，第1种先跳1阶剩下f(2)种跳法，第2种先跳2阶剩下f(1)种跳法，第3种先跳3阶只有一种跳法，因此
		f(3) = f(2) + f(1) + f(0) 
（4）当有4个台阶时f(4) 分为4种方式，第1种先跳1阶剩下f(3)种跳法，第2种先跳2阶剩下f(2)种跳法，第3种先跳3阶剩下f(1)种跳法，
	 第4种先跳4阶只有一种跳法，因此f(4) = f(3) + f(2) + f(1) + f(0)
（5）当有n个台阶时，则满足f(n) = f(n-1)+ f(n-2) + f(n-3) + ……+ f(1) + f(0)
（6）当n-1个台阶时，f(n-1) = f(n-2) + f(n-3) + ……+ f(0)
（7）f(n) - f(n-1) = f(n-1),则有f(n) = 2f(n-1),该公式则为递推公式
*/

long long SolveStepUpdate(int nStair)
{
	if(nStair <= 0)
		return 0;
	else if(nStair == 1)
		return 1;
	else
	{
		long long step = 0;
		long long fstep = 1;
		for(int i = 2; i <= nStair; ++i)
		{
			step = 2 * fstep;
			fstep = step;
		}
		return step;
	}
}
int main()
{
	size_t nStairNum = 0;
	while(cin >> nStairNum && nStairNum)
	{
		//int *p = new int[nStairNum + 1];
		//memset(p, 0, sizeof(int) * (nStairNum + 1));
		/*cout<< nStairNum << "个台阶有" << SolveStep(nStairNum) << "种走法" << endl;*/
		//cout<< nStairNum << "个台阶有" << SolveStepOpti(nStairNum, p) << "种走法" << endl;
		//cout<< nStairNum << "个台阶有" << SolveStepOpti2(nStairNum) << "种走法" << endl;
		//delete []p;

		/*DWORD nCountOdd = 0;
		DWORD nCountEven = 0;
		SolveStepOddEven(nStairNum, 0, nCountOdd, nCountEven);
		cout<< nStairNum << "个台阶奇数次走法有" << nCountOdd << "种走法" << endl;
		cout<< nStairNum << "个台阶偶数次走法有" << nCountEven << "种走法" << endl;*/
		cout<< nStairNum << "个台阶有" << SolveStepUpdate(nStairNum) << "种走法" << endl;
		
	}
	return 0;
}