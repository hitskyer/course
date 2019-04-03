/**
 * @description: 优先级队列
 * @author: michael ming
 * @date: 2019/4/3 21:20
 * @modified by: 
 */

#ifndef QUEUE_PRIORITY_QUEUE_H
#define QUEUE_PRIORITY_QUEUE_H
#include <functional>
template <class T>
T& comp(T& a, T& b)
{
    return a < b ? b : a;
}

typedef unsigned int UINT;
template <class T, int *compf = comp<T> >
class priority_queue
{
public:
    priority_queue(const int capa = 10);
    ~priority_queue(void);
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

#endif //QUEUE_PRIORITY_QUEUE_H