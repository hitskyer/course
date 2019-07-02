#include <iostream>
#include <stdlib.h>
using namespace std;

#define LH +1		// 左高
#define EH 0		// 等高
#define RH -1		// 右高

/*
平衡二叉树的数据结构
*/
typedef struct BalanceBiTNode
{
	int data;
	int bf;				/*结点的平衡因子*/
	struct BalanceBiTNode *lp, *rp;
}BalanceBiTNode, *BalanceBiTree;


/****************************************************************
* @brief : 		以p为根结点的二叉树做右旋(bf正值)
* @author : 	dyx
* @date : 		2019/7/2 10:37
* @version : 	ver 1.0
* @inparam : 
* @outparam :	处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
*****************************************************************/
void R_Rotate(BalanceBiTree *p)
{
	BalanceBiTree L;
	L = (*p)->lp;		// L指向p的左子树根结点
	(*p)->lp = L->rp;	// L的右子树挂接为p的左子树
	L->rp = (*p);
	*p = L;				// p指向新的根结点
}

/****************************************************************
* @brief : 		以p为根结点的二叉树做左旋(bf负值)
* @author : 	dyx
* @date : 		2019/7/2 10:37
* @version : 	ver 1.0
* @inparam : 
* @outparam :	处理之后p指向新的树根结点，即旋转处理之前的右子树的根结点0
*****************************************************************/
void L_Rotate(BalanceBiTree *p)
{
	BalanceBiTree R;		//R指向p的右子树根结点
	R = (*p)->rp;			// R的左子树挂为p的右子树
	(*p)->rp = R->lp;		
	R->lp = (*p);
	*p = R;					// p指向新的根结点
}


/****************************************************************
* @brief : 		对以指针T所指向的结点为根的二叉树作为平衡旋转处理
* @author : 	dyx
* @date : 		2019/7/2 10:48
* @version : 	ver 1.0
* @inparam :	
* @outparam :	结束时，指针T指向新的根结点
*****************************************************************/
void LeftBalance(BalanceBiTree *T)
{
	BalanceBiTree L, Lr;
	L = (*T)->lp;				// L 指向T的左子树根结点
	switch(L->bf)
	{							// 检查T的左子树的平衡度，并左相应平衡处理
	case LH:					// 新结点插入在T的左孩子的左子树上，单做右旋处理
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:					// 新结点插入在T的左孩子的右子树上，要做双旋转处理
		Lr = L->rp;				// Lr指向T的左孩子的右子树根
		switch(Lr->bf)			// 修改T及其左孩子的平衡因子
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lp);		// 对T的左子树做左旋平衡处理
		R_Rotate(T);				// 对T做右旋平衡处理
		break;
	}
}

/****************************************************************
* @brief : 		对以指针T所指结点为根的二叉树做右平衡旋转处理
* @author : 	dyx
* @date : 		2019/7/2 13:35
* @version : 	ver 1.0
* @inparam : 
* @outparam :	算法结束时，指针T指向新的根结点
*****************************************************************/
void RightBalance(BalanceBiTree *T)
{
	BalanceBiTree L, Ll;
	L = (*T)->rp;			// L指向T的右子树根结点
	switch(L->bf)
	{
		/*检查T的右子树的平衡度，并做相应平衡处理*/
	case RH:		// 新节点插入在T的右孩子的左子树上，要做单左处理
		(*T)->bf = L->bf = EH;
		L_Rotate(T);
		break;
	case LH:			// 新结点插入在T的右孩子的左子树上，要做双旋处理
		Ll = L->lp;		// Lr指向T的右孩子的左子树根
		switch(Ll->bf)		// 修改T及其右孩子的平衡因子
		{
		case LH:
			(*T)->bf = EH;
			L->bf = RH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = LH;
			L->bf = EH;
			break;
		}
		Ll->bf = EH;
		R_Rotate(&(*T)->rp);		// 对T的右子树做右旋平衡处理
		L_Rotate(T);				// 对T做左平衡处理
		break;
	}
}

/****************************************************************
* @brief : 		若在平衡二叉树排序T中，和e有相同关键字的结点，
				则插入一个e,返回1，否则，返回0
				若插入后，影响平衡，则进行旋转处理
* @author : 	dyx
* @date : 		2019/7/2 13:40
* @version : 	ver 1.0
* @inparam :	taller:表示T是否长高。true则长高。
* @outparam : 
*****************************************************************/
bool InsertAVL(BalanceBiTree *T, int e, bool *taller)
{
	if (!*T)
	{
		/* 插入新结点，树“长高”，taller为true*/
		*T = (BalanceBiTree) malloc(sizeof(BalanceBiTNode));
		(*T)->data = e;
		(*T)->lp = (*T)->rp = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else
	{
		if (e == (*T)->data)
		{			/* 树中已经存在和e有相同关键字的结点，则不再插入*/
			*taller = false;
			return false;
		}
		if (e < (*T)->data)
		{
			/* 应继续在T的左子树中进行搜索*/
			if (!InsertAVL(&(*T)->lp, e, taller))	// 未插入
			{
				return false;
			}
			if (taller)	// 已经插入到Ttaller左子树“长高”
			{
				switch((*T)->bf)
				{
				case LH:				// 原本左子树比右子树高，需要作左平衡处理
					LeftBalance(T);
					*taller = false;
					break;
				case EH:				// 原本左子树等高，现在因左子树增高而树增高
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:				// 原本右子树比左子树高，现左右子树等高
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
		else
		{
			/*应继续在T的右子树中进行搜索*/
			if (!InsertAVL(&(*T)->rp, e, taller))	// 未插入
			{
				return false;
			}
			if (*taller)		// 已插入到T的右子树且右子树“长高”
			{
				switch((*T)->bf)	// 检查T的平衡度
				{
				case LH:			// 原本左子树比右子树高，现在左右等高
					(*T)->bf = EH;
					*taller = false;
					break;	
				case EH:			// 原本左右子树等高，现在右子树增高，树也增高
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:			// 原本右子树比左子树高，需要做右平衡处理
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return true;
}


/****************************************************************
* @brief : 		中序打印输出
* @author : 	dyx
* @date : 		2019/7/2 13:59
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void innerPrint(BalanceBiTree T)
{
	if (!T)
	{
		return;
	}
	innerPrint(T->lp);
	cout << T->data << " ";
	innerPrint(T->rp);
}
int main()
{
	int i;
	int a[10] = {3,2,1,4,5,6,7,10,9,8};
	BalanceBiTree T = NULL;
	bool taller;
	for (i = 0; i < 10; ++i)
	{
		InsertAVL(&T, a[i], &taller);
	}
	innerPrint(T);
	//system("pause");
	return 0;
}
