#include "single_linkedlist.h"
#include <iostream>
#include <string>

int main()
{
    Single_linkedlist<int> intList1(3);
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
    return 0;
}