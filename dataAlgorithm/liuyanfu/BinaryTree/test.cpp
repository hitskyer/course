#include <iostream>

using namespace std;

typedef char DATA;
struct SNode
{
	DATA data;
	SNode *pLeft;
	SNode *pRight;
	SNode(DATA d):data(d),
		pLeft(NULL),pRight(NULL) {}
};

//前序遍历
void PreOrder(SNode *pRoot)
{
	if(!pRoot)
		return;
	cout << pRoot->data << " ";
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

//中序遍历
void InnerOrder(SNode *pRoot)
{
	if(!pRoot)
		return;
	if(pRoot->pLeft)
		InnerOrder(pRoot->pLeft);
	cout << pRoot->data << " ";
	if(pRoot->pRight)
		InnerOrder(pRoot->pRight);
}


//后序输出
void PostOrder(SNode *p)
{
	if(!p)
		return;
	if(p->pLeft)
		PostOrder(p->pLeft);
	if(p->pRight)
		PostOrder(p->pRight);
	cout << p->data << " ";
}
int main()
{
	SNode *p = new SNode('A');
	p->pLeft = new SNode('B');
	SNode *pL = p->pLeft;
	pL->pLeft = new SNode('G');
	pL->pRight = new SNode('H');
	pL->pLeft->pRight = new SNode('D');

	p->pRight = new SNode('C');
	SNode *pR = p->pRight;
	pR->pLeft = new SNode('E');
	pR->pLeft->pLeft = new SNode('I');
	pR->pLeft->pRight = new SNode('J');
	pR->pRight = new SNode('F');

	cout << "前序遍历： ";
	PreOrder(p);
	cout << endl;
	cout << "中序遍历： ";
	InnerOrder(p);
	cout << endl;
	cout << "后序遍历： ";
	PostOrder(p);
	cout << endl;
	system("pause");
	return 0;
}