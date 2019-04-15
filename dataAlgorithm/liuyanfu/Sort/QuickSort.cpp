/*
* Copyright: (c) 2019
*
* 文件名称:  QuickSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/10  13:02
*/


#include <iostream>
#include <algorithm>
using namespace std;


void print(int *arr, int nLen);

/**
* @brief	  第一版
*
* @method:    Partition
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int * sentinel
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/10  17:24 
*/
void Partition(int *arr, int left, int right, int *sentinel)
{
	int mid = (left + right)/2;//选取哨兵的方式
	if(arr[left] > arr[mid])
		swap(arr[left], arr[mid]);
	if(arr[mid] > arr[right])
		swap(arr[mid], arr[right]);
	if(arr[mid] > arr[left])
		swap(arr[mid], arr[left]);
	int temp = arr[left];

	int lf = left + 1;
	int rg = right;
	while(lf < rg)
	{
		while(arr[lf] <= temp && lf < rg)
			lf++;
		while(arr[rg] > temp && lf < rg)
			rg--;
		if(lf >= rg)
			break;
		swap(arr[lf++], arr[rg--]);
	}
	while(arr[lf] >= temp && lf >left)
		--lf;
	swap(arr[lf], arr[left]);
	*sentinel = lf;
}


/**
* @brief	  optimization1
*
* @method:    PartitionOpti
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int * sentinel
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/10  22:07 
*/
void PartitionOpti(int *arr, int left, int right, int *sentinel)
{
	int mid = (left + right) / 2;
	if(arr[left] > arr[mid])
		swap(arr[left], arr[mid]);
	if(arr[mid] > arr[right])
		swap(arr[mid], arr[right]);
	if(arr[mid] > arr[left])
		swap(arr[left], arr[mid]);

	int lf = left;
	int rg = right;
	while(lf != rg)
	{
		while(arr[rg] >= arr[left] && lf != rg)
			--rg;
		while(arr[lf] <= arr[left] && lf != rg)
			++lf;
		if(lf != rg)
			swap(arr[lf], arr[rg]);
	}
	swap(arr[rg], arr[left]);
	*sentinel = rg;
}


/**
* @brief
*
* @method:    PartitionOpti2
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int * sentinel
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/10  22:24 
*/
void PartitionOpti2(int *arr, int left, int right, int *sentinel, int *offset)
{
	int mid = (left + right) / 2;
	if(arr[left] > arr[mid])
		swap(arr[left], arr[mid]);
	if(arr[mid] > arr[right])
		swap(arr[mid], arr[right]);
	if(arr[mid] > arr[left])
		swap(arr[left], arr[mid]);

	int lf = left;
	int rg = right;
	while(lf != rg)
	{
		while(arr[rg] >= arr[left] && lf != rg)
			--rg;
		while(arr[lf] < arr[left] && lf != rg)
			++lf;
		if(lf != rg)
			swap(arr[lf], arr[rg]);
	}
	swap(arr[rg], arr[left]);
	*sentinel = rg;
	int nCount = 0;
	while(arr[*sentinel] == arr[rg++])
		++nCount;
	*offset = nCount;
	
}


/**
* @brief	  分割区间
*
* @method:    Separate
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/10  15:58 
*/
void Separate(int *arr, int left, int right)
{
	if(left >= right)
		return;
	else
	{
		int sentinel = 0;
		int offset = 0;
		PartitionOpti2(arr, left, right, &sentinel, &offset);
		Separate(arr, left, sentinel);
		Separate(arr, sentinel + offset, right);
	}
}

/**
* @brief	  快速排序（自顶向下）
*
* @method:    QuickSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/10  15:57 
*/
void QuickSort(int *arr, int nLen)
{
	Separate(arr, 0, nLen - 1);
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
	QuickSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	QuickSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	QuickSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	QuickSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}