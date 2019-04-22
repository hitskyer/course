#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <vector>
#define NUM_SIZE 500		// 需要排序数字数量
#define BUCKET_NUM 10		// 10个桶
using namespace std;
/********************************************************************
* @brief : 		用于桶排序
* @author : 	dyx
* @date : 		2019/4/19
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
struct ListNode
{
	ListNode* pNext;
	int mData;
};

class SortClass
{
//private:
public:
	int arr[NUM_SIZE];
	int temparr[NUM_SIZE];
public:
	SortClass(void);
	~SortClass(void);

	void RandNum();
	void InitTempArr();

	void Bobble();			// 冒泡排序
	void InsertArr();		// 插入排序
	void Select();			// 选择排序

	void Merge(int *data, int start, int end, int *result);
	void MergeSort(int *data, int start, int end, int *result);		// 归并排序

	void Shell();			// 希尔排序

	int Partition(int *arr, int left, int right);
	void QuickSort(int *arr, int left, int right);		// 快速排序

	void Partition_2(int *arr, int left, int right, int &sentinel, int &offset);
	void QuickSort_2(int *arr, int left, int right);		// 改进的快排

	void CountSort(int *arr);		// 计数排序

	ListNode *Insert(ListNode *head, int val);		// 插入桶
	ListNode *MergeBucket(ListNode *head1, ListNode *head2);	// 归并桶
	void BucketSort(int *arr, int n);		// 桶排序

	int GetMaxDigit(int *arr, int len);
	void RadixSort(int *arr, int len);		// 基数排序

	void HeapSort();		// 堆排序

	void Print();
	void PrintSort();
	

private:
	inline void swap(int &a, int &b);
	ListNode *mNode;
};

#endif
