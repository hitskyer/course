#include "MaxHeap.h"


using namespace std;

template<typename T>
MaxHeap<T>::MaxHeap(void)
{
	count = 0;
}


template<typename T>
MaxHeap<T>::~MaxHeap(void)
{
}


/**
* @brief	自下而上
*
* @method:    up
* @access:    private 
* @param:     int index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  23:03 
*/
template<typename T>
void MaxHeap<T>::up(int index)
{
	assert(index < count);
	int temp = heap[index];
	while(index > 0 && temp > heap[(index-1)/2])
	{
		heap[index] = heap[(index-1)/2];
		index = (index-1)/2;
	}
	heap[index] = temp;
}


/**
* @brief	自上而下
*
* @method:    down
* @access:    private 
* @param:     int index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  22:52 
*/
template<typename T>
void MaxHeap<T>::down(int index)
{
	assert(index >= 0);
	int temp = heap[index];
	index = index*2 + 1;
	while(index < count)
	{
		if(index+1 < count && heap[index+1] > heap[index])//找到左右节点中最大的值与父节点的值进行比较
			index++;
		if(heap[index] < temp)
			break;
		else
		{
			heap[(index - 1)/2] = heap[index];
			index = index*2 + 1;
		}
	}
	heap[(index-1)/2] = temp;
}


/**
* @brief
*
* @method:    makeHeap
* @access:    private 
* @param:     T * arr
* @param:     int nSize
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  23:14 
*/
template<typename T>
void MaxHeap<T>::makeHeap(T* arr, int nSize)
{
	heap.assign(arr, arr + nSize);
	for(int i = nSize/2 - 1; i >= 0; --i)
		down(i);
}


/**
* @brief
*
* @method:    push
* @access:    public 
* @param:     cosnt T data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  23:21 
*/
template<typename T>
void MaxHeap<T>::push(cosnt T data)
{
	heap.push_back(data);
	++count;
	up(count-1);
}


/**
* @brief
*
* @method:    pop
* @access:    public 
* @Return:    T
* @author:    RF_LYF
* @since:   2019/6/11  23:23 
*/
template<typename T>
T MaxHeap<T>::pop()
{
	assert(count > 0);
	T result = heap[0];
	heap[0] = heap[count - 1];
	count--;
	heap.pop_back();
	down(0);
	return result;
}


/**
* @brief
*
* @method:    size
* @access:    public 
* @Return:    size_t
* @author:    RF_LYF
* @since:   2019/6/11  23:23 
*/
template<typename T>
size_t MaxHeap<T>::size()
{
	return count;
}