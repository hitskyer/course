#include "FindTopK.h"


FindTopK::FindTopK(void)
{
}


FindTopK::~FindTopK(void)
{
}


Heap<int, vector<int>, Greater<int>>& FindTopK::findTopK(vector<int>& vec, int k)
{
	ret.make_heap(vec.begin(), vec.begin() + k);
	for(int i = k; i < vec.size(); ++i)
	{
		if(vec[i] > ret.heap_top())
		{
			ret.heap_pop();
			ret.heap_push(vec[i]);
		}
	}
	return ret;
}