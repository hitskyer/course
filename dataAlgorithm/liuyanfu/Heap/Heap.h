#ifndef _HEAP_H
#define _HEAP_H

#include <vector>
#include <cassert>
using namespace std;
template<class T>
struct Less
{
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};

template<class T, class Container = std::vector<T>, class Compare = Less<T>>
class Heap
{
public:
	Heap(void);
	~Heap(void);
	void make_heap(typename Container::iterator begin, typename Container::iterator end);
	void heap_push(const T& data);
	T heap_pop();
	int size();
	bool empty();
	T& heap_top();
	void print();
private:
	void heapify_up(int index);
	void heapify_down(int index);
	Container m_heap;
	int m_size;
};


//实现
template<class T, class Container, class Compare>
Heap<T, Container, Compare>::Heap(void)
{
	m_size = 0;
}

template<class T, class Container, class Compare>
Heap<T, Container, Compare>::~Heap(void)
{
}


/**
* @brief	自下而上
*
* @method:    heapify_up
* @access:    private 
* @param:     int index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  10:30 
*/
template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::heapify_up(int index)
{
	assert(index < m_size);
	Compare cmp;
	T temp = m_heap[index];
	while(index > 0 && cmp(m_heap[(index - 1)/2], temp))
	{
		m_heap[index] = m_heap[(index - 1)/2];
		index = (index - 1)/2;
	}
	m_heap[index] = temp;
}


/**
* @brief	自上而下
*
* @method:    heapify_down
* @access:    private 
* @param:     int index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  10:30 
*/
template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::heapify_down(int index)
{
	assert(index >= 0);
	Compare cmp;
	T temp = m_heap[index];
	index = index*2 + 1;
	while(index < m_size)
	{
		if(index + 1 < m_size && cmp(m_heap[index], m_heap[index+1]))
			index++;
		if(cmp(m_heap[index], temp))
			break;
		m_heap[(index-1)/2] = m_heap[index];
		index = index*2 + 1;
	}
	m_heap[(index - 1)/2] = temp;
}


/**
* @brief
*
* @method:    make_heap
* @access:    public 
* @param:     typename vector<T>::iterator begin
* @param:     typename vector<T>::iterator end
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  11:05 
*/
template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::make_heap(typename Container::iterator begin, typename Container::iterator end)
{
	m_heap.assign(begin, end);
	m_size = m_heap.size();
	for(int i = (m_size -1)/2; i >= 0; --i)
	{
		heapify_down(i);
	}
}


/**
* @brief	
*
* @method:    heap_push
* @access:    public 
* @param:     const T & data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  10:52 
*/
template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::heap_push(const T& data)
{
	m_heap.push_back(data);
	++m_size;
	heapify_up(m_size-1);
}


/**
* @brief
*
* @method:    heap_pop
* @access:    public 
* @Return:    boost::foreach_detail_::T
* @author:    RF_LYF
* @since:   2019/6/12  10:55 
*/
template<class T, class Container, class Compare>
T Heap<T, Container, Compare>::heap_pop()
{
	assert(m_size > 0);
	T result = m_heap.front();
	m_heap[0] = m_heap[m_size-1];
	m_heap.pop_back();
	--m_size;
	if(!empty())
		heapify_down(0);
	return result;
}


/**
* @brief
*
* @method:    size
* @access:    public 
* @Return:    size_t
* @author:    RF_LYF
* @since:   2019/6/12  10:56 
*/
template<class T, class Container, class Compare>
int Heap<T, Container, Compare>::size()
{
	return m_heap.size();
}


/**
* @brief
*
* @method:    empty
* @access:    public 
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/6/12  10:57 
*/
template<class T, class Container, class Compare>
bool Heap<T, Container, Compare>::empty()
{
	return m_heap.empty();
}


/**
* @brief
*
* @method:    heap_top
* @access:    public 
* @Return:    T&
* @author:    RF_LYF
* @since:   2019/6/12  11:11 
*/
template<class T, class Container, class Compare>
T& Heap<T, Container, Compare>::heap_top()
{
	assert(m_size > 0);
	return m_heap[0];
}


/**
* @brief
*
* @method:    print
* @access:    public 
* @Return:    void
* @author:    RF_LYF
* @since:   2019/6/12  14:26 
*/
template<class T, class Container, class Compare>
void Heap<T, Container, Compare>::print()
{
	for(int i = 0; i < m_heap.size(); ++i)
	{
		cout << m_heap[i] << " " ;
	}
	cout << endl;
}

#endif //_HEAP_H
