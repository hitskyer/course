/*
* Copyright: (c) 2019
*
* 文件名称:  HashTableOpti.h	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/10  16:36
*/

#ifndef _HASHTABLEOPTI_H
#define _HASHTABLEOPTI_H
enum StateType {Empty, Active, Deleted};
struct HashItem
{
	int data;
	StateType info;
	HashItem()
	{
		info = Empty;
	}
	HashItem(const int& InputData)
	{
		data = InputData;
		info = Active;
	}
	bool operator == (const int& InputData)
	{
		return data == InputData;
	}
	bool operator != (const int& InputData)
	{
		return data != InputData;
	}
};
class HashTableOpti
{
public:
	HashTableOpti(void);
	HashTableOpti(const int& nLen, const double& f);
	~HashTableOpti(void);

	bool Insert(const int& data);
	bool Delete(const int& data);
	bool Contain(const int& data);
	int Count();
	void print();
private:
	int Hash(int key, int mod);
	void Expand();
	bool ArrEmpty();
	int Find(const int& data, bool& inOldArr);
	void InsertAssist(const int &data);
	int FindValidDataInOldArr();
private:
	int module;
	int moduleOld;
	int nCount;
	int nCountOld;
	HashItem* pHash;
	HashItem* pHashOld;
	double factor;
};

#endif //_HASHTABLEOPTI_H