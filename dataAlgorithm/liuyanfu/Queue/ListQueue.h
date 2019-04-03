#ifndef _LIST_QUEUE_H
#define _LIST_QUEUE_H

template<typename T>
struct SNode
{
	T data;
	SNode* pNext;
};

typedef unsigned int UINT;

template<typename T>
class ListQueue
{
public:
	typedef SNode<T>* QueueNode;
public:
	ListQueue(void);
	~ListQueue(void);
	bool enqueue(const T& data);
	bool dequeue();
	void print() const;
	UINT getlength() const;
	bool empty() const;
	void erase();
private:
	QueueNode m_pHead;
	QueueNode m_pTail;
	UINT m_QueueLen;
};

#endif //_LIST_QUEUE_H