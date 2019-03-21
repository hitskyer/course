#include <iostream>
#include "DoubleCircleList.cpp"

using namespace std;


int main()
{
	DoubleCircleList<int> dlst;
	dlst.AddHead(34);
	dlst.AddHead(22);
	dlst.AddHead(58);
	dlst.AddHead(9);
	dlst.AddTail(15);
	dlst.AddTail(85);
	dlst.AddTail(72);
	dlst.AddTail(90);
	dlst.PrintList();
	cout << "list length is " << dlst.GetLength() << endl;
	cout << endl;

	cout << "delete 9 node data" << endl;
	dlst.RemoveAt(dlst.Find(9));
	cout << "delete 90 node data" << endl;
	dlst.RemoveAt(dlst.Find(90));
	dlst.RemoveAt(1);
	dlst.PrintList();
	cout << "list length is " << dlst.GetLength() << endl;
	cout << endl;

	cout << "Insert 69 before 72" << endl;
	dlst.InsertAt(dlst.Find(72), 69);
	cout << "Insert 44 before 58" << endl;
	dlst.InsertAt(dlst.Find(58), 44);
	dlst.PrintList();
	cout << "list length is " << dlst.GetLength() << endl;
	cout << endl;

	cout << "change 22 to 33" << endl;
	dlst.ModifyAt(dlst.Find(22), 33);
	dlst.PrintList();

	cout << "reverse list" << endl;
	dlst.Reverse();
	dlst.PrintList();
	return 0;
}