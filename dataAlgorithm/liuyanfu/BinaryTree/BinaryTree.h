/*
* Copyright: (c) 2019
*
* 文件名称:  BinaryTree.h	
* 文件标识： 
* 摘	要： 顺序存储法,没有实现动态扩容，因此只能存放有限个数
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/20  15:56
*/

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
template<typename T>
class BinaryTree
{
public:
	BinaryTree(void);
	BinaryTree(const int& length);
	~BinaryTree(void);

	void PreOrder(const int& index);
	void InOrder(const int& index);
	void PostOrder(const int& index);
	
	void Insert(const T& data);
	void Delete(const T& data);
	const T& find(const T& data);

	int Height();
	int Length();
private:
	T* pRoot;
	int nCount;
	int nLen;
};

#endif