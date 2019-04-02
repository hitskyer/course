/**
 * @description: 链式队列
 * @author: michael ming
 * @date: 2019/4/1 22:47
 * @modified by:
 */

#ifndef QUEUE_LISTQUEUE_H
#define QUEUE_LISTQUEUE_H
template <class T>
struct SNode
{
    T data;
    SNode* pNext;
};

typedef unsigned int UINT;
template <class T>
class ListQueue
{
public:
    ListQueue(void);
    ~ListQueue(void);
    bool enqueue(const T& data);  //入队    从队列的尾部插入数据
    bool dequeue();		//出队   从队列的头部弹出数据
    UINT getlength() const;	//获得队列的长度
    bool empty() const;		//判断队列是否为空
    void erase();		//清空队列
    void print() const;       //打印队列
    SNode<T>* getHead() const;    //获取队首
    SNode<T>* getTail() const;    //获取队尾
private:
    SNode<T>* m_pHead;
    SNode<T>* m_pTail;
    UINT m_QueueLen;
};

#include "listQueue.cpp"
#endif //QUEUE_LISTQUEUE_H