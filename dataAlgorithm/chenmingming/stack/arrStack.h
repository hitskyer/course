//
// Created by mingm on 2019/3/27.
//
#ifndef STACK_ARRSTACK_H
#define STACK_ARRSTACK_H
typedef unsigned int UINT;
template <class T>
class arrStack
{
public:
    arrStack(int capacity);		// 初始化栈
    ~arrStack(void);		// 析构栈

    bool Empty() const;		// 判断是否为空
    bool IsFull() const;    //判断栈是否满了
    void Clear();		// 则清空栈

    T& GetTop() const;	// 得到栈顶元素
    UINT GetLength() const;	// 返回栈的长度

    void Push(T &data);	//往栈中压入数据
    void Expand();  //栈扩容
    void Pop();		//将栈顶数据弹出
    void print();   //自己加的接口，打印输出stack内容
private:
    int m_pTop;	// 栈顶指针
    UINT m_nStackLen;	// 栈容量
    T* arr; //数组arr
};

#endif //STACK_ARRSTACK_H
