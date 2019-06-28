#include "HashTableList.h"
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/****************************************************************
* @brief : 		初始化散列链表
* @author : 	dyx
* @date : 		2019/6/28 14:03
* @version : 	ver 1.0
* @inparam :	余数默认取17，且开辟17的容量的指针数组
* @outparam :	
*****************************************************************/
HashTableList::HashTableList(void)
{
	module = 17;
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}

/****************************************************************
* @brief : 		允许初始化指针数组长度
* @author : 	dyx
* @date : 		2019/6/28 14:23
* @version : 	ver 1.0
* @inparam :	
* @outparam :	
*****************************************************************/
HashTableList::HashTableList(int nLen):module(nLen)
{
	if (nLen <= 0)
	{
		return;
	}
	nCount = 0;
	pHeadArr = new NodeType[module];
	memset((void *)pHeadArr, 0, module*sizeof(NodeType));
}

HashTableList::~HashTableList(void)
{
	erase();
}

/****************************************************************
* @brief : 		插入数据
* @author : 	dyx
* @date : 		2019/6/28 14:25
* @version : 	ver 1.0
* @inparam :	需要插入的数
* @outparam :	成功，则返回true
*****************************************************************/
bool HashTableList::Insert(const int &data)
{
	int index = Hash(data);		// get index
	if (pHeadArr[index] == NULL)
	{
		pHeadArr[index] = new list<HashItem>;
	}
	HashItem *pTemp = new HashItem(data);
	pHeadArr[index]->push_back(*pTemp);
	delete pTemp;
	++nCount;
	return true;
}

/****************************************************************
* @brief : 		删除存在的某个元素
* @author : 	dyx
* @date : 		2019/6/28 14:26
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool HashTableList::Delete(const int &data)
{
	if (pHeadArr[Hash(data)] == NULL)
	{
		return false;
	}
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for (; it != pHeadArr[index]->end(); ++it)
		{
			if (it->data == data)
			{
				pHeadArr[index]->erase(it);
				--nCount;
				return true;
			}
		}
		return false;
	}
}

/****************************************************************
* @brief : 		是否包含某个元素
* @author : 	dyx
* @date : 		2019/6/28 14:31
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool HashTableList::Contain(const int &data)
{
	if (pHeadArr[Hash(data)] == NULL)
	{
		return false;
	}
	else
	{
		int index = Hash(data);
		list<HashItem>::iterator it = pHeadArr[index]->begin();
		for (; it != pHeadArr[index]->end(); ++it)
		{
			if (it->data == data)
			{
				return true;
			}
		}
		return false;
	}
}

/****************************************************************
* @brief : 		目前含有多少元素
* @author : 	dyx
* @date : 		2019/6/28 14:32
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int HashTableList::Count()
{
	return nCount;
}

/****************************************************************
* @brief : 		对输入的数字取模
* @author : 	dyx
* @date : 		2019/6/28 14:32
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int HashTableList::Hash(int key)
{	
	if (key < 0)
	{
		return -1;
	}
	return key%module;
}

/****************************************************************
* @brief : 		删除某个元素
* @author : 	dyx
* @date : 		2019/6/28 14:33
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HashTableList::erase()
{
	for (int i = 0; i < module; ++i)
	{
		if (pHeadArr[i] != NULL)
		{
			delete pHeadArr[i];
			pHeadArr[i]= NULL;
		}
	}
	delete []pHeadArr;
	pHeadArr = NULL;
}

/****************************************************************
* @brief : 		打印测试
* @author : 	dyx
* @date : 		2019/6/28 14:33
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HashTableList::print()
{
	for (int i = 0; i < module; ++i)
	{
		if (pHeadArr[i] != NULL)
		{
			list<HashItem>::iterator it = pHeadArr[i]->begin();
			for (; it != pHeadArr[i]->end(); ++it)
			{
				cout << it->data << "-" << it->info << "  ";
			}
			cout <<endl;
		}
		else
			cout << endl;
	}
}

/****************************************************************
* @brief : 		平方取中法。处理手机后四位。
* @author : 	dyx
* @date : 		2019/6/27 19:26
* @version : 	ver 1.0
* @inparam :  输入为4位数的整数，对其进行求平方，然后输出中间的三位数。如果有8位，则前3位，中间3位，后2位。取中间3位。
* @outparam : 
*****************************************************************/
int HashTableList::hashFunc_1(int num)
{
	if (num < 1000 && num > 9999)
	{
		return -1;
	}
	int square = 0;
	int count = 0;
	square = num * num;
	while (square > 0)
	{
		square /= 10;
		++count;
	}
	int back = 0;
	back = (count - 3)/2;

	return num / back % 1000;
}

/****************************************************************
* @brief : 		除余取模
* @author : 	dyx
* @date : 		2019/6/27 19:47
* @version : 	ver 1.0
* @inparam :  原始数据，模。 通常，模取小于等于原始数据的质数。
* @outparam : 
*****************************************************************/
int HashTableList::hashFunc_2(int num, int mod)
{
	if (num <0 || mod <= 0)
	{
		return -1;
	}
	return num % mod;
}

/****************************************************************
* @brief : 		随机数法。
* @author : 	dyx
* @date : 		2019/6/27 19:51
* @version : 	ver 1.0
* @inparam :	输入的数据，大小不确定时，位数不确定时，建议使用。
* @outparam :	控制输出为4位之内的数
*****************************************************************/
int HashTableList::hashFunc_3(int num)
{
	int result; 
	srand(num);
	result = rand();
	if (result > 9999)
	{
		result%=1000;
	}
	return result;
}
