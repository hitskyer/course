#include<iostream>
#include"SingleCircleList.h"
using namespace std;

int main()
{
	SingleCircleList scl;
	// 0 结点，测试函数
	/*if(scl.IsEmpty())
	{
		std::cout << "This is an empty List!" << std::endl;
	}
	else
	{
		std::cout << "This is not an empty List!" << std::endl;
	}
	scl.GetLength();
	scl.Erase();
	scl.Find(5);
	scl.GetHeadNode();
	scl.GetMidNode();
	scl.GetTailNode();
	scl.Reverse();

	SCLNode pos;
	pos = scl.GetHeadNode();
	scl.RemoveAt(pos);
	scl.ModifyAt(pos, 5);
	scl.RemoveAt(pos);
	scl.RemoveAt(2);
	scl.InsertAt(pos, 10);*/

	// 1,2,多个结点
	scl.AddHead(11);
	scl.AddTail(12);
	scl.AddHead(6);
	scl.AddHead(4);
	scl.AddTail(15);
	scl.PrintList();
	if(scl.IsEmpty())
	{
		std::cout << "This is an empty List!" << std::endl;
	}
	else
	{
		std::cout << "This is not an empty List!" << std::endl;
	}
	scl.GetLength();
	scl.Find(5);
	scl.Find(15);
	SCLNode pos1, pos2, pos3;
	pos1 = scl.GetHeadNode();
	std::cout << pos1->data << std::endl;
	pos2 = scl.GetMidNode();
	std::cout << pos2->data << std::endl;
	pos3 = scl.GetTailNode();
	std::cout << pos3->data << std::endl << std::endl;
	scl.PrintList();
	cout<<endl;
	scl.Reverse();
	scl.PrintList();
	cout << endl;
	SCLNode pos4;
	pos4 = scl.GetHeadNode();
	std::cout << pos4->data << std::endl;
	pos4 = scl.ModifyAt(pos2, 5);
	std::cout << pos4->data << std::endl;
	pos4 = scl.InsertAt(pos4, 10);
	std::cout << pos4->data << std::endl;
	scl.PrintList();
	cout << endl;
	scl.RemoveAt(pos2);
	scl.PrintList();
	cout << endl;
	scl.RemoveAt(2);
	scl.PrintList();

 	system("pause");
	return 0;
}