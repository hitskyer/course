template <class ElemType> Single_linkedlist<ElemType>::Single_linkedlist(int len)
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
template <class ElemType> Single_linkedlist<ElemType>::Single_linkedlist(char reverse, int len)
{
    if(reverse == 'r' | reverse == 'R')
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
                curNode->_next = prevNode;
                p_head = curNode;
                prevNode = curNode;
            }
            ++listlength;
        }
    }
    else
    {
        cout << "you should enter 'r' or 'R' to the second Parameter！" << endl;
    }
}

template <class ElemType> void Single_linkedlist<ElemType>:: deleteAll()
{
    LinkNode<ElemType> *del_tempNode, *tempNode;
    del_tempNode = this -> p_head;
    while(del_tempNode != NULL)
    {
        tempNode = del_tempNode -> _next;
        delete del_tempNode;
        del_tempNode = tempNode;
    }
    p_head = NULL;
    p_tail = NULL;
}

template <class ElemType> void Single_linkedlist<ElemType>::printList() const
{
    int m = 0;
    LinkNode<ElemType>* tempNode;
    tempNode = this -> p_head;
    for(;tempNode != NULL; tempNode = tempNode->_next)
    {
        cout << "N.O[" << m++ << "] element "  << tempNode->_data << endl;
    }
}

