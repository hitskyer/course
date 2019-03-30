#ifndef _SHARE_STACK_H
#define _SHARE_STACK_H
#include <iostream>
#include <stdio.h>
#define INIT_SIZE 20
typedef unsigned UINT;
template<typename DATA>

class ShareStack
{
public:
	ShareStack(void);
	ShareStack(const UINT&);
	~ShareStack(void);
	bool IsEmpty() const;
	void Clear();

	UINT GetLength() const;
	const DATA* GetLeftStackTop() const;
	void LeftStackPush(const DATA &data);
	void LeftStackPop();

	const DATA* GetRightStackTop() const;
	void RightStackPush(const DATA &data);
	void RightStackPop();
	void PrintStack() const;
private:
	bool IsFull() const;
	void Expand();

	DATA *m_pStack;
	int m_nTop1;
	int m_nTop2;
	UINT m_nStackLen;		// 栈的有效数据个数
	UINT m_nStackSize;		// 栈的大小
};


#endif //_SHARE_STACK_H
