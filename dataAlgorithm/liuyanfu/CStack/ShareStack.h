#ifndef _SHARE_STACK_H
#define _SHARE_STACK_H


typedef unsigned int UINT;
template<typename DATA>
class ShareStack
{
public:
	ShareStack(void);
	ShareStack(const UINT&);
	~ShareStack(void);
	bool Empty() const;
	void Clear();

	UINT GetLength() const;
	const DATA* GetLeftStackTop() const;
	void LeftStackPush(const DATA& data);
	void LeftStackPop();

	const DATA* GetRightStackTop() const;
	void RightStackPush(const DATA& data);
	void RigthStackPop();
	void PrintStack() const;
private:
	bool IsFull();
	void Expand();

	DATA* m_pStack;
	int m_nTop1;
	int m_nTop2;
	UINT m_nStackLen;
	UINT m_nStackSize;
};

#endif //_SHARE_STACK_H