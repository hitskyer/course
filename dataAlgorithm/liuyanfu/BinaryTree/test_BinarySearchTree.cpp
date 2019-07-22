#include "BinarySearchTree.cpp"

int main()
{
	BinarySearchTree<char> bst;
	bst.Insert('K');
	bst.Insert('G');
	bst.Insert('Q');
	bst.Insert('C');
	bst.Insert('H');
	bst.Insert('B');
	bst.Insert('D');
	bst.Insert('M');
	bst.Insert('Y');
	bst.Insert('P');
	bst.PreOrder();
	cout << endl;
	bst.InOrder();
	cout << endl;
	bst.PostOrder();
	cout << endl;
	bst.LevelOrder();
	cout << endl;
	cout << bst.GetHeight() << endl;
	cout << bst.Find('M')->data << endl;;
	bst.Delete('M');
	bst.PreOrder();
	cout << endl;
	bst.Delete('B');
	bst.PreOrder();
	cout << endl;
	bst.Delete('K');
	bst.PreOrder();
	cout << endl;
	cout << bst.FindMin()->data << endl;
	cout << bst.FindMax()->data << endl;
	return 0;
}