/*
* Copyright: (c) 2019
*
* 文件名称:  HashTable.cpp	
* 文件标识：
* 摘	要：该散列表不能存放重复数据
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/9  22:29
*/

#include "HashTable.h"
#include <iostream>
using namespace std;
HashTable::HashTable()
{
	module = 17;
	pHash = new HashItem[module];
	nCount = 0;
}

HashTable::HashTable(const int len):module(len)
{
	pHash = new HashItem[module];
	nCount = 0;
}

HashTable::~HashTable()
{
	delete []pHash;
	pHash = NULL;
}

/**
* @brief
*
* @method:    Insert
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  10:38 
*/
bool HashTable::Insert(const int data)
{
	if(nCount == module)
		return false;
	else
	{
		nCount++;
		int index = Hash(data);
		while(pHash[index].info != Empty && pHash[index].info != Deleted)
		{
			index = index + 1;
		}
		pHash[index] = data;
		return true;
	}
}

/**
* @brief
*
* @method:    Delete
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  10:38 
*/
bool HashTable::Delete(const int data)
{
	int index = Hash(data);
	while(pHash[index] != data)
	{
		index = index + 1;
		if(pHash[index].info == Empty || index == Hash(data))
			return false;//数据不存在
	}
	pHash[index].info = Deleted;
	nCount--;
	return true;
}

/**
* @brief
*
* @method:    Count
* @access:    public 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  10:20 
*/
int  HashTable::Count()
{
	return nCount;
}

/**
* @brief
*
* @method:    Contain
* @access:    public 
* @param:     int data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/10  10:25 
*/
bool HashTable::Contain(const int data)
{
	if(pHash[Hash(data)] == data)
		return true;
	else
	{
		int index = Hash(data);
		while(pHash[index] != data)
		{
			index = index + 1;
			if(pHash[index].info == Empty || index == Hash(data))
				return false;
		}
		return true;
	}
}


/**
* @brief      除留法
*
* @method:    Hash
* @access:    private 
* @param:     int key
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  10:11 
*/
int HashTable::Hash(int key)
{
	return key % module;
}


/**
* @brief	  用来测试程序
*
* @method:    print
* @access:    public
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/10  14:24 
*/
void HashTable::print()
{
	for(int i = 0; i < module; ++i)
	{
		if(pHash[i].info != Empty && pHash[i].info != Deleted)
			cout << pHash[i].data << endl;
	}
}