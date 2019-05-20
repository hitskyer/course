#ifndef _HASHTABLELIST_H
#define _HASHTABLELIST_H
#include <list>
enum StateType {Empty, Deleted, Active};
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
};
class HashTableList
{
public:
	HashTableList(void);
	HashTableList(int nLen);
	~HashTableList(void);
	bool Insert(const int& data);
	bool Delete(const int& data);
	bool Contain(const int& data);
	int Count();
	void print();
private:
	int Hash(int key);
	void erase();
	
	typedef std::list<HashItem>* NodeType;
private:
	int module;
	NodeType *pHeadArr;
	int nCount;
};

#endif // _HASHTABLELIST_H