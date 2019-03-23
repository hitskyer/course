#include <iostream>
#include "CircleListNH.cpp"
using namespace std;


int main()
{
	CircleListNH<int> clst;
	clst.AddHead(33);
	clst.RemoveAt(clst.GetHeadNode());

	clst.AddHead(33);
	clst.AddHead(32);
	clst.AddHead(31);
	
	cout << "The Find Node data is: " << clst.Find(31)->data << endl;
	clst.InsertAt(clst.GetNode(31), 30);

	clst.PrintList();
	clst.RemoveAt(clst.GetHeadNode());
	cout << "The Head Node data is : " << clst.GetHeadNode()->data << endl;
	clst.RemoveAt(clst.GetTailNode());
	cout << "The Tail Node data is : " << clst.GetTailNode()->data << endl;
	clst.PrintList();
	return 0;
}