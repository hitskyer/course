package com.ht.algorithm.Stack.LinkedListStack;

public class StackImpl implements Stack {

    // 保存该链栈的栈顶元素
    private Node top;
    // 保存该链栈中已包含的节点数
    private int size;


    // 创建空链栈
    public StackImpl() {
        // 空链栈，top的值为null
        top = null;
    }

    // 以指定数据元素来创建链栈，该链栈只有一个元素
    public StackImpl(Integer element) {
        top = new Node(element, null);
        size++;
    }


    @Override
    public Boolean isEmpty() {
        if(null == top && size==0){
            return true;
        }else{
            return false;
        }
    }

    @Override
    public void clear() {
        top = null;
        size = 0;
    }

    @Override
    public Object getTop() {
        return top.data;
    }

    @Override
    public Integer getLength() {
        return size;
    }

    @Override
    public void push(Integer data) {
        top = new Node(data, top);
        size++;
    }

    @Override
    public Integer pop() {
        Node oldTop = top;
        // 让top引用指向原栈顶元素的下一个元素
        top = top.next;
        // 释放原栈顶元素的next引用
        oldTop.next = null;
        size--;
        return oldTop.data;
    }


}
