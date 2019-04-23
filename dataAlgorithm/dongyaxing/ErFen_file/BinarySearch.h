#ifndef _BIANRY_SEARCH_H
#define _BIANRY_SEARCH_H

#include <iostream>
using namespace std;

/********************************************************************
* @brief : 		二分查找，在有序数组中，查找val。数据有序，且无重复
* @author : 	dyx
* @date : 		2019/4/19 16:33
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch(int *arr, int len, int val)
{
	int low = 0;
	int high = len;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		if (arr[mid] == val)
		{
			return mid;
		}
		else if (arr[mid] > val)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/********************************************************************
* @brief : 		公式法，求val的平方根，保留6位小数,精度不好确定
*					用 i控制循环次数，不ok。用差值，也不ok
* @author : 	dyx
* @date : 		2019/4/19 18:03
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
double Squre(double a)
{
	double x;
	int i = 15;
	x = a/2;
	while(true)
	{
		x = (x + a/x)/2;
		if (abs(a - x*x) < 0.00000001)
		{
			break;
		}
	}
	return x;
}

/********************************************************************
* @brief : 		二分查找发求一个大于0的val的平方根，保留6位小数
* @author : 	dyx
* @date : 		2019/4/22 10:59
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
double FindRoot(double val)
{
	double low;
	double high;
	double mid;
	if (val < 0)
	{
		return -1;
	}
	else if (val < 1)
	{
		low = 0.0;
		high = 1.0;
		while(high - low > 0.000001)
		{
			mid = low + (high - low) / 2;
			if(mid * mid > val)
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
	}
	else
	{
		low = 1.0;
		high = val;
		while(high - low > 0.000001)	// 保留六位
		{
			mid = low + (high - low)/2;
			if(mid * mid > val)
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
	}
	return mid;
}

/********************************************************************
* @brief : 		数据有序，查找第一个给定值val——顺序扫描法，
*												适用于重复数据少的情况
* @author : 	dyx
* @date : 		2019/4/22 11:10
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch_1(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		if (arr[mid] == val)
		{
			if (mid == 0)
			{
				return mid;
			}
			else
			{
				--mid;
				while(arr[mid] == val && mid >=0)
				{
					--mid;
				}
				return ++mid;
			}
		}
		else if (arr[mid] > val)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/********************************************************************
* @brief : 		数据有序，查找第一个给定值val——嵌套二分查找法，
*											适用于重复数据多的情况
* @author : 	dyx
* @date : 		2019/4/22 11:24
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch_2(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		if (arr[mid] == val)
		{
			if (mid == 0 || arr[mid - 1] != val)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if (arr[mid] > val)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/********************************************************************
* @brief : 		二分查找，查找最后一个值，等于给定值
* @author : 	dyx
* @date : 		2019/4/22 11:37
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch_3(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		if (arr[mid] == val)
		{
			if (mid == len - 1 || arr[mid + 1] != val)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else if (arr[mid] > val)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/********************************************************************
* @brief : 		二分查找，查找第一个大于等于给定值的元素
* @author : 	dyx
* @date : 		2019/4/22 11:40
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch_4(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)/2;
		if (arr[mid] >= val)
		{
			if (mid == 0 || arr[mid - 1] < val)
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

/********************************************************************
* @brief : 		二分查找，查找最后一个小于等于给定值的数
* @author : 	dyx
* @date : 		2019/4/22 13:40
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
int BioSearch_5(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] <= val)
		{
			if (mid == len - 1 || arr[mid + 1] > val)
			{
				return mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
//靠靠靠
//2019/4/23
//dyx
//
int BioSearch_6(int *arr, int len, int val)
{
	int low = 0;
	int high = len - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = low + ((high - low) /2 );
		if (arr[low] < arr[mid])
		{
			low = mid;
		}
		else if(arr[low] > arr[mid])
		{
			high = mid;
		}
		else
		{
			mid = low;
			break;
		}
	}
	low = 0;
	high = mid;
	int low_2 = mid +1;
	int high_2 = len - 1;
	int mid_2 = 0;
	if (val <= arr[mid] && val >= arr[low])
	{
		while(low <= high)
		{
			mid = low + (high - low)/2;
			if (arr[mid] == val)
			{
				return mid;
			}
			else if (arr[mid] > val)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	else
	{
		while(low_2 <= high_2)
		{
			mid_2 = low_2 + (high_2 - low_2)/2;
			if (arr[mid_2] == val)
			{
				return mid_2;
			}
			else if (arr[mid_2] > val)
			{
				high_2 = mid_2 - 1;
			}
			else
			{
				low_2 = mid_2 + 1;
			}
		}
	}
	return -1;
}



#endif
