/**
 * @description: 循环顺序队列，减少队列中数组的挪移
 * @author: michael ming
 * @date: 2019/4/2 22:43
 * @modified by: 
 */
#ifndef QUEUE_CIRCULARQUEUE_H
#define QUEUE_CIRCULARQUEUE_H
typedef unsigned int UINT;
template <class T>
class circularQueue
{
public:
    circularQueue(const int capa = 10);
    ~circularQueue(void);
    bool enqueue(const T& data);  //入队    从队列的尾部插入数据
    bool dequeue();		//出队   从队列的头部弹出数据
    UINT getlength() const;	//获得队列的长度
    bool empty() const;		//判断队列是否为空
    bool full() const;      //判断队列是否满
    void erase();		//清空队列
    void print() const;       //打印队列
    const T& getHead() const;    //获取队首
    const T& getTail() const;    //获取队尾
private:
    int m_pHead;
    int m_pTail;
    UINT m_QueueLen;
    UINT m_capacity;
    T* arrQ;
};

#include "circularQueue.cpp"
#endif //QUEUE_CIRCULARQUEUE_H