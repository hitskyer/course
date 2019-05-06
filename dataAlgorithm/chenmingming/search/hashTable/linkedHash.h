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
struct linkedNode   //链表节点
{
    DataType data;
    linkedNode *next;
    linkedNode():next(NULL){}
    linkedNode(const DataType &d):next(NULL), data(d){}
};
template <class DataType>
class linkedList    //链表
{
public:
    linkedNode<DataType> *head;
    linkedList()
    {
        head = new linkedNode<DataType>();  //表头哨兵
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
    int bucket;  //散列表桶个数
public:
    linkedHash<DataType>(int m):bucket(m)
    {
        htList = new linkedList<DataType> [bucket] ();
    }
    ~linkedHash<DataType>()
    {
        for(int i = 0; i < bucket; ++i)
        {
            linkedNode<DataType> *p = htList[i].head->next, *q = p;
            while(q != NULL)
            {
                p = q;
                q = q->next;
                delete p;
            }
        }
        delete [] htList;
    }
    int hash(const DataType &newData) const
    {
        return newData%bucket;   //留余数法
    }
    linkedNode<DataType>* find(const DataType &x) const
    {
        int i = hash(x);
        linkedNode<DataType> *p = htList[i].head->next, *q = htList[i].head;
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
        linkedNode<DataType> *p = htList[i].head, *q = p;
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
            linkedNode<DataType> *p = htList[i].head->next;
            while(p)
            {
                std::cout << p->data << "->";
                p = p->next;
            }
            std::cout << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    }
};
#endif //SEARCH_LINKEDHASH_H