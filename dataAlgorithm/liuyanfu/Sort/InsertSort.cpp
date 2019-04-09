/*
* Copyright: (c) 2019
*
* 文件名称:  InsertSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/9  11:21
*/
#include <iostream>
using namespace std;
typedef size_t UINT;

/**
* @brief	  插入排序
*
* @method:    InsertSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  11:22 
*/
//认为左端为已经排序的序列，右端为待排序的序列。
void InsertSort(int *arr, int nLen)
{
	int temp = 0;
	for(int i = 1; i< nLen; ++i)
	{
		temp = arr[i];//将待插入的元素保存起来
		int j = i - 1;
		for(; j >= 0; --j)//
		{
			if(arr[j] > temp)//如果前边的元素大，直接将前边的元素赋值给其后边的元素
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = temp;//当第j个元素小于等于待插入的元素时，直接将第j+1个元素赋值为待插入的元素
	}
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @param:     int arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  11:08 
*/
void print(int *arr, int nLen)
{
	for(int i = 0;i < nLen; ++i)
	{
		cout << arr[i] << " ";
	}
	cout <<	endl;
}

int main()
{
	int arr[10] = {5, 4, 6, 3, 3, 2, 5, 8, 9, 7};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	InsertSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	InsertSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	InsertSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}