/**
 * @description: 跳表
 * @author: michael ming
 * @date: 2019/4/22 22:21
 * @modified by: 
 */

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H
typedef unsigned int UINT;
template <class T>
class skipNode
{
public:
    T data;
    skipNode<T> **next; //跳表节点的next是 skipNode<T>* 类型的数组
    skipNode(const T& inputdata, UINT level):data(inputdata)
    {
        next = new skipNode<T>* [level+1];  //索引级别从0（链表自身）开始
    }
};
template <class T>
class skiplist
{
public:
    UINT level;
    skipNode<T> *head;
//    skiplist<T>
};


#endif //SKIPLIST_SKIPLIST_H
