#ifndef _TEMPLET_STACK_H
#define _TEMPLET_STACK_H

template<typename DATA>
struct SNode
{
	DATA data;
	SNode* pNext;
};

typedef unsigned int UINT;

template<typename DATA>
class TmpStack
{
public:
	typedef SNode<DATA>* StackNode;
public:
	TmpStack(void);
	~TmpStack(void);

	bool Empty() const;		// 判断是否为空
	void Clear();		// 则清空栈

	const SNode<DATA>* GetTop() const;	// 得到栈顶元素
	UINT GetLength() const;	// 返回栈的长度
	void Push(const DATA& data);	//往栈中压入数据
	void Pop();		//将栈顶数据弹出
	void PrintStack();
private:
	StackNode m_pTop;	// 栈顶元素
	UINT m_nStackLen;
};

#endif //_TEMPLET_STACK_H