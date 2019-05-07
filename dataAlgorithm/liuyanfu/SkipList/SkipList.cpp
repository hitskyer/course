/*
* Copyright: (c) 2019
*
* 文件名称:  SkipList.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/5  22:27
*/

#include "SkipList.h"

static unsigned int seed = NULL;


/**
* @brief
*
* @method:    randomval
* @access:    private 
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/5  22:38 
*/
bool SkipList::randomval()
{
	if(seed == NULL)
		seed = (unsigned)time(NULL);
	::srand(seed);
	int ret = ::rand() % 2;
	seed = ::rand();
	if(ret == 0)
		return true;
	else
		return false;
}

/**
* @brief
*
* @method:    insert
* @access:    public 
* @param:     int val
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/5  22:41 
*/
void SkipList::insert(int val)
{
	Node* cursor = head;
	Node* newNode = NULL;
	while(cursor->down != NULL)
		cursor = cursor->down;
	
	Node* cur_head = cursor;
	while(cursor->right != NULL)
	{
		if(val < cursor->right->value && newNode == NULL)
		{
			newNode = new Node(val);
			newNode->right = cursor->right;
			cursor->right = newNode;
		}
		cursor = cursor->right;
	}
	if(newNode == NULL)
	{
		newNode = new Node(val);
		cursor->right = newNode;
	}

	int cur_lvl = 1;
	while(randomval())
	{
		cur_lvl++;
		if(lvl_num < cur_lvl)
		{
			lvl_num++;
			Node* new_head = new Node();
			new_head->down = head;
			head->up = new_head;
			head = new_head;
		}
		cur_head = cur_head->up;
		cursor = cur_head;
		Node* skipNode = NULL;
		while(cursor->right != NULL)
		{
			if(val < cursor->right->value && skipNode == NULL)
			{
				skipNode = new Node(val);
				skipNode->right = cursor->right;
				cursor->right = skipNode;
			}
			cursor = cursor->right;
		}
		if(skipNode == NULL)
		{
			skipNode = new Node(val);
			cursor->right = skipNode;
		}

		while(newNode->up != NULL)
			newNode = newNode->up;

		skipNode->down = newNode;
		newNode->up = skipNode;
	}
}

/**
* @brief
*
* @method:    search
* @access:    public 
* @param:     int val
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/5/6  21:55 
*/
bool SkipList::search(int val)
{
	Node* cursor = NULL;
	if(head == NULL)
		return false;

	cursor = head;
	while(cursor->down != NULL)
	{
		while(cursor->right != NULL)
		{
			if(val <= cursor->right->value)
				break;
			cursor = cursor->right;
		}
		cursor = cursor->down;
	}
	while(cursor->right != NULL)
	{
		if(val > cursor->right->value)
			cursor = cursor->right;
		else if(val == cursor->right->value)
			return true;
		else if(val < cursor->right->value)
			return false;
	}
	return false;
}

/**
* @brief
*
* @method:    remove
* @access:    public 
* @param:     int val
* @Return:    void
* @author:    RF_LYF
* @since:   2019/5/6  22:11 
*/
void SkipList::remove(int val)
{
	Node* cursor = head;
	Node* pre_head = NULL;
	while(true)
	{
		Node* cur_head = cursor;
		if(pre_head != NULL)
		{
			cur_head->up = NULL;
			pre_head->down = NULL;
			delete pre_head;
			pre_head = NULL;
			lvl_num--;
			head = cur_head;
		}
		
		while(cursor != NULL && cursor->right != NULL)
		{
			if(val == cursor->right->value)
			{
				Node* delptr = cursor->right;
				cursor->right = cursor->right->right;
				delete delptr;
			}
			cursor = cursor->right;
		}
		if(cur_head->right == NULL)
			pre_head = cur_head;
		if(cur_head->down == NULL)
			break;
		else
			cursor = cur_head->down;
	}
}