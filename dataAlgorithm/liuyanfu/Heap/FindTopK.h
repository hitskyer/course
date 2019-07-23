#ifndef _FIND_TOPK_H
#define _FIND_TOPK_H

#include "Heap.h"

class FindTopK
{
public:
	FindTopK(void);
	~FindTopK(void);
	Heap<int, vector<int>, Greater<int>>& findTopK(vector<int>& vec, int k);
private:
	Heap<int, vector<int>, Greater<int>> ret;
};

#endif // _FIND_TOPK_H