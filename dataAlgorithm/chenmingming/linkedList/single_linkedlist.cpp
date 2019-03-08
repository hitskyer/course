/*
 * 内存泄漏总结：
 * 局部定义的指针，指向new出来的节点（堆空间），指针就可以返回
 * （如果指针没有指向堆空间，函数退出后，栈内的内容销毁，返回的指针也就是无效的）
 * 链表析构的时候delete 这些new出来的节点的地址（堆指针）
 */
template <class ElemType> Single_linkedlist<ElemType>::Single_linkedlist(int len)
{
    LinkNode<ElemType> *curNode;
    for(int i = 0; i != len; ++i) {
        curNode = new LinkNode<ElemType>;
        if(i == 0) {
            p_head = curNode;
            p_tail = curNode;
        } else {
            p_tail->_next = curNode;
            p_tail = curNode;
        }
        ++listlength;
    }
}
template <class ElemType> Single_linkedlist<ElemType>::Single_linkedlist(char reverse, int len)
{
    if(reverse == 'r' | reverse == 'R') {
        LinkNode<ElemType> *curNode, *prevNode;
        for(int i = 0; i != len; ++i) {
            curNode = new LinkNode<ElemType>;
            if(i == 0) {
                p_head = curNode;
                p_tail = curNode;
                prevNode = curNode;
            } else {
                curNode->_next = prevNode;
                p_head = curNode;
                prevNode = curNode;
            }
            ++listlength;
        }
    } else {
        cout << "you should enter 'r' or 'R' to the second Parameter！" << endl;
    }
}

template <class ElemType> void Single_linkedlist<ElemType>:: deleteAll()
{
    LinkNode<ElemType> *del_tempNode, *tempNode;
    del_tempNode = this -> p_head;
    while(del_tempNode != NULL) {
        tempNode = del_tempNode -> _next;
        delete del_tempNode;
        del_tempNode = tempNode;
        listlength--;
    }
    p_head = NULL;
    p_tail = NULL;
}

template <class ElemType> LinkNode<ElemType>* Single_linkedlist<ElemType>::find(int m) const
{
    if(m < 0 | m >= listlength)
    {
        cout << "位置不正确（位置序号从0开始）！" << endl;
        return NULL;
    }
    else
    {
        LinkNode<ElemType> *tempNode = p_head;
        for (int i = 0; i < m; ++i, tempNode = tempNode->_next)
        {   //空函数体
        }
        return tempNode;
    }
}
template <class ElemType> LinkNode<ElemType>* Single_linkedlist<ElemType>::find(ElemType &data) const
{
    LinkNode<ElemType> *tempNode = p_head;
    for (; (tempNode != NULL) && (tempNode->_data != data); tempNode = tempNode->_next) {   //空函数体
    }
    if(tempNode != NULL) {
        cout << "找到了指定元素！地址是：" << tempNode << endl;
        return tempNode;
    } else {
        cout << data << " is not exist!" << endl;
        return NULL;
    }
}
template <class ElemType> void Single_linkedlist<ElemType>::addHead(const ElemType &data)
{
    LinkNode<ElemType> *node = new LinkNode<ElemType>(data);
    if(p_head == NULL) {
        p_head = node;
        p_tail = node;
    } else {
        node->_next = p_head;
        p_head = node;
    }
    ++listlength;
    cout << "新的链表是：\n";
    this->printList();
    cout << "链表的长度是：" << listlength << endl;
}
template <class ElemType> void Single_linkedlist<ElemType>::addTail(const ElemType &data)
{
    LinkNode<ElemType> *node = new LinkNode<ElemType>(data);
    if(p_tail == NULL) {
        p_head = node;
        p_tail = node;
    } else {
        p_tail->_next = node;
        p_tail = node;
    }
    ++listlength;
    cout << "新的链表是：\n";
    this->printList();
    cout << "链表的长度是：" << listlength << endl;
}
template <class ElemType> bool Single_linkedlist<ElemType>::insertAtElemFront(const LinkNode<ElemType> &data, int i)
{
    LinkNode<ElemType> *node = new LinkNode<ElemType>(data);
    LinkNode<ElemType> *tempNode = p_head;
    if(i < 0 | i >= listlength)
    {
        cout << "位置不正确（位置序号从0开始）！" << endl;
        return false;
    }
    else
    {
        if(this->find(i) == NULL)
        {
            p_head = node;
            p_tail = node;
        }
        else
        {
            while(tempNode->_next != this->find(i))
            {
                tempNode = tempNode->_next;
            }
            node->_next = this->find(i);
            tempNode->_next = node;
        }
        return true;
    }
}
template <class ElemType> bool Single_linkedlist<ElemType>::insertAtElemBack(const LinkNode<ElemType> &data, int i)
{
    LinkNode<ElemType> *node = new LinkNode<ElemType>(data);
    LinkNode<ElemType> *tempNode = p_head;
    if(i < 0 | i >= listlength)
    {
        cout << "位置不正确（位置序号从0开始）！" << endl;
        return false;
    }
    else
    {
        if(this->find(i) == NULL)
        {
            p_head = node;
            p_tail = node;
        }
        else
        {
            tempNode = this->find(i);
            node->_next = tempNode->_next;
            tempNode->_next = node;
        }
        return true;
    }
}
template <class ElemType> bool Single_linkedlist<ElemType>::deleteElem(int i)
{

}
template <class ElemType> void Single_linkedlist<ElemType>::printList() const
{
    int m = 0;
    LinkNode<ElemType>* tempNode = p_head;
    for(; tempNode != NULL; tempNode = tempNode->_next)
    {
        cout << "N.O[" << m++ << "] element "  << tempNode->_data << endl;
    }
}

