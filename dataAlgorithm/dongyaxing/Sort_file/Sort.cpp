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

void SortClass::RandNum()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		arr[i] = rand()%NUM_SIZE +1;
	}
}

void SortClass::InitTempArr()
{
	memcpy(temparr, arr, sizeof(temparr));
}

inline void SortClass::swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


// 排序，从小到大
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

// 从小到大，且稳定
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

// 从小到大
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

void SortClass::Print()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << arr[i] << "  ";
	}
}

void SortClass::PrintSort()
{
	for (int i = 0; i < NUM_SIZE; ++i)
	{
		if(i%20 == 0)
			cout << endl;
		cout << temparr[i] << "  ";
	}
}