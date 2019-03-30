package com.ht.algorithm.Stack.LinkedListStack;

public class Main {
    public static void main(String[] args) {
        StackImpl stack = new StackImpl();
        stack.push(20);
        stack.push(50);

        System.out.println("栈中元素的长度:"+stack.getLength());
        System.out.println("栈顶元素为:"+stack.getTop());
        System.out.println("弹出栈顶元素为:"+stack.pop());
        System.out.println("栈是否为空："+stack.isEmpty());


        stack.clear();
        System.out.println("栈是否为空："+stack.isEmpty());
    }
}
