#include <iostream>
#include "SingleList.h"
#include "SingleList.cpp"
using namespace std;

int main()
{
	SingleList<int> lst;
	lst.AddHead(20);
	lst.AddHead(23);
	lst.AddHead(21);
	lst.AddHead(28);
	lst.AddHead(12);
	lst.AddTail(66);
	lst.AddTail(89);
	lst.AddTail(45);
	lst.AddTail(80);

	lst.PrintList();

	cout << "头结点的数据为： " << lst.GetHeadNode()->data << endl;
	cout << "尾节点的数据为： " << lst.GetTailNode()->data << endl;
	cout << "链表的长度为： "   << lst.GetSize() << endl;

	int a = 0;
	cout << "请输入你要查找的内容： ";
	cin >> a;
	if(!lst.Find(a))
		cout << "您查找的数据不存在！" << endl;
	else
		cout << "找到了，您查找的数据为： " << lst.Find(a)->data << endl;

	cout << endl;
	cout << "删除指定的数据节点" << endl;
	lst.RemoveAt(lst.GetNode(21));
	lst.PrintList();
	cout << "链表的长度为： "   << lst.GetSize() << endl;

	cout << endl;
	cout << "在指定数据节点位置插入数据" << endl;
	lst.InsertAt(lst.GetNode(28), 88);
	lst.PrintList();
	cout << "链表的长度为： "   << lst.GetSize() << endl;

	cout << endl;
	cout << "修改指定数据节点的数据" << endl;
	lst.ModifyAt(lst.GetNode(89), 99);
	lst.PrintList();
	cout << "链表的长度为： "   << lst.GetSize() << endl;
	
	lst.Erase();
	return 0;
}