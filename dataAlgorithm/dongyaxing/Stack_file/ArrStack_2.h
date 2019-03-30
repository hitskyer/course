/**
* 摘要：	数组-栈，直接类封装，没有数组结构
* 修改：	在mingming的基础上，修改，添加一个当前长度，获得当前位置
* 作者：	dongyaxing
* 日期：	2019/3/30
*/
#ifndef _ARRSTACK_2_H
#define _ARRSTACK_2_H

#define MAX_SIZE 20
typedef unsigned int UINT;
template <class T>

class arrStack
{
public:
	arrStack(void);				// 构造函数，不用指定大小
	arrStack(UINT max_size);	// 可以指定大小
	~arrStack(void);			// 析构函数

	bool IsEmpty() const;			// 判断是否为空
	bool IsFull() const;			// 判断是否满栈
	void Clear();					// 清空栈

	T GetTop() const;				// 得到栈顶元素
	UINT GetLength() const;			// 返回栈的长度
	UINT GetCurrLength() const;		// 返回当前栈的长度

	void Push(T &data);				// 压栈
	void Pop();						// 弹栈
	void Print();					// 输出栈的内容

//private:
	void Expand();					// 扩容

private:
	int m_nTop;			// 栈顶索引
	UINT m_nStackLen;	// 栈长度
	T* arr;				// 数组arr
};





#endif
