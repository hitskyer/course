#include <iostream>
using namespace std;


//struct node
//{
//	int data;
//	node(){}
//};
//
//class arr_binary_tree
//{
//public:
//	arr_binary_tree()
//	{
//		size = 20;
//		tree_arrlen = 0;
//		tree = new node[size];
//	}
//
//	~arr_binary_tree()
//	{
//		delete [] tree;
//	}
//
//	inline void insert(int &data)
//	{
//		if (tree_arrlen < size)
//		{
//			tree[++tree_arrlen].data = data;
//		}
//	}
//	void preOrder(int index = 1)
//	{
//		if (tree_arrlen < 1 || index > tree_arrlen)
//		{
//			return;
//		}
//		cout << tree[index].data << " ";
//		preOrder(index * 2);
//		preOrder(index * 2 + 1);
//	}
//	void inOrder(int index = 1)
//	{
//		if (tree_arrlen < 1 || index > tree_arrlen)
//		{
//			return;
//		}
//		inOrder(index*2);
//		cout << tree[index].data << " ";
//		inOrder(index * 2 + 1);
//	}
//	void postOrder(int index = 1)
//	{
//		if (tree_arrlen < 1 || index > tree_arrlen)
//		{
//			return;
//		}
//		inOrder(index*2);
//		inOrder(index * 2 + 1);
//		cout << tree[index].data << " ";
//	}
//private:
//	int size;				// init tree size;
//	int tree_arrlen;			// current data count;
//	node *tree;
//};
//
//int main()
//{
//	arr_binary_tree abtr;
//	for (int i = 1; i < 8; ++i)
//	{
//		abtr.insert(i);
//	}
//	abtr.preOrder();
//	cout << endl;
//	abtr.inOrder();
//	cout << endl;
//	abtr.postOrder();
//	cout << endl;
//	system("pause");
//	return 0;
//}


template <class T>
struct node
{
	T data;
	node<T>(){}
};

template <class T>
class binary_tree
{
private:
	size_t size;
	size_t tree_arrlen;
	node<T>* tree;
public:
	binary_tree(int len = 20):size(len),tree_arrlen(0)
	{
		tree = new node<T> [size];
	}
	~binary_tree()
	{
		delete [] tree;
	}
	void insert(T &data)
	{
		if(tree_arrlen < size)
			tree[++tree_arrlen].data = data;
	}
	void preOrderPrint(size_t index = 1)
	{
		if(tree_arrlen < 1 || index > tree_arrlen)
			return;
		cout << tree[index].data << " ";
		preOrderPrint(index*2);
		preOrderPrint(index*2+1);
	}
	void inOrderPrint(size_t index = 1)
	{
		if(tree_arrlen < 1 || index > tree_arrlen)
			return;
		inOrderPrint(index*2);
		cout << tree[index].data << " ";
		inOrderPrint(index*2+1);
	}
	void postOrderPrint(size_t index = 1)
	{
		if(tree_arrlen < 1 || index > tree_arrlen)
			return;
		postOrderPrint(index*2);
		postOrderPrint(index*2+1);
		cout << tree[index].data << " ";
	}
};

int main()
{
	binary_tree<int> btree;
	for(int i = 1; i < 8; ++i)
		btree.insert(i);
	btree.preOrderPrint();
	cout << endl;
	btree.inOrderPrint();
	cout << endl;
	btree.postOrderPrint();
	return 0;
}
