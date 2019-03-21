#include<iostream>
#include "SingleList.h"

using namespace std;

int main()
{
	// 创建对象
	SingleList sl;
	// 判断是否有数
	if(sl.IsEmpty())
	{
		std::cout << "sl is empty!" << std::endl;
	}
	else
	{
		std::cout << "sl is not empty!" << std::endl;
	}
	// 头插入，
	sl.AddHead(20);
	sl.AddHead(10);
	sl.PrintList();		// 输出：10,20
	std::cout << sl.GetHeadNode()->data << std::endl;		// 获得链表头
	std::cout << sl.GetTailNode()->data << std::endl;		// 获得链表尾
	std::cout << sl.GetLength() << std::endl;				// 获得链表长度
	// 尾插入
	sl.AddTail(30);
	sl.AddTail(40);
	sl.PrintList();		// 输出：10，20,30,40
	std::cout << sl.GetMidNode()->data << std::endl;		// 获得链表中间，20
	sl.AddHead(5);
	sl.AddTail(50);
	sl.AddHead(2);
	sl.PrintList();		// 输出：2,5,10,20,30,40,50
	std::cout << sl.GetMidNode()->data << std::endl;		// 获得链表中间，20

	ListNode pos;
	pos = sl.GetHeadNode()->pNext->pNext;					// 指定链表的第3个节点，data = 10

	sl.InsertAt(pos, 15);
	sl.PrintList();											// 输出：2,5,15,10,20,30,40,50，但是pos的位置，为第四个节点 pos->data = 10

	sl.InsertAt(pos, 18);
	sl.PrintList();											// 输出：2,5,15,18，10,20,30,40,50，所以，此处，插入18，在10前面，pos->data = 10

	sl.ModifyAt(pos, 33);
	sl.PrintList();											// 输出：2,5,15,18,33，20,30,40,50，此时，pos->data = 33
	
	pos = sl.GetHeadNode()->pNext->pNext;
	sl.RemoveAt(pos);
	sl.PrintList();											// 输出：2,5,18,33，20,30,40,50，此时，pos->data = 18
	
	sl.RemoveAt(1);
	sl.PrintList();											// 输出：2，18,33,20,30，40,50

	pos = sl.Find(33);
	std::cout << pos->data << std::endl;					// 如果查找的数字不在列表中，则返回中断。

	sl.Reverse();											// 反转通过
	sl.PrintList();

 	system("pause");
	return 0; 
}