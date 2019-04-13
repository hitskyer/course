/*
* Copyright: (c) 2019
*
* 文件名称:  BucketSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/11  23:15
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
* @brief
*
* @method:    BucketSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/11  11:54 
*/


/**
* @brief
*
* @method:    compare
* @access:    public 
* @param:     const void * a
* @param:     const void * b
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/11  23:45 
*/
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


/**
* @brief	  冒泡排序
*
* @method:    BubbleSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/9  10:40 
*/
void BubbleSort(int* arr, int nLen)
{
	int temp = 0;
	for(int i = 0;i < nLen - 1; ++i)
	{
		for(int j = 0;j < nLen - i - 1; ++j)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
桶排序的应用场景：
（1）数据易于划分成多个桶来进行处理
（2）桶与桶之间有天然的大小顺序
（3）数据在每个桶的分布数量比较均匀
实现过程：
（1）确定桶内数据的范围，即最小和最大值
（2）确定要将所有的数据划分到几个桶里
（3）扫描所有数据，将数据划分到对应的桶中
（4）分别对每个桶中的数据进行排序
（5）从第一个桶开始，依次将桶内的数据放在数组中
*/

void BucketSort(int *arr, int nLen)
{
	int minvalue = arr[0];
	int maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
		minvalue = minvalue <= arr[i] ? minvalue : arr[i];
	}

	if(maxvalue == minvalue)
		return;

	int BucketNum = nLen;//桶的个数
	vector<vector <int> > vv(BucketNum, 0);

	int index = 0;
	double width = (double)(maxvalue - minvalue + 1)/BucketNum;
	for(int i = 0;i < nLen; ++i)
	{
		index = (int)(arr[i] - minvalue)/width; 
		vv[index].push_back(arr[i]);
	}

	for(size_t i =0; i < vv.size(); ++i)
	{
		//qsort(&vv[i][0], vv[i].size(), sizeof(vv[0][0]),compare);
		if(vv[i].empty())
			continue;
		BubbleSort(&vv[i][0], vv[i].size());
	}

	int i = 0;
	while(i < nLen)
	{
		for(size_t m =0; m < vv.size(); ++m)
		{
			for(size_t n = 0; n < vv[m].size(); ++n)
			{
				arr[i++] = vv[m][n];
				if(i == nLen)
					break;
			}
			if(i == nLen)
				break;
		}
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
	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;
	return 0;
}