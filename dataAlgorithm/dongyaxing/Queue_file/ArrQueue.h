/**
* 摘要：	顺序栈（尾不存放数据）
*/

#ifndef _ARRQUEUE_H
#define _ARRQUEUE_H

#define MAX_SIZE 10
typedef unsigned int UINT;
template<typename T>
class ArrQueue
{
public:
	ArrQueue(void);		// 构造
	~ArrQueue(void);	// 析构
	ArrQueue(const UINT & InitSize);		// 构造（初始化长度）

	bool EnQueue(const T &data);
	bool DeQueue();

	UINT GetLength() const;

	bool Empty() const;
	void Print() const;
	void Erase();

private:
	T* m_pQueue;
	UINT m_nHead;
	UINT m_nTail;
	UINT m_nQueueLen; // 有效数据
	UINT m_nQueueSize;	// 开辟空间
};





#endif //_ARRQUEUE_H
