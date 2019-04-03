package com.ht.algorithm.Stack.LinkedListStack;

// 栈的接口定义
public interface Stack {

    // 判断栈是否为空
    public Boolean isEmpty();

    // 清空栈
    public void clear();

    // 获取栈顶元素
    public Object getTop();

    // 获取栈的长度
    public Integer getLength();

    // 压栈
    public void push(Integer data);

    // 弹栈
    public Integer pop();




}
