package com.ht.algorithm.CycleLinkList;

public class Node {

    public Node next;
    public Integer data;

    public Node(Integer data) {
        this.data = data;
    }

    public Node(Integer obj, Node next) {
        this.next = next;
        this.data = obj;
    }

    public void setNext(Node next){
        this.next  =next;
    }

    public Node getNext() {
        return next;
    }

    public void setData(Integer data) {
        this.data = data;
    }

    public Integer getData() {
        return data;
    }
}
