#include "Heap.h"
#include <iostream>

using namespace std;


template<typename T>
Heap<T>::Heap(void)
{
	m_capacity = 20;
	m_count = 0;
	m_arr = new T[m_capacity + 1];
}


template<typename T>
Heap<T>::Heap(int capacity):m_capacity(capacity)
{
	m_count = 0;
	m_arr = new T[m_capacity + 1];
}

template<typename T>
Heap<T>::~Heap(void)
{
	delete []m_arr;
	m_arr = NULL;
	m_count = 0;
}


/**
* @brief
*
* @method:    Insert
* @access:    public 
* @param:     const T data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  10:08 
*/
template<typename T>
void Heap<T>::Insert(const T data)
{
	if(m_count >= m_capacity)
		return;//堆已满
	++m_count;
	m_arr[m_count] = data;
	int i = m_count;
	while(i/2 > 0 && m_arr[i] > m_arr[i/2])
	{
		swap(m_arr, i, i/2);
		i = i/2;
	}
}


/**
* @brief
*
* @method:    RemoveMax
* @access:    public 
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  10:18 
*/
template<typename T>
void Heap<T>::RemoveMax()
{
	if(m_count == 0)
		return;//堆中没有数据
	m_arr[1] = m_arr[m_count];
	--m_count;
	HeapifyMax(m_arr, m_count, 1);
}


/**
* @brief
*
* @method:    swap
* @access:    private 
* @param:     T * arr
* @param:     int i
* @param:     int j
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  10:00 
*/
template<typename T>
void Heap<T>::swap(T* arr, int i, int j)
{
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}



/**
* @brief	自上而下建堆，适用于堆本身就是最大堆（或者最小堆结构），
			由于插入或者删除操作导致最大堆（或者最小堆）结构被破坏，
			此时可以用这种方式恢复最大堆（或者最小堆）
*
* @method:    HeapifyMax
* @access:    public 
* @param:     T * arr
* @param:     int nSize
* @param:     int i
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  9:41 
*/
template<typename T>
void Heap<T>::HeapifyMax(T* arr, int nSize, int i)
{
	while(true)
	{
		int maxPos = i;
		if(2*i <= nSize && arr[i] < arr[2*i])
			maxPos = 2*i;
		if(2*i + 1 <= nSize && arr[maxPos] < arr[2*i + 1])
			maxPos = 2*i + 1;
		if(maxPos == i)
			break;
		swap(arr, i, maxPos);
		i = maxPos;
	}
}


/**
* @brief
*
* @method:    HeapifyMin
* @access:    public 
* @param:     T * arr
* @param:     int nSize
* @param:     int i
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  16:20 
*/
template<typename T>
void Heap<T>::HeapifyMin(T* arr, int nSize, int i)
{
	while(true)
	{
		int minPos = i;
		if(2*i <= nSize && arr[i] > arr[2*i])
			minPos = 2*i;
		if(2*i + 1 <= nSize && arr[minPos] > arr[2*i + 1])
			minPos = 2*i + 1;
		if(minPos == i)
			break;
		swap(arr, i, minPos);
		i = minPos;
	}
}


/**
* @brief
*
* @method:    BuildMaxHeap
* @access:    public 
* @param:     T * arr
* @param:     int nSIze
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  10:00 
*/
template<typename T>
void Heap<T>::BuildMaxHeap(T* arr, int nSize)
{
	for(int i = nSize/2; i >= 1; --i)
		HeapifyMax(arr, nSize, i);
}


/**
* @brief
*
* @method:    BuildMinHeap
* @access:    public 
* @param:     T * arr
* @param:     int nSize
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  16:25 
*/
template<typename T>
void Heap<T>::BuildMinHeap(T* arr, int nSize)
{
	for(int i = nSize/2; i >= 1; --i)
		HeapifyMin(arr, nSize, i);
}


/**
* @brief	堆排序分为两个步骤：（1）建立堆 （2）排序
*
* @method:    HeapSort
* @access:    public 
* @param:     T * arr
* @param:     int n
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  10:24 
*/
template<typename T>
void Heap<T>::HeapSort(T* arr, int n)
{
	BuildMaxHeap(arr, n);
	int k = n;
	while(k > 1)
	{
		swap(arr, 1, k);
		k--;
		HeapifyMax(arr, k, 1);
	}
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/11  16:27 
*/
template<typename T>
void Heap<T>::print()
{
	for(int i = 1; i <= m_count; ++i)
	{
		cout << m_arr[i] << " ";
	}
	cout << endl;
}


/**
* @brief
*
* @method:    FindTopK
* @access:    public 
* @param:     T * arr
* @param:     int nSize
* @param:     int k
* @Return:    
* @author:    RF_LYF
* @since:   2019/6/11  17:07 
*/
template<typename T>
vector<T> Heap<T>::FindTopK(T* arr, int nSize, int k)
{
	vector<T> ret(k+1);
	for(int i = 0; i < k; ++i)
	{
		int j = i + 1;
		ret[j] = arr[i];
		while(j/2 > 0 && ret[j/2] > ret[j])
		{
			swap(&ret[0], j, j/2);
			j = j/2;
		}
	}
	for(int i = k; i < nSize; ++i)
	{
		if(arr[i] < ret[1])
			ret[1] = arr[i];
	}
	return ret;
}

