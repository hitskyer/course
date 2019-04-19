#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <vector>
#define NUM_SIZE 500		// ĞèÒªÅÅĞòÊı×ÖÊıÁ¿
#define BUCKET_NUM 10		// 10¸öÍ°
using namespace std;
/********************************************************************
* @brief : 		ÓÃÓÚÍ°ÅÅĞò
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

	void Bobble();			// Ã°ÅİÅÅĞò
	void InsertArr();		// ²åÈëÅÅĞò
	void Select();			// Ñ¡ÔñÅÅĞò

	void Merge(int *data, int start, int end, int *result);
	void MergeSort(int *data, int start, int end, int *result);		// ¹é²¢ÅÅĞò

	void Shell();			// Ï£¶ûÅÅĞò

	int Partition(int *arr, int left, int right);
	void QuickSort(int *arr, int left, int right);		// ¿ìËÙÅÅĞò

	void CountSort(int *arr);		// ¼ÆÊıÅÅĞò

	ListNode *Insert(ListNode *head, int val);		// ²åÈëÍ°
	ListNode *MergeBucket(ListNode *head1, ListNode *head2);	// ¹é²¢Í°
	void BucketSort(int *arr, int n);		// Í°ÅÅĞò

	int GetMaxDigit(int *arr, int len);
	void RadixSort(int *arr, int len);		// »ùÊıÅÅĞò

	void HeapSort();		// ¶ÑÅÅĞò

	void Print();
	void PrintSort();
	

private:
	inline void swap(int &a, int &b);
	ListNode *mNode;
};

#endif
