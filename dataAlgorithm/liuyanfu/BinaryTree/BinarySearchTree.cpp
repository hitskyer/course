#include "BinarySearchTree.h"
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

template<typename T>
BinarySearchTree<T>::BinarySearchTree(void)
{
	pRoot = NULL;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(void)
{
	Erase(pRoot);
}


template<typename T>
void BinarySearchTree<T>::Insert(const T data)
{
	if(pRoot == NULL)
	{
		pRoot = new NodeType(data);
		return;
	}
	pNode pTemp = pRoot;
	while(pTemp)
	{
		if(data < pTemp->data)
		{
			if(pTemp->pLeft == NULL)
			{
				pTemp->pLeft = new NodeType(data);
				return;
			}
			pTemp = pTemp->pLeft;
		}
			
		else
		{
			if(pTemp->pRight == NULL)
			{
				pTemp->pRight = new NodeType(data);
				return;
			}
			pTemp = pTemp->pRight;
		}
	}
}


template<typename T>
void BinarySearchTree<T>::Delete(const T data)
{
	pNode CurNode = pRoot;
	pNode fNode = NULL;
	pNode ChildNode;
	while(CurNode && data != CurNode->data)
	{
		fNode = CurNode;
		if(data < CurNode->data)
			CurNode = CurNode->pLeft;
		if(data > CurNode->data)
			CurNode = CurNode->pRight;
	}
	if(CurNode == NULL)
		return;
	//被删除的节点有两个子节点的情况
	if(CurNode->pLeft && CurNode->pRight)
	{
		pNode minp = CurNode->pRight;
		pNode minpp = CurNode;
		while(minp->pLeft)
		{
			minpp = minp;
			minp = minp->pLeft;
		}
		CurNode->data = minp->data;
		CurNode = minp;
		fNode = minpp;
	}
	//被删除的节点有一个子节点或者没有子节点的情况
	if(CurNode->pLeft)
		ChildNode = CurNode->pLeft;
	else if(CurNode->pRight)
		ChildNode = CurNode->pRight;
	else
		ChildNode = NULL;
	if(fNode == NULL)
	{
		delete pRoot;
		pRoot = ChildNode;
	}
	else if(fNode->pLeft == CurNode)
	{
		delete CurNode;
		fNode->pLeft = ChildNode;
	}
	else
	{
		delete CurNode;
		fNode->pRight = ChildNode;
	}
}


template<typename T>
const typename BinarySearchTree<T>::pNode BinarySearchTree<T>::Find(const T data) const
{
	pNode pTemp = pRoot;
	while(pTemp)
	{
		if(data == pTemp->data)
			return pTemp;
		else if(data < pTemp->data)
			pTemp = pTemp->pLeft;
		else
			pTemp = pTemp->pRight;
	}
	return NULL;
}


template<typename T>
const typename BinarySearchTree<T>::pNode BinarySearchTree<T>::FindMin() const
{
	pNode pTemp = pRoot;
	if(pTemp == NULL)
		return NULL;
	while(pTemp->pLeft)
	{
		pTemp = pTemp->pLeft;
	}
	return pTemp;
}


template<typename T>
const typename BinarySearchTree<T>::pNode BinarySearchTree<T>::FindMax() const
{
	pNode pTemp = pRoot;
	if(pTemp == NULL)
		return NULL;
	while(pTemp->pRight)
	{
		pTemp = pTemp->pRight;
	}
	return pTemp;
}


template<typename T>
void BinarySearchTree<T>::PreOrder() const
{
	if(pRoot == NULL)
		return;
	else
	{
		stack<pNode> st;
		pNode pTemp = pRoot;
		st.push(pTemp);
		while(!st.empty())
		{
			pTemp = st.top();
			cout << pTemp->data << "->";
			st.pop();
			if(pTemp->pRight)
				st.push(pTemp->pRight);
			if(pTemp->pLeft)
				st.push(pTemp->pLeft);
		}
	}
}


template<typename T>
void BinarySearchTree<T>::InOrder() const
{
	if(pRoot == NULL)
		return;
	else
	{
		pNode pTemp = pRoot;
		stack<pNode> st;
		while(pTemp || !st.empty())
		{
			while(pTemp)
			{
				st.push(pTemp);
				pTemp = pTemp->pLeft;
			}
			if(!st.empty())
			{
				pTemp = st.top();
				cout << pTemp->data << "->";
				st.pop();
				pTemp = pTemp->pRight;
			}
		}
	}
}

template<typename T>
void BinarySearchTree<T>::PostOrder() const
{
	if(pRoot == NULL)
		return;
	else
	{
		pNode pTemp = pRoot;
		stack<pNode> st;
		pNode temp = NULL;
		while(pTemp || !st.empty())
		{
			if(pTemp)
			{
				st.push(pTemp);
				pTemp = pTemp->pLeft;
			}
			else
			{
				pTemp = st.top();
				if(pTemp->pRight && pTemp->pRight != temp)
				{
					pTemp = pTemp->pRight;
				}
				else
				{
					cout << pTemp->data << "->";
					st.pop();
					temp = pTemp;
					pTemp = NULL;
				}
			}
		}
	}
}


template<typename T>
void BinarySearchTree<T>::LevelOrder() const
{
	if(pRoot == NULL)
		return;
	else
	{
		queue<pNode> que;
		que.push(pRoot);
		while(!que.empty())
		{
			pNode pTemp = que.front();
			que.pop();
			cout << pTemp->data << "->";
			if(pTemp->pLeft)
				que.push(pTemp->pLeft);
			if(pTemp->pRight)
				que.push(pTemp->pRight);
		}
	}
}


template<typename T>
int BinarySearchTree<T>::GetHeight_recursion(pNode p) const
{
	if(p == NULL)
		return 0;
	else
	{
		int leftHeight = Height(p->pLeft);
		int rightHeight = Height(p->pRight);
		return max(leftHeight, rightHeight) + 1;
	}
}


template<typename T>
const typename BinarySearchTree<T>::pNode BinarySearchTree<T>::GetRoot() const
{
	return pRoot;
}



template<typename T>
void BinarySearchTree<T>::Erase(pNode del)
{
	if(del == NULL)
		return;
	else
	{
		Erase(del->pLeft);
		Erase(del->pRight);
		delete del;
		del = NULL;
	}
}


template<typename T>
int BinarySearchTree<T>::GetHeight() const
{
	if(pRoot == NULL)
		return 0;
	else
	{
		queue<pNode> que;
		que.push(pRoot);
		int height = 0;
		while(!que.empty())
		{
			height++;
			int width = que.size();
			for(int i = 0; i < width; ++i)
			{
				pNode pTemp = que.front();
				que.pop();
				if(pTemp->pLeft)
					que.push(pTemp->pLeft);
				if(pTemp->pRight)
					que.push(pTemp->pRight);
			}
		}
		return height;
	}
}


template<typename T>
void BinarySearchTree<T>::PreOrder_recursion(pNode p) const
{
	if(p == NULL)
		return;
	else
	{
		cout << p->data << "->";
		PreOrder_recursion(p->pLeft);
		PreOrder_recursion(p->pRight);
	}
}


template<typename T>
void BinarySearchTree<T>::InOrder_recursion(pNode p) const
{
	if(p == NULL)
		return;
	else
	{
		InOrder_recursion(p->pLeft);
		cout << p->data << "->";
		InOrder_recursion(p->pRight);
	}
}


template<typename T>
void BinarySearchTree<T>::PostOrder_recursion(pNode p)const
{
	if(p == NULL)
		return;
	else
	{
		PostOrder_recursion(p->pLeft);
		PostOrder_recursion(p->pRight);
		cout << p->data << "->";
	}
}