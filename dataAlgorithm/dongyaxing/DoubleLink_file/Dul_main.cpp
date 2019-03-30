#include<iostream>
#include "DulNode.h"
using namespace std;

int main()
{
	DulList dl;
	if(dl.IsEmpty())
	{
		std::cout << "dl is empty" << std::endl;
	}
	else
	{
		std::cout << "dl is not empty" << std::endl;
	}
	dl.AddHead(40);
	dl.AddHead(30);
	dl.AddHead(20);
	dl.PrintList();
	std::cout << std::endl;

	dl.AddTail(40);
	dl.AddTail(50);
	dl.AddTail(60);
	dl.GetTailNode();

	dl.AddTail(50);
	dl.PrintList();

	DNode pos1;
	pos1 = dl.GetHeadNode();
	dl.InsertAt(pos1, 20);
	dl.PrintList();
	std::cout << std::endl;

	dl.Reverse();
	dl.PrintList();

	DNode pos2;
	pos2 = dl.GetHeadNode()->pNext;

	dl.ModifyAt(pos2, 28);
	dl.PrintList();

	DNode pos4;
	pos4 = dl.RemoveAt(3);
	std::cout << pos4->data << std::endl;
	dl.PrintList();

	DNode pos5;
	pos5 = dl.Find(80);
	if(pos5)
	{
		std::cout << pos5->data <<std::endl;
	}
	else
	{
		std::cout << "There is no this data." << std::endl;
	}
	dl.PrintList();

	system("pause");
	return 0;
}