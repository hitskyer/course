#include "AC.h"
#include <iostream>
#include <queue>

using namespace std;

AC::AC(void)
{
	root = new ACNode('/');
}


AC::~AC(void)
{
	clear();
}


template<typename Iterator>
void AC::insert(Iterator begin, Iterator end)
{
	ACNode *cur = root;
	int i;
	for(i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		if(cur->child[index] == 0)
		{
			cur->child[index] = new ACNode(*begin);
			++cur->nodeNum;
		}
		cur = cur->child[index];
	}
	cur->isEndingChar = true;
	cur->length = i;
}


void AC::insert(const char* text)
{
	insert(text, text + strlen(text));
}


template<typename Iterator>
bool AC::find(Iterator begin, Iterator end)
{
	ACNode* cur = root;
	for(; begin != end; ++begin)
	{
		int index = *begin - 'a';
		if(cur->child[index] == 0)
			return false;
		cur = cur->child[index];
	}
	return cur->isEndingChar;
}


bool AC::find(const char* pattern)
{
	return find(pattern, pattern + strlen(pattern));
}


void AC::buildFailurePointer()
{
	queue<ACNode> que;
	root->pFail = NULL;
	que.push(*root);
	while(!que.empty())
	{
		ACNode p = que.front();
		que.pop();
		for(int i = 0; i < 26; ++i)
		{
			ACNode* pc = p.child[i];
			if(pc == NULL)
				continue;
			if(p == *root)
				pc->pFail = root;
			else
			{
				ACNode* q = p.pFail;
				while(q != NULL)
				{
					ACNode* qc = q->child[pc->data - 'a'];
					if(qc != NULL)
					{
						pc->pFail = qc;
						break;
					}
					q = q->pFail;
				}
				if(q == NULL)
					pc->pFail = root;
			}
			que.push(*pc);
		}
	}
}


template<typename Iterator>
void AC::match(Iterator begin, Iterator end, PosSet* ret)
{
	ACNode* cur = root;
	for(int i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		while(cur->child[index] == 0 && cur != root)
		{
			cur = cur->pFail;
		}
		cur = cur->child[index];
		if(cur == 0)
			cur = root;
		ACNode* pTemp = cur;
		while(pTemp != root)
		{
			if(pTemp->isEndingChar == true)
			{
				ret->vPos.push_back(i - pTemp->length + 1);
				ret->vLen.push_back(pTemp->length); 
			}
			pTemp = pTemp->pFail;
		}
	}
}


void AC::match(const char* text, PosSet* ret)
{
	match(text, text + strlen(text), ret);
}


void AC::clear_node(ACNode cur)
{
	for(int i = 0; i < 26; ++i)
	{
		if(cur.child[i] == 0)
			continue;
		clear_node(*cur.child[i]);
		delete cur.child[i];
		cur.child[i] = 0;
		if(--cur.nodeNum == 0)
			break;
	}
}


void AC::clear()
{
	clear_node(*root);
	for(int i = 0; i < 26; ++i)
	{
		root->child[i] = 0;
	}
}


void AC::print(const char* text)
{
	string str(text, text + strlen(text));
	PosSet ret;
	match(text, text + strlen(text), &ret);
	for(int i = 0; i < ret.vPos.size(); ++i)
	{
		string stemp(ret.vLen[i], '*');
		str = str.replace(ret.vPos[i], ret.vLen[i], stemp.c_str());
	}
	cout << str.c_str() << endl;
}