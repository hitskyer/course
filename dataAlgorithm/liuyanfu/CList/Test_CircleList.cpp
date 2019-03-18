#include <iostream>
#include "CircleList.cpp"

using namespace std;


int main()
{
	CCircleList<int> clst;
	clst.PushBack(22);
	clst.PushFront(23);
	clst.PushBack(34);
	clst.PushFront(76);
	clst.PushBack(59);
	clst.PushFront(98);
	clst.PrintList();
	cout << endl;

	cout << "the HeadNode is : " << clst.GetHead()->data << endl;
	cout << "the MidNode is : " << clst.GetMidNode()->data << endl;
	cout << "Insert 66 before 59" << endl;
	clst.InsertAt(clst.Find(59), 66);
	clst.PrintList();
	cout << endl;

	cout << "delete 76" << endl;
	clst.RemoveAt(clst.Find(76));
	clst.PrintList();
	cout << endl;

	cout << "reverse list" << endl;
	clst.Reverse();
	clst.PrintList();

	cout << endl;
	cout << "print 3th data of the list: " << clst.FindByIndex(3)->data << endl;

	CCircleList<int> clst2;
	clst2.PushBack(20);
	clst2.PushFront(33);
	clst2.PushBack(65);
	clst2.PushFront(12);
	clst2.PushBack(80);
	clst2.PushFront(100);
	cout << "print the second list" << endl;
	clst2.PrintList();

	cout << "merge two list" << endl;
	clst.MergeList(clst2);
	clst.PrintList();

	system("pause");
	return 0;
}