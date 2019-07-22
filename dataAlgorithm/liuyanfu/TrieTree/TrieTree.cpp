#include "TrieTree.h"

TrieTree::TrieTree(void)
{
	root = new TrieNode('/');
}


TrieTree::~TrieTree(void)
{
	clear();
}


template<typename Iterator>
void TrieTree::insert(Iterator begin, Iterator end)
{
	TrieNode* cur = root;
	for(; begin != end; ++begin)
	{
		int index = *begin - 'a';
		if(cur->children[index] == 0)
		{
			cur->children[index] = new TrieNode(*begin);
			++cur->nodeNum;
		}
		cur = cur->children[index];
	}
	cur->isEndingChar = true;
}


void TrieTree::insert(const char* text)
{
	insert(text, text + strlen(text));
}


template<typename Iterator>
bool find(Iterator begin, iterator end)
{
	TrieNode* cur = root;
	for(; begin != end; ++begin)
	{
		int index = *begin - 'a';
		if(cur->children[index] == 0)
			return false;
		cur = cur->children[index];
	}
	return cur->isEndingChar;
}

bool TrieTree::find(const char* pattern)
{
	return find(pattern, pattern + strlen(pattern));
}


void TrieTree::clear()
{
	clear_node(*root);
	for(int i = 0; i < 26; ++i)
	{
		root->children[i] = 0;
	}
}

void TrieTree::clear_node(TrieNode cur)
{
	for(int i = 0; i < 26; ++i)
	{
		if(cur.children[i] == 0) 
			continue;
		clear_node(*cur.children[i]);
		delete cur.children[i];
		cur.children[i] = 0;
		if(--cur.nodeNum == 0)
			break;
	}
}