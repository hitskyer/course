/*
* Copyright: (c) 2019
*
* 文件名称:  SkipList.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/14  8:50
*/

#include "SkipList.h"
#include <stdlib.h>
#include <time.h>

template<typename T>
SkipList<T>::SkipList(void)
{
	levelCount = 1;
	head = new SNode<T>();
}


template<typename T>
SkipList<T>::~SkipList(void)
{
	//clear();
}


template<typename T>
void SkipList<T>::Insert(const T value)
{
	int level = randomLevel();
	cout << "current level is " << level << endl;
	pSNode newNode = new SNode<T>(); 
	newNode->data = value;
	newNode->maxLevel = level;

	pSNode* update = new pSNode[level];
	InitArr(update, level);
	for(int i = 0; i < level; ++i)
	{
		update[i] = head;
	}

	pSNode p = head;
	for(int i = level - 1; i >= 0; --i)
	{
		while(p->forward[i] != NULL && p->forward[i]->data < value)
			p = p->forward[i];
		update[i] = p;
	}

	for(int i = 0; i < level; ++i)
	{
		newNode->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = newNode;
	}

	if(levelCount < level)
		levelCount = level;
	delete []update;
}


template<typename T>
void SkipList<T>::Delete(const T value)
{
	pSNode *update = new pSNode[levelCount];
	InitArr(update, levelCount);
	pSNode p = head;
	for(int i = levelCount - 1; i >= 0; --i)
	{
		while(p->forward[i] != NULL && p->forward[i]->data < value)
			p = p->forward[i];
		update[i] = p;
	}

	if(p->forward[0] != NULL && p->forward[0]->data == value)
	{
		for(int i = levelCount - 1; i >=0; --i)
		{
			if(update[i]->forward[i] != NULL && update[i]->forward[i]->data == value)
			{
				pSNode delptr = update[i]->forward[i];
				update[i]->forward[i] = update[i]->forward[i]->forward[i];
				delete delptr;
			}
		}
	}
	delete []update;
}


template<typename T>
typename SkipList<T>::pSNode SkipList<T>::Find(const T value)
{
	pSNode p = head;
	for(int i = levelCount - 1; i >=0; --i)
	{
		while(p->forward[i] != NULL && p->forward[i]->data < value)
			p = p->forward[i];
	}
	if(p->forward[0] != NULL && p->forward[0]->data == value)
		return p->forward[0];
	else
		return NULL;
}


template<typename T>
int SkipList<T>::randomLevel()
{
	int level = 1;
	unsigned int seed = NULL;
	for(int i = 1; i < MAX_LEVEL; ++i)
	{
		if(seed == NULL)
			seed = (unsigned)(time(NULL));
		srand(seed);
		int ret = rand() % 2;
		seed = rand() % (MAX_LEVEL - i);
		if(ret == 1)
			level++;
	}
	return level;
}


template<typename T>
void SkipList<T>::InitArr(typename SkipList<T>::pSNode* Arr, int nLen)
{
	for(int i = 0; i < nLen; ++i)
	{
		Arr[i] = NULL;
	}
}


template<typename T>
void SkipList<T>::printAll()
{
	pSNode p = head;
	while(p->forward[0] != NULL)
	{
		std::cout << p->forward[0]->data << std::endl;
		p = p->forward[0];
	}
}


template<typename T>
void SkipList<T>::printByLayer()
{
	pSNode p = head;
	for(int i = levelCount -1; i >= 0; --i)
	{
		if(p->forward[i] != NULL)
			std::cout << "第" << i + 1 << "层" << std::endl;
		while(p->forward[i] != NULL)
		{
			std::cout << p->forward[i]->data << " ";
			p = p->forward[i];
		}
		std::cout << endl;
	}
}


template<typename T>
void SkipList<T>::clear()
{
	pSNode p = head;
	for(int i = levelCount - 1; i >= 0; --i)
	{
		while(p->forward[i] != NULL)
		{
			pSNode delptr = p->forward[i];
			p->forward[i] = p->forward[i]->forward[i];
			delete delptr;
		}
	}
	delete head;
	head = NULL;
}