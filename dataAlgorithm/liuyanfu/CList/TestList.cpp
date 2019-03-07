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

	cout << "The First Node is: " << lst.GetHeadNode()->data << endl;
	cout << "The Last Node is:  " << lst.GetTailNode()->data << endl;
	cout << "The Length of current list is: "   << lst.GetSize() << endl;

	int a = 0;
	cout << "Enter a Number to find ";
	cin >> a;
	if(!lst.Find(a))
		cout << "This Number is not exist in current list!" << endl;
	else
		cout << "I find it. It is  " << lst.Find(a)->data << endl;

	cout << endl;
	cout << "Remove special node" << endl;
	lst.RemoveAt(lst.GetNode(21));
	lst.PrintList();
	cout << "The length of current list:  "   << lst.GetSize() << endl;

	cout << endl;
	cout << "Insert data in list" << endl;
	lst.InsertAt(lst.GetNode(28), 88);
	lst.PrintList();
	cout << "The length of current list:  "   << lst.GetSize() << endl;

	cout << endl;
	cout << "Modify data of specail node" << endl;
	lst.ModifyAt(lst.GetNode(89), 99);
	lst.PrintList();
	cout << "The length of current list:  "   << lst.GetSize() << endl;
	
	lst.Erase();
	return 0;
}
