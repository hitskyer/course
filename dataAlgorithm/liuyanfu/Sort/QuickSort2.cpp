/*
* Copyright: (c) 2019
*
* 文件名称:  QuickSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/18  13:45
*/

#include <iostream>
#include <algorithm>
using namespace std;

/**
* @brief
*
* @method:    partition
* @access:    public 
* @param:     int * arr
* @param:     int begin
* @param:     int end
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/18  14:17 
*/
int partition(int *arr, int begin, int end)
{
	int pivot = arr[end];
	int i = begin;
	for(int j = begin; j < end; ++j)
	{
		if(arr[j] < pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[end]);
	return i;
}


/**
* @brief
*
* @method:    divide
* @access:    public 
* @param:     int * arr
* @param:     int begin
* @param:     int end
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  14:16 
*/
void divide(int *arr, int begin, int end)
{
	if(begin >= end)
		return;
	else
	{
		int pivot = partition(arr, begin, end);
		divide(arr, begin, pivot - 1);
		divide(arr, pivot + 1, end);
	}
}


/**
* @brief
*
* @method:    quicksort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  14:16 
*/
void quicksort(int *arr, int nLen)
{
	divide(arr, 0, nLen - 1);
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  14:16 
*/
void print(int *arr, int nLen)
{
	for(int i = 0; i < nLen; ++i)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}

int main()
{
	int arr[10] = {5, 4, 6, 3, 3, 2, 5, 8, 9, 7};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	int arr4[10] = {6,6,6,6,6,6,6,6,6,7};
	/*print(arr, sizeof(arr)/sizeof(arr[0]));
	quicksort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	quicksort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	quicksort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	quicksort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	cout << endl;*/

	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	quicksort(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}