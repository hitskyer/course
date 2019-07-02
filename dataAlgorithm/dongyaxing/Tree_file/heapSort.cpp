#include <iostream>
#include <stdlib.h>
using namespace std;

/*
* 堆结构：
* 基于完全二叉树，除了最后一层，其他全是满的，且最后一层结点都靠左
* 每个结点必须大于等于（或者小于等于）其子树中每个结点的值
* 完全二叉树，适合用数组存储
*/
#define MAXSIZE 10
typedef struct SqList
{
	int r[MAXSIZE + 1];
	int length;
	SqList()
	{
		length = 0;
	}
}SqList;


/****************************************************************
* @brief : 		交换两个结点的位置
* @author : 	dyx
* @date : 		2019/7/2 17:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/****************************************************************
* @brief : 		调整数组中r[s-m]的数据，使之成为一个大顶堆
* @author : 	dyx
* @date : 		2019/7/2 16:55
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HeapAdjust(SqList *L, int s, int m)//4.9
{
	int temp, j;
	temp = L->r[s];		// 当前结点4
	for(j = 2*s; j <= m; j*=2)		// j = 2s，为当前结点的子结点
	{
		if (j < m && L->r[j] < L->r[j+1])	// 沿着关键字较大的孩子结点向下筛选
		{
			++j;							// j 为关键字中较大的记录的下标
		}
		if (temp >= L->r[j])
		{
			break;							// rc应插入在位置s上
		}
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;			// 插入
}


/****************************************************************
* @brief : 		对顺序表L进行堆排序
* @author : 	dyx
* @date : 		2019/7/2 17:12
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void HeapSort(SqList *L)
{
	int i;
	for (i = L->length/2; i > 0; --i)		// 把L中的r构成一个大顶堆
	{
		HeapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; --i)
	{
		swap(L, 1, i);						// 将堆定记录和当前未经排序子序列的最后一个记录交换
		HeapAdjust(L, 1, i-1);						// 将L->r[1...i-1]重新调整为大顶推
	}
}

/****************************************************************
* @brief : 		打印输出
* @author : 	dyx
* @date : 		2019/7/2 17:31
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void print(SqList *L)
{
	for (int i = 1; i < L->length; ++i)
	{
		cout << L->r[i] << " ";
	}
	cout << endl;
}

int main()
{
	// 初始化
	int arr[10] = {0,50,10,90,30,70,40,80,60,20};
	SqList sl;
	sl.r[0] = 0;
	for (int i = 1; i < 10; ++i)
	{
		sl.r[i] = arr[i];
		++sl.length;
	}
	// 打印输出原始数据
	print(&sl);
	cout << endl;
	// 堆排序
	HeapSort(&sl);
	//打印输出结果
	print(&sl);
//	system("pause");
	return 0;
}
