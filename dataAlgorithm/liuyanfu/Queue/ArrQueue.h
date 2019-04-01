#ifndef _ARR_QUEUE_H
#define _ARR_QUEUE_H
#pragma once




typedef unsigned int UINT;
template<typename T>
class ArrQueue
{
public:
	ArrQueue(void);
	ArrQueue(const UINT& InitSize);
	~ArrQueue(void);
	bool enqueue(const T& data);
	bool dequeue();
	UINT getlength() const;
	bool empty() const;
	void erase();
	void print() const;
private:
	T* m_pQueue;
	int m_nHead;
	UINT m_nTail;
	UINT m_nQueueLen;
	UINT m_nQueueSize;
};

#endif //_ARR_QUEUE_H