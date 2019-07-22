#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include <iostream>
template<typename T>
struct Node
{
	T data;
	Node* pLeft;
	Node* pRight;
	Node(T d)
	{
		data = d;
		pLeft = NULL;
		pRight = NULL;
	}
};

template<typename T>
class BinarySearchTree
{
	typedef Node<T>* pNode;
	typedef Node<T>  NodeType;
public:
	BinarySearchTree(void);
	~BinarySearchTree(void);

	void Insert(const T data);
	void Delete(const T data);
	const pNode Find(const T data) const;
	const pNode FindMin() const;
	const pNode FindMax() const;
	void PreOrder() const;
	void InOrder() const;
	void PostOrder() const;
	void LevelOrder() const;
	int GetHeight() const;
	const pNode GetRoot() const;

	void PreOrder_recursion(pNode p) const;
	void InOrder_recursion(pNode p) const;
	void PostOrder_recursion(pNode p)const;
	int  GetHeight_recursion(pNode p) const;
private:
	pNode pRoot;
	void Erase(pNode del);
	

};

#endif //_BINARY_SEARCH_TREE