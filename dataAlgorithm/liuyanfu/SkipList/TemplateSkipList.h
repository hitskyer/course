#ifndef _TEMPLATE_SKIPLIST_H
#define _TEMPLATE_SKIPLIST_H

#include <ctime>
#include <cstdlib>
template<typename T>
class Entry
{
private:
	int key;
	T value;
	Entry* pNext;
	Entry* pDown;
public:
	Entry(int k, T v):key(k), value(v), pNext(NULL), pDown(NULL){}
	Entry(const Entry& e): key(e.key), value(e.value), pNext(NULL), pDown(NULL){}
public:
	bool operator < (const Entry& right)
	{
		return key < right.key
	}
	bool operator > (const Entry& right)
	{
		return key > right.key;
	}
	bool operator <=(const Entry& right)
	{
		return key <= right.key;
	}
	bool operator >= (const Entry& right)
	{
		return key >= right.key;
	}
	bool operator == (const Entry& right)
	{
		return key = right.key;
	}
	Entry* & next()
	{
		return pNext;
	}
	Entry* & down()
	{
		return pDown;
	}
};

template<typename T>
class TSkipList
{
private:
	struct Endpoint
	{
		Endpoint* up;
		Endpoint* down;
		Entry<T>* right;
	};

	struct Endpoint* header;
	int lvl_num;
	unsigned int seed;
	bool random()
	{
		srand(seed);
		int ret = rand() % 2;
		seed = rand();
		return ret == 0;
	}
public:
	TSkipList():lvl_num(1), seed(time(0))
	{
		header = new Endpoint();
	}

	void insert(const Entry<T>* entry)
	{
		Endpoint* cur_header = header;
		while(cur_header->down != NULL)
			cur_header = cur_header->down;

		int cur_lvl = 0;
		Entry<T>* temp_entry = NULL;
		do 
		{
			Entry<T>* cur_cp_entry = new Entry<T>(*entry);
			cur_lvl++;
			if(lvl_num < cur_lvl)
			{
				lvl_num++;
				Endpoint* new_header = new Endpoint();
				new_header->down = header;
				header->up = new_header;
				header = new_header;
			}

			if(cur_lvl != 1)
			{
				cur_header = cur_header->up;
				cur_cp_entry->down() = temp_entry;
			}
			temp_entry = cur_cp_entry;
			if(cur_header->right == NULL)
			{
				cur_header->right = cur_cp_entry;
				break;
			}
			else
			{
				Entry<T>* cursor = cur_header->right;
				while(true)
				{
					if(*cur_cp_entry < *cursor)
					{
						cur_header->right = cur_cp_entry;
						cur_cp_entry->next() = cursor;
						break;
					}
					else if(cursor->next() == NULL)
					{
						cursor->next() = cur_cp_entry;
						break;
					}
					else if(*cur_cp_entry < *cursor->next())
					{
						cur_cp_entry->next() = cursor->next();
						cursor->next() = cur_cp_entry;
						break;
					}
					cursor = cursor->next();
				}
			}

		} while (random());
	}

	bool search(Entry<T>* entry) const
	{
		if(header->right == NULL)
			return false;
		Endpoint* cur_header = header;
		for(int i = 0; i < lvl_num; ++i)
		{
			if(*entry < *cur_header->right)
				cur_header = cur_header->down;
			else
			{
				Entry<T>* cursor = cur_header->right;
				while(cursor->down() != NULL)
				{
					while(cursor->next() != NULL)
					{
						if(*entry <= cursor->next())
							break;
						cursor = cursor->next();
					}
					cursor = cursor->down();
				}
				while(cursor->next() != NULL)
				{
					if(*entry > cursor->next())
						cursor = cursor->next();
					else if(*entry == *cursor->next())
						return true;
					else
						return false;
				}
				return false;
			}
		}
		return false;
	}


	void remove(Entry<T>* entry)
	{
		if(header->right == NULL)
			return;
		Endpoint* cur_header = header;
		Endpoint* cursor = header->right;
		int lvl_counter = lvl_num;
		for(int i = 0; i < lvl_num; ++i)
		{
			if(*entry == cur_header->right)
			{
				Entry<T>* delptr = cur_header->right;
				cur_header->right = cur_header->right->next();
				delete delptr;
			}
			else
			{
				Entry<T>* cursor = cur_header->right;
				while(cursor->next() != NULL)
				{
					if(*entry == cursor->next())
					{
						Entry<T>* delptr = cursor->next();
						cursor->next() = cursor->next()->next();
						delete delptr;
						break;
					}
					cursor = cursor->next();
				}
			}
			if(cur_header->right == NULL)
			{
				Endpoint* delheader = cur_header;
				cur_header = cur_header->down;
				header = cur_header;
				delete delheader;
				lvl_num--;
			}
			else
				cur_header = cur_header->down;
		}
	}
};


#endif // _TEMPLATE_SKIPLIST_H