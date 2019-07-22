#ifndef _MEDIAN_FINDER_H
#define _MEDIAN_FINDER_H

#include <queue>
class MedianFinder
{
public:
	void addNum(int Num);
	double find_median();
	MedianFinder(void);
	~MedianFinder(void);
private:
	std::priority_queue<int, std::vector<int>, std::less<int> > max_heap;
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
};

#endif //_MEDIAN_FINDER_H