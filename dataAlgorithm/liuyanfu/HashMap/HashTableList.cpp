#include "HashTableList.h"
#include <iostream>
#include <string.h>
using namespace std;

HashTableList::HashTableList(void)
{
	module = 17;
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}


HashTableList::~HashTableList(void)
{
	erase();
}


HashTableList::HashTableList(int nLen):module(nLen)
{
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}


/**
* @brief
*
* @method:    Insert
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  11:51 
*/
bool HashTableList::Insert(const int& data)
{
	int index = Hash(data);
	if(pHeadArr[index] == NULL)
	{
		pHeadArr[index] = new list<HashItem>();
	}
	HashItem *pTemp = new HashItem(data);
	pHeadArr[index]->push_back(*pTemp);
	delete pTemp;
	++nCount;
	return true;
}


/**
* @brief
*
* @method:    Delete
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  12:03 
*/
bool HashTableList::Delete(const int& data)
{
	if(pHeadArr[Hash(data)] == NULL)
		return false;
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for(; it != pHeadArr[index]->end(); ++it)
		{
			if(it->data == data)
			{
				pHeadArr[index]->erase(it);
				--nCount;
				return true;
			}
		}
		return false;
	}
}


/**
* @brief
*
* @method:    Contain
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  11:58 
*/
bool HashTableList::Contain(const int& data)
{
	if(pHeadArr[Hash(data)] == NULL)
		return false;
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for(; it != pHeadArr[index]->end(); ++it)
		{
			if(it->data == data)
				return true;
		}
		return false;
	}
}


/**
* @brief
*
* @method:    Count
* @access:    public 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  11:25 
*/
int HashTableList::Count()
{
	return nCount;
}


/**
* @brief
*
* @method:    Hash
* @access:    private 
* @param:     int key
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  11:27 
*/
int HashTableList::Hash(int key)
{
	return key % module;
}


/**
* @brief
*
* @method:    erase
* @access:    private 
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/10  13:48 
*/
void HashTableList::erase()
{
	for(int i = 0; i < module; ++i)
	{
		if(pHeadArr[i] != NULL)
		{
			delete pHeadArr[i];
			pHeadArr[i] = NULL;
		}
	}
	delete []pHeadArr;
	pHeadArr = NULL;
}


void HashTableList::print()
{
	for(int i = 0; i < module; ++i)
	{
 		if(pHeadArr[i] != NULL)
 		{
 			list<HashItem>::iterator it = pHeadArr[i]->begin();
 			for(; it != pHeadArr[i]->end(); ++it)
 				cout << it->data << " ";
 		}
		cout << endl;
	}
}
