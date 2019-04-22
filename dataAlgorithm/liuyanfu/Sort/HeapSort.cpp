/*
* Copyright: (c) 2019
*
* 文件名称:  HeapSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/15  10:51
*/


#include <iostream>
#include <algorithm>
using namespace std;

void print(int *arr, int nLen);
/**
* @brief	  构建最大堆(自底向上构建)
*
* @method:    BigHeap
* @access:    public 
* @param:     int * arr
* @param:     int rootIndex
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/15  10:54 
*/
/*
在二叉树中，若当前节点的下表为i，则其父节点的下标为i/2，其左子节点的下标为2*i，其右子节点的下标为2*i + 1
*/
void BigHeapUp(int *arr, int nLen)
{
	//找到最后一个叶子结点的父节点如果下标从1开始则  
	//最后一个非叶子结点 = 堆的长度 / 2，相应的左叶子结点的下标为2*i,右叶子结点的下标为2*i + 1
	//如果下标从0开始则	最后一个非叶子结点 = 堆的长度 / 2 - 1,
	//相应的左叶子结点的下标为2*i + 1，右叶子结点的下标为2*i + 2
	for(int i = nLen / 2 - 1;i >= 0; --i)
	{
		if(2*i + 1 < nLen && arr[2*i + 1] > arr[i])
			swap(arr[2*i +1], arr[i]);
		if(2*i + 2 < nLen && arr[2*i + 2] > arr[i])
			swap(arr[2*i + 2], arr[i]);
	}
}


/**
* @brief      构建最大堆（自顶向下构建）
*
* @method:    BigHeapDown
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/15  14:16 
*/
void BigHeapDown(int *arr, int nLen, int maxIndex)
{
	int leftchild = 2*maxIndex + 1;
	int rightchild = 2*maxIndex + 2;
	int i = maxIndex;
	if(leftchild < nLen && arr[leftchild] > arr[maxIndex])
	{
		i = leftchild;
	}
	if(rightchild < nLen && arr[rightchild] > arr[maxIndex])
	{
		i = rightchild;
	}
	if(i != maxIndex)
	{
		swap(arr[i], arr[maxIndex]);
		BigHeapDown(arr, nLen, i);
	}
}

/**
* @brief	  堆排序
*
* @method:    HeapSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/15  10:52 
*/
void HeapSort(int *arr, int nLen)
{
	for(int i = nLen;i > 0; --i)
	{
		BigHeapUp(arr, i);
		swap(arr[0], arr[i - 1]);
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
	int arr[10] = {15, 4, 13, 33, 23, 24, 5, 83, 19, 74};
	int arr1[10] = {1,1,1,1,1,1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	HeapSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	HeapSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	HeapSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	return 0;
}