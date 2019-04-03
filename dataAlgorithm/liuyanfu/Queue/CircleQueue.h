#ifndef _CIRCLE_QUEUE_H
#define _CIRCLE_QUEUE_H
#pragma once

typedef unsigned int UINT;
template<typename T>
class CircleQueue
{
public:
	CircleQueue(void);
	CircleQueue(const UINT &InitSize);
	~CircleQueue(void);
	bool enqueue(const T& data);
	bool dequeue();
	UINT getlength() const;
	bool empty() const;
	void erase();
	void print() const;
private:
	T* m_pQueue;
	UINT m_nHead;
	UINT m_nTail;
	UINT m_nQueueLen;
	UINT m_nQueueSize;
};

#endif //_CIRCLE_QUEUE_H