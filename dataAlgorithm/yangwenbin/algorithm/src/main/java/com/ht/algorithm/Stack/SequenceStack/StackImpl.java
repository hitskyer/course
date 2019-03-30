package com.ht.algorithm.Stack.SequenceStack;

public class StackImpl implements Stack {

    private int maxSize;// 栈的大小
    private int top;
    private Integer[] arr;

    // 初始化栈
    public StackImpl(int size) {
        maxSize = size;
        top = -1;
        arr = new Integer[maxSize];
    }


    @Override
    public Boolean isEmpty() {
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    @Override
    public void clear() {
        if(top == -1) return;
        Integer loopIndex = top;
        for(int i =0;i<= loopIndex;i++){
            pop();
        }
    }

    @Override
    public Object getTop() {
        return arr[top];
    }

    @Override
    public Integer getLength() {
        return top+1;
    }

    @Override
    public void push(Integer data) {
        arr[++top] = data;
    }

    @Override
    public Integer pop() {
        return arr[top--];
    }

    @Override
    public Boolean isFull() {
        return (top-1 == arr.length) ? true : false;
    }
}
