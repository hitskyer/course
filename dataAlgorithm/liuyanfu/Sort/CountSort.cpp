/*
* Copyright: (c) 2019
*
* 文件名称:  CountSort.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/12  11:00
*/

#include <iostream>


using namespace std;
void print(int *arr, int nLen);

/**
* @brief	  计数排序(该版本数据都是从0开始存储的会浪费很多空间，而且实现不叫复杂)
*
* @method:    CountSort
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/12  11:01 
*/

/*
计数排序是桶排序的一个特例，即桶的个数和元素范围相同。
因此桶的编号就是元素的值，桶内存储的是该元素出现的次数。
计数排序应用场景：
（1）数据范围不是很大的场景中，如果数据范围k比要排序的数据n大很多，那就不适合用计数排序，太浪费空间
（2）数据均为非负整数，如果要排序的数据是其他类型，要将其在不改变相对大小的情况下，转化为非负整数
*/
void CountSort(int *arr, int nLen)
{
	if(nLen <= 1)
		return;
	//确定数据的范围
	int maxvalue = arr[0];
	for(int i = 1;i < nLen; ++i)
	{
		maxvalue = maxvalue >= arr[i] ? maxvalue : arr[i];
	}

	//申请一个动态数组，用来记录每个数据出现的次数
	int *countTimes = new int[maxvalue + 1];
	//memset(countTimes, 0, sizeof(int) * (maxvalue + 1));
	for(int i = 0;i <= maxvalue; ++i)
	{
		countTimes[i] = 0;
	}

	for(int i = 0;i < nLen; ++i)
	{
		countTimes[arr[i]]++;
	}
	//将数组中元素的值，记录数据在有序数组中的位置
	for(int i = 1;i <= maxvalue; ++i)
	{
		countTimes[i] += countTimes[i - 1];
	}

	//申请临时数组用来存储排序后的结果
	int *ResultArr = new int[nLen];
	//for(int i = nLen - 1;i >=0; --i)
	for(int i = 0;i < nLen; ++i)
	{
		ResultArr[countTimes[arr[i]] -1] = arr[i];
		countTimes[arr[i]]--;
	}

	//将有序数组赋值给待排序数组
	memcpy(arr, ResultArr, sizeof(int) * nLen);

	//释放动态数组
	delete []countTimes;
	delete []ResultArr;
}

void CountSort2(int *arr, int nLen)
{
	if(nLen < 2)
		return;
	int maxvalue = arr[0];
	int minvalue = arr[0]; 
	for(int i = 1; i < nLen; ++i)
	{
		maxvalue = maxvalue < arr[i] ? arr[i] : maxvalue;
		minvalue = minvalue > arr[i] ? arr[i] : minvalue;
	}

	int *ptemp = new int[maxvalue - minvalue + 1];
	memset(ptemp, 0, sizeof(int) * (maxvalue - minvalue + 1));
	int Index = 0;
	for(int i = 0; i < nLen; ++i)
	{
		Index = arr[i] - minvalue;
		ptemp[Index]++;
	}
	//print(ptemp, maxvalue - minvalue + 1);
	int j = 0;
	for(int i = minvalue; i <= maxvalue; ++i)
	{
		while(ptemp[i - minvalue]--)
		{
			arr[j] = i;
			j++;
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
	int arr4[10] = {15, 4, 13, 33, 23, 24, 5, 83, 19, 74};
	print(arr, sizeof(arr)/sizeof(arr[0]));
	CountSort2(arr,sizeof(arr)/sizeof(arr[0]));
	print(arr, sizeof(arr)/sizeof(arr[0]));
	cout << endl;

	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	CountSort2(arr1,sizeof(arr1)/sizeof(arr1[0]));
	print(arr1, sizeof(arr1)/sizeof(arr1[0]));
	cout << endl;

	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	CountSort2(arr2,sizeof(arr2)/sizeof(arr2[0]));
	print(arr2, sizeof(arr2)/sizeof(arr2[0]));
	cout << endl;

	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	CountSort2(arr3,sizeof(arr3)/sizeof(arr3[0]));
	print(arr3, sizeof(arr3)/sizeof(arr3[0]));
	cout << endl;

	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	CountSort2(arr4,sizeof(arr4)/sizeof(arr4[0]));
	print(arr4, sizeof(arr4)/sizeof(arr4[0]));
	return 0;
}
