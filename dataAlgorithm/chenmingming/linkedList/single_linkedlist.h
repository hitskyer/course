#ifndef LINKEDLIST_SINGLE_LINKEDLIST_H
#define LINKEDLIST_SINGLE_LINKEDLIST_H

#include<iostream>
using namespace std;

template<class ElemType>
struct LinkNode      //节点类
{
    ElemType _data;    //节点的数据
    LinkNode *_next;    //指向该节点的下一个节点的指针
    LinkNode(): _next(NULL)
    {
        cout << "please enter data: ";
        cin >> _data;
    }
    LinkNode(const ElemType &d, LinkNode* p = NULL) : _data(d), _next(p) {}
    ~LinkNode(){}
};
template <class ElemType> class Single_linkedlist
{
    LinkNode<ElemType> *p_head = NULL;   //首尾指针
    LinkNode<ElemType> *p_tail = NULL;
    int listlength = 0; //链表长度
public:
    Single_linkedlist(int len = 0); //构造函数(顺序插入)
    Single_linkedlist(char reverse, int len = 0); //构造函数(逆序插入)
    ~Single_linkedlist()    //析构函数
    {
        deleteAll();  //释放new出来的节点
    }

    void deleteAll();   //删除所有节点
    void *get_p_head() const //返回头节点的位置，即头指针
    {
        return p_head;
    }

    void *get_p_tail() const //返回为节点的位置，即尾指针
    {
        return p_tail;
    }

    int getLength() const //返回链表长度
    {
        return listlength;
    }

    bool isEmpty() const    //判断链表是否为空
    {
        return listlength == 0;
    }

    ElemType getCurData(LinkNode<ElemType> *p) const  //返回当前节点的数据内容
    {
        return p->_data;
    }

    void addHead(const ElemType &data);    //在链表头部添加元素
    void addTail(const ElemType &data);     //在链表尾部添加元素
    LinkNode<ElemType> *find(int m) const; //按下标查找
    LinkNode<ElemType> *find(ElemType &data) const; //按元素值查找
    void printList() const; //打印链表数据

};

#include "single_linkedlist.cpp"
#endif //LINKEDLIST_SINGLE_LINKEDLIST_H
