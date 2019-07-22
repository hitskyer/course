/*
* Copyright: (c) 2019
*
* 文件名称:  ACM1577.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/6/4  14:14
*/

#include <stdio.h>
#include <string.h>
#include <stack>
#define MAXLEN 30

using namespace std;
struct Node
{
	char data;
	Node* pleft;
	Node* pright;
	Node(char ch)
	{
		data = ch;
		pleft = NULL;
		pright = NULL;
	}
};

char Input[MAXLEN][MAXLEN];
Node* root = NULL;

void BuildSearchTree(char data)
{
	if(root == NULL)
	{
		root = new Node(data);
		return;
	}
	Node* pTemp = root;
	while(pTemp)
	{
		if(data < pTemp->data)
		{
			if(pTemp->pleft == NULL)
			{
				pTemp->pleft = new Node(data);
				return;
			}
			pTemp = pTemp->pleft;
		}
			
		else
		{
			if(pTemp->pright == NULL)
			{
				pTemp->pright = new Node(data);
				return;
			}
			pTemp = pTemp->pright;
		}
			
	}
}


void PreOrder(Node* proot)
{
	if(proot == NULL)
		return;
	else
	{
		Node* p = proot;
		stack<Node*> que;
		que.push(p);
		while(!que.empty())
		{
			p = que.top();
			printf("%c", p->data);
			que.pop();
			if(p->pright)
				que.push(p->pright);
			if(p->pleft)
				que.push(p->pleft);
		}
	}
}


void Erase(Node* proot)
{
	if(proot == NULL)
		return;
	else
	{
		Erase(proot->pleft);
		Erase(proot->pright);
		delete proot;
		proot = NULL;
	}
	root = NULL;
}


int main()
{
	bool nFlag = false;
	while(1)
	{
		int n = 0;
		while(scanf("%s", Input[n]) && Input[n][0] != '*' && Input[n][0] != '$')
		{
			n++;
		}
		if(Input[n][0] == '$')
			nFlag = true;
		for(int i = n-1; i >= 0; --i)
		{
			for(int j = 0; j < strlen(Input[i]); ++j)
			{
				BuildSearchTree(Input[i][j]);
			}
		}
		PreOrder(root);
		printf("\n");
		Erase(root);
		memset(Input, NULL, 30*30);
		if(nFlag)
			break;
	}
	
	return 0;
}