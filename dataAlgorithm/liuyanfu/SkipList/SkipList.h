/*
* Copyright: (c) 2019
*
* 文件名称:  SkipList.h	
* 文件标识：
* 摘	要： 跳表的一种实现方法，跳表中存储的是正整数，并且存储的是不重复的
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/14  8:51
*/

#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <iostream>
#define MAX_LEVEL 16

template<typename T>
class SNode
{
public:
	typedef SNode<T>* pSNode;
	SNode()
	{
		maxLevel = 0;
		forward = new pSNode[MAX_LEVEL];
		for(int i = 0; i < MAX_LEVEL; ++i)
		{
			forward[i] = NULL;
		}
	}
	~SNode()
	{
		delete []forward;
	}
	T data;
	int maxLevel;
	pSNode *forward;
};

template<typename T>
class SkipList
{
	typedef SNode<T>* pSNode;
public:
	SkipList(void);
	~SkipList(void);

	void Insert(const T value);
	void Delete(const T value);
	pSNode Find(const T value);
	void printAll();
	void printByLayer();
private:
	int randomLevel();
	void InitArr(pSNode*, int);
	void clear();
private:
	int levelCount;
	pSNode head;
};
#endif //_SKIPLIST_H
