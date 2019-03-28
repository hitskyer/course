#ifndef _ASTACK_H
#define _ASTACK_H

typedef unsigned int UINT;
class AStack
{
public:
	AStack(void);// 初始化栈
	~AStack(void);// 析构栈	
	AStack(UINT &);

	bool Empty() const;		// 判断是否为空
	void Clear();		// 则清空栈

	const int* GetTop() const;	// 得到栈顶元素 返回常量指针
	UINT GetLength() const;	// 返回栈的长度

	void Push(const UINT &data);	//往栈中压入数据
	void Pop();		//将栈顶数据弹出

	void PrintStack();//打印栈中的数据
private:
	void ExpandStack();
	bool isFull();

	int* m_pStack;	// 栈顶元素
	UINT m_nStackLen;	// 栈中有效数据的长度
	UINT m_nStackSize;   //栈的容量
	int m_nTop;	//记录栈顶的位置
};


#endif // _ASTACK_H
