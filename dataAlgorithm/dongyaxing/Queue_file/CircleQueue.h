/**
* 摘要：	循环队列，尾不存放数据
* 创建时间：2019/4/4    17：00
*/

#ifndef _CIRCLE_QUEUE_H
#define _CIRCLE_QUEUE_H

#define MAX_SIZE 10
typedef unsigned int UINT;
template <typename T>
class CircleQueue
{
public:
	CircleQueue(void);
	CircleQueue(const UINT &InitSize);
	~CircleQueue(void);

	UINT GetLength() const;
	bool Empty() const;
	bool EnQueue(const T &data);
	bool DeQueue();
	void Erase();
	void Print() const;
private:
	T *CQueue;
	UINT m_nHead;
	UINT m_nTail;
	UINT m_nCQueueLen;		// 有效长度
	UINT m_nCQueueSize;		// 循环队列的大小
};

#endif //_CIRCLE_QUEUE_H