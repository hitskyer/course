#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

#include <vector>
#include <cassert>

template<typename T>
class MaxHeap
{
public:
	MaxHeap(void);
	~MaxHeap(void);
	void push(const T data);
	T pop();
	size_t size();
private:
	void up(int index);
	void down(int index);
	void makeHeap(T* arr, int nSize);

	std::vector<T> heap; 
	size_t count;
};

#endif //_MAX_HEAP_H