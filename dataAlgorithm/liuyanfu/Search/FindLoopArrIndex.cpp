/*
* Copyright: (c) 2019
*
* 文件名称:  FindLoopArrIndex.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/23  23:03
*/

#include <iostream>
using namespace std;

/**
* @brief	将循环有序数组分成多个有序数组再分别进行二分
*
* @method:    FindLoopArrValue
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/23  23:04 
*/
int FindLoopArrValue(int *arr, int nLen, int value)
{
	int low = 0;
	int high = nLen - 1;
	int mid = 0;
	while(low <= high)
	{
		mid = low + ((high - low) >> 1);
		if(arr[mid] == value)
			return mid;
		if(arr[low] <= arr[mid])//证明左边有序
		{
			if(arr[low] <= value && arr[mid] > value)
				high = mid - 1;
			else
				low = mid + 1;
		}
		else//(mid, high)是有序的，因为当arr[left] > arr[mid]时，mid肯定在最大值位置的后边
		{
			if(arr[mid] < value && arr[high] >= value)
				low = mid + 1;
			else
				high = mid - 1;
		}

	}
	return -1;
}


int main()
{
	int arr[] = {4,5,6,7,8,1,2,3};
	cout << FindLoopArrValue(arr, 8, 2) << endl;
	return 0;
}