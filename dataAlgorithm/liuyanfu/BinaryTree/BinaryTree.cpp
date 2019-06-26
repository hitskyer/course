#include "BinaryTree.h"
#include <iostream>
using namespace std;

template<typename T>
BinaryTree::BinaryTree(void)
{
	nLen = 20;
	pRoot = new T[nLen];
	memset(pRoot, NULL, nLen * sizeof(T));
	nCount = 0;
}


template<typename T>
BinaryTree::BinaryTree(const int& length):nLen(length)
{
	pRoot = new T[nLen];
	memset(pRoot, NULL, nLen * sizeof(T));
	nCount = 0;
}


template<typename T>
BinaryTree::~BinaryTree(void)
{
	delete []pRoot;
	pRoot = NULL;
}


/**
* @brief	节点->左子树->右子树
*
* @method:    PreOrder
* @access:    public 
* @param:     const int& index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/20  16:44 
*/
template<typename T>
void BinaryTree::PreOrder(const int& index)
{
	if(pRoot == NULL || nCount == 0)
		return;
	cout << pRoot[index] << endl;
	if(2*index + 1 < nCount)
		PreOrder(2*index + 1);
	if(2*index + 2 < nCount)
		PreOrder(2*index + 2);
}



/**
* @brief	左子树-》节点-》右子树
*
* @method:    InOrder
* @access:    public 
* @param:     const int & index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/20  17:18 
*/
template<typename T>
void BinaryTree::InOrder(const int& index)
{
	if(pRoot == NULL || nCount == 0)
		return;
	else
	{
		if(2*index+1 < nCount)
			InOrder(2*index+1);
		cout << pRoot[index] << endl;
		if(2*index+2 < nCount)
			InOrder(2*index+2);
	}
}


/**
* @brief
*
* @method:    PostOrder
* @access:    public 
* @param:     const int & index
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/20  16:45 
*/
template<typename T>
void BinaryTree::PostOrder(const int & index)
{
	if(pRoot == NULL || length == 0)
		return;
	if(pRoot[2*index+1] < nCount)
		PostOrder(2*index+1);
	if(pRoot[2*index+2] < nCount)
		PostOrder(2*index+2);
	cout << pRoot[index] << endl;
}

int Height();
int Length();