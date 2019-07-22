#ifndef _FINDMEDIAN_H
#define _FINDMEDIAN_H

#include "Heap.h"

class FindMedian
{
public:
	FindMedian(void);
	~FindMedian(void);
	void addNum(const int& data);
	int findMedian();
private:
	Heap<int, vector<int>, Less<int>> max_heap;
	Heap<int, vector<int>, Greater<int>> min_heap;
};

#endif // _FINDMEDIAN_H