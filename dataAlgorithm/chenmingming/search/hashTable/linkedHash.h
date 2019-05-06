/**
 * @description: 拉链法散列表
 * @author: michael ming
 * @date: 2019/5/6 17:56
 * @modified by: 
 */

#ifndef SEARCH_LINKEDHASH_H
#define SEARCH_LINKEDHASH_H
#include <iostream>
template <class DataType>
struct linkedNode
{
    DataType data;
    linkedNode *next;
    linkedNode():next(NULL){}
    linkedNode(const DataType &d):next(NULL), data(d){}
};
template <class DataType>
class linkedList
{
public:
    linkedNode<DataType> *head;
    linkedList()
    {
        head = new linkedNode<DataType>();
    }
    ~linkedList()
    {
        delete head;
    }
};
template <class DataType>
class linkedHash
{
private:
    linkedList<DataType> *htList; //散列表链表数组
    linkedNode<DataType> **htListHead;
    int bucket;  //散列表桶个数
public:
    linkedHash<DataType>(int m):bucket(m)
    {
        for(int i = 0; i < bucket; ++i)
        {
            htList = new linkedList<DataType> [bucket] ();
            htListHead = new linkedNode<DataType>* [bucket] ();
            htListHead[i] = htList[i].head;
        }
    }
    ~linkedHash<DataType>()
    {
        delete [] htListHead;
        delete [] htList;
    }
    int hash(const DataType &newData) const
    {
        return newData%bucket;   //留余数法
    }
    linkedNode<DataType>* find(const DataType &x) const
    {
        int i = hash(x);
        linkedNode<DataType> *p = htListHead[i].next, *q = htListHead[i];
        while(p && p->data != x)
        {
            q = p;
            p = p->next;
        }
        return q;   //返回找到元素的前一个节点，或者没有找到,返回最后一个元素
    }
    linkedNode<DataType>* insert(const DataType &x)
    {
        int i = hash(x);
        linkedNode<DataType> *p = htListHead[i]->next, *q = p;
        while(q != NULL)
        {
            p = q;
            q = q->next;
        }
        p->next = new linkedNode<DataType>(x);
        return p->next;
    }
    void delete_elem(const DataType &x)
    {
        linkedNode<DataType> *q = find(x), *p;
        if(q->next)
        {
            p = q->next;
            q->next = q->next->next;
            delete p;
        }
    }
    void print() const
    {
        for(int i = 0; i < bucket; ++i)
        {
            std::cout << i << "[ ]";
            linkedNode<DataType> *p = htListHead[i]->next;
            while(p)
            {
                std::cout << p->data << "->";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }
};
#endif //SEARCH_LINKEDHASH_H
