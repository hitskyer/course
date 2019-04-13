/*
* Copyright: (c) 2019
*
* 文件名称:  BucketSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/11  11:22
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* @brief
*
* @method:    compare
* @access:    public 
* @param:     const void * a
* @param:     const void * b
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/12  10:13 
*/
int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}


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
	double minvalue = arr[0];
	double maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
		minvalue = minvalue <= arr[i] ? minvalue : arr[i];
	}
	//桶的个数
	int BucketNum = nLen;

	//分配桶空间存储元素
	vector<vector<int> > bucketspace(BucketNum, 0);

	int index = 0;//定义桶的编号

	//扫描数组中的数据，分别放在对应编号的桶中
	for(int i = 0; i< nLen; ++i)
	{
		index = (int)(arr[i] - minvalue)/(maxvalue - minvalue + 1) * BucketNum;//加1是为了保证桶的编号小于BucketNum
		bucketspace[index].push_back(arr[i]);
	}

	//对每个桶内的元素进行排序,并将内容赋值到被排序的数组中
	int startpos = 0;
	for(size_t i = 0; i < bucketspace.size(); ++i)
	{
		if(bucketspace[i].empty())
			continue;
		qsort(&bucketspace[i][0], bucketspace[i].size(), sizeof(bucketspace[i][0]), compare);
		memcpy(&arr[startpos],&bucketspace[i][0], sizeof(bucketspace[i][0]) * bucketspace[i].size());
		startpos += bucketspace[i].size();
	}

	////按住桶的编号由小到大，依次将每个桶内的元素赋值到被排序的数组中
	//int startpos = 0;
	//for(size_t i = 0; i < bucketspace.size(); ++i)
	//{
	//	if(bucketspace[i].empty())
	//		continue;
	//	memcpy(&arr[startpos],&bucketspace[i][0], sizeof(bucketspace[i][0]) * bucketspace[i].size());
	//	startpos += bucketspace[i].size();
	//}
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
	int arr4[10] = {1,99,29,38,69,69,65,32,21,30};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	BucketSort(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	BucketSort(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	BucketSort(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	BucketSort(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	cout << endl;

	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	BucketSort(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}