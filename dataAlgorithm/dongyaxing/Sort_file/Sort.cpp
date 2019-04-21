#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

SortClass::SortClass(void)
{
	memset(arr, 0, sizeof(arr));
	memcpy(temparr, arr, sizeof(temparr));
}

SortClass::~SortClass(void)
{
}
/********************************************************************
* @brief : 		初始化数组，用于排序
* @author : 	dyx
* @date : 		2019/4/19
* @version : 	
* @inparam :	NUM_SIZE 总共需要排序的数量
* @outparam : 
*********************************************************************/
void SortClass::RandNum()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		//arr[i] = rand()%NUM_SIZE +1;		// 为其他数据初始化数据
		arr[i] = rand()%50 + 1;				// 专为计数排序初始化数据
	}
}
/********************************************************************
* @brief : 		复制一个临时数组temparr，用于排序，原数组依然保留
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::InitTempArr()
{
	memcpy(temparr, arr, sizeof(temparr));
}
/********************************************************************
* @brief : 		交换
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
inline void SortClass::swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/********************************************************************
* @brief : 		冒泡排序，从小到大。时间复杂度O(n^2), 稳定排序，空间复杂度0
* @author : 	dyx
* @date : 	
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Bobble()
{
	int temp = 0;
	bool flag = true;
	for (int i = 0; i < NUM_SIZE - 1; ++i)
	{
		flag = true;
		for (int j = 0; j < NUM_SIZE - 1 - i; ++j)
		{
			if (temparr[j] > temparr[j+1])
			{
				swap(temparr[j], temparr[j+1]);
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
/********************************************************************
* @brief : 		插入排序，从小到大，时间复杂度O(n^2), 稳定排序，空间复杂度0，比冒泡优秀
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::InsertArr()
{
	int preIndex, current;
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		preIndex = i-1;
		current = temparr[i];
		while(preIndex >= 0 && temparr[preIndex] > current)
		{
			temparr[preIndex + 1] = temparr[preIndex];
			--preIndex;
		}
		temparr[preIndex+1] = current;
	}
}
/********************************************************************
* @brief : 		选择排序，从小到大，时间复杂度O(n^2), 不稳定（涉及到交换），空间复杂度0
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Select()
{
	int index;
	int i, j;
	for (j = 0; j < NUM_SIZE - 1; ++j)
	{
		index = j;
		for (i = j + 1; i < NUM_SIZE; ++i)
		{
			if (temparr[i] < temparr[index])
			{
				index = i;
			}
		}
		swap(temparr[index], temparr[j]);
	}
}
/********************************************************************
* @brief : 		归并排序——归并排序[O(nlogn), 非原地排序]
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::MergeSort(int *data, int start, int end, int *result)
{
	if (1 == end - start)		// 如果区间中 只有两个元素，则对这两个元素进行排序
	{
		if (data[start] > data[end])
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if (0 == end - start)		// 只有一个元素，不排序
	{
		return;
	}
	else
	{
		// 继续划分子区间，分别对左右区间进行排序
		MergeSort(data, start, (end - start +1)/2+start, result);
		MergeSort(data, (end - start +1)/2+start+1, end, result);
		// 开始归并已经排好序的start到end之间的数据
		Merge(data, start, end, result);
		// 把排序后的数据复制到原始数据中去
		for (int i = start; i <= end; ++i)
		{
			data[i] = result[i];
		}
	}
}
/********************************************************************
* @brief : 		归并排序——归并
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Merge(int *data, int start, int end, int *result)
{
	int left_len = (end - start + 1)/2 +1;		// 左侧元素个数
	int left_index = start;
	int right_index = start + left_len;
	int result_index = start;
	while(left_index < start + left_len && right_index < end+1)
	{
		// 对已经排好序的左右区间进行合并
		if (data[left_index] <= data[right_index])
		{
			result[result_index++] = data[left_index++];
		}
		else
			result[result_index++] = data[right_index++];
	}
	while(left_index < start + left_len)
		result[result_index++] = data[left_index++];
	while(right_index < end +1)
		result[result_index++] = data[right_index++];
}
/********************************************************************
* @brief : 		希尔排序，从小到大，稳定，0(n^2),但优于插入排序
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Shell()
{
	int gap = NUM_SIZE/2;
	int temp;
	int preIndex;
	while (gap > 0)
	{
		for (int i = gap; i < NUM_SIZE; ++i)
		{
			temp = temparr[i];
			preIndex = i - gap;
			while(preIndex >= 0 && temparr[preIndex] > temp)
			{
				temparr[preIndex + gap] = temparr[preIndex];
				preIndex -= gap;
			}
			temparr[preIndex+gap] = temp;
		}
		gap/=2;
	}
}
/********************************************************************
* @brief : 		快速排序——找中点，分左（小）右（大）
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
int SortClass::Partition(int *Qarr, int left, int right)
{
	int i = left;
	int j = right;
	int temp = Qarr[i];		// 暂存哨兵
	while(i < j)
	{
		while (i < j && Qarr[j] >= temp)
		{	
			j--;
			if (i < j)
			{
				Qarr[i] = Qarr[j];
			}
			//j--;
		}
		while(i < j && Qarr[i] <= temp)
		{	
			i++;
			if (i < j)
			{
				Qarr[j] = Qarr[i];
			}
			//i++;
		}
	}
	Qarr[i] = temp;
	return i;
}
/********************************************************************
* @brief : 		快速排序——快排 O(nlogn)，不稳定，原地排序
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
//快速排序
void SortClass::QuickSort(int *Qarr, int left, int right)
{
	int dp; // 记录中点
	if (left < right)
	{
		dp = Partition(Qarr, left, right);
		QuickSort(Qarr, left, dp);
		QuickSort(Qarr, dp + 1, right);
	}
}
/********************************************************************
* @brief : 		桶排序——把数据有序的插入桶内(小到大)，用单向链表实现
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
ListNode *SortClass::Insert(ListNode *head, int val)
{
	ListNode dummyNode;		// 头结点之前的哨兵,
	ListNode *newNode = new ListNode;
	newNode->mData = val;
	newNode->pNext = NULL;
	dummyNode.pNext = head;
	ListNode *pre, *curr;
	pre = &dummyNode;
	curr = head;
	while (NULL != curr && curr->mData <= val)
	{
		pre = curr;
		curr = curr->pNext;
	}
	newNode->pNext = curr;
	pre->pNext = newNode;
	return dummyNode.pNext;
}
/********************************************************************
* @brief : 		桶排序——合并桶
* @author : 	dyx
* @date : 		 
* @version : 	 
* @inparam : 
* @outparam : 
*********************************************************************/
ListNode *SortClass::MergeBucket(ListNode *head1, ListNode *head2)
{
	ListNode dummyNode;
	ListNode *dummy = &dummyNode;
	while(NULL != head1 && NULL != head2)
	{
		if (head1->mData <= head2->mData)
		{
			dummy->pNext = head1;
			head1 = head1->pNext;
		}
		else
		{
			dummy->pNext = head2;
			head2 = head2->pNext;
		}
		dummy = dummy->pNext;
	}
	if (NULL != head1)
	{
		dummy->pNext = head1;
	}
	if(NULL != head2)
	{
		dummy->pNext = head2;
	}
	return dummyNode.pNext;
}
/********************************************************************
* @brief : 		桶排序——排序O(n)  不是原地排序，稳定。适合对数据量大且范围小的数据排序。
* @author : 	mark
* @date : 		$YEAR$/$MONTH$/$DAY$ $HOUR$:$MINUTE$
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::BucketSort(int *Barr, int n)
{
	vector<ListNode*> bucket(BUCKET_NUM, (ListNode*)(0));
	int min = Barr[0];
	int max = Barr[0];
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		if (min > Barr[i])
		{
			min = Barr[i];
		}
		else if (max < Barr[i])
		{
			max = Barr[i];
		}
	}

	int dis = (max - min)/n + 1;
	int j;
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		ListNode *head;
		j = 0;
		while(Barr[i] >= min)
		{
			if (Barr[i] <= (min + (j + 1)*dis))
			{
				head = bucket.at(j);
				bucket.at(j) = Insert(head, Barr[i]);
				break;
			}
			else
				++j;
		}
	}

	ListNode *head = bucket.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i)
	{
		head = MergeBucket(head, bucket.at(i)); 
	}
	for (int i = 0; i < NUM_SIZE && head != NULL; ++i)
	{
		Barr[i] = head->mData;
		head = head->pNext;
	}
}
/********************************************************************
* @brief : 		计数排序，O(n+k),k是数据范围,稳定，不是原地排序。适合对数据量大且范围小的数据排序。
* @author : 	dyx
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::CountSort(int *arr)
{
	// 找最大的数
	int max = arr[0];
	for (int i = 1; i < NUM_SIZE; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	// 填充C数组
	int *C = new int [max + 1];
	memset(C, 0, sizeof(int)*(max+1));
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		C[arr[i]]++;
	}
	// 直接复制到arr, 不稳定
	int j = 0;
	for (int i = 0; i <= max; ++i)
	{
		while (C[i] != 0)
		{
			arr[j] = i;
			++j;
			--C[i];
		}
	}
}
/********************************************************************
* @brief : 		基数排序——找到最大的数
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
int SortClass::GetMaxDigit(int *arr, int len)
{
	int digit = 1;
	int base = 10;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] >= base)
		{
			++digit;
			base*=10;
		}
	}
	return digit;
}
/********************************************************************
* @brief : 		基数排序——排序，适合电话号码或者字符串的排序，低位不够，补0
*						中间用到桶排序的方法。不是原地排序，稳定。 O(dn),d是维度
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::RadixSort(int *arr, int len)
{
	int digit = GetMaxDigit(arr, len);
	int base = 1;
	int *temp = new int[len];
	while(digit--)
	{
		int Count[10] = {0};
		int index = 0;
		for (int i = 0; i < len; ++i)	// 先求最后一位的大小，然后进行比较
		{
			index = (arr[i] / base) % 10;
			Count[index]++;
		}
		//求和
		for (int i = 1; i < 10; ++i)
		{
			Count[i] += Count[i-1];
		}
		for (int i = len - 1; i >= 0; --i)		// 经过第一次排序之后，低位数大的都在数组后边
		{
			index = (arr[i] / base) %10;
			temp[Count[index] - 1] = arr[i];
			Count[index]--;
		}
		memcpy(arr, temp, sizeof(int)*len);
		base *= 10;
	}
	delete [] temp;
}
/********************************************************************
* @brief : 		打印原始数组arr
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::Print()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << arr[i] << "  ";
	}
}
/********************************************************************
* @brief : 		打印排序之后的数组temparr
* @author : 	
* @date : 		
* @version : 	
* @inparam : 
* @outparam : 
*********************************************************************/
void SortClass::PrintSort()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << temparr[i] << "  ";
	}
}
