/*
* Copyright: (c) 2019
*
* 文件名称:  Timer.h	
* 文件标识：
* 摘	要： 好用的计时器
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/15  18:20
*/

#ifndef _TIMER_H
#define _TIMER_H

#include <windows.h>

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

#endif // _TIMER_H