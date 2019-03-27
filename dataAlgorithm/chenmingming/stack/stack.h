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
template <class T>
struct SNode
{
    T data;
    SNode *pNext;
};
template <class T>
        using StackNode = SNode<T>* ;
//typedef SNode<T>* StackNode;
typedef unsigned int UINT;
template <class T>
class Stack
{
public:
    Stack(void);		// 初始化栈
    ~Stack(void);		// 析构栈

    bool Empty() const;		// 判断是否为空
    void Clear();		// 则清空栈

    StackNode<T> GetTop() const;	// 得到栈顶元素
    UINT GetLength() const;	// 返回栈的长度

    void Push(T &data);	//往栈中压入数据
    void Pop();		//将栈顶数据弹出
    void print();   //自己加的接口，打印输出stack内容
private:
    StackNode<T> m_pTop;	// 栈顶元素
    UINT m_nStackLen;	// 栈长度
};

#endif  //_STACK_H