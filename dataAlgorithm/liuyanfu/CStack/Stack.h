/*
* 概述：	栈
* 作者：	dongyaxing
* 版本：	1.0
* 创建时间：2019/3/25   20:47
* 修改者： liuyanfu
* 修改时间： 2019/3/25   21:14
*/

#ifndef _STACK_H
#define _STACK_H

struct SNode
{
	int data;
	SNode *pNext;
};
typedef SNode *StackNode;
typedef unsigned int UINT;

class CStack
{
public:
	CStack(void);
	~CStack(void);

	bool Empty() const;	
	void Clear();

	StackNode GetTop() const;
	UINT GetLength() const;	

	void Push(const int &data);
	void Pop();
	void Print() const;
private:
	StackNode m_pTop;
	UINT m_nStackLen;
};

#endif//_STACK_H
