#include "Sort.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

SortClass::SortClass(void)
{
	memset(arr, 0, sizeof(int)*NUM_SIZE);
	memcpy(temparr, arr, sizeof(int)*NUM_SIZE);
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
	memcpy(temparr, arr, sizeof(int)*NUM_SIZE);
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
