/**
 * @description: 跳表
 * @author: michael ming
 * @date: 2019/4/22 22:21
 * @modified by: 
 */

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H
#include <ctime>
#include <cstdlib>

typedef unsigned int UINT;
template <class T>
class skipNode
{
public:
    T data;
    skipNode<T> **next; //跳表节点的next是 skipNode<T>* 类型的数组
    skipNode(UINT level)
    {
        next = new skipNode<T>* [level+1];  //索引级别从0（链表自身）开始
        for(int i = 0; i < level+1; ++i)
            next[i] = NULL;
    }
    skipNode(UINT level, const T& inputdata):data(inputdata)
    {
        next = new skipNode<T>* [level+1];  //索引级别从0（链表自身）开始
        for(int i = 0; i < level+1; ++i)
            next[i] = NULL;
    }
};
template <class T>
class skiplist
{
private:
    UINT randomLevel()
    {
        UINT lv = 0;
        while(rand()%2)
            lv++;
        return lv > maxLevel ? maxLevel:lv;
    }
public:
    UINT maxLevel;
    skipNode<T> *head;
    skiplist<T>(UINT level = 10):maxLevel(level)
    {
        head = new skipNode<T>();
    }
    void insert(const T& inputdata)
    {
        skipNode<T>* newNode = new skipNode<T>(maxLevel, inputdata);

    }
};

#endif //SKIPLIST_SKIPLIST_H