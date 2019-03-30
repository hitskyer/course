package com.ht.algorithm.Stack.SequenceStack;

public class Main {
    public static void main(String[] args) {
        StackImpl stack = new StackImpl(10);

        for(int i = 0;i<5;i++){
            stack.push(i);
        }

        System.out.println("栈中元素的长度:"+stack.getLength());
        System.out.println("栈顶元素为:"+stack.getTop());
        System.out.println("弹出栈顶元素为:"+stack.pop());
        System.out.println("栈是否为空："+stack.isEmpty());
        System.out.println("栈是否已经满了："+stack.isFull());

        stack.clear();
        System.out.println("栈是否为空："+stack.isEmpty());
    }
}
