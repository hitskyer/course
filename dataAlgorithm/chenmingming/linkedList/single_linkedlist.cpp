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
//        delete curNode;
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
//            if(i != 0)
//            {
//                delete curNode;
//            }
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

template <class ElemType> LinkNode<ElemType>* Single_linkedlist<ElemType>::find(int m) const
{
    if(m < 0 | m >= listlength)
    {
        cout << "位置不正确（位置序号从0开始）！" << endl;
    }
    else
    {
        LinkNode<ElemType> *tempNode;
        tempNode = p_head;
        for(int i = 0; i < m; ++i,tempNode = tempNode->_next)
        {   //空函数体
        }
        return tempNode;
    }
}
template <class ElemType> LinkNode<ElemType>* Single_linkedlist<ElemType>::find(ElemType &data) const
{
    LinkNode<ElemType> *tempNode;
    for(tempNode = p_head; (tempNode != NULL) && (tempNode->_data != data); tempNode = tempNode->_next)
    {   //空函数体
    }
    if(tempNode != NULL)
    {
        cout << "找到了指定元素！地址是：" << tempNode << endl;
        return tempNode;
    }
    else
    {
        cout << data << " is not exist!" << endl;
        return NULL;
    }
}
template <class ElemType> void Single_linkedlist<ElemType>::addHead(ElemType &data)
{
    LinkNode<ElemType> node = LinkNode<ElemType>(data);
    node._next = p_head;
    p_head = &node;
    ++listlength;
    cout << "新的链表是：\n";
    this->printList();
    cout << "链表的长度是：" << listlength << endl;
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

