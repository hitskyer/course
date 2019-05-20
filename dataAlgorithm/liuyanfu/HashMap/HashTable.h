#ifndef _HASHTABLE_H
#define _HASHTABLE_H

enum StateType {Empty, Deleted, Active};
struct HashItem
{
	int data;
	StateType info;
	HashItem()
	{
		info = Empty;
	}
	HashItem(int InputData):data(InputData)
	{
		info = Active;
	}
	bool operator ==(const int& InputData)
	{
		return data == InputData;
	}
	bool operator !=(const int& InputData)
	{
		return data != InputData;
	}
};

class HashTable
{
public:
	HashTable();
	~HashTable();
	HashTable(const int len);
	bool Insert(const int data);
	bool Delete(const int data);
	bool Contain(const int data);
	int  Count();
	void print();
private:
	int Hash(int key);
private:
	int module;
	HashItem *pHash;
	int nCount;
};
#endif //_HASHTABLE_H