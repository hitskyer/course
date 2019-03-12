#ifndef LINKEDLIST_CIRCULAR_LINKEDLIST_H
#define LINKEDLIST_CIRCULAR_LINKEDLIST_H

#include <iostream>
using namespace std;
template <class T> class CNode
{
    T _data;
    CNode* _next;
    CNode():_next(NULL)
    {
        cout << "please enter data: ";
        cin >> _data;
    }
    CNode(const T &d, CNode* p = NULL):_data(d),_next(p){}
    ~CNode(){}
};

template <class T> class circular_linkedlist
{
    CNode<T> *p_head;
    size_t listlength;
public:
    circular_linkedlist():p_head(NULL),listlength(0){}
    void insertAfter(CNode<T> *p);
    void delete
};


#endif //LINKEDLIST_CIRCULAR_LINKEDLIST_H
