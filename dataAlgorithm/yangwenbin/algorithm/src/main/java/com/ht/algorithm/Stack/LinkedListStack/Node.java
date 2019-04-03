package com.ht.algorithm.Stack.LinkedListStack;

public class Node {
    // 保存节点的数据
    public Integer data;
    // 指向下个节点的引用
    public Node next;
    // 无参构造器
    public Node() {
    }
    // 初始化全部属性的构造器
    public Node(Integer data, Node next) {
        this.data = data;
        this.next = next;
    }

}
