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

	sl.PrintList();
	sl.AddHead(20);
	sl.AddTail(30);
	sl.PrintList();

	sl.AddHead(10);
	sl.PrintList();		
	sl.GetHeadNode();		
	sl.GetTailNode();		
	sl.GetLength();				

	
	sl.AddTail(40);
	sl.PrintList();		
	//std::cout << sl.GetMidNode()->data << std::endl;		
	sl.AddHead(5);
	sl.AddTail(50);
	sl.AddHead(2);
	sl.PrintList();		
	//std::cout << sl.GetMidNode()->data << std::endl;		

	ListNode pos;
	pos = sl.GetHeadNode();					

	sl.InsertAt(pos, 15);
	sl.PrintList();											

	sl.InsertAt(pos, 18);
	sl.PrintList();											

	sl.ModifyAt(pos, 33);
	sl.PrintList();											
	
	sl.RemoveAt(pos);
	sl.PrintList();											
	
	sl.RemoveAt(1);
	sl.PrintList();											

	pos = sl.Find(33);				

	sl.Reverse();											
	sl.PrintList();

 	system("pause");
	return 0; 
}