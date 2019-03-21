#include <iostream>
#include "DoubleList.cpp"
using namespace std;

int main()
{
	DoubleList<int> dlst;
	dlst.AddHead(12);
	dlst.AddHead(23);
	dlst.AddHead(45);
	dlst.AddHead(83);
	dlst.AddTail(64);
	dlst.AddTail(10);
	dlst.AddTail(77);
	dlst.AddTail(68);
	dlst.PrintList();
	cout << "the list length is " << dlst.GetLength() << endl;
	dlst.Reverse();
	cout << "Reverse current list" << endl;
	dlst.PrintList();
	cout << "the reverse list length is " << dlst.GetLength() << endl;

	cout << "delete 10" << endl;
	dlst.RemoveAt(dlst.GetNode(10));
	dlst.PrintList();
	cout << "current list length is " << dlst.GetLength() << endl;


	cout << "Insert 67 before 68" << endl;
	dlst.InsertAt(dlst.GetNode(68), 67);
	dlst.PrintList();
	cout << "current list length is " << dlst.GetLength() << endl;

	cout << "change 83 to 55" << endl;
	dlst.ModifyAt(dlst.GetNode(83), 55);
	dlst.PrintList();
	cout << "current list length is " << dlst.GetLength() << endl;

	cout << "delete 55" << endl;
	dlst.RemoveAt(dlst.GetNode(55));
	dlst.PrintList();
	cout << "current list length is " << dlst.GetLength() << endl;

	dlst.Erase();
	return 0;
}