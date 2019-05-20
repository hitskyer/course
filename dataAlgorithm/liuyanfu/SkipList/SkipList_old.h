#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <cstdlib>
#include <ctime>
#include <climits>

class SkipList{
private:
	struct Node
	{
		Node(int val = INT_MIN):value(val), up(NULL), down(NULL),
			left(NULL), right(NULL){}
		int value;
		struct Node* up;
		struct Node* down;
		struct Node* left;
		struct Node* right;
	};
private:
	Node* head;
	int lvl_num;
	bool randomval();
public:
	SkipList(): lvl_num(1)
	{
		head = new Node();
	}

	void insert(int val);
	bool search(int val);
	void remove(int val);
};
#endif //_SKIPLIST_H