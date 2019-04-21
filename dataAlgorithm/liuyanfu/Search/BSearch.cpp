/*
* Copyright: (c) 2019
*
* 文件名称:  BSearchCycle.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/17  23:10
*/



/**
* @brief
*
* @method:    BSearchCycle
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int findNum
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/17  23:15 
*/
int BSearchCycle(int *arr, int low, int high, int value)
{
	int mid = 0;
	while(low <= high)
	{
		mid = low + (high - low) >> 1;
		if(arr[mid] == value)
			return mid;
		else if(arr[mid] > value)
			high = mid -1;
		else
			low = mid + 1;
	}
	return -1;
}


/**
* @brief
*
* @method:    BSearchRecursive
* @access:    public 
* @param:     int * arr
* @param:     int left
* @param:     int right
* @param:     int value
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/17  23:19 
*/
int BSearchRecursive(int *arr, int low, int high, int value)
{
	int mid = low + (high - low) >> 1;
	if(low > high)
		return -1;
	if(arr[mid] == value)
		return mid;
	else if(arr[mid] < value)
		BSearchRecursive(arr, mid + 1, high, value);
	else
		BSearchRecursive(arr, low, mid - 1, value);
}