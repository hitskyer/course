/*
* 概述：	链式队列
* 作者：	lyf
* 版本：	1.0
* 创建时间：2019/4/1   20:56
* 修改：	dyx
* 修改内容：规范函数名和变量名
* 修改时间：2019/4/3	20:00
****** 接口千万条，规范第一条
****** 接口不规范，农民两行泪
*/
#ifndef _QUEUE_H
#define _QUEUE_H

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
	typedef SNode<T> *QNode;
public:
	ListQueue(void);
	~ListQueue(void);
	bool enqueue(const T& data);	//入队    从队列的尾部插入数据
	bool dequeue();					//出队   从队列的头部弹出数据
	UINT getlength() const;			//获得队列的长度
	bool empty() const;				//判断队列是否为空
	void erase();					//清空队列
	void print() const;
private:	
	QNode m_pHead;			// 头
	QNode m_pTail;			// 尾
	UINT m_nQueueLen;		// 有效长度
};
#endif //_QUEUE_H