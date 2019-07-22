#include "MedianFinder.h"


MedianFinder::MedianFinder(void)
{
}


MedianFinder::~MedianFinder(void)
{
}


void MedianFinder::addNum(int num)
{
	if(max_heap.empty())
	{
		max_heap.push(num);
		return;
	}
	if(max_heap.size() == min_heap.size())
	{
		if(num < max_heap.top())
			max_heap.push(num);
		else
			min_heap.push(num);
	}
	else if(max_heap.size() < min_heap.size())
	{
		if(num < min_heap.top())
			max_heap.push(num);
		else
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(num);
		}
	}
	else
	{
		if(num < max_heap.top())
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
			max_heap.push(num);
		}
		else
		{
			min_heap.push(num);
		}
	}
}


int MedianFinder::find_median()
{
	if(max_heap.size() == min_heap.size())
	{
		return (max_heap.top() + min_heap.top())/2.0;
	}
	else if(max_heap.size() < min_heap.size())
		return min_heap.top();
	else
		return max_heap.top();
}