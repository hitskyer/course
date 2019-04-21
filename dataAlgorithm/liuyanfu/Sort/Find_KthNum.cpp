/*
* Copyright: (c) 2019
*
* 文件名称:  Find_KthNum.cpp	
* 文件标识：
* 摘	要： 从无序的一组数中找到第K个数
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/15  22:53
*/

#include <iostream>
#include <algorithm>

using namespace std;
void print(int *arr, int nLen);
/**
* @brief
*
* @method:    Partition
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int & sentinel
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/15  23:04 
*/
void Partition(int *arr, int left, int right, int& sentinel)
{
	int temp = arr[right];
	int i = left;
	int j = right;
	while(i != j)
	{
		while(arr[i] < temp && i != j)
			i++;
		while(arr[j] >= temp && i != j)
			j--;
		if(i != j)
			swap(arr[i], arr[j]);
	}
	sentinel = i;
	swap(arr[i], arr[right]);
	//print(arr, 10);
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @param:     int * arr
* @param:     int nLen
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/15  23:11 
*/
void print(int *arr, int nLen)
{
	for(int i = 0;i < nLen; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


/**
* @brief
*
* @method:    FindKthNum
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int KthNum
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/15  23:33 
*/
int FindKthNum(int *arr, int left, int right, int KthNum)
{
	int pivot = 0;
	Partition(arr, left, right, pivot);
	if(pivot + 1 == KthNum)
		return arr[pivot];
	else if(pivot + 1 > KthNum)
		return FindKthNum(arr, left, pivot -1, KthNum);
	else
		return FindKthNum(arr, pivot + 1, right, KthNum);
}

int main()
{
	int arr[] = {69 ,21, 13, 35, 17, 20, 48, 91, 11, 68};
	int KthNum;
	cout << "please input you want to look for Kth number: " << endl;
	while(cin >> KthNum && KthNum)
		cout << FindKthNum(arr, 0, 9, KthNum) << endl;
	return 0;
}