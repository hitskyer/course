#ifndef LINKEDLIST_SINGLE_LINKEDLIST_H
#define LINKEDLIST_SINGLE_LINKEDLIST_H

#include<iostream>
using namespace std;

template <class ElemType> struct LinkNode      //节点类
{
    ElemType _data;    //节点的数据
    LinkNode* _next;    //指向该节点的下一个节点的指针
    LinkNode(): _next(NULL) {}
    LinkNode(const ElemType &d, LinkNode* p = NULL) : _data(d), _next(p) {}
    ~LinkNode(){}
};
template <class ElemType> class Single_linkedlist
{
    LinkNode<ElemType> *p_head = NULL;   //首尾指针
    LinkNode<ElemType> *p_tail = NULL;
    int listlength = 0; //链表长度
public:
    Single_linkedlist(int len = 0)
    {
        LinkNode<ElemType> *curNode, *prevNode;
        for(int i = 0; i != len; ++i)
        {
            curNode = new LinkNode<ElemType>;
            if(i == 0)
            {
                p_head = curNode;
                p_tail = curNode;
                prevNode = curNode;
            }
            else
            {
                prevNode->_next = curNode;
                p_tail = curNode;
                prevNode = curNode;
            }
            ++listlength;
        }
    }
    void* get_p_head() //返回头节点的位置，即头指针
    {
        return p_head;
    }
    void* get_p_tail() //返回为节点的位置，即尾指针
    {
        return p_tail;
    }
    int getLength()  //返回链表长度
    {
        return listlength;
    }
    ElemType getCurData(LinkNode<ElemType>* p) const  //返回当前节点的数据内容
    {
        return p->_data;
    }
    void printList() const
    {
        int m = 0;
        LinkNode<ElemType>* tempNode;
        tempNode = this -> p_head;
        for(;tempNode != NULL; tempNode = tempNode->_next)
        {
            cout << "N.O[" << m++ << "] element "  << tempNode->_data << endl;
        }
    }
};

#endif //LINKEDLIST_SINGLE_LINKEDLIST_H
