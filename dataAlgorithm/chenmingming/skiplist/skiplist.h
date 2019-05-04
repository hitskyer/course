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
#include <iostream>
using namespace std;
typedef unsigned int UINT;
template <class T>
class skipNode
{
public:
    T data;
    skipNode<T> **next; //跳表节点的next是 skipNode<T>* 类型的数组
    skipNode(const UINT level)
    {
        next = new skipNode<T>* [level+1];  //索引级别从0（链表自身）开始
        for(int i = 0; i < level+1; ++i)
            next[i] = NULL;
    }
    skipNode(const UINT level, const T& inputdata):data(inputdata)
    {
        next = new skipNode<T>* [level+1];  //索引级别从0（链表自身）开始
        for(int i = 0; i < level+1; ++i)
            next[i] = NULL;
    }
    ~skipNode<T>()
    {
        delete [] next;
    }
};
template <class T>
class skiplist
{
private:
    UINT randomLevel()
    {
        static bool flag = false;
        if(!flag)
        {
            srand(UINT(time(0)));
            flag = true;
        }
        else
            flag = false;
        UINT lv = 0;
        for(int i = 0; i < maxLevel; ++i)
        {
            if(rand()%2)
                lv++;
        }
        return lv;
    }
public:
    UINT maxLevel;
    skipNode<T> *head;
    skiplist<T>(UINT level = 10):maxLevel(level)
    {
        head = new skipNode<T>(level);
    }
    ~skiplist<T>()
    {
        skipNode<T> *p = head, *q;
        while(p)
        {
            q = p;
            p = p->next[0];
            delete q;
        }
    }
    void insert(const T& inputdata)
    {
        skipNode<T>* newNode = new skipNode<T>(maxLevel, inputdata);
        skipNode<T>* temPos[maxLevel+1];
        skipNode<T> *p = head, *q = NULL;
        for(int i = maxLevel-1; i >= 0; i--)
        {
            while((q = p->next[i]) && (q->data <= inputdata))
            {
                p = q;
            }
            temPos[i] = p;
        }
        UINT lv = randomLevel();
        for(int i = 0; i <= lv; ++i)
        {
            newNode->next[i] = temPos[i]->next[i];
            temPos[i]->next[i] = newNode;
        }
    }
    void printSkipList()
    {
        skipNode<T> *p, *q;
        for(int i = maxLevel; i >= 0; --i)
        {
            p = head;
            while(q = p->next[i])
            {
                cout << q->data << " -> ";
                p = q;
            }
            cout << endl;
        }
    }
};

#endif //SKIPLIST_SKIPLIST_H