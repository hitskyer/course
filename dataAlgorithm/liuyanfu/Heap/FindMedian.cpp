/*
* Copyright: (c) 2019
*
* 文件名称:  FindMedian.cpp	
* 文件标识：
* 摘	要：对于求中位数的问题可以分两种场景
*			（1）求一组静态数据中的中位数
*			（2）求一组动态数据中的中位数
*	对于静态数据而言，我们只需要将数据先进行排序时间复杂度是O(nlogn),再找到中位数时间复杂度为O(1);
*	对于动态数据而言，如果每插入一个数据都对数据进行排序之后再获取中位数，这个时间复杂度将是O(nlogn * n),
*	显然不能接受，因此我们采用堆的方法解决这个问题，我们只需要维护两个堆，一个为大顶堆，一个为小顶堆，
*	要保证大顶堆的堆顶元素小于小顶堆的堆顶元素，且它们之间的个数相差不超过1。通过这种方式，获取动态数组中
*	的中位数的时间复杂度是O(nlogn)
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/6/12  15:37
*/

#include "FindMedian.h"


FindMedian::FindMedian(void)
{
}


FindMedian::~FindMedian(void)
{
}


/**
* @brief	动态维护一个大顶堆max_heap和一个小顶堆min_heap，这两个堆各自存放“一半”数据，
*			这里的一半是指两个堆的size()相差小于等于1，且维持max_heap的堆顶 <= min_heap的堆顶
*
* @method:    addNum
* @access:    public 
* @param:     const int & data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  14:49 
*/
void FindMedian::addNum(const int& data)
{
	if(max_heap.empty())
	{
		max_heap.heap_push(data);
		return;
	}
	if(max_heap.size() == min_heap.size())
	{
		if(data < max_heap.heap_top())
		{
			max_heap.heap_push(data);
			return;
		}
		else
		{
			min_heap.heap_push(data);
			return;
		}
	}
	else if(max_heap.size() > min_heap.size())
	{
		if(data < max_heap.heap_top())
		{
			min_heap.heap_push(max_heap.heap_top());
			max_heap.heap_pop();
			max_heap.heap_push(data);
			return;
		}
		else
		{
			min_heap.heap_push(data);
			return;
		}
	}
	else
	{
		if(data < min_heap.heap_top())
		{
			max_heap.heap_push(data);
			return;
		}
		else
		{
			max_heap.heap_push(min_heap.heap_top());
			min_heap.heap_pop();
			min_heap.heap_push(data);
			return;
		}
	}
}


/**
* @brief
*
* @method:    findMedian
* @access:    public 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/6/12  15:10 
*/
int FindMedian::findMedian()
{
	if(max_heap.size() >= min_heap.size())
		return max_heap.heap_top();
	else
		return min_heap.heap_top();		
}