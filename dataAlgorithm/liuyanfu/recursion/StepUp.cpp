#include <iostream>
#include <windows.h>
#include <map>
using namespace std;

LARGE_INTEGER litmp;
LONGLONG QPart1,QPart2;	
double dfMinus, dfFreq, dfTim;

#define CLOCK_START dfMinus = 0.0;dfFreq = 0.0;dfTim = 0.0; \
	QueryPerformanceFrequency(&litmp);	\
	dfFreq = (double)litmp.QuadPart;	\
	QueryPerformanceCounter(&litmp);	\
	QPart1 = litmp.QuadPart;			


#define CLOCK_END QueryPerformanceCounter(&litmp);	\
	QPart2 = litmp.QuadPart;		\
	dfMinus = (double)(QPart2-QPart1);		\
	dfTim = dfMinus / dfFreq;	

int f(int n)
{
	if(n == 1) 
		return 1;
	else if(n == 2)
		return 2;
	else
		return f(n - 1) + f(n - 2);
}

long long CycleMethod(int n)
{
	long long step, frontstep = 2, frontfrontstep = 1;
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
	{
		for(int i =2; i < n; ++i)
		{
			step = frontstep + frontfrontstep;
			frontfrontstep = frontstep;
			frontstep = step;
		}
		return step;
	}
}


//增加避免重复计算功能的函数
map<int, unsigned long> hasSolveList;
long long fop(int n)
{
	if(hasSolveList.find(n) != hasSolveList.end())
	{
		return hasSolveList[n];
	}
	if(n == 1) 
	{
		hasSolveList[1] = 1;
		return 1;
	}
	else if(n == 2)
	{
		hasSolveList[2] = 2;
		return 2;
	}
	else
	{
		hasSolveList[n] = fop(n - 1) + fop(n - 2);
		return hasSolveList[n];
	}
}

int main()
{
	long long ret = 0;
	map<unsigned long, unsigned long> n_Fn;   //n，f(n)的 k，v 容器
	CLOCK_START
	ret = fop(100);
	CLOCK_END
	cout << "总的走法为：" << ret << endl;
	cout << "运行耗时为：" << dfTim << endl;
	return 0;
}