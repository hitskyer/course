#include"ArrStack_2.h"
#include<iostream>
using namespace std;

template <class T> arrStack<T>::arrStack(void)
{
	m_nStackLen = MAX_SIZE;
	arr = new T[m_nStackLen];
	m_nTop = -1;
}

template <class T> arrStack<T>::arrStack(UINT max_size)
{
	m_nStackLen = max_size;
	arr = new T[m_nStackLen];
	m_nTop = -1;
}

template <class T> arrStack<T>::~arrStack(void)
{
	Clear();
	delete [] arr;
	arr = NULL;
	m_nStackLen = 0;
}

template <class T> bool arrStack<T>::IsEmpty() const
{
	return m_nTop == -1;
}

template <class T> bool arrStack<T>::IsFull() const
{
	return m_nTop == (m_nStackLen - 1);
}

template <class T> void arrStack<T>::Clear()
{
	m_nTop = -1;
}

template <class T> T arrStack<T>::GetTop() const
{
	if(!IsEmpty())
		return arr[m_nTop];
	return NULL;
}

template <class T> UINT arrStack<T>::GetLength() const
{
	return m_nStackLen;
}

template <class T> UINT arrStack<T>::GetCurrLength() const
{
	int n = (m_nTop + 1);
	return n;
}

template <class T> void arrStack<T>::Push(T &data)
{
	if(IsFull())
	{
		Expand();
		arr[++m_nTop] = data;
	}
	else
		arr[++m_nTop] = data;
}

template <class T> void arrStack<T>::Pop()
{
	if(!IsEmpty())
		--m_nTop;
}

template <class T> void arrStack<T>::Expand()
{
	m_nStackLen = 2*m_nStackLen;
	T* temparr = new T[m_nStackLen];
	//memcpy(temparr, arr, sizeof(arr));
	for(int i = 0; i <= m_nTop; ++i)
	{
		temparr[i] = arr[i];
	}
	T *temp = arr;
	arr = temparr;
	temparr = temp;
	delete [] temparr;
	temparr = NULL;
}

template <class T> void arrStack<T>::Print()
{
	std::cout << "-------arrStack top-----------" << std::endl;
	int i = m_nTop;
	while(i != -1)
	{
		std::cout << "No." << (i + 1) << " elem : " << arr[i] << endl;
		--i;
	}
	std::cout << "-------arrStack bottom---------" << std::endl;
}