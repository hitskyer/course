#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lp, *rp;
}BiTNode, *BiTree;

/*
* 递归查找二叉排序树（也叫二叉查找树）T中是否存在key
* 指针f指向T的双亲，其初始调用值为NULL
* 若查找成功，则指针p指向该数据元素结点，并返回TRUE
* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
*/
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else if (key == T->data)
	{
		*p = T;
		return true;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lp, key, T, p);
	}
	else
	{
		return SearchBST(T->rp, key, T, p);
	}
}


/****************************************************************
* @brief : 		二叉排序(查找)树，的插入方法
* @author : 	dyx
* @date : 		2019/7/2 9:45
* @version : 	ver 1.0
* @inparam :    T ：树的头结点指针，key:要插入的数据
* @outparam :	bool：是否插入成功
*****************************************************************/
bool InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p))		//查找不成功，才插入。即先判断是否数据库中 存在此数据。
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lp = s->rp = NULL;
		if (!p)
		{
			*T = s;					// 没有结点，直接作为根结点
		}
		else if (key < p->data)
		{
			p->lp = s;				// s作为查找到最后一个结点的左子
		}
		else
		{
			p->rp = s;				// s作为查找到最后一个结点的右子
		}
		return true;
	}
	else
		return false;				// 树中有此结点，不允许插入
}

/****************************************************************
* @brief : 		删除某个结点
* @author : 	dyx
* @date : 		2019/7/2 9:49
* @version : 	ver 1.0
* @inparam :	T：要删除的结点
* @outparam :	bool：是否删除成功
*****************************************************************/
bool Delete(BiTree *p)
{
	BiTree q,s;
	bool flag = false;
	if ((*p)->rp == NULL)		// 只有左子树
	{
		q = *p;
		*p = (*p)->lp;
		free(q);
		flag = true;
	}
	else if ((*p)->lp == NULL)		// 只有右子树
	{
		q = *p;
		*p = (*p)->rp;
		free(q);
		flag = true;
	}
	else						// 左右子树子子孙孙
	{
		q = *p;
		s = (*p)->lp;
		while(s->rp)
		{
			q = s;
			s = s->rp;
		}
		(*p)->data = s->data;
		if (q!=*p)
		{
			q->rp = s->lp;
		}
		else
		{
			q->lp = s->lp;
		}
		free(s);
		flag = true;
	}
	return flag;
}

/****************************************************************
* @brief : 		递归删除某棵树的某个值
* @author : 	dyx
* @date : 		2019/7/2 9:51
* @version : 	ver 1.0
* @inparam :	T：树的根结点。key:要删除的值
* @outparam :	bool：是否删除成功
*****************************************************************/
bool DeleteBST(BiTree *T, int key)
{
	if (!*T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			return  Delete(T);
		}
		else if (key <(*T)->data)
		{
			return DeleteBST(&(*T)->lp, key);
		}
		else
		{
			return DeleteBST(&(*T)->rp, key);
		}
	}
}


/****************************************************************
* @brief : 		前序打印，检查结果是否正确
* @author : 	dyx
* @date : 		2019/7/2 9:52
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void preOrderPrint(BiTree T)
{
	if (!T)
	{
		return;
	}
	cout << T->data << " ";
	preOrderPrint(T->lp);
	preOrderPrint(T->rp);
}

int main()
{
	int i;
	int a[10] = {62,88,58,47,35,73,51,99,37,93};
	BiTree T = NULL;
	for(i = 0; i < 10; ++i)
	{
		InsertBST(&T, a[i]);
	}

	cout << endl;
	cout << InsertBST(&T,73) << endl;
	cout << InsertBST(&T,56) << endl;
	preOrderPrint(T);
	cout << endl;

	DeleteBST(&T,35);
	preOrderPrint(T);
	cout << endl;
//	system("pause");
	return 0;
}

