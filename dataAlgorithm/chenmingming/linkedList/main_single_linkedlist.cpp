#include "single_linkedlist.h"
#include <iostream>
#include <string>

int main()
{
    Single_linkedlist<int> intList1(2);
    intList1.printList();
    cout << "链表的长度是：" << intList1.getLength() << endl;
    intList1.deleteAll();
    cout << "链表的长度是：" << intList1.getLength() << endl;
    Single_linkedlist<string> strList1('r',3);
    strList1.printList();
    cout << "链表是空的吗？(0:不是；1:是)" << strList1.isEmpty() << endl;
    cout << "链表的第2号元素list[2]是：" << (strList1.find(2))->_data << endl;
    string str("abc");
    cout << "链表的包含字符串\"abc\"的元素的地址：" << endl;
    strList1.find(str);
    strList1.addHead(str);
    strList1.addTail(str);
    strList1.insertAtElemFront(str,2);
    strList1.printList();
    strList1.insertAtElemBack(str,3);
    strList1.printList();
    strList1.deleteElem(strList1.getLength()-1);
    strList1.printList();
    strList1.modifyElem(strList1.getLength()-1,string("end"));
    strList1.printList();
    return 0;
}