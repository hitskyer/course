#include "HashTableOpti.h"
#include <iostream>
using namespace std;

HashTableOpti::HashTableOpti(void)
{
	module = 17;
	moduleOld = 0;
	nCount = 0;
	pHash = new HashItem[module];
	factor = 0.75;
}


HashTableOpti::HashTableOpti(const int& nLen, const double& f):
module(nLen), factor(f)
{
	moduleOld = 0;
	nCount = 0;
	pHash = new HashItem[module];
}


HashTableOpti::~HashTableOpti(void)
{
	delete []pHash;
	pHash = NULL;
	if(pHashOld != NULL)
	{
		delete []pHashOld;
		pHashOld = NULL;
	}
}


/**
* @brief
*
* @method:    Insert
* @access:    public 
* @param:     const int & data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/20  11:27 
*/
bool HashTableOpti::Insert(const int& data)
{
	double ret = (double)nCount / module;
	if(ret >= factor)
	{
		Expand();
	}
	int temp = FindValidDataInOldArr();
	if(temp >= 0)
	{
		InsertAssist(pHashOld[temp].data);
		ArrEmpty();
	}
	InsertAssist(data);
	return true;
}


/**
* @brief
*
* @method:    FindValidDataInOldArr
* @access:    private 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/20  14:37 
*/
int HashTableOpti::FindValidDataInOldArr()
{
	if(pHashOld == NULL)
		return -1;
	else
	{
		for(int i = 0; i < moduleOld; ++i)
		{
			if(pHashOld[i].info != Empty && pHashOld[i].info != Deleted)
			{
				pHashOld[i].info = Deleted;
				return i;
			}
		}
		return -1;
	}
}


/**
* @brief
*
* @method:    InsertAssist
* @access:    private 
* @param:     const int & data
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/20  14:39 
*/
void HashTableOpti::InsertAssist(const int &data)
{
	int index = Hash(data, module);
	while(pHash[index].info != Empty && pHash[index].info != Deleted)
	{
		index = index + 1;
	}
	pHash[index].data = data;
	pHash[index].info = Active;
	nCount++;
}


/**
* @brief
*
* @method:    ArrEmpty
* @access:    private 
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/20  12:02 
*/
bool HashTableOpti::ArrEmpty()
{
	if(--nCountOld == 0)
	{
		delete []pHashOld;
		pHashOld = NULL;
		return true;
	}
	return false;
}


/**
* @brief
*
* @method:    Find
* @access:    private 
* @param:     const int & data
* @param:     bool & inOldArr
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/20  12:03 
*/
int HashTableOpti::Find(const int& data, bool& inOldArr)
{
	int nFlag = -1;
	if(pHashOld)
	{
		int index = Hash(data, moduleOld);
		while(pHashOld[index].info != Empty)
		{
			if(pHashOld[index] == data)
			{
				nFlag = index;
				inOldArr = true;
				break;
			}
			index = index + 1;
		}
	}
	if(nFlag < 0)
	{
		int index = Hash(data, module);
		while(pHash[index].info != Empty)
		{
			if(pHash[index] == data)
			{
				nFlag = index;
				inOldArr = false;
				break;
			}
			index = index + 1;
		}
		return nFlag;
	}
	else
	{
		return nFlag;
	}	
}


/**
* @brief
*
* @method:    Delete
* @access:    public 
* @param:     const int & data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/20  13:41 
*/
bool HashTableOpti::Delete(const int& data)
{
	bool bFlag = false;
	int ret = Find(data, bFlag);
	if(ret >= 0 && bFlag)
	{
		pHashOld[ret].info = Deleted;
		ArrEmpty();
		return true;		
	}
	else if(ret >= 0 && !bFlag)
	{
		pHash[ret].info = Deleted;
		--nCount;
		return true;
	}
	else
		return false;
}


/**
* @brief
*
* @method:    Contain
* @access:    public 
* @param:     const int & data
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/20  14:39 
*/
bool HashTableOpti::Contain(const int& data)
{
	bool bFlag = false;
	int ret = Find(data, bFlag);
	if(ret < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


/**
* @brief
*
* @method:    Count
* @access:    public 
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  16:53 
*/
int HashTableOpti::Count()
{
	return nCount + nCountOld;
}


void HashTableOpti::print()
{
	if(pHashOld)
	{
		cout << "member in Old Array is :" << endl;
		for(int i = 0; i < moduleOld; ++i)
		{
			if(pHashOld[i].info != Empty && pHashOld[i].info != Deleted)
			cout << pHashOld[i].data << " ";
		}
		cout << endl;
	}
	cout << "member in Current Array is :" << endl;
	for(int i = 0; i < module; ++i)
	{
		if(pHash[i].info != Empty && pHash[i].info != Deleted)
			cout << pHash[i].data << " ";
	}
	cout << endl;
}


/**
* @brief
*
* @method:    Hash
* @access:    private 
* @param:     int key
* @Return:    int
* @author:    RF_LYF
* @since:   2019/5/10  17:14 
*/
int HashTableOpti::Hash(int key, int mod)
{
	return key % mod;
}


/**
* @brief
*
* @method:    Expand
* @access:    private 
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/20  14:46 
*/
void HashTableOpti::Expand()
{
	moduleOld = module;
	module *= 2;
	pHashOld = pHash;
	nCountOld = nCount;
	nCount = 0;
	pHash = new HashItem[module];
}